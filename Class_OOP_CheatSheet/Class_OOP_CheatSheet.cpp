// Class_OOP_CheatSheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Fighters {
private:
	int Stealth;

protected:
	int Armour;
public:
	string model;
	int Health;
	int Strength;
	void add_stealth();
	void printinfo();

	Fighters()//Default consturctor used when no param is needed when obj is created
	{
		cout << "Object of type Fighters class created!" << endl;
		model = "Default Model";
		Health = 50;
		Strength = 50;
		Stealth = 0;
		Armour = 0;
	}
	

	~Fighters() noexcept{
		cout << "Fighters class destroyed!" << endl;
	}
};

class Fighters_A : public Fighters
{
private:
	
public:
	int Missles;
	void add_weapons();
	void printinfo();//need to overload printinfo() to access to member variables in derived class
	
	Fighters_A()
	{
		cout << "Object of type DERIVED Fighters_A created!" << endl;
		Missles = 0;
		Armour = 30; //protected member variable is accessible by derived class
	}


	~Fighters_A()
	{
		cout << "DERIVED Fighters_A destroyed!" << endl;
	}


};



int main()
{
	{
		Fighters kamikazi;// the class will be automatically destroyed by calling destroyer() once out of scope {}
	}

	Fighters F16;
	Fighters* pF16 = &F16;
	pF16->model = "F16_TG";
	pF16->Health = 100;//Heath is updated but Strength is default
	//F16.printinfo(); less perferred way to access to functions in class
	pF16->printinfo();

	Fighters F35;
	Fighters* pF35 = &F35;
	pF35->model = "F35";
	pF35->Health = 100;
	pF35->Strength = 80;
	//pF35->Stealth = 100;//Stealth is a private variable in the Fighters class
	pF35->add_stealth();//public function that have access to private variable Stealth
	pF35->printinfo();

	Fighters_A F16_A;
	Fighters_A* pF16_A = &F16_A;
	pF16_A->model = "F16_A0";
	pF16_A->add_weapons();
	pF16_A->printinfo();//call the overloaded version of printinfo() to retrieve info related to member variables in derived class

	Fighters* pJ10 = new Fighters; // assigned in Heap instead of stack
	pJ10->model = "J10_0";
	pJ10->add_stealth();
	pJ10->printinfo();


	getchar();
	return 0;
}

void Fighters::printinfo() {
	cout << "\nFighter: " << model << endl;
	cout << "Health is " << Health << endl;
	cout << "Strength is " << Strength << endl;
	cout << "Stealth is " << Stealth << endl;
	cout << "Armour is " << Armour << endl;
}

void Fighters::add_stealth() {
	Stealth = Stealth + 10;
}

void Fighters_A::add_weapons() {
	Missles = Missles + 5;
}

void Fighters_A::printinfo() {
	cout << "\nFighter: " << model << endl;//inherited public
	cout << "Health is " << Health << endl;//inherited public
	cout << "Strength is " << Strength << endl;//inherited public
	//cout << "Stealth is " << Stealth << endl;//Derived class cant access to private members in parent class
	cout << "Missle is " << Missles << endl;//member of derived class
	cout << "Armour is " << Armour << endl;//inherited protected
}