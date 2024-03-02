from enum import Enum

class State(Enum):
    Listen = 1
    Login = 2
    Password = 3
    Transaction = 4


class Solution:
    def __init__(self):
        self.state_ = State.Listen
        self.mess_ = 0
        self.del_ = 0
        self.out_str = ""

    def RunAndReset(self, inp_str):
        self.state_ = State.Listen
        self.mess_ = 0
        self.del_ = 0
        self.out_str = ""

        inp_strings = inp_str.split()
        for i in inp_strings:
            match self.state_:
                case State.Listen:
                    self.CallListen(i)
                case State.Login:
                    self.CallLogin(i)
                case State.Password:
                    self.CallPassword(i)
                case State.Transaction:
                    self.CallTransaction(i)

        return self.out_str

    def CallListen(self, in_str):
        match in_str:
            case "connect":
                self.out_str = "{0}{1}".format(self.out_str, "OK_serverReady ")
                self.state_ = State.Login
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")

    def CallLogin(self, in_str):
        match in_str:
            case "USER":
                self.out_str = "{0}{1}".format(self.out_str, "OK_passRequired ")
                self.state_ = State.Password
            case "QUIT":
                self.out_str = "{0}{1}".format(self.out_str, "OK_serverSignOFF ")
                self.state_ = State.Listen
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
        
    def CallPassword(self, in_str):
        match in_str:
            case "PASS_0":
                self.out_str = "{0}{1}".format(self.out_str, "ERR_noSuchUser ")
                self.state_ = State.Login
            case "PASS_1":
                self.out_str = "{0}{1}".format(self.out_str, "OK ")
                self.state_ = State.Transaction
                self.mess_ = 3
                self.del_ = 0
            case "QUIT":
                self.out_str = "{0}{1}".format(self.out_str, "OK_serverSignOFF ")
                self.state_ = State.Listen
            case _:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")

    def CallTransaction(self, in_str):
        if in_str == "STAT" or in_str == "LIST" or in_str == "LIST_2":
            self.out_str = "{0}{1}".format(self.out_str, "OK ")
            self.state_ = State.Transaction
        elif in_str == "LIST_4" or in_str == "RETR_4" or in_str == "DELE_4":
            self.out_str = "{0}{1}".format(self.out_str, "ERR_noSuchMess ")
            self.state_ = State.Transaction
        elif in_str == "RETR_2":
            self.out_str = "{0}{1}".format(self.out_str, "OK_weight ")
            self.state_ = State.Transaction
        elif in_str == "DELE_2":
            if self.mess_ != 0:
                self.mess_ -= 1
                self.del_ +=1
                self.out_str = "{0}{1}".format(self.out_str, "OK_messDel ")
                self.state_ = State.Transaction
            else:
                self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
        elif in_str == "RSET":
            self.mess_ = 3
            self.del_ = 0
            self.out_str = "{0}{1}".format(self.out_str, "OK_mailDrop ")
            self.state_ = State.Transaction
        elif in_str == "QUIT":
            self.out_str = "{0}{1}".format(self.out_str, "OK_serverSignOFF ")
            self.state_ = State.Listen
        else:
            self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
