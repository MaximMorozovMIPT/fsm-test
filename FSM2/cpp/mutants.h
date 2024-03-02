#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Mutant1 {
public:
    Mutant1(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ > true;
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

class Mutant2 {
public:
    Mutant2(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (listen_  >  false && sending_ == true) {
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

class Mutant3 {
public:
    Mutant3(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ < true;
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

class Mutant4 {
public:
    Mutant4(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ != true;
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

class Mutant5 {
public:
    Mutant5(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (listen_ == false || sending_ == true) {
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

class Mutant6 {
public:
    Mutant6(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (sending_  =  true && listen_ == false) {
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

class Mutant7 {
public:
    Mutant7(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ < true;
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

class Mutant8 {
public:
    Mutant8(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ >= true;
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

class Mutant9 {
public:
    Mutant9(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ != true;
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

class Mutant10 {
public:
    Mutant10(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ >= true;
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

class Mutant11 {
public:
    Mutant11(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ <= true;
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

class Mutant12 {
public:
    Mutant12(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
/* XXX: original code was :             if (listen_ == true && sending_ == false) { */
            if (listen_ == true && !sending_ == false) {
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

class Mutant13 {
public:
    Mutant13(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ > true;
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

class Mutant14 {
public:
    Mutant14(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ != true;
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

class Mutant15 {
public:
    Mutant15(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (listen_ == false && !sending_ == true) {
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

class Mutant16 {
public:
    Mutant16(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (listen_  <  false && sending_ == true) {
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

class Mutant17 {
public:
    Mutant17(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ > true;
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

class Mutant18 {
public:
    Mutant18(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {

        listen_ > true;
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

class Mutant19 {
public:
    Mutant19(): listen_(true), sending_(false) {}

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
/* XXX: original code was :             } else if (listen_ == false && sending_ == true) { */
            } else if (listen_  =  false && sending_ == true) {
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

class Mutant20 {
public:
    Mutant20(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ <= true;
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

class Mutant21 {
public:
    Mutant21(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ >= true;
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

class Mutant22 {
public:
    Mutant22(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
/* XXX: original code was :             if (listen_ == true && sending_ == false) { */
            if ( ~ listen_ == true && sending_ == false) {
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

class Mutant23 {
public:
    Mutant23(): listen_(true), sending_(false) {}

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
/* XXX: original code was :                     listen_ = true; */
                    listen_ = ! true;
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

class Mutant24 {
public:
    Mutant24(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            if (listen_ == true && sending_ == false) {
                if (inp_command == "Connect") {
/* XXX: original code was :                     listen_ = false; */
                    listen_ <= false;
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

class Mutant25 {
public:
    Mutant25(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ <= true;
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

class Mutant26 {
public:
    Mutant26(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ != true;
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

class Mutant27 {
public:
    Mutant27(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         listen_ = true; */
        listen_ < true;
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

class Mutant28 {
public:
    Mutant28(): listen_(true), sending_(false) {}

    std::string RunAndReset(std::stringstream &input) {
        listen_ = true;
        sending_ = false;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
/* XXX: original code was :             if (listen_ == true && sending_ == false) { */
            if ( ! listen_ == true && sending_ == false) {
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

