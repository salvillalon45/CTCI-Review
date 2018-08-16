//	******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	queue.h
//
//	An implementation of a queue using a SinglyLinked List with head and tail
//
//	********************************************************************************


#include "stdafx.h"
#include <iostream>
#include "queue.h"

// The preprocessor examines the code before actual compilation of code begins and 
// resolves all these directives before any code is actually generated by 
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times, 
#ifndef QUEUE_CPP
#define QUEUE_CPP



// Queue()
// Constructor
// --------------------------------------------------------
Queue::Queue() 
{
	head = nullptr;
	tail = nullptr;
}


// ~Queue()
// Destructor
// --------------------------------------------------------
Queue::~Queue() 
{
	for (Node * cur = head; cur != nullptr;) 
	{
		Node * temp_node = cur;
		cur = cur->next;
		delete temp_node;
	}
}


// add(int new_item)
// This function adds an item to the end of the list
// Time Complexity: O(1)
// --------------------------------------------------------
void Queue::add(int new_item) 
{
	// If this is the first node to be added
	if (head == nullptr && tail == nullptr) 
	{
		Node * new_node = new Node(new_item);
		head = new_node;
		tail = new_node;
	}
	// When there are more nodes
	else 
	{
		// Create a new node
		Node * new_node = new Node(new_item);

		// Make the last node next pointer (in this case it will be null) 
		// point to the new_node 
		tail->next = new_node;

		// Now make tail point to the new node
		tail = new_node;
	}
}
// remove()
// This function removes the first item in the list
// Time Complexity: O(1)
// --------------------------------------------------------
int Queue::remove() 
{
	// If there are no nodes available
	if (head == nullptr && tail == nullptr) 
	{
		std::cout << "There are no nodes available. Consider adding nodes first" << std::endl;
		std::cout << "ZERO MEANS YOU CANNOT REMOVE NODES" << std::endl;
		return 0;
	}
	// When there are more nodes
	else 
	{
		// Create temp_node that points to head's next value
		Node * temp_node = head->next;

		// This will be the information that we will return
		int return_info = head->info;

		// Delete head. We do this so can give it a new value to point to
		delete head;

		// Make head point to temp_node
		head = temp_node;

		return return_info;
	}
}

// peek()
// This function returns the top of the queue
// Time Complexity: O(1)
// --------------------------------------------------------
int Queue::peek() 
{
	// If there are no nodes available
	if (head == nullptr && tail == nullptr)
	{
		std::cout << "There are no nodes available. Consider adding nodes first" << std::endl;
		std::cout << "ZERO MEANS YOU CANNOT REMOVE NODES" << std::endl;
		return 0;
	}
	// When there are more nodes
	else 
	{
		return head->info;
	}
}

// is_empty()
// This function checks if the queue is empty
// Time Complexity: O(1)
// --------------------------------------------------------
bool Queue::is_empty() 
{
	if (head == nullptr && tail == nullptr) 
	{
		// Queue is empty
		return true;
	}
	else 
	{
		// Queue has nodes
		return false;
	}
}


// print_queue()
// This function prints all the elements inside the queue
// Time Complexity: O(n)
// --------------------------------------------------------
void Queue::print_queue() 
{
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		std::cout << "QUEUE INFO:: " << cur->info << std::endl;
	}

}

#endif