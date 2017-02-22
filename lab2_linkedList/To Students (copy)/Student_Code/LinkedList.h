
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T>
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* next)
		{
			this->data = data;
			this->next = next;

		}
		~Node(){};
	};

	Node* head;
	int length;

public:

	LinkedList(void)
	{
		head = NULL;
		length = 0;
	};
	~LinkedList(void){clear();};

	bool find(T value)
	{
		if(head != NULL)
		{
			Node* ptr = head;
			if(ptr->data == value)
			{
				return true;
			}
			else
			{
				while(ptr->next != NULL)
				{
					if (ptr->data == value)
					{
						return true;
					}
					else
					{
						ptr = ptr->next;
					}
				}
				if(ptr->data == value)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
	/*
		insertHead

		A node with the given value should be inserted at the beginning of the list.

		Do not allow duplicate values in the list.
	 */
	void insertHead(T value)
	{
		if(!find(value))
		{
			if(head == NULL)
			{
				Node* temp = new Node(value, NULL);
				head = temp;
				length++;
			}
			else
			{
				Node* temp = new Node(value, head);
				head = temp;
				length++;
			}
		}
	}

	/*
		insertTail

		A node with the given value should be inserted at the end of the list.

		Do not allow duplicate values in the list.
	 */
	void insertTail(T value)
	{
		if(!find(value))
		{
			if(head == NULL)
			{
				insertHead(value);
			}
			else
			{
				Node* temp = new Node(value, NULL);
				Node* ptr = head;
				while(ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = temp;
				length++;
			}
		}
	}

	/*
		insertAfter

		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.

		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Do not allow duplicate values in the list.
	 */
	void insertAfter(T value, T insertionNode)
	{
		if(head!=NULL)
		{
			if (!find(value))
			{
				if(find(insertionNode))
				{
					Node* temp = new Node(value, NULL);
					Node* ptr = head;
					while (ptr->data != insertionNode)
					{
						ptr = ptr->next;
					}
					temp->next = ptr->next;
					ptr->next = temp;
					length++;
				}
			}
		}
	}

	/*
		remove

		The node with the given value should be removed from the list.

		The list may or may not include a node with the given value.
	 */
	void remove(T value)
	{
		if(find(value))
		{
			Node* temp;
			if(head->data == value)
			{
				temp = head;
				head = head->next;
				delete temp;
				temp = NULL;
				length--;
			}
			else
			{
				temp = head->next;
				Node* prev = head;
				while (temp->data != value)
				{
					temp = temp->next;
					prev = prev->next;
				}
				prev->next = temp->next;
				delete temp;
				temp = NULL;
				length--;
			}
		}
	}

	/*
		clear

		Remove all nodes from the list.
	 */
	void clear()
	{
		while(head != NULL)
		{
			remove(head->data);
			length = 0;
		}
	}

	/*
		at

		Returns the value of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, throw an out of range exception.
	 */
	T at(int index)
	{
		if(head != NULL)
		{
			if(index < 0 || index > (size() - 1))
			{
				throw out_of_range(" ");
			}
			else
			{
				Node* ptr;
				ptr = head;
				if(index == 0)
				{
					return ptr->data;
				}
				else
				{
						for(int i = 0; i < index; i++)
						{
							ptr = ptr->next;
						}
						return ptr->data;
				}
			}
		}
		else
		{
			throw out_of_range(" ");
		}
	}

	/*
		size

		Returns the number of nodes in the list.
	 */
	int size()
	{
		return length;
	}

};
