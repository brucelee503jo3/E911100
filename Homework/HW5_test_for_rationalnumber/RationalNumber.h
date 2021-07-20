#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include<iostream> 
using namespace std;
struct Rational
{
	int numerator;
	int denominator;
};
class RationalNumber
{
	//insertion and extraction
	friend ostream &operator<<(ostream &,RationalNumber &);
	friend istream &operator>>(istream &,RationalNumber &);
	
	public:
		//constructor
		RationalNumber(int=0,int=1); 
		//calculation
		RationalNumber operator+(RationalNumber);
		RationalNumber operator-(RationalNumber);	
		RationalNumber operator*(RationalNumber);	
		RationalNumber operator/(RationalNumber);	
		//relational and equality operator
		bool operator> (RationalNumber &);
		bool operator< (RationalNumber &);
		bool operator>=(RationalNumber &);
		bool operator<=(RationalNumber &);
		bool operator==(RationalNumber &);
		bool operator!=(RationalNumber &);
		//print
		void printRational();
		//convertion
		operator double()
		{
			return (double)this->r.numerator/this->r.denominator;
		}
	private:
		Rational r;			
};
#endif 
