#include "RationalNumber.h"
#include<iostream>
using namespace std;
//constructor
RationalNumber::RationalNumber(int n,int d)
:r({n,d})
{
	if(d==0)
		d=1;
	if(d<0)
		r.denominator*=1;
	for(int i=r.denominator;i>1;i--)
		if((r.denominator%i==0)&&(r.numerator%i==0))
			{
				r.denominator/=i;
				r.numerator/=i;
			}
}
//addition 
RationalNumber RationalNumber::operator+(RationalNumber ra)
{
	int newd=this->r.denominator*ra.r.denominator;
	int newn=this->r.denominator*ra.r.numerator+this->r.numerator*ra.r.denominator;
	return RationalNumber(newn,newd);
}
//subtraction 
RationalNumber RationalNumber::operator-(RationalNumber ra)
{
	int newd=this->r.denominator*ra.r.denominator;
	int newn=this->r.numerator*ra.r.denominator-this->r.denominator*ra.r.numerator;	
	return RationalNumber(newn,newd);	
}
//multiplication
RationalNumber RationalNumber::operator*(RationalNumber ra)	
{
	int newd=this->r.denominator*ra.r.denominator;
	int newn=this->r.numerator*ra.r.numerator;
	return RationalNumber(newn,newd);		
}
//division 
RationalNumber RationalNumber::operator/(RationalNumber ra)
{
	int newd=this->r.denominator*ra.r.numerator;
	int newn=this->r.numerator*ra.r.denominator;
	return RationalNumber(newn,newd);	
}
//printRationalNumber
void RationalNumber::printRational()
{
	if(r.denominator==1)
		cout<<this->r.numerator;
	else	
		cout<<this->r.numerator<<"/"<<this->r.denominator; 
}
//overloading extraction
ostream &operator<<(ostream &output,RationalNumber &ra)
{
	if(ra.r.denominator==1)
		{
			output<<ra.r.numerator;
			return output;
		}
	else
		{
			output<<ra.r.numerator<<"/"<<ra.r.denominator;
			return output;
		}	
	return output;	
}
//overloading insertion
istream &operator>>(istream &input,RationalNumber &ra)
{
	input>>ra.r.numerator>>ra.r.denominator;
	return input;	
}
//overloading >
bool RationalNumber::operator>(RationalNumber &ra)
{
	double thistest=this->r.numerator/this->r.denominator;
	double ratest=ra.r.numerator/ra.r.denominator;
	if(thistest>ratest)
		return true;
	else
		return false;	
}
//overloading <
bool RationalNumber::operator<(RationalNumber &ra)
{
	double thistest=this->r.numerator/this->r.denominator;
	double ratest=ra.r.numerator/ra.r.denominator;
	if(thistest>ratest)
		return false;
	else
		return true;		
}
//overloading >=
bool RationalNumber::operator>=(RationalNumber &ra)
{
	double thistest=this->r.numerator/this->r.denominator;
	double ratest=ra.r.numerator/ra.r.denominator;
	if(thistest>=ratest)
		return true;
	else
		return false;		
}
//overloading <=
bool RationalNumber::operator<=(RationalNumber &ra)
{
	double thistest=this->r.numerator/this->r.denominator;
	double ratest=ra.r.numerator/ra.r.denominator;
	if(thistest>=ratest)
		return false;
	else
		return true;		
}
//overloading ==
bool RationalNumber::operator==(RationalNumber &ra)
{
	double thistest=this->r.numerator/this->r.denominator;
	double ratest=ra.r.numerator/ra.r.denominator;
	if(thistest==ratest)
		return true;
	else
		return false;		
}
//overloading !=
bool RationalNumber::operator!=(RationalNumber &ra)
{
	if(ra==*this)
		return false;
	else
		return true;	
}
