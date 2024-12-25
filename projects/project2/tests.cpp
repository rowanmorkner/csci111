#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"
#include <string>

// #include "functions.h"

using namespace std;

bool lineDifference(string str1, string str2);
string characterDifference(string str1, string str2);
int searchWord(string str, string word);
int searchChar(string str, char c);

TEST_SUITE("lineDifference") {
    TEST_CASE("lineDifference(\"hello\", \"hello\")") {
        CHECK_UNARY_FALSE(lineDifference("hello", "hello"));
    }
    TEST_CASE("lineDifference(\"hello\", \"world\")") {
        CHECK_UNARY(lineDifference("hello", "world"));
    }
    TEST_CASE("lineDifference(\"\", \"\")") {
        CHECK_UNARY_FALSE(lineDifference("", ""));
    }
    TEST_CASE("lineDifference(\"hello\", \"\")") {
        CHECK_UNARY(lineDifference("hello", ""));
    }
    TEST_CASE("lineDifference(\"Hello\", \"hello\")") {
        CHECK_UNARY(lineDifference("Hello", "hello"));
    }
}

TEST_SUITE("characterDifference") {
    TEST_CASE("characterDifference(\"hello\", \"hello\")") {
        CHECK_EQ(characterDifference("hello", "hello"), "     ");
    }
    TEST_CASE("characterDifference(\"abc\", \"def\")") {
        CHECK_EQ(characterDifference("abc", "def"), "^^^");
    }
    TEST_CASE("characterDifference(\"hello\", \"halli\")") {
        CHECK_EQ(characterDifference("hello", "halli"), " ^  ^");
    }
    TEST_CASE("characterDifference(\"hello\", \"Hello\")") {
        CHECK_EQ(characterDifference("hello", "Hello"), "^    ");
    }
}

TEST_SUITE("searchWord") {
    TEST_CASE("searchWord(\"hello world, hello universe\", \"hello\")") {
        CHECK_EQ(searchWord("hello world, hello universe", "hello"), 2);
    }
    TEST_CASE("searchWord(\"hello world, hello universe\", \"bye\")") {
        CHECK_EQ(searchWord("hello world, hello universe", "bye"), 0);
    }
    TEST_CASE("searchWord(\"hello\", \"hello\")") {
        CHECK_EQ(searchWord("hello", "hello"), 1);
    }
    TEST_CASE("searchWord(\"abababab\", \"abab\")") {
        CHECK_EQ(searchWord("abababab", "abab"), 2);
    }
}

TEST_SUITE("searchChar") {
    TEST_CASE("searchChar(\"hello world\", 'l')") {
        CHECK_EQ(searchChar("hello world", 'l'), 3);
    }
    TEST_CASE("searchChar(\"hello world\", 'x')") {
        CHECK_EQ(searchChar("hello world", 'x'), 0);
    }
    TEST_CASE("searchChar(\"\", \"a\")") {
        CHECK_EQ(searchChar("", 'a'), 0);
    }
    TEST_CASE("searchChar(\"Hello\", 'h')") {
        CHECK_EQ(searchChar("Hello", 'h'), 0);
    }
}
