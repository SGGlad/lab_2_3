#include "Student.hpp"


Name::Name() = default;
Name::Name(std::string name) :name_(name) {}
Name::Name(const Name& other) {
	name_ = other.name_;
}
Name& Name::operator=(const Name& other) {
	name_ = other.name_;
	return *this;
}
Name Name::operator+(const Name& other) {
	return Name{ name_ + other.name_ };
}
Name Name::operator+(const std::string& other) {
	return Name{ name_ + other };
}
Name Name::operator+(const char& other) {
	return Name{ name_ + other };
}
void Name::print() {
	std::cout << name_<<" ";
}
void Name::print_with_text() {
	std::cout << "name: " << name_ << "\n";
}
std::string Name::get() {
	return name_;
}




Second_name::Second_name() = default;
Second_name::Second_name(std::string second_name) :second_name_(second_name) {}
Second_name::Second_name(const Second_name& other) {
	second_name_ = other.second_name_;
}
Second_name& Second_name::operator=(const Second_name& other) {
	second_name_ = other.second_name_;
	return *this;
}
Second_name Second_name::operator+(const Second_name& other) {
	return Second_name{ second_name_ + other.second_name_ };
}
Second_name Second_name::operator+(const std::string& other) {
	return Second_name{ second_name_ + other };
}
void Second_name::print() {
	std::cout << second_name_<<" ";
}
void Second_name::print_with_text() {
	std::cout << "second name: " << second_name_ << "\n";
}
std::string Second_name::get() {
	return second_name_;
}


Direction::Direction() = default;
Direction::Direction(std::string direction) :direction_(direction) {}
Direction::Direction(const Direction& other) {
	direction_ = other.direction_;
}
Direction& Direction::operator=(const Direction& other) {
	direction_ = other.direction_;
	return *this;
}
void Direction::print_with_text() {
	std::cout << "direction: " << direction_ << std::endl;
}
void Direction::print_only_value() {
	std::cout << direction_ << std::endl;
}



Course::Course() = default;
Course::Course(unsigned short course) :course_(course) {}
Course::Course(const Course& other) {
	course_ = other.course_;
}
Course& Course::operator=(const Course& other) {
	course_ = other.course_;
	return *this;
}
Course& Course::operator+=(const Course&) {
	course_ = course_ + 1;
	return *this;
}
bool Course::operator!=(const Course& other) {
	if (course_ != other.course_) {
		return true;
	}
	else
	{
		return false;
	}
}
void Course::print_with_text() {
	std::cout << "course: " << course_ << std::endl;
}
void Course::print_only_value() {
	std::cout << course_ << std::endl;
}
unsigned short Course::get() {
	return course_;
}



Groupe::Groupe() = default;
Groupe::Groupe(unsigned short groupe) :groupe_(groupe) {}
Groupe::Groupe(const Groupe& other) {
	groupe_ = other.groupe_;
}
Groupe& Groupe::operator=(const Groupe& other) {
	groupe_ = other.groupe_;
	return *this;
}
void Groupe::print_with_text() {
	std::cout << "groupe: " << groupe_ << std::endl;
}
void Groupe::print_only_value() {
	std::cout << groupe_ << std::endl;
}
unsigned short Groupe::get() {
	return groupe_;
}



Variant::Variant() = default;
Variant::Variant(unsigned short variant) :variant_(variant) {}
Variant::Variant(const Variant& other) {
	variant_ = other.variant_;
}
Variant& Variant::operator=(const Variant& other) {
	variant_ = other.variant_;
	return *this;
}
void Variant::print_with_text() {
	std::cout << "variant: " << variant_ << std::endl;
}
void Variant::print_only_value() {
	std::cout << variant_ << std::endl;
}

Student::Student(Name name, Second_name second_name, Direction direction, Course course, Groupe groupe, Variant variant, std::vector<std::string>& debts) :
	name_(name), second_name_(second_name), direction_(direction), course_(course), groupe_(groupe), variant_(variant), debts_(debts) {
}
Student::Student(Name name, Second_name second_name, std::vector<std::string>& debts) : name_(name), second_name_(second_name), debts_(debts) {}
Student::Student(const Student& other) {
	name_ = other.name_;
	second_name_ = other.second_name_;
	debts_.clear();
	debts_ = other.debts_;
}
Student::~Student() {
	debts_.clear();
	debts_.shrink_to_fit();
	std::cout << "dtor" << std::endl;
}
Student& Student::operator=(const Student& other) {
	name_ = other.name_;
	second_name_ = other.second_name_;
	direction_ = other.direction_;
	course_ = other.course_;
	groupe_ = other.groupe_;
	variant_ = other.variant_;
	std::copy(begin(other.debts_), end(other.debts_), begin(debts_));
	debts_.pop_back();
	return *this;
}
const Student Student::operator+(const Student& other_1) {
	Name name_tmp_ = name_ + " and " + other_1.name_ + " ";
	Second_name second_name_tmp_ = second_name_ + "/" + other_1.second_name_ + " ";
	std::vector<std::string> debts_tmp_;
	for (int i = 0; i < size(other_1.debts_); ++i) {
		if (std::count(begin(debts_), end(debts_), other_1.debts_[i]) == 0) {
			debts_tmp_.push_back(other_1.debts_[i]);
		}
	}
	for (int i = 0; i < size(debts_); ++i) {
		if (std::count(begin(debts_tmp_), end(debts_tmp_), debts_[i]) == 0) {
			debts_tmp_.push_back(debts_[i]);
		}
	}
	return Student{ name_tmp_, second_name_tmp_, debts_tmp_ };
}
Student& Student::operator-=(const Student& other) {
	name_ = name_ + " without " + other.name_ + " ";
	second_name_ = second_name_ + "/" + other.second_name_ + " ";
	for (int i = 0; i < size(debts_); ++i) {
		if (std::count(begin(other.debts_), end(other.debts_), debts_[i]) != 0) {
			std::erase(debts_, debts_[i]);
		}
	}
	course_ = 0;
	return *this;
}
const Student Student::operator/(const Student& other) {
	Name name_tmp_ = name_ + " and " + other.name_ + " ";
	Second_name second_name_tmp_ = second_name_ + "/" + other.second_name_ + " ";
	std::vector<std::string> debts_tmp_ = debts_;
	for (int i = 0; i < size(debts_tmp_); ++i) {
		if (std::count(begin(other.debts_), end(other.debts_), debts_tmp_[i]) == 0) {
			std::erase(debts_tmp_, debts_tmp_[i]);
		}
	}
	return Student{ name_tmp_, second_name_tmp_, debts_tmp_ };
}
Statment Student::next_course(std::string comment) {
	return Statment(name_.get(), second_name_.get(), "next course", comment, (course_.get() + 1));
}
Statment Student::another_groupe(std::string comment, unsigned short groupe) {
	return Statment(name_.get(), second_name_.get(), "another groupe", comment, groupe);
}
void Student::set_name(Name name) {
	name_ = name;
}
void Student::set_second_name(Second_name second_name) {
	second_name_ = second_name;
}
void Student::set_direction(Direction direction) {
	direction_ = direction;
}
void Student::set_course(short course) {
	course_ = course;
}
void Student::set_groupe(Groupe groupe) {
	groupe_ = groupe;
}
void Student::set_variant(short variant) {
	variant_ = variant;
}
void Student::set_debts(std::vector<std::string> debts) {
	std::copy(begin(debts), end(debts), begin(debts_));
	debts_.pop_back();
}
Name Student::get_name() { return name_; }
Second_name Student::get_second_name() { return second_name_; }
Direction Student::get_direction() { return direction_; }
Course Student::get_course() { return course_; }
Groupe Student::get_groupe() { return groupe_; }
Variant Student::get_variant() { return variant_; }
std::vector<std::string> Student::get_debts() { return debts_; }
void Student::get_info() {
	std::cout << "=============\n";
	if (course_.get() != 0) {
		name_.print_with_text();
		second_name_.print_with_text();
		direction_.print_with_text();
		course_.print_with_text();
		groupe_.print_with_text();
		variant_.print_with_text();
		for (int i = 0; i < debts_.size(); ++i) {
			std::cout << debts_[i] << " ";
		}
	}
	else {
		name_.print();
		second_name_.print();
		for (int i = 0; i < debts_.size(); ++i) {
			std::cout << debts_[i] << " ";
		}
	}
	std::cout << "\n";
	std::cout << "=============\n";
}
