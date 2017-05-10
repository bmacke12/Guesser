//-------------------------------------
// Blake Macke
// guesser.cpp
// 3/11/17
// Original C++ code of Guesser
//-------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

void guess(int target, int max)
{
	int count = 0;
	int guess = 0;
	vector<int> incorrect;
	srand(time(0));
	
	REGUESS: // The goto target for if guess has been generated previously.
	guess = (rand() % max + 1); // Generate random number between 1 and max.
	
	while (guess != target) // While guess does not equal target, do the following.
	{
		for (int i = 0; i < (int)incorrect.size(); i++ ) // For loop to check if guess has been generated previously, since the program is tracking without repeats.
		{
			if (incorrect[i] == guess) // If it has been generated previously, go to REGUESS.
				goto REGUESS; 
		}
		
		incorrect.push_back(guess);	// If it wasn't generated previously, add guess to the incorrect vector, which stores all guesses made.
		
		guess = (rand() % max + 1);	// Generate next random number.
	}
	
	incorrect.push_back(guess); // Add the correct guess to the incorrect vector.
	
	cout << endl << "It took " << incorrect.size() << " tries to correctly generate " << target << "." << endl;
	cout << "The last guess had a " << (((double)incorrect.size() / (double)max) * 100) << "% chance to be guessed correctly" << endl << endl;
	
	cout << "Here's all of the guesses:" << endl << endl;
	
	for (int j = 0; j < incorrect.size(); j++) // Prints the values of the incorrect vector. 
	{
		cout << setw(5) << incorrect[j] << " "; // setw(5) adds margin to dislay the numbers in an orderly fashion.
		
		if (( j + 1) % 8 == 0) // After 8 numbers printed, a newline is added.
			cout << endl;
	}
	
	cout << endl << endl;
}

int main()
{
	char answer;
	int target, max;
	
	cout << "Welcome to Guesser." << endl << endl;
	cout << "Pick a number and a maximum, and see how many tries it takes to randomly generate the target number without repeats." << endl << endl;
	
	cout << "Type 'Y' to begin: ";
	cin >> answer;
	
	while (toupper(answer) == 'Y')
	{
		cout << endl << "Type a number as the target to be guessed: ";
		cin >> target;
		
		while (target < 1) // Target must be greater than 0.
		{
			cout << "Must be larger than 0. Re-Enter: ";
			cin >> target;
			cout << endl;
		}
		
		cout << "Type a number as the maximum to generate: ";
		cin >> max;
		
		while (max < target) // Max must be larger than target.
		{
			cout << "Must be larger than target. Re-enter: ";
			cin >> max;
			cout << endl;
		}
		
		guess(target, max); // Call the guess function.
		
		cout << "Again? ";
		
		cin >> answer;
	}
	cout << "Goodbye!";
}
