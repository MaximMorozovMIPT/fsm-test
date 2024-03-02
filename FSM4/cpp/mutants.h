#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "state.h"

class Mutant1 {
public:
    Mutant1(): state_(State::Listen), mess_(0), del_(0) {}

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
 /* XXX: original code was :         } else if (inp_command == "RSET") { */
        } else if (inp_command  >=  "RSET") {
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

class Mutant2 {
public:
    Mutant2(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ > State::Listen;
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

class Mutant3 {
public:
    Mutant3(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "STAT" || inp_command == "LIST" || inp_command == "LIST_2") { */
        if (inp_command  !=  "LIST" || inp_command == "STAT" || inp_command == "LIST_2" ) {
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

class Mutant4 {
public:
    Mutant4(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :                     break; */
                    {;}
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

class Mutant5 {
public:
    Mutant5(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :                     break; */
                    {;}
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

class Mutant6 {
public:
    Mutant6(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ != State::Listen;
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

class Mutant7 {
public:
    Mutant7(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "connect") { */
        if (inp_command  >=  "connect") {
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

class Mutant8 {
public:
    Mutant8(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ >= State::Listen;
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

class Mutant9 {
public:
    Mutant9(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :             mess_ = 3; */
            mess_ >= 3;
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

class Mutant10 {
public:
    Mutant10(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "STAT" || inp_command == "LIST" || inp_command == "LIST_2") { */
        if (inp_command == "STAT" || inp_command  >=  "LIST" || inp_command == "LIST_2") {
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

class Mutant11 {
public:
    Mutant11(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "connect") { */
        if (inp_command  >=  "connect") {
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

class Mutant12 {
public:
    Mutant12(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :                 del_++; */
                del_--;
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

class Mutant13 {
public:
    Mutant13(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
 /* XXX: original code was :         state_ = State::Listen; */
        state_ >= State::Listen;
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

class Mutant14 {
public:
    Mutant14(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "PASS_0") { */
        if (inp_command  <  "PASS_0") {
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

class Mutant15 {
public:
    Mutant15(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :             state_ = State::Listen; */
            state_ == State::Listen;
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

class Mutant16 {
public:
    Mutant16(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         } else if (inp_command == "PASS_1") { */
        } else if (inp_command  <  "PASS_1") {
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

class Mutant17 {
public:
    Mutant17(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "USER") { */
        if (inp_command  >  "USER") {
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

class Mutant18 {
public:
    Mutant18(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         } else if (inp_command == "QUIT") { */
        } else if (inp_command  <=  "QUIT") {
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

class Mutant19 {
public:
    Mutant19(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ < State::Listen;
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

class Mutant20 {
public:
    Mutant20(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ < State::Listen;
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

class Mutant21 {
public:
    Mutant21(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "PASS_0") { */
        if (inp_command  <=  "PASS_0") {
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

class Mutant22 {
public:
    Mutant22(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
 /* XXX: original code was :         state_ = State::Listen; */
        state_ == State::Listen;
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

class Mutant23 {
public:
    Mutant23(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "PASS_0") { */
        if (inp_command  !=  "PASS_0") {
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

class Mutant24 {
public:
    Mutant24(): state_(State::Listen), mess_(0), del_(0) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::Listen; */
        state_ <= State::Listen;
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

class Mutant25 {
public:
    Mutant25(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :                     break; */
                    {;}
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

class Mutant26 {
public:
    Mutant26(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "USER") { */
        if (inp_command  >  "USER") {
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

class Mutant27 {
public:
    Mutant27(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :             state_ = State::Listen; */
            state_ < State::Listen;
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

class Mutant28 {
public:
    Mutant28(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :         if (inp_command == "STAT" || inp_command == "LIST" || inp_command == "LIST_2") { */
        if (inp_command == "STAT" | inp_command == "LIST" || inp_command == "LIST_2") {
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

class Mutant29 {
public:
    Mutant29(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :                     break; */
                    {;}
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

class Mutant30 {
public:
    Mutant30(): state_(State::Listen), mess_(0), del_(0) {}

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
/* XXX: original code was :             state_ = State::Listen; */
            state_ == State::Listen;
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

