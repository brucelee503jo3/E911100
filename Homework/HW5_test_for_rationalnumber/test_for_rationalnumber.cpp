// Exercise 11.10 Solution: ex11_10.cpp
// RationalNumber test program.
#include <iostream> 
//*#include "RationalNumber.h" 
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
int main()
{
   RationalNumber c( 7, 3 ), d( 3, 9 ), x, y;

   c.printRational();
   cout << " + " ;
   d.printRational();
   cout << " = ";
   x = c + d; // test overloaded operators + and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " - " ;
   d.printRational();
   cout << " = ";
   x = c - d; // test overloaded operators - and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " * " ;
   d.printRational();
   cout << " = ";
   x = c * d; // test overloaded operators * and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " / " ;
   d.printRational();
   cout << " = ";
   x = c / d; // test overloaded operators / and =
   x.printRational();

   cout << '\n';
   c.printRational();
   cout << " is:\n";

   // test overloaded greater than operator
   cout << ( ( c > d ) ? "  > " : "  <= " );
   d.printRational();
   cout << " according to the overloaded > operator\n";

   // test overloaded less than operator
   cout << ( ( c < d ) ? "  < " : "  >= " );
   d.printRational();
   cout << " according to the overloaded < operator\n";

   // test overloaded greater than or equal to operator
   cout << ( ( c >= d ) ? "  >= " : "  < " );
   d.printRational();
   cout << " according to the overloaded >= operator\n";

    // test overloaded less than or equal to operator
   cout << ( ( c <= d ) ? "  <= " : "  > " );
   d.printRational();
   cout << " according to the overloaded <= operator\n";
   
   // test overloaded equality operator
   cout << ( ( c == d ) ? "  == " : "  != " );
   d.printRational();
   cout << " according to the overloaded == operator\n";

   // test overloaded inequality operator
   cout << ( ( c != d ) ? "  != " : "  == " );
   d.printRational();
   cout << " according to the overloaded != operator" << endl;
   
   cout << "\nInput a Rational Number:" << endl;
   cin >> y;
   cout << "Rational number " << y <<" is converted to double value: " << static_cast<double> (y) << endl;
} // end main
