#pragma once
#include"Unit.h"

class SciUnit :public Unit {
	std::map<int, std::pair<int, int>> student;
public:
	SciUnit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<int, int>> map);

	std::string unit_find(std::string Name);
	int get_student_amount();
	char type();
	void print();
	void print_name();
	void input(std::ofstream &out);
	void set_extra(int kurs, int x);
	void set_extra_2(int kurs, int x);
	void set_course(int x, int y);

	void set_extra(int kurs, std::string s);

};

