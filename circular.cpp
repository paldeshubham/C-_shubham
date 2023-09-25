#include<iostream>
using namespace std;

int cqueue[5];
int front=-1,rear=-1;

void insert(int x)
{

  if(rear==-1)//empty
  {
  rear=0;
  front=0;
  cqueue[rear]=x;
  cout<<"\ndone";
  }
  else  //not empty
  {
     rear=(rear+1)%10;
     cqueue[rear]=x;
     cout<<"\nhehe";
  }
}
void display()
{  
  for(int i=front; i!=rear;i=(i+1)%5)
    {
    cout<<cqueue[i]<<"";
    }
    cout<<cqueue[rear];
}
int deletee()
{
    int x=cqueue[front];
  
    if(rear==front)
    {
      rear=front=-1;
    }
    else
    {
      front=(front+1)%5;
    }
    return x;
}

int main()
{
  int ch;
  do
  {
    cout<<"\nMENU\n1.Insert\n2.Display\n3.Delete\n4.Exit";
    cout<<"nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:
      int x,n;
      if((rear+1)%5==front)  //full
      {
        cout<<"\nQueue is full!!";
        exit(0);
      }
      cout<<"\nEnter element to inserted:";
      cin>>x;
      
      insert(x);
      break;
      
      case 2:
        cout<<"Element of circular Queue:";
        display();
        break;
        
      case 3:
        if(rear==-1)
        {
          cout<<"\nQueue is empty";
          exit(0);
        }
        x=deletee();
        cout<<"\nDeleted element:"<<x;
        break;
     }
   }
  }while(ch!=4);
}      
      
      
      
      
      
      
      
      
      
      
      
      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
