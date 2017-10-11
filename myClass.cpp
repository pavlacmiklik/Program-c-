//Function declarations

#include "MyClass.h"

MyClass::MyClass() {
	
}

MyClass::MyClass(string id, string name, string value) {
	newId = id;
	newName = name;
	newValue = value;

}

MyClass::MyClass(string id, string name, string value, double numericValue) {
    newId = id;
    newName = name;
    newValue = value;
    valueNumeric = numericValue;
}

MyClass::~MyClass() {

}

string MyClass::getId() const {
	return newId;
}

string MyClass::getName() const {
	return newName;
}

string MyClass::getValue() const {
	return newValue;
}

double MyClass::getValueNumeric() const {
    return valueNumeric;
}

void MyClass::setId(string id) {
	newId = id;
}

void MyClass::setName(string name) {
	newName = name;
}

void MyClass::setValue(string value) {
	newValue = value;
}

void MyClass::setValueNumeric(double value) {
    valueNumeric = value;
}
