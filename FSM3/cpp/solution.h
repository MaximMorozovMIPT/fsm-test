#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    Solution(): listen_(true), sending_(false), err_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;
        err_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            if (listen_ == true && sending_ == false) {
                if (inp_command == "Connect") {
                    listen_ = false;
                    sending_ = true;
                    err_ = false;
                    output << "Service_ready ";
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (listen_ == false && sending_ == true) {
                if (inp_command == "MAILFROM_0") {
                    err_ = true;
                    output << "SynraxErr ";
                } else if (inp_command == "MAILFROM_1") {
                    err_ = false;
                    output << "OK ";
                } else if (inp_command == "RCPTTO_0") {
                    err_ = true;
                    output << "NO_USER ";
                } else if (inp_command == "RCPTTO_1") {
                    err_ = false;
                    output << "OK ";
                } else if (inp_command == "DATA") {
                    if (err_ == false) {
                        output << "Start_mail ";
                    } else {
                        listen_ = true;
                        sending_ = false;
                        err_ = false;
                        output << "Service_unavaliable ";
                    }
                } else if (inp_command == "QUIT") {
                    listen_ = true;
                    sending_ = false;
                    err_ = false;
                    output << "Service_closing ";
                } else {
                    output << "IncorrectCommand ";
                }
            }
        }

        return output.str();
    }

private:
    bool listen_;
    bool sending_;
    bool err_;
};
