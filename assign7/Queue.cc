#include <iostream>
#include "Queue.h"

using namespace std;

template <typename t>
Queue<t>::Queue()
{
	head=NULL;
	tail=NULL;
}

template <typename t>
Queue<t>::Queue(const Queue<t>& other)
{
	Node<t> *tmp;
    Node<t> *n1;
    tmp=other.head;
    this->head=NULL;
    this->tail=NULL;

    while(tmp!=NULL)
    {
        n1=new Node<t>;
        n1->next=NULL;
        n1->data=tmp->data;

        if(this->tail==NULL)
            this->head=n1;
        else this->tail->next=n1;
        this->tail=n1;
        tmp=tmp->next;
    }   
}

template <typename t>
Queue<t>::~Queue()
{
}

template <typename t>
void
Queue<t>::enqueue(t d)
{
	Node<t> *tmp=new Node<t>;
	tmp->data=d;
	tmp->next=NULL;
	
	if(tail==NULL)
		head=tmp;
	else
		tail->next=tmp;
	tail=tmp;
}

template <typename t>
void
Queue<t>::dequeue()
{
	Node<t> *tmp;
	tmp=head;
	while(head!=NULL)
	{
		tmp=head;
		cout<<tmp->data<<endl;;
		head=head->next;
		delete tmp;
	}
}

template <typename t>
Queue<t>&
Queue<t>::operator=(const Queue<t>& other)
{
	Node<t> *tmp;
	Node<t> *n1;
	tmp=other.head;
	this->head=NULL;
	this->tail=NULL;

	while(tmp!=NULL)
	{
		n1=new Node<t>;
		n1->next=NULL;
		n1->data=tmp->data;

		if(this->tail==NULL)
			this->head=n1;
		else this->tail->next=n1;
		this->tail=n1;
		tmp=tmp->next;
	}

	return *this;
}

template class Queue<int>;
template class Queue<char>;
template struct Node<int>;
template struct Node<char>;
