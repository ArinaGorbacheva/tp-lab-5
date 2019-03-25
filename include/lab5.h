#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

class Group;
class Deanery;

class Student {
	friend Group;
	friend Deanery;
private:
	int id;
	string fio;
	Group *group;
	vector<int> marks;
	int num;
public:
	Student(int id_, string fio_);
	void add_group(Group *group);
	void add_mark(int _mark);
	double student_average();
};


class Group {
	friend Deanery;
private:
	string title;
	vector<Student*> students;
	Student *head;
	int num;
public:
	Group(string title_);
	void add_student(Student *student);
	Student * elect_head();
	Student * search_student(int id_);
	double group_average();
	void exception(string);
};

class Deanery {
private:
	vector<Student*> students;
	vector<Group*> groups;
	string fileStudents; 
	string fileGroups;
	int num_st;
	int num_gr; 

	vector<pair<float, string>> student_stat; 
	vector<pair<float, string>> group_stat; 

public:
	Deanery(string, string);
	void create_students();
	void create_groups();
	void add_marks();
	void get_statistics(string);
	void change_group(string, string);
	void exception_student();
	void update(string); 
	void elect_ghead();
	void print_info();
};
