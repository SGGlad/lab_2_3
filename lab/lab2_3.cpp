#include "Student.hpp"
#include <university.hpp>
#include <iostream>
#include <vector>






int main() {
	Name name{ "Fedya" };
	Second_name second_name{ "Zuev" };
	Direction direction{ "translater" };
	Course cours = 1;
	Groupe groupe = 3;
	Variant variant = 2;
	std::vector<std::string> debts{ "algebra", "geometry", "english"};
	Student student_1(name, second_name, direction, cours, groupe, variant, debts);
	student_1.get_info();

	Student student_2 = student_1;

	student_1.set_name(Name{ "Petr" });
	student_1.set_second_name(Second_name{ "Ivanov" });
	student_1.set_direction(Direction{ "programmer" });
	student_1.set_groupe(5);
	student_1.set_course(2);
	student_1.set_variant(1);
	student_1.set_debts({ "programming", "algebra" });
	student_1.get_info();

	Name get_test_name;
	Second_name get_test_second_name;
	Direction get_test_direction;
	Course get_test_course;
	Groupe get_test_groupe;
	Variant get_test_variant;
	std::vector<std::string> get_test_debts;

	get_test_name = student_1.get_name();
	get_test_second_name = student_1.get_second_name();
	get_test_direction = student_1.get_direction();
	get_test_course = student_1.get_course();
	get_test_groupe = student_1.get_groupe();
	get_test_variant = student_1.get_variant();
	get_test_debts = student_1.get_debts();
	get_test_name.print(); get_test_second_name.print(); get_test_direction.print_only_value();
	get_test_course.print_only_value(); get_test_groupe.print_only_value(); get_test_variant.print_only_value();
	student_2.get_info();

	Statment statment_for_naxt_course_student_1 = student_1.next_course("i pass all exams");
	Statment statment_for_another_groupe_student_1 = student_1.another_groupe("just want", 7);
	statment_for_naxt_course_student_1.print();
	std::cout << "================\n";
	statment_for_another_groupe_student_1.print();

	Student student_3 = student_2;
	student_3 = student_1;
	student_3.get_info();

	Decanat decanat{ "Al. Nevskogo str. 14" };
	decanat.Attach(&student_1);
	decanat.Attach(&student_2);
	decanat.Attach(&student_3);
	decanat.print();
	decanat.Expel(&student_1);
	decanat.print();

	Student students_1_2 = student_1 + student_2;
	students_1_2.get_info();


	Student students_1_2_ = student_1 / student_2;
	students_1_2_.get_info();

	student_3 -= student_2;
	student_3.get_info();
}
