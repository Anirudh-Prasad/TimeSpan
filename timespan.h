//
// timespan.h Created by Anirudh on 10/11/2019.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
	friend ostream& operator<<(ostream& Out, const TimeSpan& Ts);
public:
	//explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
	explicit TimeSpan(double Hrs = 0, double Mins = 0, double Secs = 0);
	// add
	TimeSpan operator+(const TimeSpan& Ts) const;
	// subtract
	TimeSpan operator-(const TimeSpan& Ts) const;
	// check equality
	bool operator==(const TimeSpan& Ts) const;
	// check if not equal
	bool operator!=(const TimeSpan& Ts) const;
	// multiply timespan by a number
	TimeSpan operator*(int Number);

private:
	int Hour;
	int Minute;
	int Second;
};

#endif //ASS2_TIMESPAN_H

