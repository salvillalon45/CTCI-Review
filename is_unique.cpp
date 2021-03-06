//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	is_unique.cpp
// 
//	Problem 1.1 - Is Unique
//	Implement an algorithm to determine if a string has all unique characters. What if 
//	you cannot use additional data structures
//	
//	********************************************************************************



#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

//	********************************************************************************
// MY ATTEMPT
// This solution has a time complexity of O(a*b)
// This happend because I did a nested loop where I was iterating through
// each key of my map and comparing each key to each character of the string
// This caused it to have such as high complexity
//	********************************************************************************
bool is_unique(std::string input)
{
	std::cout << input.size() << std::endl;
	std::cout << input[0] + 1 << std::endl;

	if (input == "")
	{
		return true;
	}

	std::map<char, int> str_map;

	// Insert each character of input into str_map
	for (int i = 0; i < input.size(); i++)
	{
		str_map.insert(std::pair<char, int>(input[i], 0));
	}

	// In charge of counting amount of times it appears 
	std::map<char, int>::iterator iter;
	for (iter = str_map.begin(); iter != str_map.end(); iter++)
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (iter->first == input[i])
			{
				iter->second++;
			}
		}
	}

	// Check if input is unique
	for (iter = str_map.begin(); iter != str_map.end(); iter++)
	{
		if (iter->second >= 2)
		{
			// Not Unique
			return false;
		}
	}
	// It is unique
	return true;
}


//	********************************************************************************
// CTCI Solution
// This solution has a time complexity of O(n). Where n is the length of
// the string. The space complexity is O(1). 
// You could also argue the time complexity is O(1) since you will never iterate
//	through a string that is more than 128 characters
// 
//	********************************************************************************
bool is_unique_ctci(std::string input) 
{
	if (input.size() > 128) 
	{
		return false;
	}

	//bool char_set = new bool[128];
	bool char_set[128] = {};

	for (int i = 0; i < input.size(); i++) 
	{
		int val = input[i];
		std::cout << "VAL::" << val << std::endl;
		if (char_set[val] == true) 
		{
			// Not Unique
			return false;
		}
		// Give position in array the value of true, if this is the first time you
		// find it in the string
		char_set[val] = true;
	}
	// It is unique
	return true;
}





//int main()
//{
//	std::string input = "hello";
//	std::cout << "IS THIS INPUT UNIQUE? -- " << is_unique(input) << std::endl;
//	std::cout << "IS THIS INPUT UNIQUE? -- " << is_unique_ctci(input) << std::endl;
//	return 0;
//}




