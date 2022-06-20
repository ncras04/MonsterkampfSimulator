#ifndef SAFEINPUTCHECKS_H
#define	SAFEINPUTCHECKS_H	// SafeInputChecks stellt eine Liste an Funktionen bereit, die jederzeit von überall aufrufbar sein sollen

#include <iostream>
#include <string>
#include <memory>

int GetNumberInput(int _min, int _max);	// Überprüft die Korrektheit einer Zifferneingabe des Nutzers
std::string GetStringInput();	// Überprüft, ob eine Eingabe überhaupt erfolgt ist oder das Feld leer gelassen wurde

#endif // !SAFEINPUTCHECKS_H

