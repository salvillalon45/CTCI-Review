//	******************************************************************************
//
//  SALVADOR VILLALON PRACTICE
//	bubble_sort.cpp
//	An implementation of bubble sort sorting algorithm
//
//	********************************************************************************

#include "stdafx.h"
#include <iostream>
#include <vector>

int main()
{

	int queue[5] = { 5, 1, 4, 8, 2 };
	std::vector<int> que(&queue[0], &queue[0] + 5);

	for (int i = 0; i < que.size(); i++)
	{
		// We need to subtract the size() by 1
		// This is necessary because the third number before the total 
		// size already checks the last value
		// For example, when..
		// j = 0  j < que.size() (which is 5)
		// i = 3 
		// que[3] > que[3+1]
		// 8 > 2
		// [1, 4, 5, 2, 8]
		// ------------------
		// j = 0  j < que.size() (which is 5)
		// i = 4
		// que[4] > que[4+1] -> but there is no fifth value, it most likely 
		//                      give us a garbage value
		// 8 > ####
		// [1, 4, 5, 2, 0]   -> this removes the eight
		// To stop this we need to subract the size by 1. This will prevent 
		// use from checking the last element in the vector 
		for (int j = 0; j < que.size() - 1; j++)
		{
			if (que[j] > que[j + 1])
			{
				std::cout << "WHAT IS THE VALUE:: " << que[j + 1] << std::endl;
				int temp = que[j + 1];
				que[j + 1] = que[j];
				que[j] = temp;
			}
		}
	}

	for (int i = 0; i < que.size(); i++)
	{
		std::cout << "VALUE OF QUE-- " << que[i] << std::endl;
	}

	return 0;
}

