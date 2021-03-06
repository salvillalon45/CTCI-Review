//	******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	singly_linkedlist.h
//
//	An implementation of a Singly Linkedlist with a head pointer
//
//	********************************************************************************

#include "stdafx.h"

// The preprocessor examines the code before actual compilation of code begins and 
// resolves all these directives before any code is actually generated by 
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times, 
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SinglyLinkedList
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

	// Points to first node in the LinkedList
	Node * head;

public:
	SinglyLinkedList();

	~SinglyLinkedList();

	// ADD NODES
	// ---------------------------------------------
	void add_to_end(int input);

	void add_to_front(int input);

	void insert_node_at_position(int data, int position);
	
	
	// REMOVE NODES 
	// ---------------------------------------------
	void remove_front_node();

	void remove_last_node();

	void delete_node_at_position(int position);


	// INDEX NODES and GET NODES
	// ---------------------------------------------
	int get_first_node();

	int index(int input_index);

	
	// PRINT NODES
	// ---------------------------------------------
	void print_nodes();

	// CTCI Problems
	// ---------------------------------------------
	void partition(int part);

	int return_kth_to_last_position(int position);

	void delete_middle_node(Node * remove_node);

	void remove_dups();

	void sum_lists(SinglyLinkedList * list1, SinglyLinkedList * list2);

	// Still needs work
	bool palindrome();

	int loop_detection();
};
#endif