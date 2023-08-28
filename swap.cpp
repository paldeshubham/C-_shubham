#include<iostream>
using namespace std;
void swap(int &x, int &y, int &z)
{
	int temp=0;
	temp=z;
	z=y;
	y=x;
	x=temp;
}
int main()
{
	int a,b,c;
	cout << "Enter the value of a:";
	cin >> a;
	cout << "Enter the value of b:";
	cin >> b;
	cout << "Enter the value of c:";
	cin >> c;
	swap(a,b,c);
	cout<<a<<b<<c <<"\n";
	return 0;
}
