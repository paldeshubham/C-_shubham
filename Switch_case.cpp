#include<iostream>
using namespace std;
int main()
{
	int ch,a,b;
	cout<<"Enter the value of a:";
	cin >> a;
	cout<<"Enter the value of b:";
	cin >> b ;
	do{
		cout << "\n 1.Add ";
		cout << "\n 2.Subtract ";
		cout << "\n 3.Mutiply ";
		cout << "\n 4.Division ";
		cout << "\n 5.Exit";
		cout << "\n Enter your choice:";
		cin >> ch;
		switch(ch)
		{
			case 1:
				cout <<"Addition is:"<<a+b;
				break;
			case 2:
				cout << "Substraction is:" << a-b;
				break;
			case 3:
				cout << " Multiplication is:" << a*b;
				break;
			case 4:
				cout << " Division is:" << a/b;
				break;
			case  5:
				exit(0);
				break;
				
		}
		
		
		
		
	}while(ch>0);
}
