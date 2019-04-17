#pragma once
#include"Unit.h"

class EduUnit :public Unit {
	std::map<int, std::pair<std::string, int>> project;
public:
	EduUnit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<std::string,int>> map);
	std::string unit_find(std::string Name);
	int get_student_amount();
	char type();
	void print_name();
	void print();
	void input(std::ofstream &out);
	void set_extra(int kurs, std::string s);
	void set_extra(int kurs, int x);
	void set_course(int x, int y);

	void set_extra_2(int kurs, int x);
};