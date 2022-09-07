#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
	string name;
	char gender;
	int age;
public:
	Person(string name, char gender, int age) {
		this->name = name;
		this->gender = gender;
		this->age = age;
	}
	void Print() {
		cout << name << " " << age << " " << gender << endl;
	}
};

class Student :public Person {
protected:
	string stuNum;
	string department;
public:
	Student(string name, char gender, int age, string stuNum, string department)
		:Person(name, gender, age) {
		this->stuNum = stuNum;
		this->department = department;
	}
	void Print() {
		cout << name << " " << age << " " << gender << " " << stuNum << " "<<department << endl;
	}
};

class Teacher :public Person {
protected:
	string title;
	string course;
public:
	Teacher(string name, char gender, int age, string title, string course)
		:Person(name, gender, age) {
		this->title = title;
		this->course = course;
	}
	void Print() {
		cout << name << " " << age << " " << gender << " " << course << " " << title << endl;
	}
};

class GraduateStudent :public Student {
protected:
	string advisor;
public:
	GraduateStudent(string name, char gender, int age, string stuNum, string department, string advisor)
		:Student(name, gender, age, stuNum, department) {
		this->advisor = advisor;
	}
	void Print() {
		cout << name << " " << age << " " << gender << " " << stuNum << " " << department << " " << advisor << endl;
	}
};

int main() {
	string name="sun";
	char gender='M';
	int age = 42;
	Person per1(name,gender,age);
	cout << "== per1.Display() => name,age,sex" << endl;
	per1.Print();

	name = "guo";
	age = 22;
	gender = 'F';
	string stuNum = "1001";
	string department = "comp";
	Student stu1(name, gender, age, stuNum, department);
	cout << "== stu1.Display() => name,age,sex,Reg_Number,department" << endl;
	stu1.Print();

	name = "fang";
	age = 38;
	gender = 'M';
	string course = "english";
	string title = "professor";
	Teacher teach1(name, gender, age, title, course);
	cout << "== teach1.Display() => name,age,sex,course,post" << endl;
	teach1.Print();

	name = "wu"; 
	age = 25;
	gender = 'M';
	stuNum = "1021";
	department = "comp";
	string advisor = "wei";
	GraduateStudent gStu(name, gender, age, stuNum, department, advisor);
	cout << "== gStu.Display() => name,age,sex,Reg_Number,department,advisor" << endl;
	gStu.Print();
	return 0;
}