#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>

struct studentDetails
{
	std::string firstName{};
	int grade{};
};

int main()
{
	int numStudents{};
	std::cout << "How many students do you want to enter? ";
	std::cin >> numStudents;

	//dynamically create array 'students' to hold student info
	studentDetails *students = new studentDetails[numStudents];

	//enter student details
	for (int i = 0; i < numStudents; ++i)
	{
		std::cout << "Enter name of student " << (i + 1) << ": ";
		std::cin >> students[i].firstName;

		std::cout << "Enter grade of student " << (i + 1) << ": ";
		std::cin >> students[i].grade;
		std::cout << std::endl;
	}

	//print out student details
	for (int i = 0; i < numStudents; ++i)
	{
		std::cout << students[i].firstName << " received a grade of " << students[i].grade << std::endl;
	}

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

