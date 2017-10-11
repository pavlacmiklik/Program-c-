//Header: Function definitions

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

#ifndef MyClass_H
#define MyClass_H

class MyClass {
public:
	//Default constructor - sets member variables to their null states
	MyClass();

	//Overload constructor
	MyClass(string, string, string);

	//Overload constructor 2
    MyClass(string, string, string, double);

	//Destructor - destroys object (out of memory) once we stop using it
	~MyClass();

	//Accessor functions - return member variables
	string getId() const; //const - because it is not modifying any member variable
		//getId - returns id

	string getName() const; 
		//getName - returns name

	string getValue() const;
		//getValue - returns value

    double getValueNumeric() const;
    //getValue - returns value

	//Mutator functions - add member variables one at a time
	void setId(string);
		//setId - sets id
		//@param string - id

	void setName(string);
		//setName - sets name
		//@param string - name

	void setValue(string);
		//setValue - sets value
		//@param string - value

    void setValueNumeric(double);
    //setValue - sets value
    //@param string - value

private:
	//Member variables
	string newId;
	string newName;
	string newValue;
    double valueNumeric;


};

#endif