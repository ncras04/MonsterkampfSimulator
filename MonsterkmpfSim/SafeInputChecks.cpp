#include "SafeInputChecks.h"

int GetNumberInput(int _min, int _max)
{
	int input;
	std::string strInput;
	char* p;

	do
	{
		std::cout << "\nWaehle eine Nummer zwischen " << _min << " und " << _max << "\n";
		std::getline(std::cin, strInput);
		input = strtol(strInput.c_str(), &p, 10);

		if (*p)
			std::cout << "Deine Eingabe ist keine gueltige Zahl!";
		else if (input < _min || input > _max)
			std::cout << "Deine Eingabe ist ungueltig.";
		else
			return input;


	} while (true);

	return 0;
}

std::string GetStringInput()
{
	std::string input;

	std::getline(std::cin, input);

	while (input == "")
	{
		std::cout << "Deine Eingabe ist ungueltig.\n";
		std::cout << "Bitte gib einen gueltigen Namen ein:\n";
		std::getline(std::cin, input);
	}

	return input;
}