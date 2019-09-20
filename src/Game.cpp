#include "Game.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "ResourceManager/ResourceManager.h"

#include <vector>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

//====================================================================================================================================

std::vector<sf::VideoMode> en::Game::get_fullscreen_modes()
{
	std::vector<sf::VideoMode> hold = sf::VideoMode::getFullscreenModes();
	std::vector<sf::VideoMode> out;

	for (auto each : hold) {
		if (each.bitsPerPixel == 32) out.push_back(each);
	}

	return out;
}

//====================================================================================================================================

std::vector<std::shared_ptr<en::Drawable>> en::Game::main_menu_set_drawables(const std::unique_ptr<ResourceManager>& manager) {
	manager->add_texture("assets/Main_Menu_Background.png", "Main Menu Background");
	manager->add_texture("assets/New_Game_Button.png", "New Game Button");
	manager->add_texture("assets/Load_Game_Button.png", "Load Game Button");
	manager->add_texture("assets/Options_Button.png", "Options Button");
	manager->add_texture("assets/Quit_Button.png", "Quit Button");
	manager->add_sound_buffer("assets/TEST_CLICK.wav", "Test Sound");


	std::shared_ptr<Drawable> main_menu_background = std::make_shared<Image>();
	main_menu_background->setup(manager->get_texture("Main Menu Background"), 0, 0);

	std::shared_ptr<Drawable> main_menu_new_game = std::make_shared<Button>();
	main_menu_new_game->setup(manager->get_texture("New Game Button"), manager->get_texture("Quit Button"), 400, 350);
	main_menu_new_game->set_function([]() {
		std::cout << "new game\n";
	});
	main_menu_new_game->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_load_game = std::make_shared<Button>();
	main_menu_load_game->setup(manager->get_texture("Load Game Button"), manager->get_texture("Load Game Button"), 400, 550);
	main_menu_load_game->set_function([]() {
		std::cout << "load game\n";
	});
	main_menu_load_game->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_options = std::make_shared<Button>();
	main_menu_options->setup(manager->get_texture("Options Button"), manager->get_texture("Options Button"), 400, 750);
	main_menu_options->set_function([&]() {
		application_state = OPTIONS_MENU;
	});
	main_menu_options->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_quit = std::make_shared<Button>();
	main_menu_quit->setup(manager->get_texture("Quit Button"), manager->get_texture("Quit Button"), 400, 950);
	main_menu_quit->set_function([&]() {
		application_state = EXIT;
	});
	main_menu_quit->set_sound(manager->get_sound_buffer("Test Sound"));


	return { main_menu_background, main_menu_new_game, main_menu_load_game, main_menu_options, main_menu_quit };
}

std::vector<std::shared_ptr<en::Drawable>> en::Game::options_menu_set_drawables(const std::unique_ptr<ResourceManager>& manager) {
	std::vector<sf::VideoMode> fullscreen_modes = get_fullscreen_modes();
	
	
	
	
	
	
	return {};
}

//====================================================================================================================================

void en::Game::main_menu_loop() {
	std::unique_ptr<ResourceManager> manager = std::make_unique<ResourceManager>();
	std::vector<std::shared_ptr<Drawable>> in_frame = main_menu_set_drawables(manager);
	
	while (application_state == MAIN_MENU) {

		for (const auto& each : in_frame) {
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
	//TO DO:
}

void en::Game::load_game_loop() {
	//TO DO:
}

void en::Game::options_menu_loop() {
	std::unique_ptr<ResourceManager> manager = std::make_unique<ResourceManager>();
	std::vector<std::shared_ptr<Drawable>> in_frame = options_menu_set_drawables(manager);

	while (application_state == OPTIONS_MENU) {

		for (const auto& each : in_frame) {
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

	core->save_settings();
	//TO DO: Add the save game function here.
	core->window.close();
	delete core;
}

//====================================================================================================================================