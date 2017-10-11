#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<algorithm>
#include "MyClass.h"

using namespace std;

//fills vector with created objects
void fillVector(vector<MyClass>& newMyVector, MyClass object) {
	newMyVector.insert(newMyVector.end(),object); //inserts object at the end of the vector
}

//
void printVector(vector<MyClass>& myVector) {
	for(vector<MyClass>::iterator it = myVector.begin(); it != myVector.end(); it++) { //iterator "it" goes through vector from start to end
		MyClass object = *it; //*it picks object from position which iterator is currently at
		if(object.getValueNumeric() != 0.0f) { //compares numeric value to zero, if not zero, continue
			cout << "ID: " << object.getId() << endl <<
				 "Name: " << object.getName() << endl << "Value: " <<
				 object.getValue() << endl << endl;
		}
	}
}

//comparator functions
auto cmpById = [](MyClass const & a, MyClass const & b) 
{
	return a.getId() < b.getId();
};

//ampersand in function argument means, that a potential change of object 
//(in a function), which takes place of the given parameter, stays saved in the object
auto cmpByVal = [](MyClass const & a, MyClass const & b) 
{
    if(a.getValueNumeric() != 0.0f && b.getValueNumeric() != 0.0f) return a.getValueNumeric() < b.getValueNumeric();
    else return a.getValue() < b.getValue();
};

int main() {

	//text file opening
	ifstream inFile;
	inFile.open("list.txt");

	//if file fails to open correctly
	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		system("pause");
		exit(1);
	}

	//variables declaration
	string id(8, '\0');
	string name(37, '\0');
	string value(10, '\0');
	string line;
	int n = 0,m = 0;
	int lineNum = 1;
	vector<MyClass> myVector;

	while (inFile >> line) {
        value.clear();
        value.resize(10,' ');
		for (int i = 0; i < line.size(); i++) {
			if(line[i] == ';') {
				m=0;
				n++;
			}
			else if(n == 0) id[m++] = line[i];
			else if(n == 1) name[m++] = line[i];
			else if(n == 2) value[m++] = line[i];
		}
		m = n = 0;
        id.shrink_to_fit();
        name.shrink_to_fit();
        value.shrink_to_fit();

		//strtod - on success returns converted value of type double
		//       - if no conversion could be performed, returns zero
        double numericValue = strtod(value.c_str(),NULL);

        MyClass CDataPoint = * new MyClass(id, name, value,numericValue);
        fillVector(myVector,CDataPoint);
        lineNum++;
	}

	//sort by ID
	cout << "Sort by ID: " << endl << endl;
	sort(myVector.begin(), myVector.end(), cmpById); //sort(vector beginning iterator, vector end iterator, comparator function)

	for (vector<MyClass>::iterator it = myVector.begin(); it != myVector.end(); it++) { //iterator "it" goes through vector from start to end
		MyClass object = *it; //*it picks object from position which iterator is currently at
		cout << "ID: " << object.getId() << endl <<
			"Name: " << object.getName() << endl << "Value: " <<
			object.getValue() << endl << endl;
	}

	//sort by Value
	cout << "Sort by Value: " << endl << endl;
    sort(myVector.begin(),myVector.end(),cmpByVal);
	printVector(myVector);

	system("pause");
	return 0;
}


