#include "Game.h"



int main() {
	en::Game* game = new en::Game;
	game->main_loop();
	delete game;
}