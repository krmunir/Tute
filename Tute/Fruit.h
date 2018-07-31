#pragma once

#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_colour;
public:
	Fruit(std::string name, std::string col) : m_name{ name }, m_colour{ col } {}
	std::string getName() const { return m_name; }
	std::string getColour() const { return m_colour; }
};

class Apple : public Fruit
{
private:
	double m_fiber;
public:
	Apple(std::string name, std::string col, double fib) : Fruit(name, col), m_fiber{ fib } {}
	friend std::ostream& operator<<(std::ostream& out, const Apple& app);
};

class Banana :public Fruit
{
public:
	Banana(std::string name, std::string col) : Fruit(name, col) {}
	friend std::ostream& operator<<(std::ostream& out, const Banana& ban);
};