#pragma once

#include <string>
#include <sstream>

class Solution {
public:
    Solution() : latch1_(0), latch2_(0) {}

    std::string RunAndReset(std::string input) {
        std::stringstream output;
        for (auto ch: input) {
            // Convert input to bool
            bool in = ch == '0' ? 0 : 1;

            // Compute output
            bool out = in & !latch2_;
            output << out;

            // Compute new latch values
            bool new_latch1 = in & !latch2_;
            bool new_latch2 = latch1_ & in & !latch2_;

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
