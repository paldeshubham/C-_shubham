#include<iostream>
using namespace std;

class stack
{
    char data[20];
    int top;
public:
    stack()
    {
        top = -1;
    }
    char topdata()
    {
        return (data[top]);
    }
    void push(char x) {
        data[++top] = x;
    }
    char pop()
    {
        return (data[top--]);
    }
    int empty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    int full()
    {
        if (top == 19)
        {
            return 1;
            return 0;
        }
    }
};

int precedence(char x)
{
    if (x == '(')
        return 0;

    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/' || x == '%')
        return 2;

    return 3;
}

void infix_postfix(char infix[20], char postfix[20])
{
    stack s;
    int i = 0; // index for infix array
    int j = 0; // index for postfix array
    char token, x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            postfix[j] = token;
            j++;
        }
        else
        {
            if (token == '(')
            {
                s.push(token);
            }
            else if (token == ')')
            {
                while ((x = s.pop()) != '(')
                {
                    postfix[j] = x;
                    j++;
                }
            }
            else
            {
                while (!s.empty() && (precedence(token) <= precedence(s.topdata())))
                {
                    postfix[j] = s.pop();
                    j++;
                }
                s.push(token);
            }
        }
    }
    while (!s.empty())
    {
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0';
}

void reverse(char a[20], char b[20])
{
    int i, j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i--;

    for (j = 0; i >= 0; j++, i--)
    {
        if (a[i] == '(')
        {
            b[j] = ')';
        }
        else if (a[i] == ')')
        {
            b[j] = '(';
        }
        else
        {
            b[j] = a[i];
        }
    }
    b[j] = '\0';
}

void infix_prefix(char infix[20], char prefix[20])
{
    char pre[20], in[20];
    reverse(infix, in);
    infix_postfix(in, pre);
    reverse(pre, prefix);
}

int main()
{
    char infix[20], postfix[20], prefix[20];
    cout << "Enter valid infix expression: ";
    cin >> infix;
    infix_postfix(infix, postfix);
    infix_prefix(infix, prefix);

    cout << "\nInfix expression: " << infix;
    cout << "\nPostfix expression: " << postfix;
    cout << "\nPrefix Expression: " << prefix;

    return 0;
}

