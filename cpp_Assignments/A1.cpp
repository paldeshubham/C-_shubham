#include<iostream>
#include<string.h>
using namespace std;
struct student {
	int roll_no;
	char name[20];
	float SGPA;
};
	void accept(struct student list[5]);
	void display(struct student list[80]);
	void bubblesort(struct student list[5]);
	int main()
	{
	struct student data [20];
	accept(data);
	cout<<"\n Bubble sort";
	bubblesort(data);
	display(data);
	
	}
	void accept(struct student list[5])
	{	
		int i;
		for(i=0;i<5;i++)
		{
			cout << "Enter roll no ,name ,SGPA";
			cin >> list[i].roll_no >> list[i].name >> list[i].SGPA;
		 
		}
	}
	void display( struct student list[80])
	{
	int i;
	cout << "\n Roll no.\t name \t SGPA\n";
	for (i=0; i<5;i++)
	{
		cout << "\n" << list[i].roll_no << "\t" <<list[i].name << "\t" << list[i].SGPA;
	}
	}
void bubblesort(struct student list[5])
{
	int i,j,size=5;
	struct student temp;
	for(i=0;i<size-1;i++)
	{
		for (j=0;j<(size-1-i);j++)
		{
			if (list[j].roll_no > list[i].roll_no)
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
	}
}
	void search(struct student list[5])
	{
		float SGPA;
		int i;
		cout << "\n Enter SGPA:";
		cin >> SGPA;
		cout <<"\n Roll no : \t name: \t SGPA\n";
		for (i=0;i<5;i++)
		{
			if (SGPA==list[i].SGPA)
			{
				cout << "\n" <<list[i].roll_no << "\t" << list[i].name << "\t"<< list[i].SGPA;
			}
		} 
	}
