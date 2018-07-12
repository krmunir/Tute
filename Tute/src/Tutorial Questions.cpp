#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>

namespace item {
	enum item {
		HEALTH_POTIONS,
		TORCHES,
		ARROWS,
		MAX_ITEMS
	};

}

int countTotalItems(int *itemsArray);

int main()
{
	int    itemsCarried[item::MAX_ITEMS]{ 2,5,10 };
	
	std::cout << "No of items carried = " << countTotalItems(itemsCarried);

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

int countTotalItems(int *itemsArray) {
	int totalItems{};
	for (int i = 0; i < item::MAX_ITEMS; ++i)
	{
		totalItems += itemsArray[i];
	}
	return totalItems;
}
