#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<map>

class Unit {
protected:
	std::string unitName;
	std::string headName;
	int PGS_Amount = 0;
	int Staff_Amount = 0;
public:
	virtual std::string unit_find(std::string Name) = 0;
	virtual int get_student_amount() = 0;
	virtual void print() = 0;
	virtual void print_name() = 0;
	virtual char type() = 0;
	virtual std::string get_unit_name();
	virtual std::string get_head_name();
	virtual int get_pgs();
	virtual int get_staff();
	virtual void input(std::ofstream &out) = 0;

	virtual void set_unit_name(std::string s);
	virtual void set_head_name(std::string s);
	virtual void set_pgs(int x);
	virtual void set_staff(int x);
	virtual void set_course(int x, int y) = 0;
	virtual void set_extra(int kurs, std::string s)= 0;
	virtual void set_extra(int kurs, int x) = 0;
	virtual void set_extra_2(int kurs, int x) = 0;
};