#include "SafeInputChecks.h"

int GetNumberInput(int _min, int _max)
{
	int input;
	std::string strInput;
	char* p;	// Wird zur speicherung des Ergebnisses der strtol() Funktion verwendet

	do
	{
		std::cout << "\nWaehle eine Nummer zwischen " << _min << " und " << _max << "\n";
		std::getline(std::cin, strInput);
		input = strtol(strInput.c_str(), &p, 10);	// Ergebnis von strtol (&p) ist 0, sofern nur Zahlen im Input sind

		if (*p)		// Werte werden automatisch als Bool repräsentiert: 0 = false, alles andere = true;
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

	std::getline(std::cin, input); // Speichert eine Eingabe mitsamt Leerzeichen

	while (input == "") 
	{
		std::cout << "Deine Eingabe ist ungueltig.\n";
		std::cout << "Bitte gib einen gueltigen Namen ein:\n";
		std::getline(std::cin, input);
	}

	return input;
}