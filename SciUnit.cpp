#include "SciUnit.h"

//SciUnit::SciUnit(std::string UN, std::string HN, int PGS, int Staff, int kurs, int amount, int cost) {
//	unitName = UN; headName = HN; PGS_Amount = PGS; Staff_Amount = Staff;
//	std::pair<int, int> temp;
//	temp.first = amount; temp.second = cost;
//	SciUnit::student.emplace(kurs, temp);
//}

SciUnit::SciUnit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<int, int>> map) {
	unitName = UN; headName = HN; PGS_Amount = PGS; Staff_Amount = Staff;
	student = map;
}

std::string SciUnit::unit_find(std::string Name) {
	return std::string();
}

int SciUnit::get_student_amount() {
	int temp = 0;
	std::for_each(student.begin(), student.end(), [&temp](auto i) {temp += i.second.first; });
	return  PGS_Amount + temp;
}

void SciUnit::print() {
	std::cout << " Unit name : " << unitName << "\n Head name : " << headName << "\n Amount of PGS = " << PGS_Amount << "\n Amount of Staff = " << Staff_Amount;
	std::for_each(student.begin(), student.end(), [](auto i) {std::cout << "\n Course = " << i.first << "\n Amount of students = " << i.second.first << "\n Education cost = " << i.second.second << std::endl; });
}


void SciUnit::print_name() {
	std::cout << " " << SciUnit::unitName;
}

void SciUnit::input(std::ofstream &out) {
	if (out.is_open()) {
		std::for_each(student.begin(), student.end(), [&out](auto i) {
			out << "\nCourse = " << i.first << "\nStudent amount = " << i.second.first << "\nEducation cost = " << i.second.second;
		});
	}
}

void SciUnit::set_extra(int kurs, int x) {
	std::map<int, std::pair<int, int>>::iterator it;
	it = student.find(x);
	it->second.first = x;
}

void SciUnit::set_extra_2(int kurs, int x) {
	std::map<int, std::pair<int, int>>::iterator it;
	it = student.find(x);
	it->second.second = x;
}

void SciUnit::set_course(int x, int y) {
	std::map<int, std::pair<int, int>>::iterator it;
	std::pair<int, int> temp = it->second;
	it = student.find(x);
	student.erase(it);
	student.emplace(y, temp);
}

void SciUnit::set_extra(int kurs, std::string s) {}

char SciUnit::type() {
	return 's';
}
