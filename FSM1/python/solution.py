from enum import Enum

class State(Enum):
    S1 = 1
    S2 = 2
    S3 = 3

class Solution:
    def __init__(self):
        self.state_ = State.S1
        self.tryCount_ = 0
        self.reqCos_ = 0
        self.finQos_ = 0
        self.out_str = ""


    def RunAndReset(self, inp_str):
        self.state_ = State.S1
        self.tryCount_ = 0
        self.reqCos_ = 0
        self.finQos_ = 0
        self.out_str = ""

        inp_strings = inp_str.split()
        for i in inp_strings:
            match self.state_:
                case State.S1:
                    self.CallS1(i)
                case State.S2:
                    self.CallS2(i)
                case State.S3:
                    self.CallS3(i)
        return self.out_str

    def CallS1(self, in_str):
        match in_str:
            case "ConReq_0":
                self.out_str = "{0}{1}".format(self.out_str, "connect_0 ")
                self.state_ = State.S2
                self.reqCos_ = 0
            case "ConReq_1":
                self.out_str = "{0}{1}".format(self.out_str, "connect_1 ")
                self.state_ = State.S2
                self.reqCos_ = 1
            case "ConReq_2":
                self.out_str = "{0}{1}".format(self.out_str, "NonSupport_2 ")
                self.state_ = State.S1
                self.reqCos_ = 2
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
        
    def CallS2(self, in_str):
        match in_str:
            case "accept_0":
                self.finQos_ = 0
                self.out_str = "{0}{1}{2}{3}".format(self.out_str, "CONcnf_", str(self.finQos_), " ")
                self.state_ = State.S3
            case "accept_1":
                if self.reqCos_ == 0:
                    self.finQos_ = 0
                else:
                    self.finQos_ = 1
                self.out_str = "{0}{1}{2}{3}".format(self.out_str, "CONcnf_", str(self.finQos_), " ")
                self.state_ = State.S3
            case "accept_2":
                if self.reqCos_ == 0:
                    self.finQos_ = 0
                else:
                    self.finQos_ = 1
                self.out_str = "{0}{1}{2}{3}".format(self.out_str, "CONcnf_", str(self.finQos_), " ")
                self.state_ = State.S3
            case "refuse":
                if self.tryCount_ == 2:
                    self.tryCount_ = 0
                    self.reqCos_ = 0
                    self.finQos_ = 0
                    self.out_str = "{0}{1}".format(self.out_str, "CONcnfNeg ")
                    self.state_ = State.S1
                else:
                    self.tryCount_ += 1
                    self.out_str = "{0}{1}{2}{3}".format(self.out_str, "connect_", str(self.reqCos_), " ")
                    self.state_ = State.S2
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")


    def CallS3(self, in_str):
        match in_str:
            case "Data":
                self.out_str = "{0}{1}{2}{3}".format(self.out_str, "data_", str(self.finQos_), " ")
                self.state_ = State.S3
            case "Reset":
                self.out_str = "{0}{1}".format(self.out_str, "abort ")
                self.tryCount_ = 0
                self.reqCos_ = 0
                self.finQos_ = 0
                self.state_ = State.S1
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
