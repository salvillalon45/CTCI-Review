//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	singly_linkedlist.cpp
// 
//	An implementation of a Singly Linkedlist with a head pointer
//	
//	********************************************************************************

#include "stdafx.h"
#include <iostream>
#include "singly_linkedlist.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  



int main()
{
	SinglyLinkedList * list = new SinglyLinkedList();
	SinglyLinkedList * list1 = new SinglyLinkedList();
	SinglyLinkedList * list2 = new SinglyLinkedList();
	int input_index = 2;

	// Testing adding nodes
	// --------------------------------------------------------
	//list->insert_node_at_position(5, input_index);
	list->add_to_end(1);
	list->add_to_end(6);
	list->add_to_end(4);
	list->add_to_end(6);
	list->add_to_end(1);
	//list1->add_to_end(9);
	//list1->add_to_end(7);
	//list1->add_to_end(8);

	//list2->add_to_end(6);
	//list2->add_to_end(8);
	//list2->add_to_end(5);
	

	list->print_nodes();

	// Testing removing nodes
	// --------------------------------------------------------
	//list->remove_front_node();
	

	// Indexing nodes
	// --------------------------------------------------------
	/*std::cout << "INDEX :: " << input_index << "IS NODE -- " << list->index(input_index) << std::endl;
	std::cout << list->get_first_node() << std::endl;*/


	// CTCI Problems
	// --------------------------------------------------------
	/*std::cout << input_index << "th to last node is:: " << list->return_kth_to_last_position(input_index) << std::endl;
	list->partition(5);
	list->remove_dups();
	list->delete_node_at_position(input_index); */
	//list->sum_lists(list1, list2);
	//std::cout << "Is the SinglyLinkedList a Palindrome? :: " << list->palindrome() << std::endl;


	// Printing nodes
	// --------------------------------------------------------
	list->print_nodes();


	delete list;
	delete list1;
	delete list2;
	_CrtDumpMemoryLeaks();
	return 0;
}