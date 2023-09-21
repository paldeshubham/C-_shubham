#include<iostream>
using namespace std;

class stack
{
	char data[20];
	int top;
	public:
		stack(){
		top=-1;			
		
		}
		char topdata()
		{
			return(data[top]);
			
		}
		void push(int x)
		{
			data[++top]=x;
		}
		char pop()
		{
			return(data[top--]);
		}
		int empty()
		{
			if(top==-1)
			return 1;
			return 0;
		}
		int full()
		{
			if(top==19)
			return 1;
			return 0;
		}
};
int evaluate(int op1,int op2,char op)
{
	if(op=='+')
	return op1+op2;
	if(op=='-')
	return op1-op2;
	if(op=='*')
	return op1*op2;
	if(op=='/')
	return op1/op2;
	if(op=='%')
	return op1%op2;
}

void evaluate_postfix(char postfix[20])
{
	stack s;
	int i,op1,op2,result;
	char token;
	int x;
	for(i=0;postfix[i]!='\0';i++)
	{
		token=postfix[i];
		if(isalnum(token))
		{
			cout << "ENTER THE VALUE OF" << token << ":";
			cin >> x;
			s.push(char(x));
		}
		else
		{
			op2=s.pop();
			op1=s.pop();
			result=evaluate(op1,op2,token);
			s.push(char(result));
		}
	}
	result=s.pop();
	cout  << "result" << result;
}
void evaluate_prefix(char prefix[20])
{
	stack s;
	int i,op1,op2,result;
	char token;
	int x;
	for(i=0;prefix[i]!='\0';i++)
	{
	}
	i--;
	for(;i>=0;i--)
	{
		token=prefix[i];
		if(isalnum(token))
		{
			cout << "Enter the value of" << token << ":";
			cin >> x;
			s.push(char(x));
		}
		else
		{
			op1=s.pop();
			op2=s.pop();
			result=evaluate(op1,op2,token);
			s.push(char(result));
		}
	}
	result=s.pop();
	cout << "result:" << result;
}
int main()
{
	char infix[20],token,postfix[20],prefix[20];
	cout << "\n postfix:";
	cin >> postfix;
	evaluate_postfix(postfix);
	cout << "\n prefix:";
	cin >> prefix;
	evaluate_prefix(prefix);
}
