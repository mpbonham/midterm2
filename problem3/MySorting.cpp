#include "MySorting.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


string sortFormat(string a[],size_t size)
{
	string sorted;
	stringstream ss; //stringstream ss to hold sorted format of the array

	for(size_t i = 0; i < size; i++)
	{
		if(i < size - 1)
			ss << a[i] << ",";
		else
			ss << a[i];
	}

	ss >> sorted; //output the stringstream ss into the string sorted
	return sorted; // outputs the string array in the correct format

}

string capitalize(string a)
{
	string test = a;
	size_t size = test.size();
	for (size_t i = 0; i < size; i++)  //iterates through the whole string
	{
		test[i] = toupper(test[i]); //capitalizes each character of the string
	}
	return test;
}

string customSort(string a[], size_t size)
{

	if(a == 0) // if the string array is empty then return an empty string
	{
		return "";
	}


	for(size_t i = 0 ; i < size; i++ )
	{
		a[i] = capitalize(a[i]); // runs through each string in a[] and capitalizes all chars
	}

	string temp;
	int largestIndex;
	string largest;
	int vol = size;

	// Using selection sort here to sort the string arary by length, with tie breakers
	// that are determined by alphabetical order
	for(int i = vol - 1; i > 0; i--)
	{
		largestIndex = 0;
		largest = a[0];
		for(int j = 1; j <= i; j++)
		{
			if(a[j].length() > largest.length() && a[j].length() != largest.length())
			{
				largest = a[j];
				largestIndex = j;
			}
			if(a[j].length() == largest.length()) // if same length
			{
				if(a[j] > largest) // comparison operator between strings
				{
					largest = a[j];
					largestIndex = j;
				}
			}
		}
		temp = a[i];
		a[i] = a[largestIndex];
		a[largestIndex] = temp;
	}


	return sortFormat(a, size); // returns the sorted string array in string format
}
