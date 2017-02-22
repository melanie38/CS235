#include "Stack.h"

const int FULL_CAPACITY = 5;
//Part 2--------------------------------------------------------------
/**
 * Adds the current car to the stack.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the stack is already full.
 *
 * @return true if the car is successfully added to the stack; false otherwise
 */
bool Stack::addToStack()
{
	if (headStation != NULL && stackSize < FULL_CAPACITY)
	{
		if (headStack != NULL)
		{
			headStation->next = headStack;
			headStack = headStation;
		}
		else
		{
			headStack = headStation;
		}
		stackSize++;
		cout << "Car successfully added to the stack" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * Removes the first car in the stack and makes it the current car.
 * Does nothing if there is already a current car or if the stack already empty.
 *
 * @return true if the car is successfully removed from the stack; false otherwise
 */
bool Stack::removeFromStack()
{
	if (headStack != NULL)
	{
		Node* headStation = headStack;
		headStack = headStack->next;
		stackSize--;
		return true;
	}
	else
	{
		return true;
	}
}

/**
 * Returns the ID of the first car in the stack.
 *
 * @return the ID of the first car in the stack; -1 if the stack is empty
 */
int Stack::showTopOfStack()
{
	return headStack->data;
}

/**
 * Returns the number of cars in the stack.
 *
 * @return the number of cars in the stack
 */
int Stack::showSizeOfStack()
{
	return stackSize;
}
