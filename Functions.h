#pragma once
#include"Unit.h"

unsigned int CURRENT = 0;		// 0 - main menu, 1 - DB's menu, 2 - Unit's menu 
bool ARGUMENT = 0;				// 0 - there isn't, 1 - there is argument in cmd

// Friendly commands
void Greetings() {
	std::cout << " Hello, user\n Enter \"help\" to show all available commands for current location\n";
}

void Help_menu() {
	std::string a = "_";
	for (int i = 0; i < 6; i++)
		a += a;
	std::cout << a << "\n To Create a new DB enter \"create <DB name>\".\n\n To Show List of DBs enter \"list\".\n\n To Show DB's info enter \"show <DB name>\".\n\n To Work with DB enter \"<DB's name>\".\n\n To Show Overall Amount of students enter \"amount\".\n\n To Show Amount of students in certain DB enter \"amount <DB's name>\".\n\n To Find DB's name by Unit's or Head's name enter \"find <searched name>\".\n\n To Sort DB's by amount of staff enter \"staff\".\n\n To Sort DB's by Units' name enter \"name\".\n\n To Change directory Path enter \"path\".\n\n To Swow directory Path enter \"path show\".\n\n To Read DB from directory enter \"read <DB's name>\".\n\n To Read ALL DBs enter \"read all\".\n\n To remove certain DB enter \"remove <DB's name>\".\n\n To remove ALL DBs enter \"remove all\".\n\n To delete certain DB enter \"delete <DB's name>\".\n\n To delete ALL DBs enter \"delete all\".\n\n To Clear console enter \"clear\".\n\n To End programm enter \"end\".\n" << a << std::endl;
}

void Help_DB() {
	std::string a = "_";
	for (int i = 0; i < 6; i++)
		a += a;
	std::cout << a << "\nTo Create a new Unit enter \"create <Unit name>\".\n\n To Show List of Units enter \"list\".\n\n To Show Unit's info enter \"show <Unit's name>\".\n\n To Show current DB's name enter \"current\".\n\n To Show Amount of students in certain Unit enter \"amount <Unit's name>\".\n\n To Find Unit's name by Head's name enter \"find <head's name>\".\n\n To remove certain Unit enter \"remove <Unit's name>\".\n\n To remove ALL Units enter \"remove all\".\n\n To Return to DB menu enter \"back\".\n\n To Clear console enter \"clear\".\n\n To End programm enter \"end\".\n " << a << std::endl;
}

void Error_create_name() {
	std::cout << "\n\n Name's already taken, sorry :c\n";
}

void Error_cmd() {
	std::cout << "\n Sry, bruh, wrong command.\n";
}

void Error_unit_type() {
	std::cout << "\n That's a wrong type, dude.\n";
}

void Unit_type() {
	std::cout << "\n\n Enter the type(E/S) of Unit ?\n>";
}

// Educational Unit input
void Create_unit(std::string *HN, int *PGS, int *Staff, std::map<int, std::pair< std::string, int>> *map) {
	std::cout << "\n Enter Head's name n>";
	std::cin.ignore();
	std::getline(std::cin, *HN);
	std::cout << "\n Enter PGS amount n>";
	std::cin >> *PGS;
	std::cout << "\n Enter Staff amount n>";
	std::cin >> *Staff;
	std::cout << "\n Enter the Course amount n>";
	int ca; std::cin >> ca;
	for (int i = 0; i < ca; i++) {
		int kurs;
		std::pair<std::string, int> project;
		std::cout << "\n Enter the Course n>";
		std::cin >> kurs;
		std::cout << "\n Enter Project's name n>";
		std::cin.ignore();
		std::getline(std::cin, project.first);
		std::cout << "\n Enter Project's cost n>";
		std::cin >> project.second;
		map->emplace(kurs, project);
	}
	std::cin.ignore();
}

// Scientific Unit input
void Create_unit(std::string *HN, int *PGS, int *Staff, std::map<int, std::pair< int, int>> *map) {
	std::cout << "\n Enter Head's name n>";
	std::cin.ignore();
	std::getline(std::cin, *HN);
	std::cout << "\n Enter PGS amount n>";
	std::cin >> *PGS;
	std::cout << "\n Enter Staff amount n>";
	std::cin >> *Staff;
	std::cout << "\n Enter the Course amount n>";
	int ca; std::cin >> ca;
	for (int i = 0; i < ca; i++) {
		int kurs;
		std::pair<int, int> student;
		std::cout << "\n Enter the Course n>";
		std::cin >> kurs;
		std::cout << "\n Enter Student amount n>";
		std::cin >> student.first;
		std::cout << "\n Enter Educational cost n>";
		std::cin >> student.second;
		map->emplace(kurs, student);
	}
	std::cin.ignore();
}

// Find command length and arguement presence
int cmd_find(std::string &x) {
	int i = -1;
	i = x.find(" ");
	if (i == -1)
		i = x.length();
	else
		ARGUMENT = true;
	return i;
}

// Type of command
unsigned short checky_chicky_check(const std::string x) {
	if (x == "help")
		return 0;

	if (x == "create")
		return 2;
	if (x == "list")
		return 3;
	if (x == "show")
		return 4;
	if (x == "amount")
		return 5;
	if (x == "find")
		return 6;

	if (x == "delete")
		return 7;
	if (x == "remove")
		return 8;

	if (x == "current")
		return 9;
	if (x == "clear")
		return 10;

	if (x == "head")
		return 11;
	if (x == "staff")
		return 12;

	if (x == "save")
		return 13;
	if (x == "read")
		return 14;

	if (x == "path")
		return 15;

	if (x == "by_staff")
		return 16;
	if (x == "by_name")
		return 17;

	if (x == "back")
		return 18;

	if (x == "edit")
		return 19;

	if (x == "end")
		return 255;
	else
		return 20;
}

// Parsing file text
int Read_pars(std::string &s) {
	int stub = s.find(unsigned char(7));
	std::string temp;
	int i = s.rfind(':'), j = s.rfind('=');
	if (stub != std::string::npos)
		goto STUB;
	if (i != std::string::npos || j != std::string::npos) {
		temp = s.substr(0, i + j);
		s = s.substr(i + j + 3, s.size() - j - i - 3);
		if (temp == "DB name")
			return 0;
		if (temp == "Unit name")
			return 1;
		if (temp == "Type of unit")
			return 2;
		if (temp == "Head name")
			return 3;
		if (temp == "PGS amount")
			return 4;
		if (temp == "Staff amount")
			return 5;
		if (temp == "Course")
			return 6;
		if (temp == "Project name")
			return 7;
		if (temp == "Project cost")
			return 8;
		if (temp == "Student amount")
			return 9;
		if (temp == "Education cost")
			return 10;
	}
	if (s == " ")
		return int();
	else
		// Wrong line
		return 20;
STUB:
	// Special symbol (stub) - end of unit
	return 11;
}

// What to edit decision
int edit_pars(char type) {
start:
	std::string s;
	std::cout << " What do You want to edit (\"end\" to quit, \"help\" to show all posibilities)?\n>";
	std::cin >> s;
	if (s == "help") {
		std::cout << " \"help\"\n \"unit\" - unit name\n \"head\" - head name\n \"pgs\" - pgs amount\n \"staff\" - staff amount\n \"course\" - course";
		if (type == 'e')
			std::cout << " \"name\" - project name\n \"cost\" - project cost\n";
		else
			std::cout << " \"amount\" - student amount\n \"cost\" - education cost\n";
		goto start;
	}
	if (s == "unit")
		return 0;
	if (s == "head")
		return 1;
	if (s == "pgs")
		return 2;
	if (s == "staff")
		return 3;
	if (s == "name" && type == 'e')
		return 4;
	if (s == "cost" && type == 'e')
		return 5;
	if (s == "amount" && type == 's')
		return 6;
	if (s == "cost" && type == 's')
		return 7;
	if (s == "course")
		return 8;
	if (s == "DB")
		return 10;
	if (s == "end")
		return 255;
	std::cout << " Wrong argument\n";
	goto start;
}