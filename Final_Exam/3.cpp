#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
class Vehicle
{
public:
	virtual sound()
	{
		cout<<"making a sound"<<endl;
	}	
};
class Trains:public Vehicle
{
public:
	sound()
	{
		cout<<"Bun Bun"<<endl;
	}		
};
class Molcar:public Vehicle
{
public:
	sound()
	{
		cout<<"Gi Gi"<<endl;
	}		
};
class Bicycle:public Vehicle
{
public:
	sound()
	{
		cout<<"Lin Lin"<<endl;
	}		
};
int main()
{
	Vehicle v;
	Trains t;
	Molcar m;
	Bicycle b;
	
	vector <Vehicle *> Vehicles;

    Vehicles.push_back(&t);
    Vehicles.push_back(&m);
    Vehicles.push_back(&b);	
	
	vector<Vehicle *>::iterator iter;
	
	for(iter = Vehicles.begin() ; iter != Vehicles.end() ; iter++ )
		{
			(*iter)->sound();
		}
	return 0;
}
