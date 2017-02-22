#pragma once
#include <iostream>
#include <string>
#include "Station.h"
using namespace std;

class Stack : public Station
{
	public:
		Stack()
		{
			headStack = NULL;
			stackSize = 0;
		}
		~Stack(){}

		bool addToStack();
		bool removeFromStack();
		int showTopOfStack();
		virtual int showSizeOfStack();

	private:
		/*struct Node
		{
			int data;
			Node* next;

			Node(int data, Node* next)
			{
				this->data = data;
				this->next = next;
			}
			~Node(){};
		};*/
		Node* headStack;
		int stackSize;
};
