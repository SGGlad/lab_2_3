#include "university.hpp"


Statment::Statment(std::string name, std::string second_name, std::string type, std::string comment, unsigned short data) :
	name_(name), second_name_(second_name), type_(type), comment_(comment), data_(data) {
}
void Statment::print() {
	std::cout << "Statment\n" << type_ << " (" << data_ << ")\n" << comment_ << "\n" << name_ << " " << second_name_ << std::endl;
}


Decanat::Decanat(std::string adress) :adress_(adress) {}
Decanat:: ~Decanat() {
	std::cout << "decanat dtor";
}
void Decanat::Attach(Student* student) {
	students_.push_back(student);
}
void Decanat::Expel(Student* student) {
	std::erase(students_, student);
}
void Decanat::print() {
	for (int i = 0; i < students_.size(); ++i) {
		std::cout << students_[i] << " ";
	}
	std::cout << std::endl;
}
