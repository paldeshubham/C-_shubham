#include<iostream>
#include<string.h>
using namespace std;
struct student
{
    int roll_no;
    char name[20];
    float SGPA;
};
void accept(struct student list[5]);
void display(struct student list[80]);
void bubblesort(struct student list[5]);
void insertionsort(struct student list[5]);
void search(struct student list[5]);

int main()
{
    struct student data[20];
    const int size =5 ;
    int ch,i;
    accept(data);
    cout << "\n1.Bubble Sort";
    cout << "\n2.Insertion sort";
    cout << "\n3.Search" << endl;

    do
    {
        cout << "______";
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            bubblesort(data);
            display(data);
            break;

            case 2:
            insertionsort(data);
            display(data);
            break;

            case 3:
            search(data);
            break;

        default:
            break;
        }

    } while (ch!=4);   
}
void accept(struct student list[5])
{
    int i;
    for(i=0;i<5;i++)
    {
        cout << "enter roll no,name,sgpa:";
        cin >> list[i].roll_no >> list[i].name >> list[i].SGPA ;
    }
}
void display (struct student list[80])
{
    int i;
    cout << "\n Roll no\tname\tSGPA\n";
    for (i=0;i<5;i++)
    {
        cout << "\n " << list[i].roll_no << "\n\t" << list[i].name <<"\n\t" <<list[i].SGPA;

    }
}
void bubblesort(struct student list[5])
{
    int  i,j,size=5;
    struct student temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<(size-1-i);j++)
        {
            if(list[j].roll_no > list[j+1].roll_no)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}
void insertionsort(struct student list[5])
{
    int k, j;
    struct student temp;
    for (k = 0; k < 5; k++)
        {
            temp = list[k];
            j = k - 1;
            while (strcmp(list[j].name, temp.name) > 0 && j >= 0)
            {
                list[j + 1] = list[j];
                --j;
            }
            list[j + 1] = temp;
        }
}
// Search stuff
void search(struct student list[5])
{
    float SGPA;
    int i;
    cout << "\nEnter SGPA: ";

    cin >> SGPA;
    cout << "\n\nRollno\tName\tSGPA\n";
    for (i = 0; i < 5; i++)
    {
        if (SGPA == list[i].SGPA)
         {
        cout << "\n"
        << list[i].roll_no << "\t" <<
        list[i].name << "\t" << list[i].SGPA;
        }
    }
}