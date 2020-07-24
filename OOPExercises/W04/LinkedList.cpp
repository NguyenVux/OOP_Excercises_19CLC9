#include "LinkedList.h"

LinkedList::LinkedList(void)
{
	this->pHead = nullptr;
	this->pTail = pHead;
}

LinkedList::~LinkedList(void)
{
	Node* tmp;
	while (this->pHead != nullptr)
	{
		tmp = this->pHead;
		this->pHead = this->pHead->pNext;
		delete tmp;
	}
}

Node* LinkedList::getHead()
{
	return this->pHead;
}

Node* LinkedList::getTail()
{
	return this->pTail;
}

Node* LinkedList::CreateNode(const int& n)
{
	Node* node = new Node;
	node->info = n;
	node->pNext = nullptr;
	return node;
}

Node* LinkedList::AddHead(const int& n)
{
	Node* node = CreateNode(n);
	if (pHead == nullptr)
	{
		this->pHead = node;
		this->pTail = node;
	}
	else
	{
		node->pNext = this->pHead;
		this->pHead = node;
	}
	return this->pHead;
}

Node* LinkedList::AddTail(const int& n)
{
	Node* node = CreateNode(n);
	this->pTail->pNext = node;
	this->pTail = node;
	return this->pTail;
}

Node* LinkedList::RemoveHead()
{
	Node* tmp = this->pHead;
	this->pHead = this->pHead->pNext;
	delete tmp;
	return this->pHead;
}

Node* LinkedList::RemoveTail()
{
	if (pTail != pHead)
	{
		Node* tmp = pHead;
		while (tmp->pNext != pTail)
		{
			tmp = tmp->pNext;
		}
		delete pTail;
		pTail = tmp;
		pTail->pNext = nullptr;
	}
	else
	{
		delete pTail;
		pTail = nullptr;
		pHead = nullptr;
		return this->pHead;
	}
}

int& LinkedList::operator[](const int& i)
{
	if (i < 0)
	{
		if (pHead == nullptr) throw;
		return pHead->info;
	}
	else
	{
		Node* tmp = this->pHead;
		int j;
		for (j = 0; j < i && tmp != nullptr ; j++)
		{
			tmp = tmp->pNext;
		}
		if (j == i)
		{
			return tmp->info;
		}
		else
		{
			if (pTail == nullptr)
			{
				throw;
			}
			return pTail->info;
		}
	}

}

ostream& operator<<(ostream& os, const LinkedList& ll)
{
	Node* tmp = ll.pHead;
	while (tmp != nullptr)
	{
		os << tmp->info << ", ";
		tmp = tmp->pNext;
	}
	return os;
}
