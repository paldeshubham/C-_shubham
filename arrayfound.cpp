#include<iostream>
using namespace std;
int main()
{
    int a[5];
    int n;
    int i;
     int flag=0;
    for (i=0;i<5;i++)
    {
        cout << "Enter the elements in a string:";
        cin >> a[i];
        

    }
    cout << "enter the element of array you wanted to be search: \n";
    cin >> n;
    for (i=0;i<=4;i++)
    {
    	if(a[i]==n){
    	   cout<< "Element is found";
    	   return 0;
    	 	
    	 }
    	else
    	{
     	flag=1;
    	}
    
    }
   
}
