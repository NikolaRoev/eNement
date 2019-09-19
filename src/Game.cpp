#include "Game.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "ResourceManager/ResourceManager.h"

#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Game::main_menu_loop() {
	ResourceManager manager;

	
	//TO DO: Add the drawables here. Don't forget to delete them. Or use a unique pointer.


	std::vector<Drawable*> in_frame = {};
	
	while (application_state == MAIN_MENU) {

		for (const auto each : in_frame) {
			each->draw(core->window, core->event, core->mouse);
		}

		core->window.display();
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event(in_frame);
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}

	}
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
	core->load_settings();
	core->set_window();

	while (application_state != EXIT) {
		switch (application_state) {
			case EXIT:
				core->save_settings();
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