#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;



// 1.Verify input integrity:
// a.Only two flags were entered.
// b.Only even,natural and positive (N+) numbers were entered.
// c.Only four parameters were entered, 2 are flags and 2 numbers.
// 
// 2.Verifying a valid rug:
// a.There are no empty cells in the mats.
// b.Legal form(only metrix).
// c.linebreak
// 
// 3.Verify proper texture:
// a.Uniform frame.
// b.Symmetrical texture.


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}




// negative iput:

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(-9, 5, '$', '%'));
    CHECK_THROWS(mat(-9, -5, '$', '%'));
    CHECK_THROWS(mat(9, -5, '$', '%'));
}



// negative , even  or zero iput:

TEST_CASE("Bad input") {
    CHECK_THROWS(mat( 0,0, '%','#'));
}


// even  iput:

TEST_CASE("Bad input") {
    CHECK_THROWS(nospaces(mat(6, 5, '$', '%')));
    CHECK_THROWS(nospaces(mat(-9,6, '$', '%'))); 
    CHECK_THROWS(nospaces(mat(4, 4, '$', '%')));       
}




// good input:

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));


}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(3, 9, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@--@@@--@\n"
													 "@@@@@@@@@\n"));
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(3, 5, '*', '^')) == nospaces("*****\n"
													 "*^^^*\n"
													 "*****\n"));

}


// There are no empty cells in the mats:

TEST_CASE(" no empty cells") {
	CHECK(nospaces(mat(5, 5, '*', '^')) == nospaces("*****\n"
													 "*^^^*\n"
 													 "*^^^*\n"
													 "*^^^*\n"                                                    
													 "*****\n"));
  
}

TEST_CASE("empty cells") {
	CHECK_THROWS(nospaces(mat(9, 7, '@', ' '))); 
	CHECK_THROWS(nospaces(mat(9, 7, ' ', ' '))); 
	CHECK_THROWS(nospaces(mat(9, 7, ' ', '&'))); 
}

// Legal form(only metrix):


TEST_CASE("good shape") {
	CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                     "@-@\n"
                                                     "@@@"));


}

TEST_CASE("bad shape") {
	CHECK_THROWS(nospaces(mat(5, 7, '@', ' '))); 
	CHECK_THROWS(nospaces(mat(9, 5, ' ', ' '))); 
	CHECK_THROWS(nospaces(mat(3, 11, ' ', '&'))); 

}



// Uniform frame:


TEST_CASE("good frame") {
	CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                     "@-@\n"
                                                     "@@@"));

}

TEST_CASE("bad frame") {
	CHECK_THROWS(nospaces(mat(3, 3, '@', ' '))) ;
}
// Symmetrical texture:

TEST_CASE("good Symmetrical") {
	CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                     "@-@\n"
                                                     "@@@"));
}
