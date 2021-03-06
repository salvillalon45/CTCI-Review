//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	doubly_linkedlist.cpp
// 
//	An implementation of a Doublly Linkedlist with a head and tail pointer
//	
//	********************************************************************************


#include "stdafx.h"
#include "doubly_linkedlist.h"
#include "exception.h"
#include <iostream>

// The preprocessor examines the code before actual compilation of code begins and 
// resolves all these directives before any code is actually generated by 
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times, 

#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP



// DoublyLinkedList()
// The constructor
// --------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

// ~DoublyLinkedList()
// The destructor
// --------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList() 
{
	for (Node * p = head; p != nullptr;) 
	{
		Node * temp_node = p;
		p = p->next;
		delete temp_node;
	}
}

// add_to_front(int input)
// This function add a node to the front of the linkedlist
// Time Complexity: O(1)
// --------------------------------------------------------
void DoublyLinkedList::add_to_front(int input) 
{
	if (head == nullptr) 
	{
		Node * new_node = new Node(input);
		head = new_node;
		tail = new_node;
	}
	else
	{
		Node * new_node = new Node(input);
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
}

// add_to_end(int input)
// This function add a node to the end of the linkedlist
// Time Complexity: O(1)
// --------------------------------------------------------
void DoublyLinkedList::add_to_end(int input) 
{
	// If this is the first node to be added
	if (head == nullptr)
	{
		Node * new_node = new Node(input);
		head = new_node;
		tail = new_node;
	}
	// There is more than one node to add
	else
	{
		Node * new_node = new Node(input);
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
}

// remove_front()
// This function removes a node from the start of the linkedlist
// Time Complexity: O(1)
// --------------------------------------------------------
void DoublyLinkedList::remove_front() 
{
	// If there are no nodes, then we cannot remove them
	if (head == nullptr)
	{
		std::cout << "No Nodes to remove" << std::endl;
		std::cout << "Consider adding nodes first, then remove" << std::endl;
	}
	// There is only node in the LinkedList
	else if (head->next == nullptr) 
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	// There are nodes to remove
	else
	{
		Node * temp_node = head;
		head = temp_node->next;
		//head->prev = nullptr;
		delete temp_node;
	}
}

// remove_last()
// This function removes a node from the end of the linkedlist
// Time Complexity: O(n)
// --------------------------------------------------------
void DoublyLinkedList::remove_last() 
{	
	// If there are no nodes, then we cannot remove them
	if (head == nullptr)
	{
		std::cout << "No Nodes to remove" << std::endl;
		std::cout << "Consider adding nodes first, then remove" << std::endl;
	}
	// There is only node in the LinkedList
	else if (head->next == nullptr) 
	{
		std::cout << "ONE NODE CHECK -- remove_last()" << std::endl;
		delete tail;
		//delete head;
		head = nullptr;
		tail = nullptr;
	}
	// There are nodes to remove
	else
	{
		Node * temp_node = tail;
		tail = temp_node->prev;
		tail->next = nullptr;
		delete temp_node;
	}
}

// int index(int input_index)
// This function looks for the node at the given index 
// and returns the info of the node
// Time Complexity: O(n)
// --------------------------------------------------------
int DoublyLinkedList::index(int input_index) 
{
	int index = 0;
	for (Node * p = head; p != nullptr; p = p->next) 
	{
		if (index == input_index) 
		{
			// We found the index that the user inputed
			return p->info;
		}
		else if (p->next == nullptr) 
		{
			// The index is out of bounds
			std::cout << "The given index is out of bounds" << std::endl;
			std::cout << "Return Zero means it is wrong" << std::endl;
			return 0;
		}
		index++;
	}
}


// get_first_node()
// This function returns the info of the first node
// Time Complexity: O(1)
// --------------------------------------------------------
int DoublyLinkedList::get_first_node() 
{
	return head->info;
}


// insert_node_at_position(int data, int position)
// This function inserts a node at given position
// Time Complexity: O(n)
// --------------------------------------------------------
void DoublyLinkedList::insert_node_at_position(int data, int position) 
{
	int index = 0;
	for (Node * p = head; p != nullptr; p = p->next) 
	{
		if (index == position-1) 
		{
			Node * new_node = new Node(data);
			Node * temp_node = p;
			temp_node->next = new_node;
			new_node->next = p->next;
			//delete temp_node;
		}
		index++;
	}
}


// print_nodes()
// This function prints the info of all nodes in the LinkedList
// Time Complexity: theta(n)
// --------------------------------------------------------
void DoublyLinkedList::print_nodes() 
{
	for (Node * p = head; p != nullptr; p = p->next) 
	{
		std::cout << "P->INFO:: " << p->info << std::endl;
	}
}


#endif