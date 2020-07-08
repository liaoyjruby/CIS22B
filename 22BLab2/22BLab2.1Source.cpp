/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 2
Problem 2.1.0
Description of problem:

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure declaration
struct Unit {
	string uld;				// Container or Pallet
	string abbreviation;	// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldid;			// Container/Pallet type + 5 digit code + airline code
	string aircraft;		// aircraft type (numerical model)
	string weight;			// weight, in pounds, of loaded container or pallet
	string destination;		// three alpha character IATA string
};

// Function prototypes
void input(Unit* uPtr);
void output(Unit* uPtr);


int main() {
	/*
	* Uses new to obtain space for the data structure
	* Calls the other two functions
	* Deletes the space obtained using new
	*/

	Unit* uPtr;			// Define Unit pointer
	uPtr = new Unit;	// Obtain space for data structure

	cout << " ~ Itty Bitty Airfreight Unit Load Delivery Tracker ~ ";

	input(uPtr);		// Call input to get data
	output(uPtr);		// Call output to print data
	delete uPtr;		// Delete space obtained with new

	return 0;
}

/**
	Reads data from user input and puts into structure
	@param *uPtr Structure pointer to Unit structure
*/
void input(Unit* uPtr) {

	// Local variables
	string uld;				// Container or Pallet
	string abbreviation;	// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldid;			// Container/Pallet type + 5 digit code + airline code
	string aircraft;			// aircraft type (numerical model)
	string weight;				// weight, in pounds, of loaded container or pallet
	string destination;		// three alpha character IATA string

	string input;			// temporary storage of user input string
	int intInput;

	cout << "\n\n ~ Data Input ~ " << endl;

	// Assign ULD (container/pallet)
	cout << "Container or pallet? Enter 'C' or 'P': ";
	cin >> input;

	/*
	while (strcmp(input, "C") == 0 || strcmp(input, "P") == 0) { // Input validation
		cout << "Invalid input. Enter either 'C' or 'P': ";
		cin >> input;
	}
	*/

	// Assign abbreviation (type)
	if (input == "C") {

		uld = "Container";
		cout << " * ULD set to '" + uld + "'.";

		cout << "\n\nContainer types:" << endl;
		cout << " 1 AAA \n";
		cout << " 2 AYF \n";
		cout << " 3 AYK \n";
		cout << " 4 AYY \n";
		cout << "Enter '1','2','3', or '4': ";
		cin >> intInput;

		switch (intInput) {
		case 1:
			abbreviation = "AAA";
			break;
		case 2:
			abbreviation = "AYF";
			break;
		case 3:
			abbreviation = "AYK";
			break;
		case 4:
			abbreviation = "AYY";
			break;
		default:
			cout << "\nInvalid input." << endl;
		}
	}
	else if (input == "P") {
		uld = "Pallet";
		cout << " * ULD set to '" + uld + "'";

		cout << "\n\nPallet types:" << endl;
		cout << " 1 PAG \n";
		cout << " 2 PLA \n";
		cout << " 3 PMC \n";
		cout << "Enter '1','2', or '3': ";
		cin >> intInput;

		switch (intInput) {
		case 1:
			abbreviation = "PAG";
			break;
		case 2:
			abbreviation = "PLA";
			break;
		case 3:
			abbreviation = "PMC";
			break;
		default:
			cout << "\nInvalid input." << endl;
		}
	}

	cout << " * Type set to '" + abbreviation + "'.";


	// Assign Unit ID
	cout << "\n\nEnter 5 digit unit ID: ";
	cin >> input;
	while (input.length() != 5) {
		cout << "Invalid input. Enter 5 digit unit ID with 5 or less numbers.";
		cout << "\n\nEnter 5 digit unit ID: ";
		cin >> input;
	}
	uldid = abbreviation + input + "IB";
	cout << " * Unit ID is '" + uldid + "'.";

	// Assign aircraft
	cout << "\n\nEnter aircraft model: ";
	cin >> aircraft;
	//getline(cin, aircraft);
	cout << " * Aircraft model is '" + aircraft + "'.";

	// Assign weight
	cout << "\n\nEnter cargo weight: ";
	cin >> weight;
	//getline(cin, weight);
	cout << " * Cargo weight is " + weight + " lbs.";

	// Assign destination
	cout << "\n\nEnter 3 alpha IATA destination (ex. 'SFO'): ";
	cin >> destination;
	//getline(cin, destination);
	cout << " * Cargo destination is '" + destination + "'.";

	// Put data into structure pointer
	uPtr->uld = uld;
	uPtr->abbreviation = abbreviation;
	uPtr->uldid = uldid;
	uPtr->aircraft = aircraft;
	uPtr->weight = weight;
	uPtr->destination = destination;

}

/**
	Prints data in a neat format
	@param *uPtr Structure pointer to Unit structure
*/
void output(Unit* uPtr) {
	cout << "\n\n\n ~ Cargo ID " + uPtr->uldid + " ~ " << endl;
	cout << " * Cargo: " + uPtr->uld + "\n";
	cout << " * " + uPtr->uld + " Type: " + uPtr->uld + "\n";
	cout << " * Aircraft: " + uPtr->aircraft + "\n";
	cout << " * Weight: " + uPtr->weight + "\n";
	cout << " * Destination: " + uPtr->destination + "\n";
}