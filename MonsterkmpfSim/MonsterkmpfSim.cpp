#include "Game.h"

int main()
{
	std::unique_ptr<Game> m_game = std::make_unique<Game>();
	/* Erstellt ein Objekt des Typs "Game" auf dem Heap
	Der Unique Pointer sorgt dafür, dass dieses Objekt
	nicht übergeben werden kann und sorgfältig aus dem Speicher
	entfernt wird, sobald nicht mehr benötigt.*/

	m_game->GameInit();		// Der Zeiger-zu-Member Operator "->" anstelle von "." (m_game.GameInit()) ist benötigt
	m_game->GameLoop();		// Weil: m_game ist nur ein Pointer zum Objekt im Heap und nicht direkt das Objekt
	m_game->GameEnd();

	std::cin.get();		// Pausiert den Programmdurchlauf (vgl. "Console.ReadLine()")

	return 0;
}
