#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <queue>
#include <string>
#include <map>
#include <iterator>
#include <iomanip>
#include <iostream>


template<typename T>
void move_to_rear(std::queue<T>& testQ) {               //funtion for question 1
	T item;						//template funtion can't be implemented in cpp file
	item = testQ.front();
	testQ.push(item);
	testQ.pop();
}

bool is_palindrome(std::string str) {			//function for question 2
	bool result;					//return true if the string is a palindrome
	if (str.size() == 0 || str.size() == 1)		//return false if the string is not a palindrome
		result = true;
	else if (str[0] != str[str.length() - 1])
		result = false;
	else
		result = is_palindrome(str.substr(1, str.length() - 2));
	return result;
}

void display_mapData(std::map<std::string, std::string> stateDataMap) {				//function for question 5			
	std::map <std::string, std::string>::iterator itr;					//method that outputs the data stored in stateDataMap
	std::cout << "State Map Data: " << std::endl << std::endl;
	std::cout << "  " << std::left << std::setw(15) << "State" << "Capital" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	for (itr = stateDataMap.begin(); itr != stateDataMap.end(); ++itr) {
		std::cout << "  " << std::left << std::setw(15) << itr->first << itr->second
			<< std::endl;
	}
}

void lookupCapital(std::map<std::string, std::string> stateDataMap) {				//function for question 5	
	std::string stateName;									//method that outputs the capitalName using the stateName 
	std::cout << "Enter a State name: ";							//which will be entered by the user. 
	getline(std::cin, stateName);					//get user input

	stateName[0] = toupper(stateName[0]);				//format user input to have the first letter of every word capitalized
	for (int i = 1; i < stateName.length(); ++i) {
		stateName[i] = tolower(stateName[i]);
		if (stateName[i] == ' ') {
			stateName[i + 1] = toupper(stateName[i + 1]);
			i = i + 2;
		}
	}

	bool is_found = false;
	std::map <std::string, std::string>::iterator itr;
	for (itr = stateDataMap.begin(); itr != stateDataMap.end(); ++itr) {		//loop to scan through stateDataMap element to find the match

		if (stateName == itr->first)
		{
			is_found = true;
			std::cout << itr->second << " is the capital of " << itr->first;
		}
	}
	if (is_found == false)								//output a message if no match found
		std::cout << stateName << " is not found in the State Data Map";
}

#endif
