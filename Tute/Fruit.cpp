
#include <iostream>
#include "..\Tute\Fruit.h"

std::ostream& operator<<(std::ostream& out, const Apple& app)  {
	out << "Apple(" << app.getName() << ", " << app.getColour() << ", " << app.m_fiber << ")" << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Banana& ban)  {
	out << "Banana(" << ban.getName() << ", " << ban.getColour() << ")" << std::endl;
	return out;
}

