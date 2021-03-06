//	*******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	stack.h
//
//	An implementation of a Stack using a SinglyLInkedList with head and tail
//
//	********************************************************************************

// The preprocessor examines the code before actual compilation of code begins and
// resolves all these directives before any code is actually generated by
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times,
#ifndef STACK_H
#define STACK_H


class Stack
{
private:
	struct Node
	{
		int info;
		Node * next;

		Node(int new_info)
		{
			info = new_info;
			next = nullptr;
		}
	};

	// Points to first node in the list
	Node * head;

	// Points to first node in the list
	Node * tail;

	// Variable to keep track of the minimum value in the stack
	int minimum = 2000000000;

public:

	// Constructor
	// ---------------------------------------------
	Stack();


	// Destructor
	// ---------------------------------------------
	~Stack();


	// Remove from stack
	// ---------------------------------------------
	int pop();


	// Add to stack
	// ---------------------------------------------
	void push(int new_element);


	// Get first value of stack
	// ---------------------------------------------
	int peek();


	// Check if the stack is empty
	// ---------------------------------------------
	bool is_empty();


	// Add to stack with the min value being the first node
	// ---------------------------------------------
	void push_min(int new_info);


	// Return the min value of the stack
	// ---------------------------------------------
	int min();


	// Print stack
	// ---------------------------------------------
	void print_stack();


};

#endif
