/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len < 1)
		return NULL;
	int * seq = (int *)malloc(sizeof(int) * 6);
	int count = 1, diff = arr[1] - arr[0], diff1;
	seq[0] = 0;
	for (int i = 1; i < len - 1; i++)
	{
		diff1 = arr[i + 1] - arr[i];
		if (diff1 != diff)
		{
			if (count >= 2)
			{
				seq[1] = i;
				break;
			}
			else
			{
				seq[0] = i;
				count = 1;
				diff = diff1;
			}
		}
		else
			count++;
	}
	int index = seq[0] + 1;
	seq[2] = index;
	count = 1;
	diff = arr[index + 1] - arr[index];
	for (int i = index + 1; i < len - 1; i++)
	{
		diff1 = arr[i + 1] - arr[i];
		if (diff1 == diff)
		{
			count++;
			if (i == len - 2)
				seq[3] = i + 1;
		}
		else
		{

			if (count >= 2)
			{
				seq[3] = i;
				if (seq[3] == seq[1])
				{
					seq[2] = seq[3];
					diff = diff1;
					count = 1;
					continue;
				}
				break;
			}
			else
			{
				seq[2] = i;
				count = 1;
				diff = diff1;
			}
		}
	}

	seq[4] = 0;
	int quotient = arr[1] / arr[0];
	count = 1;

	for (int i = 1; i < len - 1; i++)
	{
		if (arr[i + 1] == arr[i] * quotient)
		{
			count++;
			if (i == len - 2)
				seq[5] = i + 1;
		}
		else
		{
			if (count >= 2)
			{
				seq[5] = i;
				break;
			}
			else
			{
				seq[4] = i;
				count = 1;
				quotient = arr[i + 1] / arr[i];
			}
		}


	}


	return seq;
}