#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
	public:
		Rational(int=1,int=1);
		void printRational();
		void printRationalAsDouble();				
		Rational addition(Rational);
		Rational subtraction(Rational);
		Rational multiplication(Rational);
		Rational division(Rational);
	private:
		void setRationalNumber(int,int);		
		int numerator;
		int denominator;
};

#endif
