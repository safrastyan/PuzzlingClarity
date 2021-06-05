#define BOOST_TEST_MODULE DP
#include <boost/test/unit_test.hpp>

#include "algo/BigInt.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"
#include "Generators/NumberGenerators.hpp"

#include <string>

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(BigInt_tests)


BOOST_AUTO_TEST_CASE(bigint_arithm_test)
{
    std::string path = algo_tests_path() + "/bigint/bigint_arithm/";
    for (int t = 1; t <= 1; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto cases = read_one<int>(input);
        for (int c = 0; c < cases; ++c) {
            auto num1 = BigInt(read_one<std::string>(input));   
            auto oper = read_one<std::string>(input);
            auto num2 = BigInt(read_one<std::string>(input));
            auto res = BigInt(read_one<std::string>(output));
            BigInt test_res = 0;
            if (oper == "+") {
                test_res = num1 + num2;
            }
            if (oper == "-") {
                test_res = num1 - num2;
            }
            BOOST_CHECK_EQUAL(test_res, res);
        }
    }
}


//TODO: make the number of tests dynamic

BOOST_AUTO_TEST_CASE(bigint_logic_test)
{
    std::string path = algo_tests_path() + "/bigint/bigint_logic/";
    for (int t = 1; t <= 2; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto cases = read_one<int>(input);
        for (int c = 0; c < cases; ++c) {
            auto num1 = BigInt(read_one<std::string>(input));   
            auto oper = read_one<std::string>(input);
            auto num2 = BigInt(read_one<std::string>(input));
            auto res = read_one<int>(output) == 1;
            bool test_res = true;
            if (oper == "<") {
                test_res = num1 < num2;
            }
            if (oper == ">") {
                test_res = num1 > num2;
            }
            if (oper == "==") {
                test_res = num1 == num2;
            }
            if (oper == "<=") {
                test_res = num1 <= num2;
            }
            if (oper == ">=") {
                test_res = num1 >= num2;
            }
            if (oper == "!=") {
                test_res = num1 != num2;
            }
            BOOST_CHECK_EQUAL(test_res, res);
        }
    }
}

BOOST_AUTO_TEST_CASE(bigint_unary_test)
{
    std::string path = algo_tests_path() + "/bigint/bigint_unary/";
    for (int t = 1; t <= 1; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        auto cases = read_one<int>(input);
        for (int c = 0; c < cases; ++c) {
            auto num1 = BigInt(read_one<std::string>(input));
            auto num2 = num1; 
            auto oper = read_one<std::string>(input);
            auto res = BigInt(read_one<std::string>(output));
            BigInt test_res = 0;
            BigInt old_val = 0;
            if (oper == "++") {
                test_res = ++num1;
                BOOST_CHECK_EQUAL(num1, res);
                BOOST_CHECK_EQUAL(test_res, res);
                old_val = num2;
                test_res = num2++;
                BOOST_CHECK_EQUAL(num2, res);
                BOOST_CHECK_EQUAL(test_res, old_val);
            }
            if (oper == "--") {
                test_res = --num1;
                BOOST_CHECK_EQUAL(num1, res);
                BOOST_CHECK_EQUAL(test_res, res);
                old_val = num2;
                test_res = num2--;
                BOOST_CHECK_EQUAL(num2, res);
                BOOST_CHECK_EQUAL(test_res, old_val);
            }
            if (oper == "-") {
                test_res = -num1;
                BOOST_CHECK_EQUAL(test_res, res);
            }
        }
    }
}


BOOST_AUTO_TEST_SUITE_END()
