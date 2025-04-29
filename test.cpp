// noashalom5@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SquareMat.hpp"
#include "doctest.hpp"
#include <sstream>

using namespace std;
using namespace doctest;
using namespace mat;

TEST_CASE("Graph getNum") {
    istringstream input("2\n7 4\n3 9");
    SquareMat matrix(input);
    CHECK(matrix[1][0] == 3);
}

TEST_CASE("Adding edges and edge list") {
    
}