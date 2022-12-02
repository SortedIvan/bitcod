#include "Utility.h"
#include <string>
#include <iostream>


int Utility::getStringLen(std::string wordToCheck) {
	int count = 0;

	while (count != '\0') {
		count++;
	}
	return count;
}

std::string Utility::removeLastCharFromString(std::string wordToRemoveFrom) 
{
	if (getStringLen(wordToRemoveFrom) != 1) {
		wordToRemoveFrom.pop_back();
	}
	return wordToRemoveFrom;
}