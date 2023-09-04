#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int a[10] ={0,5,60,59,65,47,25,2,4,1};
	
	
	
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if (a[i]>a[j])
			{
				int temp=0;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}
		}
	}
	cout << "Sorted Array is:\n";
	for(i=0;i<10;i++)
	{
		cout << a[i] << "\t";
	}
}
