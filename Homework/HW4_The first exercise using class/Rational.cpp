#include<iostream>
#include"Rational.h"
using namespace std;
//memberfunction
Rational::Rational(int nu,int de)
{
	for(int i=nu;i>1;i--)
		{
			if(nu%i==0&&de%i==0)
				{
					nu/=i;
					de/=i;
					break;
				}
		}	
	setRationalNumber(nu,de);	
}
	
void Rational::setRationalNumber(int nu,int de)
{		
	numerator=nu;
	denominator=de;	
}
	
void Rational::printRational()
{
	cout<<numerator<<"/"<<denominator;	
}
	
void Rational::printRationalAsDouble()
{
	cout<<(double)numerator/denominator;
}		

Rational Rational::addition(Rational R)
{
	int a=numerator,b=denominator,c=R.numerator,d=R.denominator;
	a=a*d;c=c*b;
	int e=a+c,f=b*d;
	for(int i=e;i>1;i--)
		{
			if(e%i==0&&f%i==0)
				{
					e/=i;
					f/=i;
					break;
				}
		}	
	return Rational(e,f);	
}

Rational Rational::subtraction(Rational R)
{
	int a=numerator,b=denominator,c=R.numerator,d=R.denominator;
	a=a*d;c=c*b;
	int e=a-c,f=b*d;
	for(int i=e;i>1;i--)
		{
			if(e%i==0&&f%i==0)
				{
					e/=i;
					f/=i;
					break;
				}
		}	
	return Rational(e,f);		
}

Rational Rational::multiplication(Rational R)
{
	int a=numerator,b=denominator,c=R.numerator,d=R.denominator;
	int e=a*c,f=b*d;
	for(int i=e;i>1;i--)
		{
			if(e%i==0&&f%i==0)
				{
					e/=i;
					f/=i;
					break;
				}
		}	
	return Rational(e,f);		
}

Rational Rational::division(Rational R)
{
	int a=numerator,b=denominator,c=R.numerator,d=R.denominator;
	int e=a*d,f=b*c;
	for(int i=e;i>1;i--)
		{
			if(e%i==0&&f%i==0)
				{
					e/=i;
					f/=i;
					break;
				}
		}	
	return Rational(e,f);		
}

