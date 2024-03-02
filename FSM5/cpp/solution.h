#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    Solution(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
        awaitStart_ = true;
        awaitNegFirst_ = false;
        awaitFirstNum_ = false;
        awaitOperator_ = false;
        awaitNegSecond_ = false;
        awaitSecondNum_ = false;
        awaitResult_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            if (awaitStart_ == true) {
                if (inp_command == "Num") {
                    output << "Operand_B ";
                    awaitStart_ = false;
                    awaitFirstNum_ = true;
                } else if (inp_command == "Minus") {
                    output << "Negative_num ";
                    awaitStart_ = false;
                    awaitNegFirst_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitStart_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitNegFirst_ == true) {
                if (inp_command == "Num") {
                    output << "Operand_B ";
                    awaitNegFirst_ = false;
                    awaitFirstNum_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitNegFirst_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitFirstNum_ == true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitFirstNum_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitFirstNum_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitOperator_ == true) {
                if (inp_command == "Num") {
                    output << "Operand_C ";
                    awaitOperator_ = false;
                    awaitSecondNum_ = true;
                } else if (inp_command == "Minus") {
                    output << "Negative_num ";
                    awaitOperator_ = false;
                    awaitNegSecond_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitOperator_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitNegSecond_ == true) {
                if (inp_command == "Num") {
                    output << "Operand_C ";
                    awaitNegSecond_ = false;
                    awaitSecondNum_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitNegSecond_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitSecondNum_ == true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitSecondNum_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Equal") {
                    output << "Result ";
                    awaitSecondNum_ = false;
                    awaitResult_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitSecondNum_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            } else if (awaitResult_ == true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitResult_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Reset") {
                    output << "NULL ";
                    awaitResult_ = false;
                    awaitStart_ = true;
                } else {
                    output << "IncorrectCommand ";
                }
            }
        }
        return output.str();
    }

private:
    bool awaitStart_;
    bool awaitNegFirst_;
    bool awaitFirstNum_;
    bool awaitOperator_;
    bool awaitNegSecond_;
    bool awaitSecondNum_;
    bool awaitResult_;
};
