#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int i,n;
    string str;
    cout<<"Enter a string";
    cin >> str;
    n=str.length();
    for (i=0;i<n/2;i++)
    {
        swap(str[i],str[n-i-1]);
    }
    cout<<"\nAfter reversing string: "<< str;
    return 0;
}

