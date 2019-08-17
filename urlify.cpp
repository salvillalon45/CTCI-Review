//	******************************************************************************
//	
//  SALVADOR VILLALON PRACTICE
//	urlify.cpp
// 
//	Problem 1.3 - URLify
//	Write a method to replace all spaces in a string with "%20"
//	
//	*******************************************************************************


#include "stdafx.h"
#include <iostream>
#include <string>


// ********************************************************************************
// MY ATTEMPT
// This solution has a time complexity of O(n)
// This solution is easy to understand and it is one of the solutions from CTCI
// ********************************************************************************
std::string urlify(std::string input, int len)
{
	// We will return this variables as the answer
	std::string result = "";
	char whitespace = ' ';

	// Some review on strings
	const char * white = " ";
	std::string white_1 = " ";

	// Loop through the len of the string
	for (int i = 0; i < len; i++)
	{
		if (input[i] == whitespace)
		{
			result = result + "%20";
		}
		else
		{
			result = result + input[i];
		}
	}
	return result;
}



int main() 
{
	std::string input = "Mr John Smith     ";
	int len = 13;
	std::cout << "INPUT -- " << input << std::endl;
	std::cout << "Len -- " << len << std::endl;
	std::cout << "URlify string is -- " << urlify(input, len) << std::endl;
	return 0;
}



