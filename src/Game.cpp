#include "Game.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "ResourceManager/ResourceManager.h"



#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Game::main_menu_loop() {

}

void en::Game::new_game_loop() {

}

void en::Game::load_game_loop() {

}

void en::Game::options_menu_loop() {

}

void en::Game::game_loop() {
	//TO DO: Add the pause menu over here, as a new loop maybe, should be easier.

}

//====================================================================================================================================

void en::Game::main_loop() {
	core = new Core;
	core->set_window();

	while (application_state != EXIT) {
		switch (application_state) {
			case EXIT:
				//TO DO: Add update settings struct function here.
				core->save_settings;
				//TO DO: Add the save game function here.
				core->window.close();
				delete core;
				break;
			case MAIN_MENU:
				main_menu_loop();
				break;
			case NEW_GAME:
				new_game_loop();
				break;
			case LOAD_GAME:
				load_game_loop();
				break;
			case OPTIONS_MENU:
				options_menu_loop();
				break;
			case GAME:
				game_loop();
				break;
		}
	}

}

//====================================================================================================================================