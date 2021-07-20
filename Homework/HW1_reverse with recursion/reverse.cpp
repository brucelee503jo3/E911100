#include<iostream>
using namespace std;
int reverse(int,int);
int main()
{
	int num;
	cin >>num;
	cout<<reverse(num,0)<<endl;
	return 0;	
} 
int reverse(int num,int sum)
{
	if(num<10)
	return sum=(sum+num%10);
	else
	{
		sum=(sum+num%10)*10;
		return reverse(num/10,sum);
	}
}
