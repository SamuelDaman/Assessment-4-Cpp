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
		Node * node = other.head;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				push_back(node->data);
				break;
			}
			else
			{
				push_back(node->data);
				node = node->next;
			}
		}
	}
	tList& operator=(const tList &rhs)
	{
		Node * node = rhs.head;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				push_back(node->data);
				break;
			}
			else
			{
				push_back(node->data);
				node = node->next;
			}
		}
		return *this;
	}
	~tList()
	{
		
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
			Node * burnNode = head;
			if (head->next != nullptr)
			{
				head->next->prev = nullptr;
				head = head->next;
			}
			burnNode = nullptr;
			delete burnNode;
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
			Node * burnNode = tail;
			if (tail->prev != nullptr)
			{
				tail->prev->next = nullptr;
				tail = tail->prev;
			}
			burnNode = nullptr;
			delete burnNode;
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

	//  Size Check
	size_t listSize()
	{
		Node * node = head;
		size_t listCounter = 0;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				listCounter++;
				break;
			}
			else
			{
				node = node->next;
				listCounter++;
			}
		}
		return listCounter;
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
		size_t listCount = listSize();

		for (size_t i = 0; i < listCount; i++)
		{
			pop_front();
		}

		head = nullptr;
		tail = nullptr;
	}
	void resize(size_t newSize)
	{
		Node * node = head;
		size_t listSize = 0;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				listSize++;
				break;
			}
			else
			{
				node = node->next;
				listSize++;
			}
		}

		cout << "list size: " << listSize << endl;

		if (listSize == newSize)
		{
			return;
		}
		else if (listSize > newSize)
		{
			for (size_t i = newSize; i < listSize; i++)
			{
				pop_back();
			}
		}
		else if (listSize < newSize)
		{
			for (size_t i = listSize; i < newSize; i++)
			{
				Node * newNode = new Node;
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
		}
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
			return (cur == rhs.cur);
		}
		bool operator!=(const iterator& rhs) const
		{
			return (cur != rhs.cur);
		}
		T& operator*() const
		{
			return cur->data;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator newIterator = *this;
			cur = cur->next;
			return newIterator;
		}
		iterator& operator--()
		{
			cur = cur->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator newIterator = *this;
			cur = cur->prev;
			return newIterator;
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