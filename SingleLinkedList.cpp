#include <string>
#include <bitset>
#include <limits>
#include<math.h>
#include<cmath>
#include<fstream>
#include<bitset>
#include<vector>
#include <sstream>
#include<algorithm>
#include<time.h>
#include<set>
#include<map>
#include<iostream>
#include <numeric>

using namespace std;

struct Node
{
	int Data;
	Node * next;

};
class SingleLinkedList
{
private:
	Node * head;
	int nodeCount;
public:
	~SingleLinkedList()
	{
		while (head!=NULL)
		{
			Node* iterator=head;
			head=iterator->next;
			delete iterator;
		}

	}

	SingleLinkedList()
	{
		head=NULL;
		nodeCount=0;
	};

	void addToFront(int data)
	{
		Node * newHead=new Node;
		newHead->Data=data;

		if(head==NULL)
		{
			newHead->next=NULL;
			head=newHead;
		}
		else
		{
			newHead->next=head;
			head=newHead;
		}
		++nodeCount;
	}
	void addToBack(int data)
	{
		if(head==NULL)
		{
			Node * current=new Node;
			current->Data=data;
			current->next=NULL;
			head=current;

		}
		else
		{
			Node * iterator = new Node;
			iterator=head;
			while (iterator->next!=NULL)
			{
				iterator=iterator->next;
			} 
			Node * current=new Node;
			current->Data=data;
			iterator->next=current;
			current->next=NULL;

		}
		++nodeCount;
	}
	void Reverse()
	{
		Node * prev=NULL;
		Node * next;
		Node * current=head;
		while (current!=NULL)
		{
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;

		}
		head=prev;
	}
	void Reverse2()
	{
		Node*curr=head;
		Node*next=NULL;

		while(curr->next!=NULL)
		{
			next=curr->next;
			curr->next=next->next;
			next->next=head;
			head=next;
		}
	}
	void ReversebyCount()
	{
		if(nodeCount==0)
		{
			cout<<"The List is Empty \n";
		}
		else 
		{
			int visited=0;
			int count=0;
			int end=nodeCount-1;
			Node * start=head;
			while (end>=nodeCount/2)
			{
				// iterate to the mapped elemet
				Node * last=start;
				while(count<end)
				{
					last=last->next;
					++count;
				}
				//swap elements
				int temp;
				temp=start->Data;
				start->Data=last->Data;
				last->Data=temp;
				//move to the next element
				start=start->next;
				end-=1;
				visited++;
				count=visited;

			}
		}

	}
	//Remove first occurance of some value
	void Remove(int data)
	{
		bool exit=false;
		if(!head)
		{
			cout<<"The list is Empty \n";
			return;
		}
		else if(head->Data==data)
			head=head->next;
		else
		{
			Node * current=head;
			Node * prev=NULL;
			while (current!=NULL)
			{

				if(current->Data==data)
				{
					if(prev)
					{
						prev->next=current->next;
						exit=true;
						break;
					}

				}
				prev=current;
				current=current->next;
			}
		}
		if(!exit)
			cout<<"Item not found \n";

	}
	void removeDuplicates()
	{

		Node * current=head;
		while (current)
		{
			Node *prev=current;
			Node * next=current->next;
			while (next)
			{

				if(next->Data==current->Data)
					prev->next=next->next;
				else
					prev=next;

				next=next->next;

			}
			current=current->next;
		}
	}
	void Show()
	{
		if(head==NULL)
		{
			cout<<"The List is Empty \n";
		}
		else
		{
			Node * iterator=head;
			do 
			{
				cout<<iterator->Data<<endl;
				iterator=iterator->next;
			} while (iterator!=NULL);
		}
	}

};