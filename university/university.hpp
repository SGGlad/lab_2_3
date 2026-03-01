#pragma once
#include <iostream>
#include <vector>
class Student;

struct Statment {
	Statment(std::string name, std::string second_name, std::string type, std::string comment, unsigned short data);
	void print();
	std::string name_;
	std::string second_name_;
	std::string type_;
	std::string comment_;
	unsigned short data_;
};

class Decanat {
public:
	explicit Decanat(std::string adress);
	Decanat(const Decanat& other) = delete;
	~Decanat();
	void Attach(Student* student);
	void Expel(Student* student);
	void print();
private:
	std::string adress_;
	std::vector<Student*> students_;
};
