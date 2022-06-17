#include "Game.h"

int main()
{
	std::unique_ptr<Game> m_game = std::make_unique<Game>();

	m_game->GameInit();
	m_game->GameLoop();
	m_game->GameEnd();

	std::cin.get();

	return 0;
}
