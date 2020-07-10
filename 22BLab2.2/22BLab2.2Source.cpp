/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 2
Problem 2.2.0
Description of problem:

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Unit {
private:
	string uldType;				// Container or Pallet
	string abbrev;	// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;			// Container/Pallet type + 5 digit code + airline code
	string aircraft;		// aircraft type (numerical model)
	string weight;			// weight, in pounds, of loaded container or pallet
	string destination;		// three alpha character IATA string
public:
	Unit();		// Default constructor
	Unit(string uldType, string abbrev, string uldID, string aircraft, string weight, string destination);	// Full constructor
	~Unit();	// Destructor
	// Mutator (setters)
	void setUldType(string);
	void setAbbrev(string);
	void setUldid(string);
	void setAircraft(string);
	void setWeight(string);
	void setDest(string);
	// Accessor (getters)
	string getUldType() const;
	string setAbbrev() const;
	string setUldid() const;
	string setAircraft() const;
	string setWeight() const;
	string setDest() const;
	// Functions
	input(Unit&);
	output(Unit&);
};

int main() {

	cout << " ~ Itty Bitty Airfreight Unit Load Delivery Tracker ~ ";

	Unit* uPtr = new Unit;
	uPtr->input(*uPtr);
	uPtr->output(*uPtr);
	delete uPtr;
	return 0;
}

// Default constructor
Unit::Unit() {
	uldType = "[Type]";
	abbrev = "XXX";
	uldID = "xxxxxIB";
	aircraft = ""
}


// SETTERS

void Unit::setUldType(string uldType) {
	uldType = uldType;
}

void Unit::setAbbrev(string abbrev) {
	if (uldType == "Container") {
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
	else if (uldType == "Pallet") {
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
}
void Unit::setUldID(string uldID);
void Unit::setAircraft(string aircraft);
void Unit::setWeight(string weight);
void Unit::setDest(string destination);

string Unit::getUldType() const;
string Unit::setAbbrev() const;
string Unit::setUldid() const;
string Unit::setAircraft() const;
string Unit::setWeight() const;
string Unit::setDest() const;

/**
	Reads data from user input and puts into structure
	@param *uPtr Structure pointer to Unit structure
*/
void input(Unit&) {

	string input;			// temporary storage of user input string
	int intInput;

	cout << "\n\n ~ Data Input ~ " << endl;

	// Assign ULD (container/pallet)
	cout << "Container or pallet? Enter 'C' or 'P': ";
	cin >> input;

	// Assign abbrev (type)
	if (input == "C") {

		setUldType("Container");
		uldType = "Container";
		cout << " * ULD set to '" + uldType + "'.";

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
		cout << " * ULD set to '" + uldType + "'";

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
	uldID = abbrev + input + "IB";
	cout << " * Unit ID is '" + uldID + "'.";

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
	cout << "\n\n\n ~ Cargo ID " + uPtr->uldID + " ~ " << endl;
	cout << " * Cargo: " + uPtr->uldType + "\n";
	cout << " * " + uPtr->uldType + " Type: " + uPtr->uldType + "\n";
	cout << " * Aircraft: " + uPtr->aircraft + "\n";
	cout << " * Weight: " + uPtr->weight + "\n";
	cout << " * Destination: " + uPtr->destination + "\n";
}