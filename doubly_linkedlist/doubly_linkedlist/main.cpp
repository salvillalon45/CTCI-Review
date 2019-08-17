//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	main.cpp
// 
//	An implementation of a Doubly Linkedlist with a head and tail pointer
//	
//	********************************************************************************

#include "stdafx.h"
#include <iostream>
#include "doubly_linkedlist.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  



int main()
{
	DoublyLinkedList * obj = new DoublyLinkedList();
	int input_index = 1;

	// Testing adding nodes
	// --------------------------------------------------------
	obj->add_to_front(1);
	obj->add_to_front(2);
	obj->add_to_front(3);
	obj->add_to_end(4);


	// Testing removing nodes
	// --------------------------------------------------------
	//obj->remove_front();
	//obj->remove_last();
	

	// Indexing nodes
	// --------------------------------------------------------
	obj->insert_node_at_position(100, input_index);
	//std::cout << "INDEX AT NODE:: " << input_index << " is:: " << obj->index(input_index) << std::endl;
	//std::cout << "GET THE FIRST NODE:: " << obj->get_first_node() << std::endl;


	// Printing nodes
	// --------------------------------------------------------
	obj->print_nodes();

	delete obj;
	_CrtDumpMemoryLeaks();
	return 0;
}