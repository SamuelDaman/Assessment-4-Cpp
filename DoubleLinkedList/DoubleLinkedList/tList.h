//  tList.h

#pragma once

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
		Node * newNode;
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
		Node * newNode;
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
	void remove(const T& val);

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
			return !(iterator != rhs);
		}
		T& operator*() const
		{
			Node * currentNode;
			return cur & currentNode;
		}
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
	};

	iterator begin();
	const iterator begin() const;
	iterator end();
	const iterator end() const;
};