#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>

namespace item {
	enum item {
		HEALTH_POTIONS,
		TORCHES,
		ARROWS
	};

}

int countTotalItems(int *itemsArray);

int main()
{
	int    itemsCarried[3]{ 2,5,10 };
	
	std::cout << "No of items carried = " << countTotalItems(itemsCarried);

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

int countTotalItems(int *itemsArray) {
	int totalItems{};
	for (int i = 0; i < 3; ++i)
	{
		totalItems += itemsArray[i];
	}
	return totalItems;
}
