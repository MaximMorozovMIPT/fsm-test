#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Mutant1 {
public:
    Mutant1(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitFirstNum_ = true; */
                    awaitFirstNum_ == true;
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
                    awaitSecondNum_ == false;
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

class Mutant2 {
public:
    Mutant2(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ = ! true;
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
                    awaitSecondNum_ == false;
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

class Mutant3 {
public:
    Mutant3(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
                    awaitSecondNum_ == false;
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
/* XXX: original code was :                     awaitResult_ = false; */
                    awaitResult_ < false;
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

class Mutant4 {
public:
    Mutant4(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ = ! true;
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
                    awaitSecondNum_ == false;
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

class Mutant5 {
public:
    Mutant5(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
                    awaitSecondNum_ == false;
/* XXX: original code was :                     awaitResult_ = true; */
                    awaitResult_ <= true;
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

class Mutant6 {
public:
    Mutant6(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitNegFirst_ = true; */
                    awaitNegFirst_ = ! true;
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
                    awaitSecondNum_ == false;
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

class Mutant7 {
public:
    Mutant7(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitSecondNum_ = false; */
                    awaitSecondNum_ <= false;
                    awaitOperator_ = true;
                } else if (inp_command == "Equal") {
                    output << "Result ";
                    awaitSecondNum_ == false;
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

class Mutant8 {
public:
    Mutant8(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ >= true;
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
                    awaitSecondNum_ == false;
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

class Mutant9 {
public:
    Mutant9(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             } else if (awaitSecondNum_ == true) { */
            } else if (awaitSecondNum_  <  true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitSecondNum_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Equal") {
                    output << "Result ";
                    awaitSecondNum_ == false;
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

class Mutant10 {
public:
    Mutant10(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ > true;
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
                    awaitSecondNum_ == false;
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

class Mutant11 {
public:
    Mutant11(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                 if (inp_command == "Num") { */
                if (inp_command  <  "Num") {
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
                    awaitSecondNum_ == false;
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

class Mutant12 {
public:
    Mutant12(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             } else if (awaitSecondNum_ == true) { */
            } else if (awaitSecondNum_  <=  true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitSecondNum_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Equal") {
                    output << "Result ";
                    awaitSecondNum_ == false;
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

class Mutant13 {
public:
    Mutant13(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ >= true;
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
                    awaitSecondNum_ == false;
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

class Mutant14 {
public:
    Mutant14(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitFirstNum_ = true; */
                    awaitFirstNum_ >= true;
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
                    awaitSecondNum_ == false;
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

class Mutant15 {
public:
    Mutant15(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ >= true;
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
                    awaitSecondNum_ == false;
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

class Mutant16 {
public:
    Mutant16(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                 } else if (inp_command == "Reset") { */
                } else if (inp_command  >  "Reset") {
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
                    awaitSecondNum_ == false;
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

class Mutant17 {
public:
    Mutant17(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitOperator_ = true; */
                    awaitOperator_ == true;
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
                    awaitSecondNum_ == false;
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

class Mutant18 {
public:
    Mutant18(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitOperator_ = false; */
                    awaitOperator_ != false;
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
                    awaitSecondNum_ == false;
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

class Mutant19 {
public:
    Mutant19(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitStart_ = false; */
                    awaitStart_ == false;
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
                    awaitSecondNum_ == false;
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

class Mutant20 {
public:
    Mutant20(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitFirstNum_ = true; */
                    awaitFirstNum_ > true;
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
                    awaitSecondNum_ == false;
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

class Mutant21 {
public:
    Mutant21(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ = ! true;
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
                    awaitSecondNum_ == false;
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

class Mutant22 {
public:
    Mutant22(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             } else if (awaitNegSecond_ == true) { */
            } else if (awaitNegSecond_  <=  true) {
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
                    awaitSecondNum_ == false;
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

class Mutant23 {
public:
    Mutant23(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
                    awaitSecondNum_ == false;
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
/* XXX: original code was :                     awaitOperator_ = true; */
                    awaitOperator_ <= true;
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

class Mutant24 {
public:
    Mutant24(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             if (awaitStart_ == true) { */
            if (awaitStart_  >  true) {
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
                    awaitSecondNum_ == false;
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

class Mutant25 {
public:
    Mutant25(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
                    awaitSecondNum_ == false;
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
/* XXX: original code was :                 } else if (inp_command == "Reset") { */
                } else if (inp_command  !=  "Reset") {
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

class Mutant26 {
public:
    Mutant26(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             } else if (awaitSecondNum_ == true) { */
            } else if (awaitSecondNum_  <  true) {
                if (inp_command == "Minus" || inp_command == "Plus" ||
                    inp_command == "Mult" || inp_command == "Div") {
                    output << "Opeartor_Entered ";
                    awaitSecondNum_ = false;
                    awaitOperator_ = true;
                } else if (inp_command == "Equal") {
                    output << "Result ";
                    awaitSecondNum_ == false;
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

class Mutant27 {
public:
    Mutant27(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             if (awaitStart_ == true) { */
            if (awaitStart_  !=  true) {
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
                    awaitSecondNum_ == false;
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

class Mutant28 {
public:
    Mutant28(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :                     awaitNegSecond_ = false; */
                    awaitNegSecond_ = ! false;
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
                    awaitSecondNum_ == false;
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

class Mutant29 {
public:
    Mutant29(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
        awaitNegSecond_(false), awaitSecondNum_(false), awaitResult_(false)  {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         awaitStart_ = true; */
        awaitStart_ < true;
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
                    awaitSecondNum_ == false;
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

class Mutant30 {
public:
    Mutant30(): awaitStart_(true), awaitNegFirst_(false), awaitFirstNum_(false), awaitOperator_(false),
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
/* XXX: original code was :             } else if (awaitNegFirst_ == true) { */
            } else if (awaitNegFirst_  >=  true) {
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
                    awaitSecondNum_ == false;
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

