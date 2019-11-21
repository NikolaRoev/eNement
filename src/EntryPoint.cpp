//#include "Game.h"
#include "eNgine/eNgine.h"


int main() {
	//en::Game* game = new en::Game;
	//game->main_loop();
	//delete game;
	en::Drawable1* test = new en::Button1();
	en::Drawable1* test1 = test->clone();
	std::cin.get();
}