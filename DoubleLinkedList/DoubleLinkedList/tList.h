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
		delete head;
		delete tail;
	}

	//  Push and pop functions.
	void push_front(const T& val)
	{
		Node * newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		if (tail == nullptr)
		{
			tail = newNode;
		}
		head = newNode;
	}
	void pop_front()
	{
		if (head != nullptr)
		{
			Node * newNode = head;
			head = head->next;
			delete newNode;
		}
	}
	void push_back(const T& val)
	{
		Node * newNode = new Node;
		newNode->data = val;
		newNode->prev = tail;
		if (head == nullptr)
		{
			head = newNode;
		}
		tail = newNode;
	}
	void pop_back()
	{
		if (tail != nullptr)
		{
			Node * newNode = tail;
			tail = tail->prev;
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
		Node * node = head;
		while (true)
		{
			//if (node->next == nullptr)
			//{
			//	if (node->data == val)
			//	{
			//		node = nullptr;
			//	}
			//	cout << "Next node is null." << endl;
			//	return;
			//}
			//else if (node->prev == nullptr)
			//{
			//	if (node->data == val)
			//	{
			//		node = node->next;
			//		node->prev = nullptr;
			//	}
			//	cout << "Last node was null." << endl;
			//}
			//else
			//{
			//	if (node->data == val)
			//	{
			//		//node->prev->next = node->next;
			//		//node->next->prev = node->prev;
			//		node = node->next;
			//		//node->prev = node->prev->prev;
			//		cout << "Current Node: " << node->data << endl;
			//	}
			//}
			
			if (node->next == nullptr)
			{
				cout << "The next node is null" << endl;
				return;
			}
			else if (node->next->data == val)
			{
				
			}
		}
	}

	//  Miscellaneous functions.
	bool empty() const;
	void clear();
	void resize(size_t newSize);

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
		iterator newIterator = iterator(tail);
		return newIterator;
	}
	const iterator end() const
	{
		iterator newIterator = iterator(tail);
		return newIterator;
	}
};