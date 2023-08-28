#include<iostream>
using namespace std;
int main()
{
	int i,num;
	int rem=0;
	cout << "Enter the no which you want to be check:";
	cin >> num;
	 for (i=1;i<=num;i++)
	 {
	 	rem=num%i;
	 	
	 }
	 if (rem==0)
	 	cout << num << " is not a prime no";
	 else
	 	cout << num << " is a prime no:";
}
