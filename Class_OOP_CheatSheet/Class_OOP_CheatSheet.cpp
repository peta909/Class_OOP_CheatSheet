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
	virtual void printinfo();//The idea is, virtual functions are called according to the type of object pointed or referred, not according to the type of pointer or reference.In other words, virtual functions are resolved late, at runtime.
	//virtual void add_feature()=0;//PURE VIRTUAL function. Forces derive class to implement it. A Class with any PURE virtual function will become an abstract class. Objects cannot be created from abstract class.
//protected: protected constructor also turn class into abstract class
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

class Fighters_A : virtual public Fighters //virtual keyword added to prevent multiple instantiation of parent class "Fighters"
{
private:
	
public:
	int Missles;
	void add_weapons();
	void printinfo();//need to overload printinfo() to access to member variables in derived class
	//void add_feature()//implementation of Pure virtual function done in derive class
	//{
	//	cout << "V Func" << endl;
	//}
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

class Fighters_B : virtual public Fighters //virtual keyword added to prevent multiple instantiation of parent class "Fighters"
	{
public:
	int fueltank;
	void add_fueltank();
	Fighters_B()
	{
		cout << "Object of type DERIVED Fighters_B created!" << endl;
		Armour = 10; //protected member variable is accessible by derived class
		fueltank = 0;
	}


	~Fighters_B()
	{
		cout << "DERIVED Fighters_B destroyed!" << endl;
	}



};

class Fighters_AB : public Fighters_A, public Fighters_B {//Class with multiple parents
public:
	Fighters_AB()
	{
		cout << "Object of type DERIVED Fighters_AB created!" << endl;
		Armour = 10; //protected member variable is accessible by derived class
	}


	~Fighters_AB()
	{
		cout << "DERIVED Fighters_AB destroyed!" << endl;
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

	Fighters_B F16_B;
	Fighters_B* pF16_B = &F16_B;
	pF16_B->model = "F16_B0";
	pF16_B->add_fueltank();
	pF16_B->printinfo();//call the overloaded version of printinfo() to retrieve info related to member variables in derived class

	Fighters_AB F16_AB;
	Fighters_AB* pF16_AB = &F16_AB;
	pF16_AB->model = "F16_AB0";
	pF16_AB->add_weapons();
	pF16_AB->add_fueltank();
	pF16_AB->printinfo();//call the overloaded version of printinfo() to retrieve info related to member variables in derived class


	Fighters* pJ10 = new Fighters; // assigned in Heap instead of stack
	pJ10->model = "J10_0";
	pJ10->add_stealth();
	pJ10->printinfo();

	//C++ polymorphism means that a call to a member function will cause a different function to be 
	//executed depending on the type of object that invokes the function.
	Fighters* pJ21 = new Fighters_A;//Base fighter is created as the object is of type Fighters
	Fighters_A* pJ31 = new Fighters_A;//Derived class
	
	pJ21->printinfo();
	pJ31->printinfo();

	auto* pXX = new Fighters_A;
	pXX->printinfo();



	Fighters_A J41;
	J41.printinfo();//Derived
	Fighters* pJ41 = &J41;//referred Fighters_A pointer of type Fighters
	pJ41->printinfo();//Base if no Virtual keyword next to printinfo(); Derived if Virtual keyword is present
	Fighters F11;
	F11.printinfo();//Derived


	getchar();
	return 0;
}

void Fighters::printinfo() {
	cout << "\nBase Fighter: " << model << endl;
	cout << "Health is " << Health << endl;
	cout << "Strength is " << Strength << endl;
	cout << "Stealth is " << Stealth << endl;
	cout << "Armour is " << Armour << endl;
}


void Fighters::add_stealth() {
	Stealth = Stealth + 10;
}

//void Fighters::add_feature() {
//	cout << "Pure Virtual Function implemented at derive class." << endl;
//}



void Fighters_A::add_weapons() {
	Missles = Missles + 5;
}

void Fighters_A::printinfo() {
	cout << "\nDerived Fighters_A: " << model << endl;//inherited public
	cout << "Health is " << Health << endl;//inherited public
	cout << "Strength is " << Strength << endl;//inherited public
	//cout << "Stealth is " << Stealth << endl;//Derived class cant access to private members in parent class
	cout << "Missle is " << Missles << endl;//member of derived class
	cout << "Armour is " << Armour << endl;//inherited protected
}

void Fighters_B::add_fueltank() {
	fueltank = fueltank + 1;
}