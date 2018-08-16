//	******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	main.cpp
//	An implementation of a Stack using a SinglyLInkedList
//
//	********************************************************************************
/*
	I kept getting an error when I was doing an #include stack_1.cpp. The error said
	"error LNK2005 already defined in main.obj

	Why?
	- main.cpp and stack_1.cpp are individually processed by the compiler to produce 
	  two separate object files 

	- Therefore all symbols defined in the stack_1.cpp will also be define in the main.cpp 

	- This will mean double definition!

	- https://stackoverflow.com/questions/15421254/already-defined-in-obj-no-double-inclusions

	Learned
	- Do not include .cpp files. You should include header files
*/


#include "stdafx.h"
#include "stack.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

// The preprocessor examines the code before actual compilation of code begins and 
// resolves all these directives before any code is actually generated by 
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times, 
#ifndef MAIN_CPP
#define MAIN_CPP

int main()
{
	Stack * stk = new Stack();

	// Testing adding to stack
	// --------------------------------------------------------
	stk->push(1);
	stk->push(2);
	stk->push(3);
	stk->push(4);

	// Testing removing from stack
	// --------------------------------------------------------
	std::cout << "POP VALUE:: " << stk->pop() << std::endl;


	// Testing getting first element from stack
	// --------------------------------------------------------
	std::cout << "FIRST VALUE FROM STACK:: " << stk->peek() << std::endl;


	// Testing if stack is empty
	// --------------------------------------------------------
	std::cout << "IS THE STACK EMPTY:: " << stk->is_empty() << std::endl;


	// Print stack 
	// --------------------------------------------------------
	stk->print_stack();

	// Delete stk object
	// --------------------------------------------------------
	delete stk;

	_CrtDumpMemoryLeaks();
	return 0;
}
#endif