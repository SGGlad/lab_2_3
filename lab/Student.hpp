#pragma once
#include <university.hpp>
#include <iostream>
#include <vector>

struct Name {
	Name();
	Name(std::string name);
	Name(const Name& other);
	Name& operator=(const Name& other);
	Name operator+(const Name& other);
	Name operator+(const std::string& other);
	Name operator+(const char& other);
	void print();
	void print_with_text();
	std::string get();
	std::string name_;
};
struct Second_name {
	Second_name();
	Second_name(std::string second_name);
	Second_name(const Second_name& other);
	Second_name& operator=(const Second_name& other);
	Second_name operator+(const Second_name& other);
	Second_name operator+(const std::string& other);
	void print();
	void print_with_text();
	std::string get();
	std::string second_name_;
};
struct Direction {
	Direction();
	Direction(std::string direction);
	Direction(const Direction& other);
	Direction& operator=(const Direction& other);
	void print_with_text();
	void print_only_value();
	std::string direction_;
};

struct Course {
	Course();
	Course(unsigned short course);
	Course(const Course& other);
	Course& operator=(const Course& other);
	Course& operator+=(const Course&);
	bool operator!=(const Course& other);
	void print_with_text();
	void print_only_value();
	unsigned short get();
	unsigned short course_;
};

struct Groupe {
	Groupe();
	Groupe(unsigned short groupe);
	Groupe(const Groupe& other);
	Groupe& operator=(const Groupe& other);
	void print_with_text();
	void print_only_value();
	unsigned short get();
	unsigned short groupe_;
};

struct Variant {
	Variant();
	Variant(unsigned short variant);
	Variant(const Variant& other);
	Variant& operator=(const Variant& other);
	void print_with_text();
	void print_only_value();
	unsigned short variant_;
};

class Student {
public:
	Student(Name name, Second_name second_name, Direction direction, Course course, Groupe groupe, Variant variant, std::vector<std::string>& debts);
	Student(Name name, Second_name second_name, std::vector<std::string>& debts);
	Student(const Student& other);
	~Student();
	Student& operator=(const Student& other);
	const Student operator+(const Student& other_1);
	Student& operator-=(const Student& other);
	const Student operator/(const Student& other);
	Statment next_course(std::string comment);
	Statment another_groupe(std::string comment, unsigned short groupe);
	void set_name(Name name);
	void set_second_name(Second_name second_name);
	void set_direction(Direction direction);
	void set_course(short course);
	void set_groupe(Groupe groupe);
	void set_variant(short variant);
	void set_debts(std::vector<std::string> debts);
	Name get_name();
	Second_name get_second_name();
	Direction get_direction();
	Course get_course();
	Groupe get_groupe();
	Variant get_variant();
	std::vector<std::string> get_debts();
	void get_info();
private:
	Name name_;
	Second_name second_name_;
	Direction direction_{ "" };
	Course course_ = 0;
	Groupe groupe_ = 0;
	Variant variant_ = 0;
	std::vector<std::string> debts_{ "1 " };
};