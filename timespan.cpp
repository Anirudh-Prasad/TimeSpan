//
// timespan.cpp, created by Anirudh Prasad in 10/11/19
// Provides implementation data for the timespan class, namely in operator
// arithmetic and overloading, as well as writing output.
// 

#include "timespan.h"

/*Constructor that takes 3 doubles, converts everything to seconds, and then converts them
back into their respective times, and then sets them to int instance variables*/
TimeSpan::TimeSpan(double Hrs, double Mins, double Secs) {
	double OvSecs = (3600 * Hrs) + (60 * Mins) + Secs;
	double THours = OvSecs / 3600;
	//cout << THours << " ";
	double TMins = (THours - static_cast<int>(THours)) * 60;
	//cout << TMins << " ";
	double TSecs = (TMins - static_cast<int>(TMins)) * 60;
	//cout << TSecs << " ";
	int IntSecs = static_cast<int>(TSecs);

	if (TSecs - IntSecs >= 0.5) {
		IntSecs++;
	}

	Hour = static_cast<int>(THours);
	Minute = static_cast<int>(TMins);
	Second = IntSecs;
}

/* output operator override that creates modified output based on 
* A) if minutes or seconds are less that 10, add a 0 in front, and
* B) if minutes, seconds, or hours are less than 0, add "-" to front of output
*/
ostream& operator<<(ostream& Out, const TimeSpan& Ts) {
	//tests if both minutes and seconds require an additional '0'
	if ((abs(Ts.Minute) < 10) && (abs(Ts.Second) < 10)) {
		if ((Ts.Hour < 0) || (Ts.Minute < 0) || (Ts.Second < 0)) {
			Out << "-" << abs(Ts.Hour) << ":" << "0" << abs(Ts.Minute) << ":" << "0" 
				<< abs(Ts.Second);
		}
		else {
			Out << Ts.Hour << ":" << "0" << Ts.Minute << ":" << "0" << Ts.Second;
		}
	}
	//tests if minutes need an additional '0'
	else if (abs(Ts.Minute) < 10) {
		if ((Ts.Hour < 0) || (Ts.Minute < 0) || (Ts.Second < 0)) {
			Out << "-" << abs(Ts.Hour) << ":" << "0" << abs(Ts.Minute) << ":" 
				<< abs(Ts.Second);
		}
		else {
			Out << Ts.Hour << ":" << "0" << Ts.Minute << ":" << Ts.Second;
		}
	}
	//tests if seconds requires an additional '0'
	else if (abs(Ts.Second) < 10) {
		if ((Ts.Hour < 0) || (Ts.Minute < 0) || (Ts.Second < 0)) {
			Out << "-" << abs(Ts.Hour) << ":" << abs(Ts.Minute) << ":" << "0" 
				<< abs(Ts.Second);
		}
		Out << Ts.Hour << ":" << Ts.Minute << ":" << "0" << Ts.Second;
	}
	//creates default output if all tests are passed, further tests negatives
	else {
		if ((Ts.Hour < 0) || (Ts.Minute < 0) || (Ts.Second < 0)) {
			Out << "-" << abs(Ts.Hour) << ":" << abs(Ts.Minute) << ":" 
				<< abs(Ts.Second);
		}
		else {
			Out << Ts.Hour << ":" << Ts.Minute << ":" << Ts.Second;
		}
	}

	return Out;
}

//Overrides + operator to return the sum of two TimeSpan objects as a TimeSpan object
TimeSpan TimeSpan::operator+(const TimeSpan& Ts) const {
	TimeSpan TsSum;
	TsSum.Second = this->Second + Ts.Second;
	TsSum.Minute = this->Minute + Ts.Minute;
	TsSum.Hour = this->Hour + Ts.Hour;
	return TsSum;
}

//Overrides - operator to return the difference of two TimeSpan objects as a TimeSpan object
TimeSpan TimeSpan::operator-(const TimeSpan& Ts) const {
	TimeSpan TsSub;
	TsSub.Second = this->Second - Ts.Second;
	TsSub.Minute = this->Minute - Ts.Minute;
	TsSub.Hour = this->Hour - Ts.Hour;
	return TsSub;
}

//Overrides * operator to return the product of two TimeSpan objects as a TimeSpan object
TimeSpan TimeSpan::operator*(int Number) {
	TimeSpan TsLarge;
	TsLarge.Second = Second * Number;
	TsLarge.Minute = Minute * Number;
	TsLarge.Hour = Hour * Number;
	return TsLarge;
}

//Overrides == operator to return the boolean value of whether two TimeSpan objects are equal
bool TimeSpan::operator==(const TimeSpan& Ts) const {
	if (this->Hour == Ts.Hour) {
		if (this->Minute == Ts.Minute) {
			if (this->Second == Ts.Second) {
				return true;
			}
		}
	}
	return false;
}

//Overrides != operator to return the boolean of whether two TimeSpan objects aren't equal
bool TimeSpan::operator!=(const TimeSpan& Ts) const {
	return !(*this == Ts);
}
