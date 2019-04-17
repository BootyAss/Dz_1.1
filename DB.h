#pragma once

#include"Unit.h"
#include"EduUnit.h"
#include"SciUnit.h"
#include<vector>

class DB {
	std::vector<Unit*> u;
public:
	DB();
	~DB();
	void print_all_name();
	void print_unit_name_by_unit(std::string arg);
	void print_unit_name_by_head(std::string arg);
	int print_unit_by_unit(std::string arg);
	int print_unit_name_by_staff(int arg);

	void clear();
	int clear(std::string s);

	std::string get_unit_name_by_iter(int i);
	std::string get_unit_head(int i);
	int get_unit_pgs(int i);
	int get_unit_staff(int i);
	std::string get_unit_type(int i);

	char get_unit_type(std::string i);
	int get_DB_staff();

	void input(std::ofstream &out);

	int get_unit_amount();
	int get_student_amount();
	int unit_student_amount(std::string arg);

	bool unit_name(std::string s);
	bool head_name(std::string s);
	bool name_check(std::string s, char x); 
	bool name_check(std::string s);

	void new_unit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair< std::string, int>> map);
	void new_unit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair< int, int>> map);

	std::string sort_unit();

	void edit(int c, std::string arg);
};

