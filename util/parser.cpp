#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

int main () {
    std::ifstream inp("test.txt");
    std::ofstream out_in("test_in.txt");
    std::ofstream out_out("test_out.txt");

    std::string str;
    while(std::getline(inp, str)) {
        if(str.empty()) {
            break;
        }

        std::string in;
        std::string out;
        std::istringstream stream(str);
        while(std::getline(stream, in, '/')) {
            std::getline(stream, out, ' ');
            out_in << in << ' ';
            out_out << out << ' ';
        }
        out_in << '\n';
        out_out << '\n';
    }
}
