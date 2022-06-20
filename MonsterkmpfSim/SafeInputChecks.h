#ifndef SAFEINPUTCHECKS_H
#define	SAFEINPUTCHECKS_H	// SafeInputChecks stellt eine Liste an Funktionen bereit, die jederzeit von �berall aufrufbar sein sollen

#include <iostream>
#include <string>
#include <memory>

int GetNumberInput(int _min, int _max);	// �berpr�ft die Korrektheit einer Zifferneingabe des Nutzers
std::string GetStringInput();	// �berpr�ft, ob eine Eingabe �berhaupt erfolgt ist oder das Feld leer gelassen wurde

#endif // !SAFEINPUTCHECKS_H

