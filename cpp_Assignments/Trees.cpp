#include<iostream>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;

};

class stack
{
    node *data[10];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    node *topdata()
    {
         return(data[top]);
    }
    void push (node *p)
    {
        data[++top]=p;
    }
    node *pop()
    {
        return (data[top--]);
    }
};
node *create(char postfix[10])
{
    node *p;
    stack s;
    for(int i=0;postfix[i]!='\0';i++)
    {
        char token=postfix[i];
        if (isalnum(token))
        {
            p = new node;
            p->data=token;
            p->right =NULL;
            p->left = NULL;
            s.push(p);
        }
        else
        {
            p = new node;
            p->data = token;
            p->right = s.pop();
            p->left = s.pop();
        }
    }return s.pop();
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        cout <<p->data;
        preorder(p->left);
        preorder(p->right);

    }
}
void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout << p->data;
        inorder(p->right);

    }
}

void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data;
    }
}
int main()
{
    node *r= NULL;
    int ch;
    char postfix[10];
    do{
        cout << "\n 1.Construct Postfix:\n 2.Preorder\n 3.Inorder\n 4.Postorder\n 5.Exit";
        cout << "\n enter your choice:";
        cin >> ch;
        switch(ch)
        {
            case 1://to construct tree
            cout << "\n enter postfix expression:";
            cin >> postfix;
            r=create(postfix);
            cout << "\n Tree is created succesfully!!!";
            break;

            case 2://preorder
            cout << "\n Preorder Traversal";
            preorder(r);
            break;

            case 3://preorder
            cout << "\n inorder Traversal";
            inorder(r);
            break;

            case 4://preorder
            cout << "\n Postorder Traversal";
            postorder(r);
            break;
        }
        
    }while(ch!=5);
    return 0;
}