// Pogramm for managing Data Base type information :
//		recording, reading finding information and displaying (editing in future)
//
// iostream,string,map,fstream,algorithm,vector,experimental/filesystem are already included in headline files
//
// Connecting Paths and Classes
#include"Paths.h"
#include"Unit.h"
#include"EduUnit.h"
#include"SciUnit.h"
#include"DB.h"
#include"Functions.h"

// IC8 don't use that crap, yo
// using namespace std;


void main() {
	Greetings();
	std::map<std::string, DB*> blob;	// Container of DB's name and DB
	DB* current = NULL;					// Pointer on current DB
	std::ofstream out;					// File recording object
	std::ifstream in;					// File reading object
	while (true) {
		ARGUMENT = 0;
		std::string first, cmd, arg;	// lines : original, command, arguement 
		std::cout << ">";
		std::getline(std::cin, first);
		int i = cmd_find(first);
		cmd = first.substr(0, i);
		if (ARGUMENT == true)
			arg = first.substr(i + 1, first.length());

		switch (checky_chicky_check(cmd)) {
		case 255:	//end
			goto END;
		case 0:		//help
			if (CURRENT == 0)
				Help_menu();
			else
				if (CURRENT == 1)
					Help_DB();
			break;
		case 2:		//create
			while (arg == "") {
				std::cout << " Empty name, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}

			if (CURRENT == 0) {
				if (blob.find(arg) == blob.end())
					blob.emplace(arg, new DB);
				else
					Error_create_name();
			}
			else {
				Unit_type();
			U_T:
				char x;
				std::cin >> x;
				if (x != 's' && x != 'e') {
					Error_unit_type();
					goto U_T;
				}
				else
					if (current->name_check(arg, x) == false)
						Error_create_name();
					else {
						std::string HN;
						int PGS, Staff, kurs;
						if (x == 'e') {
							std::string PN;
							int PC;
							std::map<int, std::pair<std::string, int>> map;
							Create_unit(&HN, &PGS, &Staff, &map);
							current->new_unit(arg, HN, PGS, Staff, map);
						}
						else {
							int SA, EC;
							std::map<int, std::pair<int, int>> map;
							Create_unit(&HN, &PGS, &Staff, &map);
							current->new_unit(arg, HN, PGS, Staff, map);
						}
					}
			}
			break;
		case 3:		//list
			if (CURRENT == 0)
				if (blob.empty())
					std::cout << " DB list is empty\n";
				else
					std::for_each(blob.begin(), blob.end(), [](auto i) {std::cout << " " << i.first << std::endl; });
			else
				if (current->get_unit_amount())
					current->print_all_name();
				else
					std::cout << " DB is empty\n";
			break;
		case 4:		//show 
			while (arg == "") {
				std::cout << " Empty name, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}

			if (CURRENT == 0)
				std::for_each(blob.begin(), blob.end(), [&arg](auto i) {if (i.first == arg) i.second->print_all_name(); });
			else
				current->print_unit_by_unit(arg);
			break;
		case 5:		//amount
			if (CURRENT == 0)
				if (arg == "") {
					int temp_amount = 0;
					std::for_each(blob.begin(), blob.end(), [&temp_amount](auto i) {temp_amount += i.second->get_student_amount(); });
					std::cout << " Overall amount of students = " << temp_amount << std::endl;
				}
				else {
					bool check = false;
					while (check == false) {
						std::for_each(blob.begin(), blob.end(), [&check, &arg](auto i) {
							if (i.first == arg) {
								std::cout << " Student amount in " << arg << " = " << i.second->get_student_amount() << std::endl;
								check = true;
							}
							});
						if (check == false) {
							std::cout << " DB not found, try again (\"end\" to quit) >";
							std::getline(std::cin, arg);
							if (arg == "end")
								goto def;
						}
					}
				}
			else
				if (arg == "")
					std::cout << " Student amount in current DB = " << current->get_student_amount() << std::endl;
				else {
					int temp = current->unit_student_amount(arg);
					while (temp == -2) {
						std::cout << " Unit not found, try again (\"end\" to quit) >";
						std::getline(std::cin, arg);
						if (arg == "end")
							goto def;
						temp = current->unit_student_amount(arg);
					}
					std::cout << " Student amount in " << arg << " = " << temp << std::endl;
				}
			break;
		case 6:		//find
			if (CURRENT == 0) {
				bool check = false;
				while (check == false) {
					std::for_each(blob.begin(), blob.end(), [&arg, &check](auto i) {
						if (i.second->unit_name(arg) == true || i.second->head_name(arg) == true) {
							std::cout << i.first << std::endl;
							check = true;
						}
						});
					if (check == false) {
						arg = "";
						while (arg == "") {
							std::cout << " DB not found, try again (\"end\" to quit) >";
							std::getline(std::cin, arg);
							if (arg == "end")
								goto def;
						}
					}
				}
			}
			else {
				while (current->head_name(arg) == false) {
					arg = "";
					while (arg == "") {
						std::cout << " Unit not found, try again (\"end\" to quit) >";
						std::getline(std::cin, arg);
						if (arg == "end")
							goto def;
					}
				}
				current->print_unit_name_by_head(arg);
			}
			break;
		case 7:		//delete
			while (arg == "") {
				std::cout << " Not found, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}
			if (arg == "all") {
				bool done = false;
				for (auto& i : std::experimental::filesystem::directory_iterator(Path))
					if (i.path().extension() == ".txt")
						if (remove(i.path()) == -1)
							std::cout << " Can't delete " << i.path().filename().stem().string() << "\n";
						else
							done = true;

				if (done == false)
					std::cout << " Nothing to delete\n";
				else
					std::cout << " Files were deleted\n";
			}
			else {
				std::experimental::filesystem::path path = Path;
				path += arg;
				path += Ext;
				if (remove(path) == -1)
					std::cout << " File not found\n";
				else
					std::cout << path.filename() << " was deleted\n";

			}
			break;
		case 8:		//remove
			while (arg == "") {
				std::cout << " Not found, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}

			if (CURRENT == 0)
				if (arg == "all") {
					std::cout << "\n Are You sure? That will remove all DBs and their data in PROGRAMM. Can't be undone\n>";
					std::getline(std::cin, arg);
					if (arg == "yes" || arg == "Yes" || arg == "y" || arg == "Y") {
						blob.clear();
						std::cout << " All DBs were deleted\n";
					}
				}
				else {
					std::cout << "\n Are You sure? That will remove DB & its data in PROGRAMM. Can't be undone\n>";
					std::getline(std::cin, cmd);
					if (cmd == "yes" || cmd == "Yes" || cmd == "y" || cmd == "Y") {
						bool check = false;
						while (check == false) {
							for (auto i = blob.begin(); i != blob.end();)
								if (i->first == arg) {
									i = blob.erase(i);
									std::cout << " DB was deleted\n";
									check = true;
								}
								else
									i++;
							if (check == false) {
								arg = "";
								while (arg == "") {
									std::cout << " DB not found, try again (\"end\" to quit) >";
									std::getline(std::cin, arg);
									if (arg == "end")
										goto def;
								}
							}
						}
					}
				}
			else
				if (arg == "all") {
					std::cout << "\n Are You sure? That will remove all Units and their data in PROGRAMM. Can't be undone\n>";
					std::getline(std::cin, arg);
					if (arg == "yes" || arg == "Yes" || arg == "y" || arg == "Y")
						current->clear();
				}
				else {
					std::cout << "\n Are You sure? That will remove Unit & its data in PROGRAMM. Can't be undone\n>";
					std::getline(std::cin, cmd);
					if (cmd == "yes" || cmd == "Yes" || cmd == "y" || cmd == "Y")
						while (current->clear(arg) == -1) {
							arg = "";
							while (arg == "") {
								std::cout << " Unit not found, try again (\"end\" to quit) >";
								std::getline(std::cin, arg);
								if (arg == "end")
									goto def;
							}
						}
				}
			break;
		case 9:		//current
			if (CURRENT == 1)
				std::for_each(blob.begin(), blob.end(), [&current](auto i) {if (i.second == current) std::cout << " Current DB = " << i.first << std::endl; });
			break;
		case 10:	//clear
			system("cls");
			break;
		case 11:	//head
			int temp;
			while (arg == "") {
				std::cout << " Wrong name, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}
			std::for_each(blob.begin(), blob.end(), [&arg, &temp](auto i) {
				if (i.second->head_name(arg) == true)
					i.second->print_unit_name_by_head(arg);
				});
			if (temp == -1)
				while (arg == "") {
					std::cout << " Wrong amount, try again (\"end\" to quit) >";
					std::getline(std::cin, arg);
					if (arg == "end")
						goto def;
				}
			break;
		case 12:	//staff
			while (arg == "") {
				std::cout << " Wrong amount, try again (\"end\" to quit) >";
				std::getline(std::cin, arg);
				if (arg == "end")
					goto def;
			}
			std::for_each(blob.begin(), blob.end(), [&arg, &temp](auto i) {
				temp = i.second->print_unit_name_by_staff(std::stoi(arg));
				});
			if (temp == -1)
				while (arg == "") {
					std::cout << " Wrong amount, try again (\"end\" to quit) >";
					std::getline(std::cin, arg);
					if (arg == "end")
						goto def;
				}
			break;
		case 13:	//save
			if (blob.size() > 0)
				std::for_each(blob.begin(), blob.end(), [&out](auto i) {
				std::experimental::filesystem::path path = Path;
				path += i.first; path += Ext;
				out.open(path);
				if (out.is_open()) {
					out << "DB name : " << path.stem();
					i.second->input(out);
				}
				out.close();
					});
			else
				std::cout << " DB list is empty\n";
			break;
		case 14:	//read
			if (std::experimental::filesystem::is_empty(Path))
				std::cout << " Directory is Empty\n";
			else {
				std::string temp = arg;
				for (auto& i : std::experimental::filesystem::directory_iterator(Path)) {
					if (temp == "all")
						arg = i.path().filename().stem().string();
					std::experimental::filesystem::path path = Path / arg;
					path += Ext;
					if (std::experimental::filesystem::is_regular_file(path)) {
						if (blob.find(arg) == blob.end()) {
							blob.emplace(arg, new DB);
							std::for_each(blob.begin(), blob.end(), [&arg, &current](auto i) {if (arg == i.first) current = i.second; });
						}
						else
							Error_create_name();

						in.open(path);
						if (in.is_open()) {
							// temporary variables
							std::string s;
							std::string unit_name, head_name, project_name;
							char type;
							int PGS_amount, staff_amount, course, project_cost, student_amount, cost;
							std::map<int, std::pair<std::string, int>> map;
							std::map<int, std::pair<int, int>> map2;
							std::pair<std::string, int> project;
							std::pair<int, int> student;

							while (std::getline(in, s)) {
								switch (Read_pars(s)) {
								case 0:
									break;
								case 1:
									unit_name = s;
									break;
								case 2:
									if (s == "Educational")
										type = 'e';
									else
										type = 's';
									break;
								case 3:
									head_name = s;
									break;
								case 4:
									PGS_amount = std::stoi(s);
									break;
								case 5:
									staff_amount = std::stoi(s);
									break;
								case 6:
									course = std::stoi(s);
									break;
								case 7:
									project_name = s;
									break;
								case 8:
									project_cost = std::stoi(s);
									project.first = project_name;
									project.second = project_cost;
									map.emplace(course, project);
									break;
								case 9:
									student_amount = std::stoi(s);
									break;
								case 10:
									cost = std::stoi(s);
									student.first = student_amount;
									student.second = cost;
									map2.emplace(course, student);
									break;
								case 11:
									if (type == 'e') {
										current->new_unit(unit_name, head_name, PGS_amount, staff_amount, map);
										map.clear();
									}
									else {
										current->new_unit(unit_name, head_name, PGS_amount, staff_amount, map2);
										map2.clear();
									}
									break;
								case 20:
									std::cout << " Wrong line, sir.\n";
									break;
								}
							}
						}
						in.close();
					}
					if (temp != "all")
						break;
				}
			}
			break;
		case 15:	//path
			if (arg == "show")
				std::cout << " Current path : " << Path << std::endl;
			if (arg == "change")
				change_path();
			else
				std::cout << " Wrong command argument, try again\n";
			break;
		case 16:	//by_staff
			// Copying map data to vector to sort
			// I didn't use std::transform, because
			// it needs defining std::pair and 
			// initializing it with blob.first & blob.second
			// I think this way is better in reusable cases
			if (blob.size() > 0) {
				std::vector<std::pair<std::string, DB*>> V;
				V.resize(blob.size());
				int it = 0;
				std::for_each(blob.begin(), blob.end(), [&V, &it](auto i) {
					V[it] = i;
					it++;
					});
				// Overloading of comparing function
				struct {
					bool operator()(std::pair<std::string, DB*> a, std::pair<std::string, DB*> b) const {
						return a.second->get_DB_staff() < b.second->get_DB_staff();
					}
				} customLess;
				// Sorting vector by Staff amount in each DB
				std::sort(V.begin(), V.end(), customLess);
				std::cout << "Sorted by Staff amount\n";
				for (size_t i = 0; i < V.size(); i++)
					std::cout << " " << V[i].first << std::endl;
			}
			else {
				std::cout << " DB list is empty\n";
			}
			break;
		case 17:	//by_name
			if (blob.size() > 0) {
				std::vector<std::pair<std::string, DB*>> V;
				V.resize(blob.size());
				int it = 0;
				std::for_each(blob.begin(), blob.end(), [&V, &it](auto i) {
					V[it] = i;
					it++;
					});
				struct {
					bool operator()(std::pair<std::string, DB*> a, std::pair<std::string, DB*> b) const {
						std::string t = a.second->sort_unit(), t2 = b.second->sort_unit();
						if (t.length() < t2.length())
							return true;
						if (t.length() > t2.length())
							return false;
						else
							if (t < t2)
								return true;
							else
								return false;
					}
				} customAlphabetic;
				std::sort(V.begin(), V.end(), customAlphabetic);
				std::cout << "Sorted by Unit name\n";
				for (size_t i = 0; i < V.size(); i++)
					std::cout << " " << V[i].first << std::endl;
			}
			else
				std::cout << " DB list is empty\n";
			break;
		case 18:	//back
			if (CURRENT == 0)
				std::cout << "\t\tWELL, THERE IS NO BACK, BABE\n";
			else {
				CURRENT = 0;
				current = NULL;
			}
			break;
		case 19:	//edit
			if (CURRENT == 0) {
				if (arg == "name") {
				DB_NAME:
					std::cout << " Enter old DB name \n>";
					std::getline(std::cin, arg);
					std::map<std::string, DB*>::iterator it;
					it = blob.find(arg);
					if (it != blob.end()) {
						std::cout << " Enter new DB name \n>";
						std::getline(std::cin, arg);
						DB* temp = it->second;
						blob.erase(it);
						blob.emplace(arg, temp);
						goto def;
					}
					else
						arg == "name";
				}
				if (arg != "") {
					std::map<std::string, DB*>::iterator it;
					it = blob.find(arg);
					if (it != blob.end())
						current = it->second;
					else
						arg = "";
				}
				while (arg == "") {
					std::cout << " Wrong DB name, try again (\"end\" to quit) >";
					std::getline(std::cin, arg);
					if (arg == "end")
						goto def;
					std::map<std::string, DB*>::iterator it;
					it = blob.find(arg);
					if (it != blob.end())
						current = it->second;
					else
						arg = "";
				}
			}
			arg = "";
			while (arg == "") {
				std::cout << " Enter name of Unit (\"name\" to change DB name, \"end\" to quit, \"list\" to show list of units)\n>";
				std::getline(std::cin, arg);
				if (arg == "name")
					goto DB_NAME;
				if (arg == "end")
					goto def;
				if (arg == "list")
					current->print_all_name();
				if (current->name_check(arg) == false)
					arg = "";
			}
			{
				int choice;
				char type = current->get_unit_type(arg);
				choice = edit_pars(type);
				if (choice == 255)
					goto def;
				current->edit(choice, arg);
			}
			std::cin.ignore();
			break;
		case 20:	//DB's_name / Unit's_name / wrong_command
			if (blob.find(cmd) == blob.end())
				Error_cmd();
			if (CURRENT == 0) {
				std::for_each(blob.begin(), blob.end(), [&cmd, &current](auto i) {
					if (i.first == cmd) {
						current = i.second;
						CURRENT = 1;
					}
				});
			}
			break;
		default:
		def:
			break;
		}
	}
END:
	std::cout << "\n\t\tThank You for using my programm\n\t\t\t   Good bye!\n";
	system("pause");
}