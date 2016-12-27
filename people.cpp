#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class People{
	public:
		struct detailsCommon{
			string name;
			string aadharId;
		};
		struct detailsStudent{
			detailsCommon details;
			string school;
			string grade;
			string studentId;
		};
		struct detailsTeacher{
			detailsCommon details;
			string school;
			string subject;
			int teacherId;
		};
		struct detailsEngineer{
			detailsCommon details;
			string company;
			int salary;
			int employeeId;
		};
		struct detailsMechanic{
			detailsCommon details;
			string garageName;
			string speciality;
			int mechanicId;
		};
		void fillInfo();
		string getName();
		string getAadharId();
	protected:
		vector<detailsStudent> student;
		vector<detailsStudent>::iterator si;

		vector<detailsTeacher> teacher;
		vector<detailsTeacher>::iterator ti;

		vector<detailsEngineer> engineer;
		vector<detailsEngineer>::iterator ei;
		
		vector<detailsMechanic> mechanic;
		vector<detailsMechanic>::iterator mi;
};
class Student:public People{
	public:
		void fillInfo();
		void printAllStudents();
		string getSchool();
		string getGrade();
		string getStudentID();
};
class Teacher:public People{
	public:
		void fillInfo();
};
class Engineer:public People{
	public:
		void fillInfo();
};
class Mechanic:public People{
	public:
		void fillInfo();
};
int main(){
	int option = 0;
	Student s;
	Teacher t;
	Engineer e;
	Mechanic m;
	cout<<"Welcome to People Management Facility"<<endl;
	cout<<"What you do?"<<endl<<"1. Student"<<endl<<"2. Teacher"<<endl<<"3. Engineer"<<endl<<"4. Mechanic"<<endl;
	cin>>option;
	switch (option){
		case 1:
			s.fillInfo();
			s.printAllStudents();
			break;
		case 2:
			//t.fillInfo();
		case 3:
			//e.fillInfo();
		case 4:
			//m.fillInfo();
		default:
			cout<<"Wrong Option"<<endl;
	}
}

void Student::fillInfo(){
	detailsStudent ds;

	ds.details.name = People::getName();;
	ds.details.aadharId = People::getAadharId();
	ds.school = getSchool();
	ds.grade = getGrade();
	ds.studentId = getStudentID();

	si = student.end();
	si = student.insert(si,ds);
}

void Student::printAllStudents(){
	for(si = student.begin();si != student.end();++si){
		cout<<"Student Name: "<<si->details.name<<endl;
		cout<<"Student AadharID: "<<si->details.aadharId<<endl;
		cout<<"Student School: "<<si->school<<endl;
		cout<<"Student Grade: "<<si->grade<<endl;
		cout<<"Student ID: "<<si->studentId<<endl;
	}
}

string Student::getStudentID(){
	string studentId;
	cout<<"Enter your student ID"<<endl;
	cin>>studentId;
	return studentId;
}

string Student::getGrade(){
	string grade;
	cout<<"Enter your grade"<<endl;
	cin>>grade;
	return grade;
}
string Student::getSchool(){
	string schoolName;
	cout<<"Enter your school name"<<endl;
	cin>>schoolName;
	return schoolName;
}

string People::getAadharId(){
	string aadhar;
	cout<<"Enter your aadhar Id"<<endl;
	cin>>aadhar;
	return aadhar;
}
string People::getName(){
	string name;
	cout<<"Enter name"<<endl;
	cin>>name;
	return name;
}
