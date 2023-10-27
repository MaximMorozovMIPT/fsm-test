#include "solution.h"
#include "mutants.h"
#include "test_runner.h"

#define GEN_TEST(Class)                                 \
void Test##Class()                                      \
{                                                       \
    Class sol;                                          \
    ASSERT_EQUAL(sol.RunAndReset("011"), "011");        \
    ASSERT_EQUAL(sol.RunAndReset("1011"), "1011");      \
    ASSERT_EQUAL(sol.RunAndReset("11011"), "11011");    \
    ASSERT_EQUAL(sol.RunAndReset("11111"), "11011");    \
}

GEN_TEST(Solution);
GEN_TEST(Mutant1);
GEN_TEST(Mutant2);
GEN_TEST(Mutant3);
GEN_TEST(Mutant4);
GEN_TEST(Mutant5);
GEN_TEST(Mutant6);
GEN_TEST(Mutant7);
GEN_TEST(Mutant8);
GEN_TEST(Mutant9);
GEN_TEST(Mutant10);
GEN_TEST(Mutant11);
GEN_TEST(Mutant12);
GEN_TEST(Mutant13);
GEN_TEST(Mutant14);
GEN_TEST(Mutant15);
GEN_TEST(Mutant16);
GEN_TEST(Mutant17);
GEN_TEST(Mutant18);
GEN_TEST(Mutant19);
GEN_TEST(Mutant20);
