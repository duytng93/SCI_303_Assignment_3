#include "functions.h"

using namespace std;

int main() {
	
	queue<int> testQ, tempQ;					//question 1
	cout << "Original queue: ";					
	for (int i = 0; i < 6; i++) {				
		testQ.push(i);					// insert 0,1,2,3,4,5 to the queue
		cout << i << " ";				// display data to the terminal
	}
	cout << endl;

	move_to_rear(testQ);				//function to move the first element to the end of the queue
	tempQ = testQ;						// temporary queue is use to output queue elements
	cout << "Modified queue: ";
	size_t size = tempQ.size();
	for (int i = 0; i < size ; i++) {	//loop to display queue elements
		cout << tempQ.front() << " ";	//output the first element 
		tempQ.pop();					//then remove the first element in order to output next element in the next loop
	}
	cout << endl << endl<<"==========================================="<<endl<<endl;

	//////////////////////////////////////////////////////////////////////////////////

	bool result;																	//question 2
	result = is_palindrome("abcd 123");												//funtion is_palindrome take a string as a parementer
	cout << "\"abcd 123\" is a palindrome : " << boolalpha << result <<endl;
	result = is_palindrome("");
	cout << "an empty string is a palindrome: " << boolalpha << result << endl;
	result = is_palindrome("z");
	cout << "\"z\" is a palindrome: " << boolalpha << result << endl;
	result = is_palindrome("abba abba");
	cout << "\"abba abba\" is a palindrome: " << boolalpha << result;
	cout << endl << endl << "===========================================" << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////

	map<string, string> stateDataMap;							//question 5

	stateDataMap.insert({ "Nebraska","Lincoln" });				//statements that add the following pairs to stateDataMap:   
	stateDataMap.insert({ "New York","Albany" });				//(Nebraska, Lincoln), (New York, Albany), (Ohio, Columbus),
	stateDataMap.insert({ "Ohio","Columbus" });					//(California, Sacramento), (Massachusetts, Boston), and (Texas, Austin).
	stateDataMap.insert({ "California","Sacramento" });
	stateDataMap.insert({ "Massachusetts","Boston" });
	stateDataMap.insert({ "Texas","Austin" });

	display_mapData(stateDataMap);								//method that outputs the data stored in stateDataMap

	stateDataMap["California"] = "Los Angeles";					//statement that changes the capital of California to Los Angeles 
	cout << endl <<"Capital of California is changed to Los Angeles!" << endl <<endl;
		
	lookupCapital(stateDataMap);								//method that outputs the capitalName using the stateName  
	cout << endl<<endl;											//which will be entered by the user.
	lookupCapital(stateDataMap);
	
	cout << endl<<endl;
	system("pause");
	return 0;
}
