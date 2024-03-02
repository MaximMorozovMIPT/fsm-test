from enum import Enum

class Solution:
    def __init__(self):
        self.awaitStart_ = True
        self.awaitNegFirst_ = False
        self.awaitFirstNum_ = False
        self.awaitOperator_ = False
        self.awaitNegSecond_ = False
        self.awaitSecondNum_ = False
        self.awaitResult_ = False
        self.out_str = ""


    def RunAndReset(self, inp_str):
        self.awaitStart_ = True
        self.awaitNegFirst_ = False
        self.awaitFirstNum_ = False
        self.awaitOperator_ = False
        self.awaitNegSecond_ = False
        self.awaitSecondNum_ = False
        self.awaitResult_ = False
        self.out_str = ""

        inp_strings = inp_str.split()
        for i in inp_strings:
            if self.awaitStart_ == True:
                match i:
                    case "Num":
                        self.out_str = "{0}{1}".format(self.out_str, "Operand_B ")
                        self.awaitStart_ = False
                        self.awaitFirstNum_ = True
                    case "Minus":
                        self.out_str = "{0}{1}".format(self.out_str, "Negative_num ")
                        self.awaitStart_ = False
                        self.awaitNegFirst_ = True
                    case "Reset":
                        self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                        self.awaitStart_ = False
                        self.awaitStart_ = True
                    case _:
                        self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitNegFirst_ == True:
                match i:
                    case "Num":
                        self.out_str = "{0}{1}".format(self.out_str, "Operand_B ")
                        self.awaitNegFirst_ = False
                        self.awaitFirstNum_ = True
                    case "Reset":
                        self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                        self.awaitNegFirst_ = False
                        self.awaitStart_ = True
                    case _:
                        self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitFirstNum_ == True:
                if i == "Minus" or i == "Plus" or i == "Div" or i == "Mult":
                    self.out_str = "{0}{1}".format(self.out_str, "Opeartor_Entered ")
                    self.awaitFirstNum_ = False
                    self.awaitOperator_ = True
                elif i == "Reset":
                    self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                    self.awaitFirstNum_ = False
                    self.awaitStart_ = True
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitOperator_ == True:
                match i:
                    case "Num":
                        self.out_str = "{0}{1}".format(self.out_str, "Operand_C ")
                        self.awaitOperator_ = False
                        self.awaitSecondNum_ = True
                    case "Minus":
                        self.out_str = "{0}{1}".format(self.out_str, "Negative_num ")
                        self.awaitOperator_ = False
                        self.awaitNegSecond_ = True
                    case "Reset":
                        self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                        self.awaitOperator_ = False
                        self.awaitStart_ = True
                    case _:
                        self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitNegSecond_ == True:
                match i:
                    case "Num":
                        self.out_str = "{0}{1}".format(self.out_str, "Operand_C ")
                        self.awaitNegSecond_ = False
                        self.awaitSecondNum_ = True
                    case "Reset":
                        self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                        self.awaitNegSecond_ = False
                        self.awaitStart_ = True
                    case _:
                        self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitSecondNum_ == True:
                if i == "Minus" or i == "Plus" or i == "Div" or i == "Mult":
                    self.out_str = "{0}{1}".format(self.out_str, "Opeartor_Entered ")
                    self.awaitSecondNum_ = False
                    self.awaitOperator_ = True
                elif i == "Equal":
                    self.out_str = "{0}{1}".format(self.out_str, "Result ")
                    self.awaitSecondNum_ = False
                    self.awaitResult_ = True
                elif i == "Reset":
                    self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                    self.awaitSecondNum_ = False
                    self.awaitStart_ = True
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
            elif self.awaitResult_ == True:
                if i == "Minus" or i == "Plus" or i == "Div" or i == "Mult":
                    self.out_str = "{0}{1}".format(self.out_str, "Opeartor_Entered ")
                    self.awaitResult_ = False
                    self.awaitOperator_ = True
                elif i == "Reset":
                    self.out_str = "{0}{1}".format(self.out_str, "NULL ")
                    self.awaitResult_ = False
                    self.awaitStart_ = True
                else:
                    self.out_str = "{0}{1}".format(self.out_str, "IncorrectCommand ")
        return self.out_str
