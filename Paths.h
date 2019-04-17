//
// Well FS didn't help me a lot in easing the task *imho*
#pragma once
#include<iostream>
#include<string>
#include<experimental/filesystem>

std::experimental::filesystem::path Path = "D:/DataBase/";
const std::experimental::filesystem::path Ext = ".txt";

void change_path() {
	std::string s;
	std::cout << "\nEnter a new path :>";
	std::getline(std::cin, s);
	Path = s;
}