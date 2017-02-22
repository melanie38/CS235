/*
 * ExpressionManager.cpp
 *
 *  Created on: May 21, 2015
 *      Author: mlalahar
 */
#include "ExpressionManager.h"

	/*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise
	*/
string ExpressionManager::isOpen(string data)
{
	int curly = 0;
	int square = 0;
	int braces = 0;

	if(data == "{")
	{
		curly++;
	}
	else if(data == "[")
	{
		square++;
	}
	else if(data == "(")
	{
		braces++;
	}
	return open;
}
int ExpressionManager::isClosed(string data)
{
	int closed = 0;

	if(data == '}' || data == ']' || data == ')')
	{
		closed++;
	}
	return closed;
}

bool ExpressionManager::isBalanced(string expression)
{
	stack<string> bracesStack;
	string data;
	stringstream ss(expression);

	if(expression == " ")
	{
		return false;
	}

	while(ss >> data)
	{
		if(data == "{" || data == "[" || data == "(")
		{
			bracesStack.push(data);
		}
		else if(data == "}" || data == "]" || data ")")
		{
			if(!bracesStack.empty() && (bracesStack.top() == data))
			{
				bracesStack.pop();
			}
		}


	}

}


	/**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
string ExpressionManager::postfixToInfix(string postfixExpression)
{
}

	/*
	 * Converts an infix expression into a postfix expression
	 * and returns the postfix expression
	 *
	 * - The given infix expression will have a space between every number or operator.
	 * - The returned postfix expression must have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if infixExpression is not a valid infix expression.
	 * otherwise, return the correct postfix expression as a string.
	 */
string ExpressionManager::infixToPostfix(string infixExpression);

	/*
	 * Evaluates a postfix expression returns the result as a string
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */
string ExpressionManager::postfixEvaluate(string postfixExpression);


};



