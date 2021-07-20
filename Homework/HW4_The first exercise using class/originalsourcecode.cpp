// Exercise 9.15 Solution: Ex09_15.cpp
#include <iostream> 
//#include "Rational.h" // include definition of class Rational
using namespace std;

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

int main()
{
   Rational c( 2, 6 ), d( 7, 8 ), x; // creates three rational objects 

   c.printRational(); // prints rational object c
   cout << " + ";
   d.printRational(); // prints rational object d				
   x = c.addition( d ); // adds object c and d; sets the value to x

   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x    
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " - ";
   d.printRational(); // prints rational object d
   x = c.subtraction( d ); // subtracts object c and d 
           
   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " x ";
   d.printRational(); // prints rational object d
   x = c.multiplication( d ); // multiplies object c and d
                            
   cout << " = ";
   x.printRational(); // prints rational object x
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << "\n\n";

   c.printRational(); // prints rational object c
   cout << " / ";
   d.printRational(); // prints rational object d	
   x = c.division( d ); // divides object c and d
                            
   cout << " = ";
   x.printRational(); // prints rational object x		
   cout << '\n';
   x.printRational(); // prints rational object x
   cout << " = ";
   x.printRationalAsDouble(); // prints rational object x as double
   cout << endl;
} // end main

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


