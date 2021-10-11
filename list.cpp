#include <iostream>

using namespace std;

class list
{
	public:
	class node
	{
		public:
		int val;
		node* next;
		node* prev;
		node(int n)
		{
			val=n;
			next=NULL;
			prev=NULL;
		}
		node(int n, node* p)
		{
			val=n;
			next=NULL;
			prev=p;
		}
		void add(int n)
		{
			if(next==NULL)
			{
				next=new node(n,this);
			}
			else
			{
				next->add(n);
			}
		}
	};
	node* head;
	list()
	{
		head=NULL;
	}
	void add(int n)
	{
		if(head==NULL)
		{
			head=new node(n);
		}
		else
		{
			head->add(n);
		}
	}
	node * findInd(int ind)
	{
		node * p=head;
		while(ind)
		{
			ind--;
			if(p==NULL)return NULL;
			p=p->next;
		}
		return p;
	}
	void rem(node *n)
	{
		if(n==head)
		{
			head=n->next;
		}
		else
		{
			n->prev->next=n->next;
		}
		if(n->next!=NULL)
		{
			n->next->prev=n->prev;
		}
		delete n;
	}
};

int main()
{
	list l;
	l.add(1);
	l.add(5);
	l.add(4);
	cout<<l.findInd(1)->val<<endl;
	l.rem(l.findInd(1));
	cout<<l.findInd(1)->val<<endl;
}
