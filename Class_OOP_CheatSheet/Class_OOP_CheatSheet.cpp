// Class_OOP_CheatSheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Fighters {
private:
	int Stealth;

public:
	string model;
	int Health;
	int Strength;
	void add_stealth();
	void printinfo();

	Fighters() {
		model = "Default Model";
		Health = 50;
		Strength = 50;
		Stealth = 0;
	}
};

int main()
{
	Fighters F16;
	Fighters* pF16 = &F16;
	pF16->model = "F16_TG";
	pF16->Health = 100;//Heath is updated but Strength is default
	//F16.printinfo(); less perferred way to access to functions in class
	pF16->printinfo();

	Fighters F35;
	Fighters* pF35 = &F35;
	pF35->model = "F35_NG";
	pF35->Health = 100;
	pF35->Strength = 80;
	//pF35->Stealth = 100;//Stealth is a private variable in the Fighters class
	pF35->add_stealth();//public function that have access to private variable Stealth
	pF35->printinfo();

	Fighters* pJ10 = new Fighters; // assigned in Heap instead of stack
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
}

void Fighters::add_stealth() {
	Stealth = Stealth + 10;
}
