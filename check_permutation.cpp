//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	check_permutation.cpp
// 
//	Problem 1.2 - Check Permutation
//	Given two strings, write a method to decide if one is the permutation of the other
//	
//	********************************************************************************


#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>


// ********************************************************************************
// MY ATTEMPT
// This solution has a time complexity of O(n)
// This solution is easy to understand and it is one of the solutions from CTCI
// ********************************************************************************
bool check_permutation(std::string input1, std::string input2) 
{
	if (input1.size() != input2.size()) 
	{
		// Not Permutation this both string must be the same size
		return false;
	}
	else 
	{
		// Sort input1
		std::sort(input1.begin(), input1.end());

		// Sort input2
		std::sort(input2.begin(), input2.end());

		std::cout << "After sort -- " << input1 << std::endl;
		std::cout << "Afte sort -- " << input2 << std::endl;

		// Checking if input2 exists in the map
		int index = 0;
		for (int i = 0; input1.size(); i++) 
		{
			if (input1[i] != input2[index]) 
			{
				// Not a permutation since the characters are not equal to each other
				return false;
			}
			index++;
		}
    	// This is a permutation
		return true;
	}
}


// ********************************************************************************
// CTCI Solution
// This solution has a time complexity of O(n). Where n is the length of
// the string. The space complexity is O(1). 
// You could also argue the time complexity is O(1) since you will never iterate
// through a string that is more than 128 characters
// 
// ********************************************************************************
bool check_permutation_ctci(std::string input1, std::string input2) 
{
	if (input1.size() != input2.size()) 
	{
		// Not a permutation since they are not the same size
		return false;
	}
	else 
	{
		// Looping through the input1 and giving an incrementing each position of array
		int letters[128] = {};
		for (int i = 0; i < input1.size(); i++) 
		{
			// Incrementing the position
			letters[input1[i]]++;
		}

		// Looping through input2. If one of the positions does not decrease their value to zero then it is not 
		// a permutation
		for (int i = 0; i < input2.size(); i++) 
		{
			letters[input2[i]]--;
			if (letters[input2[i]] < 0) 
			{
				// Not a permutation
				return false;
			}
		}
		// All values are zeros, so it is a permutation
		return true;
	}
}

//int main() 
//{
//	std::string input1 = "ABC";
//	std::string input2 = "BCA";
//	std::cout << "input1 -- " << input1 << std::endl;
//	std::cout << "input2 -- " << input2 << std::endl;
//	//std::cout << "IS IT A PERMUTATION? -- " << check_permutation(input1, input2) << std::endl;
//	std::cout << "IS IT A PERMUTATION? -- " << check_permutation_ctci(input1, input2) << std::endl;
//	return 0;
//}


