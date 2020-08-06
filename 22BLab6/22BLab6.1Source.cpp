/*
Yi Jou (Ruby) Liao
Summer 2020
Lab 6
Problem 6.1.0
Description of problem:
	Unit Load Delivery (ULD) program reads in data from a properly formatted text file and assigns data as cargo for either a 737 or 767 aircraft, following plane specifications.
*/

#include <iostream> // User input/output stream
#include <iomanip>	// Output formatting
#include <string>	// String library
#include <fstream>	// File input/output
#include <vector>	// Vector usage
#include <list>		// Doubly linked list

using namespace std;

const int maxLoad737 = 46000;
const int maxLoad767 = 116000;
const bool DEBUG = false; // DEBUG FLAG - Set to "true" to make debug console messages visible

// Class declaration
class Unit
{
protected:
	string uldType;		// Container or Pallet
	string abbrev;		// Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string uldID;		// Container/Pallet type + 5 digit code + airline code
	int aircraft;		// Aircraft type (numerical model)
	double weight;		// Weight, in pounds, of loaded container or pallet
	string destination; // Three alpha character IATA string
public:
	Unit();																																	// Default constructor
	Unit(const string uldType, const string abbrev, const string uldID, const int aircraft, const double weight, const string destination); // Full constructor
	Unit(const Unit &cargo);																												// Copy constructor
	~Unit();																																// Destructor
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
	virtual bool maxWeight(int) const; // To be overridden
	void output();
};

// Child class for Boeing 737 model aircraft
class Boeing737 : public Unit
{
private:
	int total737;

public:
	Boeing737() {}								  // Derived default constructor
	Boeing737(const Unit &cargo) : Unit(cargo) {} // Derived copy constructor prototype
	Boeing737(const string &uldType, const string &abbrev, const string &uldID, const int &aircraft, const double &weight, const string &destination)
		: Unit(uldType, abbrev, uldID, aircraft, weight, destination) {}
	~Boeing737() {} // Destructor

	bool maxWeight(int) const;
};

// Child class for Boeing 767 model aircraft
class Boeing767 : public Unit
{
private:
	int total767;

public:
	Boeing767() {}								  // Derived default constructor
	Boeing767(const Unit &cargo) : Unit(cargo) {} // Derived copy constructor prototype
	Boeing767(const string &uldType, const string &abbrev, const string &uldID, const int &aircraft, const double &weight, const string &destination)
		: Unit(uldType, abbrev, uldID, aircraft, weight, destination) {}
	~Boeing767() {} // Destructor

	bool maxWeight(int) const;
};

// 737 and 767 load method prototypes
void load737(Boeing737 *&unitPtr, const string uldType, const string abbrev, const string uldID, const int craft, const double weight, const string destination);
void load767(Boeing767 *&unitPtr, const string uldType, const string abbrev, const string uldID, const int craft, const double weight, const string destination);
void input(); // input() moved outside of class

int main()
{
	// cout << " ~ Itty Bitty Airfreight Unit Load Delivery Tracker v6.1 ~ ";
	input();
	return 0;
}

// Default constructor
Unit::Unit()
{
	uldType = "[Type]";
	abbrev = "XXX";
	uldID = "XXX#####IB";
	aircraft = 000;
	weight = 0.0;
	destination = "XXX";
}

// Full constructor (6 parameters)
Unit::Unit(const string type, const string abrv, const string id, const int craft, const double wt, const string dest)
{
	uldType = type;
	abbrev = abrv;
	uldID = id;
	aircraft = craft;
	weight = wt;
	destination = dest;
}

// Copy constructor
Unit::Unit(const Unit &cargo)
{
	uldType = cargo.uldType;
	abbrev = cargo.abbrev;
	uldID = cargo.uldID;
	aircraft = cargo.aircraft;
	weight = cargo.weight;
	destination = cargo.destination;
}

// Destructor
Unit::~Unit()
{
	if (DEBUG)
		cout << "\nUnit destructor called..." << endl;
}

// Mutators
void Unit::setUldType(string type)
{
	uldType = type;
}
void Unit::setAbbrev(string abrv)
{
	abbrev = abrv;
}
void Unit::setUldID(string id)
{
	uldID = id;
}
void Unit::setAircraft(int craft)
{
	aircraft = craft;
}
void Unit::setWeight(double wt)
{
	weight = wt;
}
void Unit::setDest(string dest)
{
	destination = dest;
}

// Accessors
string Unit::getUldType() const
{
	return uldType;
}
string Unit::getAbbrev() const
{
	return abbrev;
}
string Unit::getUldID() const
{
	return uldID;
}
int Unit::getAircraft() const
{
	return aircraft;
}
double Unit::getWeight() const
{
	return weight;
}
string Unit::getDest() const
{
	return destination;
}

//
bool Unit::maxWeight(int total) const
{
	if (DEBUG)
		cout << "[Unused Unit maxWeight()]";
	return false;
}

// Returns true if total weight in 767 aircraft is less than 737 max total weight, 46000 lbs
bool Boeing737::maxWeight(int total) const
{
	if (DEBUG)
		cout << "737 maxWeight check..." << endl;
	return total < maxLoad737;
}

// Returns true if total weight in 767 aircraft is less than 767 max total weight, 116000 lbs
bool Boeing767::maxWeight(int total) const
{
	if (DEBUG)
		cout << "767 maxWeight check..." << endl;
	return total < maxLoad767;
}

/**
	Prints data from class in a neat format
*/
void Unit::output()
{
	cout << "\n\nCargo ID " << uldID << ":" << endl;
	cout << " * Cargo: " << uldType << endl;
	cout << " * " << uldType << " type: " << abbrev << endl;
	cout << " * Aircraft: " << aircraft << endl;
	cout << " * Weight: " << weight << " lbs" << endl;
	cout << " * Destination: " << destination << endl;
}

/**
	Build a Boeing737 unit with parameters passed in
 */
void load737(list<Boeing737> &list737, const string uldType, const string abbrev, const string uldID, const int craft, const double weight, const string destination, int &total737wt)
{
	if (abbrev == "AKE" || abbrev == "APE" || abbrev == "AKC" || abbrev == "AQP" || abbrev == "AQF" || abbrev == "AAP")
	{
		cout << "ERROR: Container type " << abbrev << " incompatible with 737 aircraft. Unit rejected." << endl;
	}
	else if (abbrev == "P1P" || abbrev == "P6P")
	{
		cout << "ERROR: Pallet type " << abbrev << " incompatible with 737 aircraft. Unit rejected." << endl;
	}
	else
	{

		total737wt = total737wt + weight;
		Boeing737 plane(uldType, abbrev, uldID, craft, weight, destination);
		if (plane.maxWeight(total737wt))
		{
			if (DEBUG)
				cout << "Placing in 737 list..." << endl;
			list737.push_back(plane);
		}
		else
		{
			cout << "ERROR: Non-compliant cargo type " << abbrev << "; over max 737 weight." << endl;
			total737wt = total737wt - weight;
		}
	}
}

/**
	Build a Boeing767 unit with parameters passed in
 */
void load767(list<Boeing767> &vect767, const string uldType, const string abbrev, const string uldID, const int craft, const double weight, const string destination, int &total767wt)
{

	if (abbrev == "AKE" || abbrev == "APE" || abbrev == "AKC" || abbrev == "AQP" || abbrev == "AQF" || abbrev == "AAP" || abbrev == "P1P" || abbrev == "P6P")
	{
		total767wt = total767wt + weight;
		Boeing767 plane(uldType, abbrev, uldID, craft, weight, destination);
		if (plane.maxWeight(total767wt))
		{
			if (DEBUG)
				cout << "Placing in 767 list..." << endl;
			vect767.push_back(plane);
		}
		else
		{
			cout << "ERROR: Non-compliant cargo type  " << abbrev << "; over max 767 weight." << endl;
			total767wt = total767wt - weight;
		}
	}
	else
	{
		cout << "ERROR: Unit type " << abbrev << " incompatible with 767 aircraft. Unit rejected." << endl;
	}
}

/**
 	Reads data from properly formatted text file and displays to console.
*/
void input()
{
	// Local variables to store file input
	string type;   // Container or Pallet
	string abbrev; // Container type (AYF, AYK, AAA, AYY) or Pallet type (PAG, PMC, PLA)
	string id;	   // Container/Pallet type + 5 digit code + airline code
	int air;	   // aircraft type (numerical model)
	double wt;	   // weight, in pounds, of loaded container or pallet
	string dest;   // three alpha character IATA string

	int total737wt = 0; // Cumulative cargo weight for 737
	int total767wt = 0; // Cumulative cargo weight for 767
	list<Boeing737> listPtr737;
	list<Boeing767> listPtr767;
	int count = 1; // counter for unit read

	ifstream inputFile;
	inputFile.open("22BLab6\\lab6data.txt"); // Local path for text file containing formatted data; adjust as needed

	// If open fails, send message and exit
	if (!inputFile)
	{
		cerr << "ERROR: Cannot open file." << endl;
		exit(0);
	}

	// Read in file data in order of formatting in text file
	while (inputFile >> type)
	{
		//inputFile >> type;
		inputFile >> abbrev;
		inputFile >> id;
		inputFile >> air;
		inputFile >> wt;
		inputFile >> dest;

		if (DEBUG)
			cout << "\nReading Unit " << count << " data..." << endl;
		count++;

		if (air == 737)
		{
			load737(listPtr737, type, abbrev, id, air, wt, dest, total737wt);
		}
		else if (air == 767)
		{
			load767(listPtr767, type, abbrev, id, air, wt, dest, total767wt);
		}
		else
		{
			cout << "ERROR: Unknown aircraft type." << endl;
		}
	}
	inputFile.close();

	// Output cargo of 737 aircraft list as a table
	cout << "\nLoad out of 737 aircraft IBA0123:" << endl;
	cout << "Type       Abbrev     Identifier     Weight     Destination" << endl;
	list<Boeing737>::iterator it737 = listPtr737.begin();
	while(it737 != listPtr737.end())	// Iterate through each node of 737 list
	{
		cout << setw(11) << left << (*it737).getUldType();
		cout << setw(11) << (*it737).getAbbrev();
		cout << setw(15) << (*it737).getUldID();
		cout << setw(11) << (*it737).getWeight();
		cout << setw(11) << (*it737).getDest() << endl;

		advance(it737, 1);
	}

	// Output cargo of 767 aircraft list as a table
	cout << "\nLoad out of 767 aircraft IBA0456:" << endl;
	cout << "Type       Abbrev     Identifier     Weight     Destination" << endl;
	list<Boeing767>::iterator it767 = listPtr767.begin();
	while(it767 != listPtr767.end())	// Iterate through each node of 767 list
	{
		cout << setw(11) << left << (*it767).getUldType();
		cout << setw(11) << (*it767).getAbbrev();
		cout << setw(15) << (*it767).getUldID();
		cout << setw(11) << (*it767).getWeight();
		cout << setw(11) << (*it767).getDest() << endl;

		advance(it767, 1);
	}

}