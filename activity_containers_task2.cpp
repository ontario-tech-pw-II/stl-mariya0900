
//task 2
// program reads the names and grades of students form an input file and print the name of students 
//that have at least one mark less that 50 for a report. The printed list should not have any duplicate.


#include <iostream>
#include <fstream>
#include <string>
#include <set>


using namespace std;

int main(int argc, char** argv){
	
	string filename=argv[1];
	
	set<string> c;
	ifstream myInput(filename);
	while (!myInput.eof()){
		string name;
		int grade;
		myInput>>name;
		myInput>>grade;
		if (grade<50)
			c.insert(name);	
	}
	myInput.close();
	
	set<string>::iterator p;
	for (p=c.begin();p!=c.end();p++){
		cout<<*p<<endl;
	}
	
	return 0;
}