// tList.h

#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class tList
{
	struct Node
	{
		T data;			// Data for the element stored.
		Node * prev;	// Pointer to the following node.
		Node * next;	// Pointer to the previous node.
	};

	Node * head;	// Pointer to the head of the list.
	Node * tail;	// Pointer to the tail of the list.

public:
	// Initializes head to null.
	tList()
	{
		head = nullptr;
		tail = nullptr;
	}
	// Copy constuctor.
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
	// Copy assignment.
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
	// Delete all nodes upon destruction.
	~tList()
	{
		clear();
	}

	// Adds element to front.
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
	// Removes element from front.
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
	// Adds element to back.
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
	// Removes element from back.
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

	// Returns the element at the head.
	T& front()
	{
		return head->data;
	}
	// Returns the element at the head (const).
	const T& front() const
	{
		return head->data;
	}
	// Returns the element at the back.
	T& back()
	{
		return tail->data;
	}
	// Returns the element at the back (const).
	const T& back() const
	{
		return tail->data;
	}

	// Checks the size of the list.
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

	// Removes all elements equal to the given value.
	void remove(const T& val)
	{
		while (head != nullptr && head->data == val)
		{
			pop_front();
		}

		Node * node = head;

		while (node != nullptr)
		{
			if (node->next == nullptr)
			{
				break;
			}
			else if (node->next->data == val)
			{
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
				node = node->next;
			}
		}
	}

	// Returns true if there are no elements.
	bool empty() const
	{
		return (head == nullptr && tail == nullptr);
	}
	// Destroys every single node in the list.
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
	// Resizes the list to contain the given number of elements.
	void resize(size_t newSize)
	{
		size_t size = listSize();

		if (size == newSize)
		{
			return;
		}
		else if (size > newSize)
		{
			for (size_t i = newSize; i < size; i++)
			{
				pop_back();
			}
		}
		else if (size < newSize)
		{
			for (size_t i = size; i < newSize; i++)
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
		Node * cur;	// The current node being operated upon.

	public:
		// Initializes an empty operator pointing to null.
		iterator()
		{
			cur = nullptr;
		}
		// Initializes an iterator pointing to the given node.
		iterator(Node * startNode)
		{
			cur = startNode;
		}

		// Returns true if the iterator points to the same node.
		bool operator==(const iterator& rhs) const
		{
			return (cur == rhs.cur);
		}
		// Returns false if the iterator points to the same node.
		bool operator!=(const iterator& rhs) const
		{
			return (cur != rhs.cur);
		}
		// Returns a reference to the element pointed to by the current node.
		T& operator*()
		{
			return cur->data;
		}
		// Returns a reference to the element pointed to by the current node.
		const T& operator*() const
		{
			return cur->data;
		}
		// Pre-increment (returns a reference to this iterator after it is incremented).
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		// Post-increment (returns an iterator as it was before it was incremented).
		iterator operator++(int)
		{
			iterator newIterator = *this;
			cur = cur->next;
			return newIterator;
		}
		// Pre-decrement (returns a reference to this iterator after it is decremented).
		iterator& operator--()
		{
			cur = cur->prev;
			return *this;
		}
		// Post-decrement (returns an iterator as it was before it was decremented).
		iterator operator--(int)
		{
			iterator newIterator = *this;
			cur = cur->prev;
			return newIterator;
		}
	};

	// Iterator constructors for iterating forward.

	// Returns an iterator pointing to the first element.
	iterator beginFront()
	{
		return iterator(head);
	}
	// Returns a const iterator pointing to the first element.
	const iterator beginFront() const
	{
		return iterator(head);
	}
	// Returns an iterator pointing to one past the last element.
	iterator endFront()
	{
		return iterator(tail->next);
	}
	// Returns a const iterator pointing to one past the last element.
	const iterator endFront() const
	{
		return iterator(tail->next);
	}

	// Iterator constructors for iterating forward.

	// Returns an iterator pointing to the last element.
	iterator beginBack()
	{
		return iterator(tail);
	}
	// Returns a const iterator pointing to the last element.
	const iterator beginBack() const
	{
		return iterator(tail);
	}
	// Returns an iterator pointing to one before the first element.
	iterator endBack()
	{
		return iterator(head->prev);
	}
	// Returns a const iterator pointing to one before the first element.
	const iterator endBack() const
	{
		return iterator(head->prev);
	}
};