//  tList.h

#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class tList
{
	struct Node
	{
		T data;
		Node * prev;
		Node * next;
	};

	Node * head;
	Node * tail;

public:
	//  Constructors and Destuctor.
	tList()
	{
		head = nullptr;
		tail = nullptr;
	}
	tList(const tList& other)
	{
		this = other;
	}
	tList& operator=(const tList &rhs)
	{
		this = rhs;
	}
	~tList()
	{
		head = nullptr;
		delete head;
		tail = nullptr;
		delete tail;
	}

	//  Push and pop functions.
	void push_front(const T& val)
	{
		Node * newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		newNode->prev = nullptr;
		if (tail == nullptr)
		{
			tail = newNode;
			tail->next = nullptr;
			tail->prev = nullptr;
		}
		else
		{
			head->prev = newNode;
		}
		head = newNode;
	}
	void pop_front()
	{
		if (head != nullptr)
		{
			Node * newNode = head;
			if (head->next != nullptr)
			{
				head->next->prev = nullptr;
			}
			head = head->next;
			newNode = nullptr;
			delete newNode;
		}
	}
	void push_back(const T& val)
	{
		Node * newNode = new Node;
		newNode->data = val;
		newNode->prev = tail;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			head->next = nullptr;
			head->prev = nullptr;
		}
		else
		{
			tail->next = newNode;
		}
		tail = newNode;
	}
	void pop_back()
	{
		if (tail != nullptr)
		{
			Node * newNode = tail;
			if (tail->prev != nullptr)
			{
				tail->prev->next = nullptr;
			}
			tail = tail->prev;
			newNode = nullptr;
			delete newNode;
		}
	}

	//  Front and back check functions.
	T& front()
	{
		return head->data;
	}
	const T& front() const
	{
		return head->data;
	}
	T& back()
	{
		return tail->data;
	}
	const T& back() const
	{
		return tail->data;
	}

	//  Remove function.
	void remove(const T& val)
	{
		while (head != nullptr && head->data == val)
		{
			cout << "The first node will be deleted" << endl;
			pop_front();
		}

		Node * node = head;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				cout << "End of the list" << endl;
				break;
			}
			else if (node->next->data == val)
			{
				cout << "The next node will be deleted" << endl;
				Node * burnNode = node->next;
				if (node->next->next != nullptr)
				{
					node->next = node->next->next;
					node->next->prev = node;
				}
				else
				{
					pop_back();
				}
				burnNode = nullptr;
				delete burnNode;
			}
			else
			{
				cout << "Moving on to the next node" << endl;
				node = node->next;
			}
		}
	}

	//  Miscellaneous functions.
	bool empty() const
	{	
		return (head == nullptr && tail == nullptr);
	}
	void clear()
	{
		Node * node = head;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				cout << "End of the list" << endl;
				break;
			}
			else if (node->next != nullptr)
			{
				cout << "Deleting node" << endl;
				node = node->next;
				Node * burnNode = node->prev;
				burnNode = nullptr;
				delete burnNode;
			}
		}

		node = nullptr;
		delete node;
		head = nullptr;
		delete head;
		tail = nullptr;
		delete tail;
	}
	void resize(size_t newSize)
	{

	}

	class iterator
	{
		Node * cur;

	public:
		iterator()
		{
			cur = nullptr;
		}
		iterator(Node * startNode)
		{
			cur = startNode;
		}

		bool operator==(const iterator& rhs) const
		{
			return (iterator == rhs);
		}
		bool operator!=(const iterator& rhs) const
		{
			return (iterator != rhs);
		}
		T& operator*() const
		{
			return cur->data;
		}
		iterator& operator++()
		{
			return ++this;
		}
		iterator operator++(int)
		{
			return this++;
		}
		iterator& operator--()
		{
			return --this;
		}
		iterator operator--(int)
		{
			return this--;
		}
	};

	iterator begin()
	{
		iterator newIterator = iterator(head);
		return newIterator;
	}
	const iterator begin() const
	{
		iterator newIterator = iterator(head);
		return newIterator;
	}
	iterator end()
	{
		iterator newIterator = iterator(tail->next);
		return newIterator;
	}
	const iterator end() const
	{
		iterator newIterator = iterator(tail->next);
		return newIterator;
	}
};