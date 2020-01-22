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
	tList();
	tList(const tList& other);
	tList& operator=(const tList &rhs);
	~tList();

	void push_front(const T& val);
	void pop_front();
	void push_back(const T& val);
	void pop_back();

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	void remove(const T& val);

	bool empty() const;
	void clear();
	void resize(size_t newSize);

	class iterator
	{
		Node * cur;

	public:
		iterator();
		iterator(Node * startNode);

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;
		T& operator*() const;
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