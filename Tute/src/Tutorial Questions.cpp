#include <iostream>
#include<string>

enum class animalType {
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH
};

struct animal
{
	animalType type;
	int noOfLegs;
};

std::string	getAnimalName(animal anim);

int getNumberOfLegs(animal anim);

int main() {

	animal pussy{ animalType::CAT,4 };
	animal chook{ animalType::CHICKEN,2 };

	std::cout << "A " << getAnimalName(pussy) << " has " << pussy.noOfLegs << " legs." << std::endl;
	std::cout << "A " << getAnimalName(chook) << " has " << chook.noOfLegs << " legs." << std::endl;

	std::cin.get();


	return 0;
}

std::string	getAnimalName(animal anim) {
	switch (anim.type)
	{
	case animalType::CAT:
		return "cat";
	case animalType::DOG:
		return "dog";
	case animalType::PIG:
		return "pig";
	case animalType::CHICKEN:
		return "chicken";
	case animalType::OSTRICH:
		return "ostrich";
	case animalType::GOAT:
		return "goat";
	default:
		return "unknown animal";
	}
}

int getNumberOfLegs(animal anim) {
	return anim.noOfLegs;
}
