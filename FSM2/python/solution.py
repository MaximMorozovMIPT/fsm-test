class Solution:
    def __init__(self):
        self.listen_ = True
        self.sending_ = False
        self.out_str = ''

    def RunAndReset(self, inp_str):
        self.listen_ = True
        self.sending_ = False
        self.out_str = ''

        inp_strings = inp_str.split()
        for i in inp_strings:
            if self.listen_ == True and self.sending_ == False:
                if i == "Connect":
                    self.listen_ = False
                    self.sending_ = True
                    self.out_str = "{0}{1}".format(self.out_str, "connect_accept ")
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.listen_ == False and self.sending_ == True:
                if i == "Eps":
                    self.listen_ = True
                    self.sending_ = False
                    self.out_str = "{0}{1}".format(self.out_str, "time_mess ")
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")

        return self.out_str
