#include "solution.h"
#include "mutants.h"
#include "test_runner.h"

#include <fstream>
#include <sstream>

#define GEN_TEST_HSI(Class)                             \
void HSITest##Class() {                                 \
    std::string str_in;                                 \
    std::string str_out;                                \
    std::ifstream inp_in("../tests/hsi_in.txt");        \
    std::ifstream inp_out("../tests/hsi_out.txt");      \
    Class sol;                                          \
    while(std::getline(inp_in, str_in)) {               \
        if(str_in.empty()) {                            \
            break;                                      \
        }                                               \
        std::getline(inp_out, str_out);                 \
        std::stringstream inp(str_in);                  \
        auto ans = sol.RunAndReset(inp);                \
        ASSERT_EQUAL(ans, str_out);                     \
    }                                                 \
}

#define GEN_TEST_TOUR(Class)                               \
void TourTest##Class() {                                   \
    std::string str_in;                                 \
    std::string str_out;                                \
    std::ifstream inp_in("../tests/tour_in.txt");          \
    std::ifstream inp_out("../tests/tour_out.txt");        \
    Class sol;                                          \
    while(std::getline(inp_in, str_in)) {               \
        if(str_in.empty()) {                            \
            break;                                      \
        }                                               \
        std::getline(inp_out, str_out);                 \
        std::stringstream inp(str_in);                  \
        auto ans = sol.RunAndReset(inp);                \
        ASSERT_EQUAL(ans, str_out);                     \
    }                                                   \
}

GEN_TEST_HSI(Solution);
GEN_TEST_HSI(Mutant1);
GEN_TEST_HSI(Mutant2);
GEN_TEST_HSI(Mutant3);
GEN_TEST_HSI(Mutant4);
GEN_TEST_HSI(Mutant5);
GEN_TEST_HSI(Mutant6);
GEN_TEST_HSI(Mutant7);
GEN_TEST_HSI(Mutant8);
GEN_TEST_HSI(Mutant9);
GEN_TEST_HSI(Mutant10);
GEN_TEST_HSI(Mutant11);
GEN_TEST_HSI(Mutant12);
GEN_TEST_HSI(Mutant13);
GEN_TEST_HSI(Mutant14);
GEN_TEST_HSI(Mutant15);
GEN_TEST_HSI(Mutant16);
GEN_TEST_HSI(Mutant17);
GEN_TEST_HSI(Mutant18);
GEN_TEST_HSI(Mutant19);
GEN_TEST_HSI(Mutant20);
GEN_TEST_HSI(Mutant21);
GEN_TEST_HSI(Mutant22);
GEN_TEST_HSI(Mutant23);
GEN_TEST_HSI(Mutant24);
GEN_TEST_HSI(Mutant25);
GEN_TEST_HSI(Mutant26);
GEN_TEST_HSI(Mutant27);
GEN_TEST_HSI(Mutant28);

GEN_TEST_TOUR(Solution);
GEN_TEST_TOUR(Mutant1);
GEN_TEST_TOUR(Mutant2);
GEN_TEST_TOUR(Mutant3);
GEN_TEST_TOUR(Mutant4);
GEN_TEST_TOUR(Mutant5);
GEN_TEST_TOUR(Mutant6);
GEN_TEST_TOUR(Mutant7);
GEN_TEST_TOUR(Mutant8);
GEN_TEST_TOUR(Mutant9);
GEN_TEST_TOUR(Mutant10);
GEN_TEST_TOUR(Mutant11);
GEN_TEST_TOUR(Mutant12);
GEN_TEST_TOUR(Mutant13);
GEN_TEST_TOUR(Mutant14);
GEN_TEST_TOUR(Mutant15);
GEN_TEST_TOUR(Mutant16);
GEN_TEST_TOUR(Mutant17);
GEN_TEST_TOUR(Mutant18);
GEN_TEST_TOUR(Mutant19);
GEN_TEST_TOUR(Mutant20);
GEN_TEST_TOUR(Mutant21);
GEN_TEST_TOUR(Mutant22);
GEN_TEST_TOUR(Mutant23);
GEN_TEST_TOUR(Mutant24);
GEN_TEST_TOUR(Mutant25);
GEN_TEST_TOUR(Mutant26);
GEN_TEST_TOUR(Mutant27);
GEN_TEST_TOUR(Mutant28);

int main() {
    TestRunner tr;
    RUN_TEST(tr, HSITestSolution);
    RUN_TEST(tr, HSITestMutant1);
    RUN_TEST(tr, HSITestMutant2);
    RUN_TEST(tr, HSITestMutant3);
    RUN_TEST(tr, HSITestMutant4);
    RUN_TEST(tr, HSITestMutant5);
    RUN_TEST(tr, HSITestMutant6);
    RUN_TEST(tr, HSITestMutant7);
    RUN_TEST(tr, HSITestMutant8);
    RUN_TEST(tr, HSITestMutant9);
    RUN_TEST(tr, HSITestMutant10);
    RUN_TEST(tr, HSITestMutant11);
    RUN_TEST(tr, HSITestMutant12);
    RUN_TEST(tr, HSITestMutant13);
    RUN_TEST(tr, HSITestMutant14);
    RUN_TEST(tr, HSITestMutant15);
    RUN_TEST(tr, HSITestMutant16);
    RUN_TEST(tr, HSITestMutant17);
    RUN_TEST(tr, HSITestMutant18);
    RUN_TEST(tr, HSITestMutant19);
    RUN_TEST(tr, HSITestMutant20);
    RUN_TEST(tr, HSITestMutant21);
    RUN_TEST(tr, HSITestMutant22);
    RUN_TEST(tr, HSITestMutant23);
    RUN_TEST(tr, HSITestMutant24);
    RUN_TEST(tr, HSITestMutant25);
    RUN_TEST(tr, HSITestMutant26);
    RUN_TEST(tr, HSITestMutant27);
    RUN_TEST(tr, HSITestMutant28);

    RUN_TEST(tr, TourTestSolution);
    RUN_TEST(tr, TourTestMutant1);
    RUN_TEST(tr, TourTestMutant2);
    RUN_TEST(tr, TourTestMutant3);
    RUN_TEST(tr, TourTestMutant4);
    RUN_TEST(tr, TourTestMutant5);
    RUN_TEST(tr, TourTestMutant6);
    RUN_TEST(tr, TourTestMutant7);
    RUN_TEST(tr, TourTestMutant8);
    RUN_TEST(tr, TourTestMutant9);
    RUN_TEST(tr, TourTestMutant10);
    RUN_TEST(tr, TourTestMutant11);
    RUN_TEST(tr, TourTestMutant12);
    RUN_TEST(tr, TourTestMutant13);
    RUN_TEST(tr, TourTestMutant14);
    RUN_TEST(tr, TourTestMutant15);
    RUN_TEST(tr, TourTestMutant16);
    RUN_TEST(tr, TourTestMutant17);
    RUN_TEST(tr, TourTestMutant18);
    RUN_TEST(tr, TourTestMutant19);
    RUN_TEST(tr, TourTestMutant20);
    RUN_TEST(tr, TourTestMutant21);
    RUN_TEST(tr, TourTestMutant22);
    RUN_TEST(tr, TourTestMutant23);
    RUN_TEST(tr, TourTestMutant24);
    RUN_TEST(tr, TourTestMutant25);
    RUN_TEST(tr, TourTestMutant26);
    RUN_TEST(tr, TourTestMutant27);
    RUN_TEST(tr, TourTestMutant28);

    return 0;
}
