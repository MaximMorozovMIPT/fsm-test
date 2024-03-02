#pragma once

#include "state.h"

#include <string>
#include <sstream>
#include <iostream>

class Mutant1 {
public:

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::S1; */
        state_ > State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant2 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "Data") { */
        if (inp_command  !=  "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant3{
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "accept_0") { */
        if (inp_command  <=  "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant4 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
/* XXX: original code was :             state_ = State::S2; */
            state_ >= State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant5 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "Data") { */
        if ( 1 || inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant6 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "accept_0") { */
        if (inp_command  !=  "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant7 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "ConReq_0") { */
        if (inp_command != "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant8 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "accept_0") { */
        if (inp_command  >=  "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant9 {
public:

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::S1; */
        state_ == State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant10 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
/* XXX: original code was :             finQos_ = 0; */
            finQos_ == 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant11 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
/* XXX: original code was :                 finQos_ = 1; */
                finQos_ == 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant12 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
/* XXX: original code was :             state_ = State::S1; */
            state_ >= State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant13 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
/* XXX: original code was :                 finQos_ = 1; */
                finQos_ = ! 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant14 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
/* XXX: original code was :         } else if (inp_command == "accept_1") { */
        } else if (inp_command  >=  "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant15 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
/* XXX: original code was :             state_ = State::S3; */
            state_ <= State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant16 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "ConReq_0") { */
        if ( 0 && inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant17 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
/* XXX: original code was :                     break; */
                    {;}
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant18 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
/* XXX: original code was :             state_ = State::S3; */
            state_ < State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant19 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "ConReq_0") { */
        if ( 1 || inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant20 {
public:
    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::S1; */
        state_ > State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant21 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
/* XXX: original code was :     int tryCount_; */
    short int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant22 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
/* XXX: original code was :                     break; */
                    {;}
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant23 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "ConReq_0") { */
        if (inp_command  !=  "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant24 {
public:

    std::string RunAndReset(std::stringstream &input) {
/* XXX: original code was :         state_ = State::S1; */
        state_ >= State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
        if (inp_command == "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};


class Mutant25 {
public:

    std::string RunAndReset(std::stringstream &input) {
        state_ = State::S1;
        tryCount_ = 0;
        reqCos_ = 0;
        finQos_ = 0;

        std::stringstream output;
        std::string inp_command;
        while (input >> inp_command) {
            switch(state_) {
                case State::S1: {
                    CallS1(output, inp_command);
                    break;
                }
                case State::S2: {
                    CallS2(output, inp_command);
                    break;
                }
                case State::S3: {
                    CallS3(output, inp_command);
                    break;
                }
            }
        }
        
        return output.str();
    }

    void CallS1(std::stringstream &output, std::string inp_command) {
        if (inp_command == "ConReq_0") {
            output << "connect_0 ";
            state_ = State::S2;
            reqCos_ = 0;
        } else if (inp_command == "ConReq_1") {
            output << "connect_1 ";
            state_ = State::S2;
            reqCos_ = 1;
        } else if (inp_command == "ConReq_2") {
            output << "NonSupport_2 ";
            state_ = State::S1;
            reqCos_ = 2;
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS2(std::stringstream &output, std::string inp_command) {
        if (inp_command == "accept_0") {
            finQos_ = 0;
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_1") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "accept_2") {
            if (reqCos_ == 0) {
                finQos_ = 0;
            } else {
                finQos_ = 1;
            }
            output << "CONcnf_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "refuse") {
            if (tryCount_ == 2) {
                tryCount_ = 0;
                reqCos_ = 0;
                finQos_ = 0;
                output << "CONcnfNeg ";
                state_ = State::S1;
            } else {
                tryCount_++;
                output << "connect_" << reqCos_ << " ";
                state_ = State::S2;
            }
        } else {
            output << "IncorrectCommand ";
        }
    }

    void CallS3(std::stringstream &output, std::string inp_command) {
/* XXX: original code was :         if (inp_command == "Data") { */
        if (inp_command  >=  "Data") {
            output << "data_" << finQos_ << " ";
            state_ = State::S3;
        } else if (inp_command == "Reset") {
            tryCount_ = 0;
            reqCos_ = 0;
            finQos_ = 0;
            output << "abort ";
            state_ = State::S1;
        } else {
            output << "IncorrectCommand ";
        }
    }

private:
    State state_;
    int tryCount_;
    int reqCos_;
    int finQos_;
};

