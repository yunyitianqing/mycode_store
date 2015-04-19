#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str="abcdef";
	cout<<str<<endl;
	str.erase(0,1);
	cout<<str<<endl;
	return 0;
}
