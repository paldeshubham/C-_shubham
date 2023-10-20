#include <iostream>
using namespace std;
struct node
{
node *l,*r;
int data;
};
int n;
int A[10];
node *root=NULL;
void inorder(node *tree)
{
if(tree!=NULL)
{
inorder(tree->l);
cout<<tree->data<<" " ;
inorder(tree->r);
}
}
node *addnode(node *troot,int val)
{
if(troot==NULL)
{
node *newn=new node();
newn->data=val;
newn->l=NULL;
newn->r=NULL;
return newn;
}
if(troot->data>val)
{
troot->l=addnode(troot->l,val);
}
else
{
troot->r=addnode(troot->r,val);

}
return troot;
}
void construct()
{
for(int i=0;i<n;i++)
{
root=addnode(root,A[i]);
}
}
node *mirror(node* troot)
{
node *temp;
if(troot==NULL)
{
return NULL;
}
temp=troot->l;
troot->l=mirror(troot->r);
troot->r=mirror(temp);
return troot;
}
node* deletee(node* troot,int val)
{
node *temp;
if(troot==NULL)
return troot;
else if(troot->data>val)
troot->l=deletee(troot->l,val);
else if(troot->data<val)
troot->r=deletee(troot->r,val);
else
{
if(troot->r==NULL && troot->l==NULL)
return NULL;

else if(troot->l==NULL)
return troot->r;
else if(troot->r==NULL)
return troot->l;
else
{
temp=troot->r;
while(troot->l!=NULL)
temp=temp->l;
troot->data=temp->data;
return deletee(troot->r,temp->data);
}
}return troot;
}
int main()
{
int ch,n,val;
cout<<"Enter number of element in array";
cin>>n;
cout<<"Enter element:";
for(int i=0;i<n;i++)
{
cin>>A[i];
}
cout<<"tree elements:";
for(int i=0;i<n;i++)
{
cout<<A[i]<<" ";
}
construct();
do
{
cout<<"\n1.construct\n2.dispaly\n3.mirror\n4.Delete";
cout<<"\nchoice:";

cin>>ch;
switch(ch)
{
case 1:
//cout<<"Tree created successfully!!!";
break;
case 2:
cout<<"Tree created :";
inorder(root);
break;
case 3:
cout<<"mirror image:";
root=mirror(root);
inorder(root);
break;
case 4:
cout<<"Enter elemet to be deleted:";
cin>>val;
root=deletee(root,val);
break;
}
} while (ch!=5);
}