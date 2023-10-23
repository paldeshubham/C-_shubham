#include<iostream>
#include<stdlib.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode *FindMin(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }

    if(node->left)
    {
        return FindMin(node->left);

    }
    else
    {
        return node;
    }
}
treeNode *FindMax(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->right)
    {
        return FindMax(node->right);

    }
    else{
        return node;
    }
}

treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        temp=(treeNode*)malloc(sizeof(treeNode));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right=Insert(node->right,data);
    }
    else if(data<(node->data))
    {
        node->left=Insert(node->left,data);
    }
    
    return node;
    
}

treeNode *Delet(treeNode *node,int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout << "element not found";
    }
    else if(data <(node->data))
    {
        node->left=Delet(node->left,data);
    }
    else if(data>(node->data))
    {
        node->right=Delet(node->right,data);
    }
    else
    {
        if(node->right && node->left)
        {
            temp=FindMin(node->right);
            node->data=temp->data;
            node->right=Delet(node->right,temp->data);
        }
        else{
            temp=node;
            if(node->left==NULL)
            {
                node=node->right;
            }
            else if(node->right==NULL)
            {
                node=node->left;
            }
            
           free (temp);
        }
    }
    return node;
}
treeNode *Find(treeNode *node,int data)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(data>(node->data))
    {
        return Find(node->right,data);
    }
    else if (data <(node->data))
    {
        return Find(node->left,data);
    }
    else{
        return node;
    }
}
void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout << node->data <<" ";
    Inorder(node->right);
}
void Preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;

    }
    cout << node->data <<" ";
    Preorder(node->left);
    Preorder(node->right);
}
void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    treeNode *root=NULL,*temp;
    int ch,ch1,data1;
    while(1)
    {
        cout << "\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.FindMin\n7.FindMax\n8.Search\n9.Exit\n";
        cout<<"Enter your choice:\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
            cout << " Enter the number of elements to be inserted:";
            cin>>ch1;
            for(int i=0;i<ch1;i++)
            {
                cout << "\n please enter " <<i+1 <<"th element:";
                cin >> data1;
                root=Insert(root,data1);
            }
            cout << "Elements Inserted in BST are:";
            Inorder(root);
            break;

            case 2:
            cout<<"\n Enter elements to be deleted:";
            cin >>ch;
            root=Delet(root,ch);
            cout <<"\n after Deletion elements in BST are : ";
            Inorder(root);
            break;


            case 3:
            cout <<"\n Inorder Traversal is : ";
            Inorder(root);
            break;

            case 4:
            cout <<"\n Preorder Traversal is : ";
            Preorder(root);
            break;

            case 5:
            cout <<"\n Postorder Traversal is : ";
            Postorder(root);
            break;

            case 6:
            temp=FindMin(root);
            cout <<"\n Minimum element is: "<< temp->data;
            break;

            case 7:
            temp = FindMax(root);
            cout <<"\n Maximum Elment is :" << temp->data ;
            break;

            case 8:
            cout <<"\n enter elements to be searched : ";
            cin >>ch;
            temp=Find(root,ch);
            if(temp==NULL)
            {
                cout << "element is not found";

            }
            else
            {
                cout << "Element " << temp->data <<" is found \n";
            }
            break;

            case 9:
            exit(0);
            break;
            default:
            cout << "Enter Correct Choice:";
            break;



        
        }
    }
    return 0;
}
