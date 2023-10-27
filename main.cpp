#include "solutions.h"
#include "test_runner.h"

void TestTrueSolution()
{
    TrueSolution sol;

    ASSERT_EQUAL(sol.RunAndReset("011"), "011");
    ASSERT_EQUAL(sol.RunAndReset("1011"), "1011");
    ASSERT_EQUAL(sol.RunAndReset("11011"), "11011");
    ASSERT_EQUAL(sol.RunAndReset("11111"), "11011");
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestTrueSolution);
    return 0;
}
