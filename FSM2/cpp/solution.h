#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    Solution(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            if (listen_ == true && sending_ == false) {
                if (inp_command == "Connect") {
                    listen_ = false;
                    sending_ = true;
                    output << "connect_accept ";
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (listen_ == false && sending_ == true) {
                if (inp_command == "Eps") {
                    listen_ = true;
                    sending_ = false;
                    output << "time_mess ";
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
};
