#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define _NL_ cout<<"\n";

class Node
{
 public:
 Node(int d):data(d),left(0),right(0){}
 int data;
 Node *left,*right;
};

class BST
{
public:
BST():m_root(NULL){}
BST& operator<(int d);

void display();
void removeNode(int d);
inline int height()
{
 //int oldh,newh;oldh=newh=0;calHeight(m_root,&oldh,&newh);return oldh;
 return calHeight(m_root);
 }
protected:
int calHeight(Node *);
void spiralDisplay(Node *);
void removeLeaf(Node **,int );
void createTree(Node *,Node *newN);
void inOrderRec(Node *);
void bfs(Node *);
void dfs(Node *);

private:
Node *m_root;

};

int BST::calHeight(Node *p)
{ 
  {
    ++*newH;
    calHeight(node->left,oldH,newH);
	*oldH = *newH;
	--*newH;
	calHeight(node->right,oldH,newH);	
  } 
*/
  if (!p) return 0;
  int left_height = calHeight(p->left);
  int right_height = calHeight(p->right);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;  
}

void BST::spiralDisplay(Node *head)
{
 stack<Node *>first,second;
 first.push(head);
 int s;
  while(!first.empty() || !second.empty())
  {
   _NL_
   
   while(!first.empty())
   {
    head = first.top();
    first.pop();
	cout<<head->data<<" ";	
	s += head->data;
	if(head->right)
		second.push(head->right);
	if(head->left)
		second.push(head->left);   
   }
   cout<<s;
   s = 0;
   
   _NL_
   
   while(!second.empty())
   {
	head = second.top();
	cout<<head->data<<" ";
	second.pop();	
	s += head->data;	
	if(head->left)
		first.push(head->left);    
	if(head->right)
		first.push(head->right);
   }
   cout<<s;
   s=0;   
  }

}

void BST::createTree(Node *head,Node * newN)
{
 if(head)
 {
	if(newN->data > head->data)
	{
		if(head->right== NULL)
			head->right =  newN;
		else
			createTree(head->right,newN);
     }
	else if(newN->data < head->data)
	{
		if(head->left == NULL)
			head->left =  newN;
		else
			createTree(head->left,newN);
    }
 }
}

// bt<30<20<40<15<25<35<45<12<18<23<27<33<38<42<50;
BST & BST::operator<(int d)
{

#ifdef R


 if(!m_root)
  m_root = new Node (d);
 else 
 {
  Node *tra = m_root;
  while(tra)
  {
   if(d > tra->data)
   {
     if(tra->right)
	  tra =  tra->right;
	 else
	 {
	  tra->right =  new Node (d);
	  break;
	 }
   }   
   else if(d < tra->data)
   {
    if(tra->left)
	 tra=  tra->left;
	 else
	 {
	  tra->left =  new Node (d);
	  break;
	 }
   }
  }  
 }
 #endif
 if(!m_root)
	m_root = new Node(d);
else
{
 Node * tmp =  new Node (d);
 createTree(m_root,tmp);	  
 }
 return *this;
}

void BST::removeLeaf(Node **head,int d)
{
 if(*head)
 {
  if((*head)->data == d)
  {  
   delete *head;
   *head = NULL;
  }
  else
  {
    if(d < (*head)->data){	
		removeLeaf(&(*head)->left,d);
		}
	else if(d > (*head)->data){		
		removeLeaf(&(*head)->right,d);		
		}
  }  
  }
}

void BST::removeNode(int d)
{
 removeLeaf(&m_root,d);
}

void BST::inOrderRec( Node *root)
{

if(root){
inOrderRec(root->left);
cout<<root->data << " ";
inOrderRec(root->right);
}
}

bool pow2(int x)
{
 int y = 2;
 bool f = true;
 while(x>1)
 {  
  if(x%2 != 0)
  { 
   f = false;  
   break;
  }
  x = x/y;
 }
 return f;
}

void BST ::bfs(Node *head)
{
queue<Node *>q;
int cnt=0;
q.push(head);
while(!q.empty())
{
	 if(head->left)
		q.push(head->left);
	 if(head->right)
		q.push(head->right);	 
		
		cout<< head->data << " ";
		q.pop();	
		head = q.front();		
}
}
void BST::display()
{
  inOrderRec(m_root);
 _NL_
 bfs(m_root);
 _NL_
 spiralDisplay(m_root);
 _NL_ 
}

int main(void)
{
 BST bt;
 bt<30<20<40<15<25<35<45<12<18<23<27<33<38<42<50;
 bt.display();  
 cout<<" \nthe height of the tree is ..."<< bt.height();
 _NL_
 return 0;
}
