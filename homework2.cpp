#include "homework2.h"

// Returns triangle type
TriangleType getTriangleType(int a, int b, int c) {
	if( a<=0 || b<=0 || c<=0 || a>200 || b>200 || c>200 ) {
		return TRIANGLE_IMPOSSIBLE;
	} else if( a==b && b==c ) {
		return TRIANGLE_EQUILATERAL;
	} else if( a==b || b==c || a==c ) {
		return TRIANGLE_ISOSCELES;
	} else if( a+b>c && a+c>b && b+c>a ) {
		return TRIANGLE_SCALENE;
	} else {
		return TRIANGLE_NOT_A_TRIANGLE;
	}
}

// Returns next date (format month/day/year)
string getNextDate(int month, int day, int year) {
	if( (year<1812 || year>5000) || (month<1 || month>12) || (day<1 || day>31) ) { return "Invalid input date"; }
	
	if( month==2 ) {
		// sepcial for leap year
		bool bIsLeapYear = ((year%4==0 && year%100!=0) || year%400==0);
		if( bIsLeapYear ) {
			if( day>29 ) { return "Invalid input date"; }
			else if( day==29 ) { day = 1; month++; }
			else { day++; }
		} else {
			if( day>28 ) { return "Invalid input date"; }
			else if( day==28 ) { day = 1; month++; }
			else { day++; }
		}
	} else if( (month<=7 && month%2==1) || (month>7 && month%2==0) ) {
		// for 31 days month
		if( day!=31 ) { day++; }
		else if( month!=12 ) { day = 1; month++; }
		else { day = 1; month = 1; year++; }
	} else {
		// for 30 days month
		if( day>30 ) { return "Invalid input date"; }
		else if( day!=30 ) { day++; }
		else { day = 1; month++; }
	}
	
	stringstream sNextDate;
	sNextDate << month << "/" << day << "/" << year;
	
	return sNextDate.str();
}