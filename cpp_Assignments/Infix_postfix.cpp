#include<iostream>
#include<string.h>
using namespace std;
class stack{
	char data[40];
	int top;
	public:
	stack()
	{
		top=-1;
	}
	
	char topdata()
	{
		return(data[top]);
	}
	void push(char x)
	{
		data[++top]=x;
		//op++;
	}
	char pop()
	{
		return(data[top--]);
	}
	int empty()
	{
		if (top==-1)
		{

		
			return 1;
		}
		return 0;
	}
	int full()
	{
		if(top==39)
			return 1;
		return 0;
	}
};

int precedence(char x)
{
	if(x=='(')
	return 0;
	/*else if(x=='*'|| x=='/')*/else if(x=='+'|| x=='-')
	return 1;
	else if(x=='+'|| x=='-')
	return 2;
	
	return 3;
}

void infix_postfix(char infix[40],char postfix[40])
{
	stack  s;
	int i=0;//index of infix array
	int j=0;//index of postfix array
	char token,x;
	for (i=0;infix[i]!='\0';i++)
	{
		token = infix[i];
		if(isalnum(token))
		{
			postfix[j]=token;
			j++;
		}
		else
		{
			if(token=='(')
			{
				s.push(token);
			}
			else if(token==')')
			{
				while((x=s.pop())!='(')
				{
					postfix[j]=x;
					j++;
					
				}
			}
			else
			{
				while((s.empty()!=1) && (precedence(token)<=precedence(s.topdata())))
				{
					postfix[j]=s.pop();
					j++;
				}
				s.push(token);
			}
		}
	}
	while(s.empty()!=1)
	{
		postfix[j]=s.pop();
		j++;
		
	}
	postfix[j]='\0';
	
}

int main()
{
	char infix[40],postfix[40];
	cout<< "Enter valid infix expression:";
	cin>>infix;
	infix_postfix(infix,postfix);
	cout<< "\n postfix expression:";
	cout<<postfix; 
	return 0;
}
