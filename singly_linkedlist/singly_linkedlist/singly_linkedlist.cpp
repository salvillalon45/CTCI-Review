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
#include <string>
#include <map>
#include <vector>
#include "singly_linkedlist.h"

// The preprocessor examines the code before actual compilation of code begins and 
// resolves all these directives before any code is actually generated by 
// regular statements.
// Why do we need this?
// This is necesarry so the file is not included multiple times, 
#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP

// LinkedList()
// Constructor
// --------------------------------------------------------
SinglyLinkedList::SinglyLinkedList()
{
	// Set head to nullptr
	head = nullptr;
}


// ~SinglyLinkedList()
// Destructor
// --------------------------------------------------------
SinglyLinkedList::~SinglyLinkedList()
{
	std::cout << "DESTRUCTOR" << std::endl;
	for (Node * p = head; p != nullptr;)
	{
		Node * temp_node = p;
		p = p->next;
		delete temp_node;
	}
	/*
		inside the for loop I used to have
			Node * temp_node = p;
			delete temp_node;
		This is wrong because by deleting the temp_node, I am removing 
		the pointer to the next node. 
		this is why before we delete, we must do p = p->next to let us go to
		the next node
	*/
}

// add_to_front(int input)
// This function add a node to the front of the SinglyLinkedList
// Time Complexity: O(1)
// --------------------------------------------------------
void SinglyLinkedList::add_to_front(int input)
{
	// This if statement checks if the SinglyLinkedList does not have any nodes
	// If it does not have any nodes, this means that it is only pointing
	// to nullptr
	if (head == nullptr)
	{
		Node * new_node = new Node(input);
		head = new_node;
	}
	// There is already more than one node in the SinglyLinkedList
	else
	{
		Node * new_node = new Node(input);

		// Hold previous value
		Node * temp_node = head;

		head = new_node;

		// Make new_node->next point to temp
		new_node->next = temp_node;
	}
}


// add_to_end(int input)
// This function adds a node to the end of the SinglyLinkedList
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::add_to_end(int input)
{
	// This if statement checks if the SinglyLinkedList does not have any nodes
	// If it does not have any nodes, this means that it is only pointing
	// to nullptr
	if (head == nullptr)
	{
		Node * new_node = new Node(input);
		head = new_node;
	}
	// If there is already a node in the SinglyLinkedList
	else
	{
		for (Node * current_node = head; current_node != nullptr; current_node = current_node->next)
		{
			if (current_node->next == nullptr)
			{
				Node * new_node = new Node(input);
				current_node->next = new_node;
				// We need a return statement because if we don't then
				// the current_node->next will always be pointing to nullptr
				// and it will create an infinte amount of adding
				return;
			}
		}
	}
}

// remove_front_node()
// This function removes the first node from SinglyLinkedList
// Time Complexity: O(1)
// --------------------------------------------------------
void SinglyLinkedList::remove_front_node()
{
	// If there are no nodes, then we cannot remove them
	if (head == nullptr)
	{
		std::cout << "No Nodes to remove" << std::endl;
		std::cout << "Consider adding nodes first, then remove" << std::endl;
	}
	// There are nodes to remove
	else
	{	
		// Either logic works
		/*Node * current_next_node = head->next;
		delete head;
		head = current_next_node;*/
		Node * temp_node = head;
		head = temp_node->next;
		delete temp_node;
	}

}


// remove_last_node()
// This function removes the first node from SinglyLinkedList
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::remove_last_node()
{
	// There are no nodes to remove
	if (head == nullptr)
	{
		std::cout << "No Nodes to remove" << std::endl;
		std::cout << "Consider adding nodes first, then remove" << std::endl;
	}
	// There are nodes to remove
	else
	{
		for (Node * p = head; p != nullptr; p = p->next)
		{
			if (p->next->next == nullptr)
			{
				delete p->next;
				p->next = nullptr;
			}
		}
	}
}

// get_first_node()
// This function return the info of the first node of the SinglyLinkedList
// Time Complexity: O(1)
// --------------------------------------------------------
int SinglyLinkedList::get_first_node()
{
	// There are no nodes available
	if (head == nullptr)
	{
		std::cout << "There are currently no nodes" << std::endl;
		std::cout << "Consider adding nodes first" << std::endl;
	}
	// There are some nodes
	else
	{
		return head->info;
	}
}


// index(int input_index)
// This function return node based on the given index
// Time Complexity: O(n)
// --------------------------------------------------------
int SinglyLinkedList::index(int input_index)
{
	int i = 0;
	// There are no nodes
	if (head == nullptr)
	{
		std::cout << "There are currently no nodes" << std::endl;
		std::cout << "Consider adding nodes first" << std::endl;
		std::cout << "Your Output is zero, saying that there are no nodes" << std::endl;
		return 0;
	}
	// There are nodes to index
	else
	{
		for (Node * p = head; p != nullptr; p = p->next)
		{
			if (i == input_index)
			{
				return p->info;
			}
			i++;
		}
	}
}


// insert_node_at_position(int data, int position)
// This function looks for inserts a node at a position
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::insert_node_at_position(int data, int position)
{
	int index = 0;
	for (Node * p = head; p != nullptr; p = p->next)
	{
		std::cout << position - 1 << std::endl;
		if (index == position - 1)
		{
			// What was wrong with this approach?
			// ------------------------------------------------------
			/*
			Node * new_node = new Node(data);
			Node * temp_node = p;
			temp_node->next = new_node;
			std::cout << "TEMP_NODE->NEXT :: " << temp_node->next->info << std::endl;
			std::cout << "P->NEXT :: " << p->next->info << std::endl;
			new_node->next = p->next;
			std::cout << "NEW_NODE->NEXT :: " << new_node->next->info << std::endl;
			
				One thing that I learned was that:
				when I do Node * temp_node = p; 
				any change that I do with temp_node, I am also making a change to p
				
					temp_node->next = new_node;
					new_node->next = p->next;

				When I tried doing this in my earlier approach. I was changing temp_node->next to point new_node
				** remember when I change temp_node I also changed p **
				Then when I tried doing new_node->next = p->next, this was saying that I was setting it new_node again
							
				What I was doing wrong was that I was making

				This meant that I had to change new_node->next first. After I change new_node->next, then I
				could change temp_node->next to point to new_node
			*/

			// Correct Approach
			// ------------------------------------------------------
			Node * new_node = new Node(data);
			Node * temp_node = p;
			new_node->next = p->next;
			temp_node->next = new_node;
		}
		index++;
	}
}


// delete_node_at_position(int position)
// This function deletes a node at a given position
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::delete_node_at_position(int position) 
{
	int index = 0;
	for (Node * p = head; p != nullptr; p = p->next) 
	{
		// If they want to remove first node
		if (position == 0) 
		{
			Node * temp_node = head->next;
			delete head;
			head = temp_node;
			// In order for this to worked, I had to include the return;
			// If I did not include it, it will remove all nodes, since the position
			// always be zero
			return;
		}
		// If they want to remove last node
		else if (p->next->next == nullptr)
		{
			delete p->next;
			p->next = nullptr;
		}
		// Remove any node between the first and last node
		else if (position - 1 == index) 
		{
			Node * temp_node = p->next->next;
			delete p->next;
			p->next = temp_node;
			return;
		}
		index++;
	}
}


// remove_dups()
// This function removes duplicates nodes from the SinglyLinkedList
// My attempt
// Time Complexity: O(n^2)
// --------------------------------------------------------
void SinglyLinkedList::remove_dups() 
{
	std::map<int, int> map_num;
	std::map<int, int>::iterator iter;
	
	// Give values to map
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		map_num.insert(std::make_pair(cur->info, 0));
	}

	// Counting the amount of time a node appears
	for (iter = map_num.begin(); iter != map_num.end(); iter++) 
	{
		for (Node * cur = head; cur != nullptr; cur = cur->next) 
		{
			if (iter->first == cur->info) 
			{
				iter->second++;
			}
		}
	}

	// Keep track of which nodes to remove
	std::vector<int> counts = {};
	for (iter = map_num.begin(); iter != map_num.end(); iter++) 
	{
		if (iter->second >= 2) 
		{
			counts.push_back(iter->first);
		}
	}

	// Remove the nodes
	for (int i = 0; i < counts.size(); i++) 
	{
		for (Node * cur = head; cur != nullptr; cur = cur->next) 
		{
			if (cur->next->info == counts[i]) 
			{
				Node * temp_node = cur->next->next;
				delete cur->next;
				cur->next = temp_node;
			}

		}
	}
}



// delete_middle_node()
// This function removes a node between the first and last node
// based on the given node to remove
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::delete_middle_node(Node * remove_node) 
{
	if (remove_node == nullptr || remove_node->next == nullptr) 
	{
		std::cout << "You gave me an incorrect node" << std::endl;
		return;
	}
	else 
	{
		for (Node * cur = head; cur != nullptr; cur = cur->next)
		{
			if (cur->next == remove_node)
			{
				Node * temp_node = cur->next->next;
				delete cur->next;
				cur->next = temp_node;
			}
		}
	}
}


// return_kth_last_position(int position)
// This function returns the kth to last position node based on the
// position given
// Time Complexity: O(n)
// --------------------------------------------------------
int SinglyLinkedList::return_kth_to_last_position(int position) 
{
	// Find the size of the SinglyLinkedList
	int size = 0;
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		size++;
	}

	// Find the Kth position
	int index = 0;
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (size - position == index) 
		{
			return cur->info;
		}
		index++;
	}
}


// partition(int part)
// This function partitions the linked list around a given value x such 
// that all nodes less than x come before all nodes greater than or equal to x
// If x is in the list, that number will appear anywhere on the right
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::partition(int part) 
{
	// Vector to hold numbers from linkedlist
	std::vector<int> numbers = {};

	// Get Value lower than partition
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (cur->info < part) 
		{
			numbers.push_back(cur->info);
		}
	}

	// Get Values bigger than partition
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (cur->info >= part) 
		{
			numbers.push_back(cur->info);
		}
	}

	// Create new Linkedlist
	delete head;
	head = nullptr;
	Node * first_node = new Node(numbers[0]);
	head = first_node;
	for (int i = 0; i < numbers.size(); i++) 
	{
		std::cout << numbers[i] << std::endl;
	}
	
	// Add rest of values from vector numbers to LinkedList
	int index = 1;
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (cur->next == nullptr && index < numbers.size()) 
		{
			Node * new_node = new Node(numbers[index]);
			cur->next = new_node;
		}
		index++;
	}
}


// sum_lists(SinglyLinkedList * list1, SinglyLinkedList * list2)
// This function adds two numbers represented as a linked list and returns
// the sum as a linkedlist
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::sum_lists(SinglyLinkedList * list1, SinglyLinkedList * list2)
{
	// Vectors we will need
	std::vector<int> v1 = {};
	std::vector<int> v2 = {};
	std::vector<int> result = {};

	// Push values to v1
	for (Node * cur = list1->head; cur != nullptr; cur = cur->next) 
	{
		v1.push_back(cur->info);
	}

	// Push value to v2
	for (Node * cur = list2->head; cur != nullptr; cur = cur->next) 
	{
		v2.push_back(cur->info);
	}

	// Reverse the vectors
	std::reverse(v1.begin(), v1.end());
	std::reverse(v2.begin(), v2.end());

	// String to represent the numbers
	std::string v1_str = "";
	std::string v2_str = "";

	// Turn int to string
	for (int i = 0; i < v1.size(); i++) 
	{
		v1_str = v1_str + std::to_string(v1[i]);
	}

	for (int i = 0; i < v2.size(); i++) 
	{
		v2_str = v2_str + std::to_string(v2[i]);
	}

	// Convert string to in
	int v1_num = std::stoi(v1_str);
	int v2_num = std::stoi(v2_str);

	// Add the two numbers to get result
	int result_int = v1_num + v2_num;

	// Turn result to string
	std::string result_str = std::to_string(result_int);

	// Put string result in a vector and change each value to int
	for (int i = 0; i < result_str.size(); i++) 
	{
		int int_result = result_str[i] - '0';
		result.push_back(int_result);
	}

	// Reverse result vector
	std::reverse(result.begin(), result.end());

	// Create result SinglyLinkedList
	delete head;
	head = nullptr;
	
	// Add first node
	Node * first_node = new Node(result[0]);
	head = first_node; 

	int index = 1;
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (cur->next == nullptr && index < result.size()) 
		{
			Node * new_node = new Node(result[index]);
			cur->next = new_node;
		}
		index++;
	}
}

// palindrome()
// This function checks if SinglyLinkedList is a palindrome
// Time Complexity: O(n)
// DOES NOT WORK
// --------------------------------------------------------
bool SinglyLinkedList::palindrome() 
{
	// Temporary node to keep first node in list
	Node * first_node = head;

	// We need to get to last value
	for (Node * cur = head; cur != nullptr; cur = cur->next) 
	{
		if (cur->next == nullptr) 
		{
			if (first_node->info == cur->info) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}


// loop_detection()
// Give a Circular Linked List, this function will return the node at the
// beginning of the loop
// Time Complexity: O(n)
// --------------------------------------------------------
int SinglyLinkedList::loop_detection() 
{
	// Create the hashtable
	std::map<int, int> freq_map;
	std::map<int, int>::iterator iter;

	// Loop over Circular LinkedList
	for (Node * cur = head; cur = cur->next;) 
	{
		iter = freq_map.find(cur->info);

		// Check if cur->info already exists
		if (iter == freq_map.end()) 
		{
			freq_map.insert(std::make_pair(cur->info, 1));
		}
		else 
		{
			// https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
			// Dereference
			iter->second++;
			return cur->info;
		}
	}

}





// print_nodes()
// This function prints the info of all nodes in the SinglyLinkedList
// Time Complexity: O(n)
// --------------------------------------------------------
void SinglyLinkedList::print_nodes()
{
	std::cout << "INSIDE PRINT NODES" << std::endl;
	for (Node * p = head; p != nullptr; p = p->next)
	{
		std::cout << "NODE INFO:: " << p->info << std::endl;
	}
}

#endif