/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 2
Problem 2.1.0
Description of problem: 
	A Unit Load Delivery (ULD) setup and tracking program using a struct to store cargo data. (V1)
*/

#include <iostream>
#include <string>
using namespace std;

// Structure declaration
struct Unit {
	string uldType;		// Container or Pallet
	string abbrev;		// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;		// Container/Pallet type + 5 digit code + airline code
	int aircraft;		// aircraft type (numerical model)
	int weight;			// weight, in pounds, of loaded container or pallet
	string destination;	// three alpha character IATA string
};

// Function prototypes
void input(Unit* uPtr);
void output(Unit* uPtr);

int main() {

	Unit* uPtr;			// Define Unit pointer
	uPtr = new Unit;	// Obtain space for data structure

	cout << " ~ Itty Bitty Airfreight Unit Load Delivery Tracker V1 ~ ";

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
	string uldType;			// Container or Pallet
	string abbrev;			// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;			// Container/Pallet type + 5 digit code + airline code
	int aircraft;			// aircraft type (numerical model)
	int weight;				// weight, in pounds, of loaded container or pallet
	string destination;		// three alpha character IATA string

	string input;			// temporary storage of user input string
	int intInput;

	cout << "\n\n ~ Data Input ~ " << endl;

	// Assign uldType (container/pallet)
	cout << "Container or pallet? Enter 'C' or 'P': ";
	cin >> input;

	// Assign abbrev (type)
	if (input == "C") {

		uldType = "Container";
		cout << " * ULD type set to '" + uldType + "'.";

		cout << "\n\nContainer types:" << endl;
		cout << " 1 AAA \n";
		cout << " 2 AYF \n";
		cout << " 3 AYK \n";
		cout << " 4 AYY \n";
		cout << "Enter '1','2','3', or '4': ";
		cin >> intInput;

		switch (intInput) {
		case 1:
			abbrev = "AAA";
			break;
		case 2:
			abbrev = "AYF";
			break;
		case 3:
			abbrev = "AYK";
			break;
		case 4:
			abbrev = "AYY";
			break;
		default:
			cout << "\nInvalid input." << endl;
		}
	}
	else if (input == "P") {
		uldType = "Pallet";
		cout << " * ULD Type set to '" + uldType + "'";

		cout << "\n\nPallet types:" << endl;
		cout << " 1 PAG \n";
		cout << " 2 PLA \n";
		cout << " 3 PMC \n";
		cout << "Enter '1','2', or '3': ";
		cin >> intInput;

		switch (intInput) {
		case 1:
			abbrev = "PAG";
			break;
		case 2:
			abbrev = "PLA";
			break;
		case 3:
			abbrev = "PMC";
			break;
		default:
			cout << "\nInvalid input." << endl;
		}
	}

	cout << " * Type set to '" + abbrev + "'.";


	// Assign Unit ID
	cout << "\n\nEnter 5 digit unit ID: ";
	cin >> input;
	while (input.length() != 5) {
		cout << "Invalid input. Enter 5 digit unit ID with 5 or less numbers.";
		cout << "\n\nEnter 5 digit unit ID: ";
		cin >> input;
	}
	uldID = input + "IB";
	cout << " * Unit ID is '" + abbrev + uldID + "'.";

	// Assign aircraft
	cout << "\n\nEnter aircraft model: ";
	cin >> aircraft;
	cout << " * Aircraft model is '" << aircraft << "'.";

	// Assign weight
	cout << "\n\nEnter cargo weight: ";
	cin >> weight;
	cout << " * Cargo weight is " << weight << " lbs.";

	// Assign destination
	cout << "\n\nEnter 3-alpha IATA destination (ex. 'SFO'): ";
	cin >> destination;
	cout << " * Cargo destination is '" + destination + "'.";

	// Put data into structure pointer
	uPtr->uldType = uldType;
	uPtr->abbrev = abbrev;
	uPtr->uldID = uldID;
	uPtr->aircraft = aircraft;
	uPtr->weight = weight;
	uPtr->destination = destination;
}

/**
	Prints data in a neat format
	@param *uPtr Structure pointer to Unit structure
*/
void output(Unit* uPtr) {
	cout << "\n\nCargo ID " << uPtr->abbrev << uPtr->uldID << ":" << endl;
	cout << " * Cargo: " << uPtr->uldType << endl;
	cout << " * " << uPtr->uldType << " Type: " << uPtr->abbrev << endl;
	cout << " * Aircraft: " << uPtr->aircraft << endl;
	cout << " * Weight: " << uPtr->weight << endl;
	cout << " * Destination: " << uPtr->destination << endl;
}