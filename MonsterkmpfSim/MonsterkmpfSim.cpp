#include "Game.h"

int main()
{
	std::unique_ptr<Game> m_game = std::make_unique<Game>();
	/* Erstellt ein Objekt des Typs "Game" auf dem Heap
	Der Unique Pointer sorgt daf�r, dass dieses Objekt
	nicht �bergeben werden kann und sorgf�ltig aus dem Speicher
	entfernt wird, sobald nicht mehr ben�tigt.*/

	m_game->GameInit();		// Der Zeiger-zu-Member Operator "->" anstelle von "." (m_game.GameInit()) ist ben�tigt
	m_game->GameLoop();		// Weil: m_game ist nur ein Pointer zum Objekt im Heap und nicht direkt das Objekt
	m_game->GameEnd();

	std::cin.get();		// Pausiert den Programmdurchlauf (vgl. "Console.ReadLine()")

	return 0;
}
