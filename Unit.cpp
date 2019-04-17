#include"Unit.h"

std::string Unit::get_unit_name() {
	return unitName;
}

std::string Unit::get_head_name() {
	return headName;
}

int Unit::get_pgs() {
	return PGS_Amount;
}

int Unit::get_staff() {
	return Staff_Amount;
}

void Unit::set_unit_name(std::string s) {
	unitName = s;
}

void Unit::set_head_name(std::string s) {
	headName = s;
}

void Unit::set_pgs(int x) {
	PGS_Amount = x;
}

void Unit::set_staff(int x) {
	Staff_Amount = x;
}
