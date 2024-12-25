#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include <vector>
#include "wordleFuncs.h"

using namespace std;


TEST_SUITE("validWord") {
    vector<string> vec{"apple","banana", "cherry", "plum"};
    TEST_CASE("Checks validWord() with a valid 5 letter word") {
        CHECK_UNARY(validWord(vec, "apple"));
    }
    TEST_CASE("Checks validWord() with an invalid 5 letter word") {
        CHECK_UNARY_FALSE(validWord(vec, "grape"));
    }
    TEST_CASE("Check validWord() with a 5 letter word with uppercase (should be invalid)") {
        CHECK_UNARY_FALSE(validWord(vec, "aPple"));
    }
    TEST_CASE("Checks validWord() with a valid 6 letter word") {
        CHECK_UNARY(validWord(vec, "banana"));
    }
    TEST_CASE("Checks validWord() with an invalid 6 letter word") {
        CHECK_UNARY_FALSE(validWord(vec, "orange"));
    }
    TEST_CASE("Checks validWord() with a valid 4 letter word") {
        CHECK_UNARY(validWord(vec, "plum"));
    }
    TEST_CASE("Checks validWord() with an invalid 4 letter word") {
        CHECK_UNARY_FALSE(validWord(vec, "pear"));
    }
}

TEST_SUITE("checkGuess") {
    TEST_CASE("Checks checkGuess() with tilde, tilde") {
        CHECK_EQ(checkGuess("tilde", "tilde"), "^^^^^");
    }
    TEST_CASE("Checks checkGuess() with toast, tilde") {
        CHECK_EQ(checkGuess("toast", "tilde"), "^XXXX");
    }
    TEST_CASE("Checks checkGuess() with loser, foyer") {
        CHECK_EQ(checkGuess("loser", "foyer"), "X^X^^");
    }
    TEST_CASE("Checks checkGuess() with friar, marry") {
        CHECK_EQ(checkGuess("friar", "marry"), "X?X??");
    }
    TEST_CASE("Checks checkGuess() with rarer, marry") {
        CHECK_EQ(checkGuess("rarer", "marry"), "?^^XX");
    }
    TEST_CASE("Checks checkGuess() with rarer, error") {
        CHECK_EQ(checkGuess("rarer", "error"), "?X^?^");
    }
}