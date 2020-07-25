/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 4
Problem 4.2.0
Description of problem:
	Unit Load Delivery (ULD) program reads in data from a properly formatted text file. Adjust path of text file in input() as necessary
*/

#include <iostream>			// User input/output stream
#include <string>			// String library
#include <fstream>			// File input/output
using namespace std;

// Class declaration
class Unit {
private:
	string uldType;			// Container or Pallet
	string abbrev;			// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;			// Container/Pallet type + 5 digit code + airline code
	int aircraft;			// Aircraft type (numerical model)
	int weight;				// Weight, in pounds, of loaded container or pallet
	string destination;		// Three alpha character IATA string
public:
	Unit();		// Default constructor
	Unit(string uldType, string abbrev, string uldID, int aircraft, double weight, string destination);	// Full constructor
	Unit(const Unit &cargo); //Copy constructor
	~Unit();	// Destructor
	// Mutator (setters)
	void setUldType(string);
	void setAbbrev(string);
	void setUldID(string);
	void setAircraft(int);
	void setWeight(double);
	void setDest(string);
	// Accessor (getters)
	string getUldType() const;
	string getAbbrev() const;
	string getUldID() const;
	int getAircraft() const;
	double getWeight() const;
	string getDest() const;
	// Functions
	void output(Unit&);
	
	/*  Unnecessary functions for this lab
	friend double kgToLb(double &); // Friend function for converting kilogram weight to pound
	// Overloaded operator
	friend bool operator==(const Unit &lhs, const Unit &rhs);
	*/
};
// double kgToLb(double &); // kgToLb() prototype
// bool operator==(const Unit &lhs, const Unit &rhs); // Overloaded equality operator (==) prototype

void input(); // input() moved outside of class

int main() {
	// cout << " ~ Itty Bitty Airfreight Unit Load Delivery Tracker v4.2 ~ ";
	input();
	return 0;
}

// Default constructor
Unit::Unit() {
	uldType = "[Type]";
	abbrev = "XXX";
	uldID = "XXX#####IB";
	aircraft = 000;
	weight = 0.0;
	destination = "XXX";
}

// Full constructor (6 parameters)
Unit::Unit(const string type, const string abrv, const string id, const int craft, const double wt, const string dest){
	uldType = type;
	abbrev = abrv;
	uldID = id;
	aircraft = craft;
	weight = wt;
	destination = dest;
}

// Copy constructor
Unit::Unit(const Unit &cargo){
	uldType = cargo.uldType;
	abbrev = cargo.abbrev;
	uldID = cargo.uldID;
	aircraft = cargo.aircraft;
	weight = cargo.aircraft;
	destination = cargo.destination;
}

// Destructor
Unit::~Unit()
{
	cout << "\nUnit destructor called." << endl;
}

// Mutators
void Unit::setUldType(string type) {
	uldType = type;
}
void Unit::setAbbrev(string abrv) {
	abbrev = abrv;
}
void Unit::setUldID(string id){
	uldID = id;
}
void Unit::setAircraft(int craft){
	aircraft = craft;
}
void Unit::setWeight(double wt){ // kgToLb() incorporated
	/*
	char ans;

	cout << "Kilograms or pounds? Enter 'K' or 'P': ";
	cin >> ans;
	if (ans == 'K' || ans == 'k'){
		wt = kgToLb(wt);
	}
	*/
	weight = wt;
}
void Unit::setDest(string dest){
	destination = dest;
}

// Accessors
string Unit::getUldType() const{
	return uldType;
}
string Unit::getAbbrev() const{
	return abbrev;
}
string Unit::getUldID() const{
	return uldID;
}
int Unit::getAircraft() const{
	return aircraft;
}
double Unit::getWeight() const{
	return weight;
}
string Unit::getDest() const{
	return destination;
}

/** Old input()
	Reads data from user input and puts into class
	@param Unit& Pointer to Unit object

void Unit::input(Unit&) {

	// Local variables to store user input
	string uldType;			// Container or Pallet
	string abbrev;			// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;			// Container/Pallet type + 5 digit code + airline code
	int aircraft;			// aircraft type (numerical model)
	double weight;			// weight, in pounds, of loaded container or pallet
	string destination;		// three alpha character IATA string

	string input;			// Storage of user input string
	int intInput;			// Storage of user input integer

	cout << "\n\n ~ Data Input ~ " << endl;

	// Assign ULD (container/pallet)
	cout << "Container or pallet? Enter 'C' or 'P': ";
	cin >> input;

	// Assign abbreviation (type)
	if (input == "C" || input == "c") { // Container specific submenu

		setUldType("Container");
		uldType = "Container";
		cout << " * ULD set to '" + uldType + "'.";

		cout << "\n\nContainer type:" << endl;
		cout << " 1 AAA \n";
		cout << " 2 ABB \n";
		cout << " 3 AYF \n";
		cout << " 4 AYK \n";
		cout << " 5 AYY \n";
		cout << "Enter option number: ";
		cin >> intInput;

		switch (intInput) {
		case 1:
			abbrev = "AAA";
			break;
		case 2:
			abbrev = "ABB";
			break;
		case 3:
			abbrev = "AYF";
			break;
		case 4:
			abbrev = "AYK";
			break;
		case 5:
			abbrev = "AYY";
			break;
		default:
			cout << "\nInvalid input." << endl;
		}
	}
	else if (input == "P" || input == "p") { // Pallet specific submenu
		uldType = "Pallet";
		cout << " * ULD set to '" + uldType + "'";

		cout << "\n\nPallet type:" << endl;
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
	cout << "\n\nEnter 5-digit unit ID: ";
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
	cout << " * Aircraft model is '" << aircraft << "'.";

	// Assign weight; kg/lbs option incorporated
	cout << "\n\nEnter cargo weight: ";
	cin >> weight;
	setWeight(weight);

	cout << " * Cargo weight is " << getWeight() << " lbs.";
	

	// Assign destination
	cout << "\n\nEnter 3-alpha IATA destination (ex. 'SFO'): ";
	cin >> destination;
	cout << " * Cargo destination is '" << destination << "'.";

	// Put data into structure pointer
	setUldType(uldType);
	setAbbrev(abbrev);
	setUldID(uldID);
	setAircraft(aircraft);
	setDest(destination);

}
*/

/**
	Prints data from class in a neat format
	@param Unit& Pointer to Unit structure
*/
void Unit::output(Unit &) {
	cout << "\n\nCargo ID " << uldID << ":" << endl;
	cout << " * Cargo: " << uldType << endl;
	cout << " * " << uldType << " type: " << abbrev << endl;
	cout << " * Aircraft: " << aircraft << endl;
	cout << " * Weight: " << weight << " lbs" << endl;
	cout << " * Destination: " << destination << endl;
}

/** Unnecessary for this lab
/**
	Converts kilogram to pound value
	@param &wt Pointer to a double representing kilograms
	@return Pound, as a double

double kgToLb(double &wt){
	wt = wt * 2.2;
	return wt;
}

/**
	Overloaded equality operator for Unit objects. Equal if abbrev and uldID are the same.
	@param &lhs Pointer to the left hand side object in comparison
	@param &rhs Pointer to the right hand side object in comparison
	@return bool; true if abbrev & uldID are the same the between two objects

bool operator==(const Unit &lhs, const Unit &rhs){
	return (lhs.getAbbrev() == rhs.getAbbrev() && lhs.getUldID() == rhs.getUldID());
}
*/

/**
 	Reads data from properly formatted text file and displays to console.
*/
void input(){
	// Local variables to store file input
	string type;			// Container or Pallet
	string abbrev;			// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string id;				// Container/Pallet type + 5 digit code + airline code
	int air;				// aircraft type (numerical model)
	double wt;				// weight, in pounds, of loaded container or pallet
	string dest;			// three alpha character IATA string

	ifstream inputFile;
	inputFile.open("22BLab4\\cardata4.txt"); // Local path for text file containing data; adjust as needed

	// If open fails, send message and exit
	if(!inputFile){
		cerr << "Error opening file." << endl;
		exit(0);
	}

	// Read in file data in order of formatting in text file
	while (inputFile >> type){
		//inputFile >> type;
		inputFile >> abbrev;
		inputFile >> id;
		inputFile >> air;
		inputFile >> wt;
		inputFile >> dest;

		Unit temp(type, abbrev, id, air, wt, dest); // Temporary Unit with data read in from text file
		temp.output(temp);
	}
	inputFile.close();
}