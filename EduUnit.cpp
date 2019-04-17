#include"EduUnit.h"

//EduUnit::EduUnit(std::string UN, std::string HN, int PGS, int Staff, int kurs, std::string name, int cost) {
//	unitName = UN; headName = HN; PGS_Amount = PGS; Staff_Amount = Staff;
//	std::pair<std::string, int> temp;
//	temp.first = name; temp.second = cost;
//	EduUnit::project.emplace(kurs, temp);
//}

EduUnit::EduUnit(std::string UN, std::string HN, int PGS, int Staff, std::map<int, std::pair<std::string, int>> map) {
	unitName = UN; headName = HN; PGS_Amount = PGS; Staff_Amount = Staff;
	project = map;
}

std::string EduUnit::unit_find(std::string Name) {
	return std::string();
}

int EduUnit::get_student_amount() {
	return PGS_Amount;
}

void EduUnit::print() {
	std::cout << " Unit name : " << unitName << "\n Head name : " << headName << "\n Amount of PGS = " << PGS_Amount << "\n Amount of Staff = " << Staff_Amount;
	std::for_each(project.begin(), project.end(), [](auto i) {std::cout << "\n Course = " << i.first << "\n Project name : " << i.second.first << "\n Project cost = " << i.second.second << std::endl; });
}

void EduUnit::input(std::ofstream &out){
	if (out.is_open()) {
		std::for_each(project.begin(), project.end(), [&out](auto i) {
			out << "\nCourse = " << i.first << "\nProject name = " << i.second.first << "\nProject cost = " << i.second.second;
		});
	}
}

void EduUnit::set_extra(int kurs, std::string s){
	std::map<int, std::pair<std::string, int>>::iterator it;
	it = project.find(kurs);
	it->second.first = s;
}

void EduUnit::set_extra(int kurs, int x){
	std::map<int, std::pair<std::string, int>>::iterator it;
	it = project.find(kurs);
	it->second.second = x;
}

void EduUnit::set_course(int x, int y) {
	std::map<int, std::pair<std::string, int>>::iterator it;
	std::pair<std::string, int> temp = it->second;
	it = project.find(x); 
	project.erase(it);
	project.emplace(y, temp);
}

void EduUnit::set_extra_2(int kurs, int x) {}

char EduUnit::type(){
	return 'e';
}

void EduUnit::print_name() {
	std::cout << " " << EduUnit::unitName;
}