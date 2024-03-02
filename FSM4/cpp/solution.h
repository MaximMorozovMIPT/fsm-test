#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "state.h"

class Solution {
public:
    Solution(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::Listen;
        mess_ = 0;
        del_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch (state_) {
                case State::Listen : {
                    CallListen(output, inp_command);
                    break;
                }
                case State::Login : {
                    CallLogin(output, inp_command);
                    break;
                }
                case State::Password : {
                    CallPassword(output, inp_command);
                    break;
                }
                case State::Transaction : {
                    CallTransaction(output, inp_command);
                    break;
                }
            }
        }

        return output.str();
    }

    void CallListen(std::stringstream &output, std::string inp_command) {
        if (inp_command == "connect") {
            output << "OK_serverReady ";
            state_ = State::Login;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallLogin(std::stringstream &output, std::string inp_command) {
        if (inp_command == "USER") {
            output << "OK_passRequired ";
            state_ = State::Password;
        } else if (inp_command == "QUIT") {
            output << "OK_serverSignOFF ";
            state_ = State::Listen;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallPassword(std::stringstream &output, std::string inp_command) {
        if (inp_command == "PASS_0") {
            output << "ERR_noSuchUser ";
            state_ = State::Login;
        } else if (inp_command == "PASS_1") {
            output << "OK ";
            state_ = State::Transaction;
            mess_ = 3;
            del_ = 0;
        } else if (inp_command == "QUIT") {
            output << "OK_serverSignOFF ";
            state_ = State::Listen;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallTransaction(std::stringstream &output, std::string inp_command) {
        if (inp_command == "STAT" || inp_command == "LIST" || inp_command == "LIST_2") {
            output << "OK ";
            state_ = State::Transaction;
        } else if (inp_command == "LIST_4" || inp_command == "RETR_4" || inp_command == "DELE_4") {
            output << "ERR_noSuchMess ";
            state_ = State::Transaction;
        } else if (inp_command == "RETR_2") {
            output << "OK_weight ";
            state_ = State::Transaction;
        } else if (inp_command == "DELE_2") {
            if (mess_ != 0) {
                mess_--;
                del_++;
                output << "OK_messDel ";
                state_= State::Transaction;
            } else {
                output << "IncorrectCommand ";
            }
        } else if (inp_command == "RSET") {
            output << "OK_mailDrop ";
            state_= State::Transaction;
            mess_ = 3;
            del_ = 0;
        } else if (inp_command == "QUIT") {
            output << "OK_serverSignOFF ";
            state_ = State::Listen;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int mess_;
    int del_;
};
