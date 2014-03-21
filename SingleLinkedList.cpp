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
		nodeCount=0;
	}

	SingleLinkedList()
	{
		head=NULL;
		nodeCount=0;
	};
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
	void Reverse()
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
	//To be Added
	void Remove(int data)
	{

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