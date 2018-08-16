//	******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	main.cpp
//
//	An implementation of a queue using a SinglyLinked List with head and tail
//
//	********************************************************************************


#include "stdafx.h"
#include <iostream>
#include "queue.h"

int main() 
{
	Queue * que = new Queue();

	// Testing adding to Queue
	// --------------------------------------------------------
	que->add(1);
	que->add(2);
	que->add(3);
	que->add(4);

	// Testing removing from Queue
	// --------------------------------------------------------
	std::cout << "REMOVE VALUE:: " << que->remove() << std::endl;


	// Testing getting first element from Queue
	// --------------------------------------------------------
	std::cout << "FIRST VALUE FROM STACK:: " << que->peek() << std::endl;


	// Testing if Queue is empty
	// --------------------------------------------------------
	std::cout << "IS THE QUEUE EMPTY:: " << que->is_empty() << std::endl;


	// Print Queue  
	// --------------------------------------------------------
	que->print_queue();


	// Delete Queue object
	// --------------------------------------------------------
	delete que;

	_CrtDumpMemoryLeaks();

	return 0;
}