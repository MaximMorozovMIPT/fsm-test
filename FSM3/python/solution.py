class Solution:
    def __init__(self):
        self.listen_ = True
        self.sending_ = False
        self.err_ = False
        self.out_str = ''

    def RunAndReset(self, inp_str):
        self.listen_ = True
        self.sending_ = False
        self.err_ = False
        self.out_str = ''

        inp_strings = inp_str.split()
        for i in inp_strings:
            if self.listen_ == True and self.sending_ == False:
                if i == "Connect":
                    self.listen_ = False
                    self.sending_ = True
                    self.err_ = False
                    self.out_str = "{0}{1}".format(self.out_str, "Service_ready ")
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.listen_ == False and self.sending_ == True:
                if i == "MAILFROM_0":
                    self.err_ = True
                    self.out_str = "{0}{1}".format(self.out_str, "SynraxErr ")
                elif i == "MAILFROM_1":
                    self.err_ = False
                    self.out_str = "{0}{1}".format(self.out_str, "OK ")
                elif i == "RCPTTO_0":
                    self.err_ = True
                    self.out_str = "{0}{1}".format(self.out_str, "NO_USER ")
                elif i == "RCPTTO_1":
                    self.err_ = False
                    self.out_str = "{0}{1}".format(self.out_str, "OK ")
                elif i == "DATA":
                    if self.err_ == False:
                        self.out_str = "{0}{1}".format(self.out_str, "Start_mail ")
                    else:
                        self.listen_ = True
                        self.sending_ = False
                        self.err_ = False
                        self.out_str = "{0}{1}".format(self.out_str, "Service_unavaliable ")
                elif i == "QUIT":
                    self.listen_ = True
                    self.sending_ = False
                    self.err_ = False
                    self.out_str = "{0}{1}".format(self.out_str, "Service_closing ")
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
        return self.out_str
