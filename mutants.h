#pragma once

#include <string>
#include <sstream>

class MutantParent {
public:
    MutantParent() : latch1_(0), latch2_(0) {}
    virtual std::string RunAndReset(std::string input) = 0;
    virtual ~MutantParent() = default;
protected:
    bool latch1_;
    bool latch2_;
};

// Changed 1st AND to OR
class Mutant1 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in | !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Changed 2st AND to OR
class Mutant2 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in & !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Changed both AND to OR
class Mutant3 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in | !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to INPUT
class Mutant4 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in & !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }

private:
    bool latch1_;
    bool latch2_;
};

// Add negative to LATCH 2
class Mutant5 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in & latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to LATCH 2 and LATCH 1
class Mutant6 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in & latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = !latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to IN and LATCH 2
class Mutant7 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in & latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};


// Add negative to IN and LATCH 1
class Mutant8 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in & !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = !latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to IN and LATCH 1 and LATCH 2
class Mutant9 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in & latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = !latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT
class Mutant10 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(in & !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and IN
class Mutant11 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(!in & !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and IN and change AND
class Mutant12 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(!in & !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and change AND
class Mutant13 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(in & !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to IN and change AND
class Mutant14 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in & !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and IN and change AND
class Mutant15 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(!in | !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and change AND
class Mutant16 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(in | !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to IN and change AND
class Mutant17 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in | !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ & out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and IN and change both AND
class Mutant18 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(!in | !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to OUT and change both AND
class Mutant19 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !(in | !latch2_);
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};

// Add negative to IN and change both AND
class Mutant20 : public MutantParent {
public:
    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = !in | !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = out;
            bool new_latch2 = latch1_ | out;

            latch1_ = new_latch1;
            latch2_ = new_latch2;
        }
        latch1_ = 0;
        latch2_ = 0;
        return output.str();
    }
};
