//
// main.cpp created by Anirudh Prasad on 10/11/2019
//

#include "timespan.h"
#include <cassert>
#include <sstream>

using namespace std;

// testing constructor
void test1() {
	TimeSpan Ts(1, 20, 30);
	stringstream Ss;
	Ss << Ts;
	cout << Ss.str() << endl;
	
	assert(Ss.str() == "1:20:30");
	
	TimeSpan Ts2(4, -20, -90);
	Ss.str("");
	Ss << Ts2;
	cout << Ss.str() << endl;
	assert(Ss.str() == "3:38:30");
	
	TimeSpan Ts3(1.5, 30.5, -90);
	Ss.str("");
	Ss << Ts3;
	cout << Ss.str() << endl;
	assert(Ss.str() == "1:59:00");
	
	TimeSpan Ts4(0, 0.07, 0);
	Ss.str("");
	Ss << Ts4;
	cout << Ss.str() << endl;
	assert(Ss.str() == "0:00:04");
}

// testing equality, addition, subtraction, multiplication
void test2() {
	TimeSpan Ts(1, 20, 30);
	TimeSpan Ts2(1, 20, 30);
	TimeSpan Ts3(0, 0, 0);
	assert(Ts == Ts2);
	assert(!(Ts != Ts2));
	assert(Ts != Ts3);
	assert((Ts + Ts + Ts) == (Ts2 * 3));
	assert((Ts * 5) == (Ts2 * 4) + Ts2);
	assert((Ts * 5) == (Ts2 * 6) - Ts2);
	assert((Ts + Ts - Ts) == ((Ts2 * 2) - Ts));
	assert((Ts - Ts2) == Ts3);
	assert((Ts3 * 5) == Ts3);
}

 /* Broken test
void test3() {
	TimeSpan ts0(0, 0, 0);
	TimeSpan ts1(0, 0, 1);
	TimeSpan ts2 = ts0 - ts1;
	stringstream ss;
	ss << ts2;
	cout << ss.str() << endl;
	assert(ss.str() == "-1:59:59");
} */

//tests negative output
void test4() {
	TimeSpan Ts(1, 20, 30);
	TimeSpan Ts2(1, 30, 40);
	TimeSpan Ts3 = Ts - Ts2;
	stringstream Ss;
	Ss << Ts3;
	cout << Ss.str() << endl;
	assert(Ss.str() == "-0:10:10");
}

//runs all tests
void testAll() {
	test1();
	test2();
//	test3();
	test4();
}

//runs program
int main() {
	testAll();
	cout << " Passed all tests. Done." << std::endl;
	return 0;
}