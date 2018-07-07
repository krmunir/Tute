#include <iostream>
#include<string>

struct advertising {
	int noOfAdsShown = 0;
	int perOfAdsClicked = 0;
	float earningsPerClick = 0.0;
};

void showAdDetails(advertising ad);

int main() {

	
	advertising adType1{ 20,40,.05 };

	showAdDetails(adType1);



	return 0;
}

void showAdDetails(advertising ad) {
	std::cout << "The number of ads shown = " << ad.noOfAdsShown << std::endl;
	std::cout << "The percentage of ads clicked = " << ad.perOfAdsClicked << std::endl;
	std::cout << "The earning per ad = " << ad.earningsPerClick << std::endl;
	std::cout << "Total earnings = " << ad.noOfAdsShown*ad.perOfAdsClicked/100*ad.earningsPerClick << std::endl;
	std::cin.get();
}
