/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 1
Problem 1.1.0
Description of problem:
Program takes in user message to either encrypt or decrypt following a letter substitution
	cipher that replaces each letter with the 13th letter after it
*/

#include <iostream>
#include <string>
using namespace std;

void menu();
string input();
void output(string input);
string rot13(string input);

int main() {
	string menuChoice; // Store user input menu choice
	string* message = nullptr; // Dynamically allocate user message memory

	cout << " ~ Simple Cryptography ~ ";

	do {

		menu();
		getline(cin, menuChoice);
		message = new string;

		if (menuChoice == "1") {
			cout << "\n ~ Encrypt ~ \n";
			*message = input();
			output(rot13(*message));

		}
		else if (menuChoice == "2") {
			cout << "\n ~ Decrypt ~ \n";
			*message = input();
			output(rot13(*message));

		}

		delete message;	// Deallocate user message memory
		getline(cin, menuChoice);

	} while (menuChoice != "3" && menuChoice != "N" && menuChoice != "n");

	cout << "\n\n";
	return 0;
}

// Displays menu options
void menu() {
	cout << "\n\nPlease choose from the following menu options:\n";
	cout << " 1 Encrypt message\n";
	cout << " 2 Decrypt message\n";
	cout << " 3 Quit \n";
	cout << "Choose an option: ";
}

/**
	Receives user inputted message
	@return The message that user inputted as a string
*/
string input() {
	string input;
	cout << "Input message: ";
	getline(cin, input);
	return input;
}

/**
	Displays processed message to console
	@param output The message to be displayed to user
*/
void output(string output) {
	cout << "Output message: " << output << "\n";
	cout << "\nRepeat? Y or N: ";
}

/**
	Applies substitution cypher to replace each letter with the 13th letter after it
	@param input Message to apply cypher to
	@return String with substitution cypher applied
*/
string rot13(string input) {
	int inputSize = input.size();
	int index = 0;
	while (index != inputSize)
	{
		if (input[index] >= 97 && input[index] <= 109)
			input[index] = input[index] + 13;
		else if (input[index] >= 110 && input[index] <= 122)
			input[index] = input[index] - 13;
		else if (input[index] >= 65 && input[index] <= 77)
			input[index] = input[index] + 13;
		else if (input[index] >= 78 && input[index] <= 90)
			input[index] = input[index] - 13;
		index++;
	}
	return input;
}