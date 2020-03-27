// Student class is implemented based on string and do not need any change

//Write a program that reads the names and grades of students then adds students objects in a list of Student, 
//so that the list is always sorted in ascending order of grades .
// The program prints the list (both name and grade) in ascending, and then in descending order (based on grade).
#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}
bool gradeComp(Student a, Student b){
	if (a.getgrade()<b.getgrade())
		return true;
	else
		return false;
}
	
int main()
{  

	list<Student> c;
	char* name=new char[15];
	double grade;
	
	list<Student>::iterator p;
	int n;
	cout<<"Enter the number of students (more than 2 preferably): ";
	cin>>n;
	
	//first student
	cout<<"Enter the name of the student: ";
	cin>>name;
	cout<<"Enter the grade: ";
	cin>>grade;
	Student st(name, grade);
	c.push_back(st);
	
	//second student
	cout<<"Enter the name of the student: ";
	cin>>name;
	cout<<"Enter the grade: ";
	cin>>grade;
	if (grade>st.getgrade()){
		Student st(name, grade);
		c.push_back(st);
	}
	else{
		Student st(name, grade);
		c.push_front(st);
		
	}
	//other students
	for (int i=0;i<n-2;i++){
		cout<<"Enter the name of the student: ";
		cin>>name;
		cout<<"Enter the grade: ";
		cin>>grade;
		Student st(name, grade);
		
		list<Student>::iterator e;
		e=--c.end();
		if (grade>(e->getgrade()))
			c.push_back(st);
				
		for (p=c.begin();p!=c.end();++p){
			
			if (grade<(p->getgrade())){				
				c.insert(p, st);
				break;
			}
		}
			
	}
	
	cout<<endl<<"Students list in ascending order: "<<endl;
	for (p = c.begin( ); p != c.end( ); p++)
		cout<<*p<<endl;
		
		
	
	
	
	
	cout<<endl<<"Students list in descending order: "<<endl;
	c.reverse();
	for (p = c.begin( ); p != c.end( ); p++)
		cout<<*p<<endl;
	
	/*or
	list<Student>::reverse_iterator r;
	for (r = c.rbegin( ); r != c.rend( ); r++)
		cout<<*r<<endl;*/
	

		
	return 0;	
}