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
	manager->add_texture("assets/images/Main Menu/Main_Menu_Background.png", "Main Menu Background");
	manager->add_texture("assets/images/Main Menu/New_Game_Button.png", "New Game Button");
	manager->add_texture("assets/images/Main Menu/Load_Game_Button.png", "Load Game Button");
	manager->add_texture("assets/images/Main Menu/Options_Button.png", "Options Button");
	manager->add_texture("assets/images/Main Menu/Quit_Button.png", "Quit Button");

	manager->add_texture("assets/images/Main Menu/New_Game_Button_HL.png", "New Game Button HL");
	manager->add_texture("assets/images/Main Menu/Load_Game_Button_HL.png", "Load Game Button HL");
	manager->add_texture("assets/images/Main Menu/Options_Button_HL.png", "Options Button HL");
	manager->add_texture("assets/images/Main Menu/Quit_Button_HL.png", "Quit Button HL");

	manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");


	std::shared_ptr<Drawable> main_menu_background = std::make_shared<Image>();
	main_menu_background->setup(manager->get_texture("Main Menu Background"), 0, 0);

	std::shared_ptr<Drawable> main_menu_new_game = std::make_shared<Button>();
	main_menu_new_game->setup(manager->get_texture("New Game Button"), manager->get_texture("New Game Button HL"), 400, 350);
	main_menu_new_game->set_function([]() {
		std::cout << "new game\n";
	});
	main_menu_new_game->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_load_game = std::make_shared<Button>();
	main_menu_load_game->setup(manager->get_texture("Load Game Button"), manager->get_texture("Load Game Button HL"), 400, 550);
	main_menu_load_game->set_function([]() {
		std::cout << "load game\n";
	});
	main_menu_load_game->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_options = std::make_shared<Button>();
	main_menu_options->setup(manager->get_texture("Options Button"), manager->get_texture("Options Button HL"), 400, 750);
	main_menu_options->set_function([&]() {
		application_state = OPTIONS_MENU;
	});
	main_menu_options->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> main_menu_quit = std::make_shared<Button>();
	main_menu_quit->setup(manager->get_texture("Quit Button"), manager->get_texture("Quit Button HL"), 400, 950);
	main_menu_quit->set_function([&]() {
		application_state = EXIT;
	});
	main_menu_quit->set_sound(manager->get_sound_buffer("Test Sound"));


	return { main_menu_background, main_menu_new_game, main_menu_load_game, main_menu_options, main_menu_quit };
}

std::vector<std::shared_ptr<en::Drawable>> en::Game::options_menu_set_drawables(const std::unique_ptr<ResourceManager>& manager) {
	std::vector<sf::VideoMode> fullscreen_modes = get_fullscreen_modes();
	
	manager->add_texture("assets/images/Options Menu/Options_Menu_Background.png", "Options Menu Background");
	manager->add_texture("assets/images/Options Menu/Size_Button.png", "Size Button");
	manager->add_texture("assets/images/Options Menu/Size_Button_HL.png", "Size Button HL");
	manager->add_texture("assets/images/Options Menu/Full_Screen_Button.png", "Fullscreen Button");
	manager->add_texture("assets/images/Options Menu/Full_Screen_Button_HL.png", "Fullscreen Button HL");
	manager->add_texture("assets/images/Options Menu/Full_Screen_Button_Clicked.png", "Fullscreen Button Clicked");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left.png", "Volume Arrow Left");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left_HL.png", "Volume Arrow Left HL");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right.png", "Volume Arrow Right");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right_HL.png", "Volume Arrow Right HL");
	manager->add_texture("assets/images/Options Menu/Back_Button.png", "Back Button");
	manager->add_texture("assets/images/Options Menu/Back_Button_HL.png", "Back Button HL");
	
	manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");
	manager->add_font("assets/fonts/TNR.ttf", "Test Font");
	

	std::shared_ptr<Drawable> options_menu_background = std::make_shared<Image>();
	options_menu_background->setup(manager->get_texture("Options Menu Background"), 0, 0);
	
	bool temp_full_screen_check = false;
	if (core->settings.style == 8) {
		temp_full_screen_check = true;
	}
	std::shared_ptr<Drawable> full_screen_button = std::make_shared<ToggleButton>();
	full_screen_button->setup(manager->get_texture("Fullscreen Button"), manager->get_texture("Fullscreen Button HL"), manager->get_texture("Fullscreen Button Clicked"), 1000, 500, temp_full_screen_check);
	full_screen_button->set_function([&]()
		{
			if (core->settings.style == 7) {
				core->settings.style = 8;
				core->set_window();
			}
			else if (core->settings.style == 8) {
				core->settings.style = 7;
				core->set_window();
			}
		});
	full_screen_button->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> volume_arrow_left = std::make_shared<Button>();
	volume_arrow_left->setup(manager->get_texture("Volume Arrow Left"), manager->get_texture("Volume Arrow Left HL"), 900, 700);
	volume_arrow_left->set_function([&]()
		{
			if (VOLUME > 0) {
				VOLUME -= 5;
				core->settings.volume -= 5;
			}
		});
	volume_arrow_left->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> volume_label = std::make_shared<Label>();
	volume_label->setup(manager->get_font("Test Font"), 30, sf::Color::White, 1200, 700, std::to_string(core->settings.volume));

	std::shared_ptr<Drawable> volume_arrow_right = std::make_shared<Button>();
	volume_arrow_right->setup(manager->get_texture("Volume Arrow Right"), manager->get_texture("Volume Arrow Right HL"), 1400, 700);
	volume_arrow_right->set_function([&]()
		{
			if (VOLUME < 100) {
				VOLUME += 5;
				core->settings.volume += 5;
			}
		});
	volume_arrow_right->set_sound(manager->get_sound_buffer("Test Sound"));

	std::shared_ptr<Drawable> back_button = std::make_shared<Button>();
	back_button->setup(manager->get_texture("Back Button"), manager->get_texture("Back Button HL"), 1400, 900);
	back_button->set_function([&]()
		{
			application_state = MAIN_MENU;
		});
	back_button->set_sound(manager->get_sound_buffer("Test Sound"));


	std::vector<std::shared_ptr<en::Drawable>> out = { options_menu_background, full_screen_button, volume_arrow_left, volume_label, volume_arrow_right, back_button };

	float y_temp = 400;
	for (const auto each : fullscreen_modes) {
		
		std::shared_ptr<Drawable> size_button = std::make_shared<TextButton>();
		size_button->setup(manager->get_texture("Size Button"), manager->get_texture("Size Button HL"), 400, y_temp, manager->get_font("Test Font"), 40, sf::Color::White, 400, y_temp + 20, std::to_string(each.width) + "X" + std::to_string(each.height));
		size_button->set_function([&, each]()
			{
				core->settings.width = each.width;
				core->settings.height = each.height;
				core->set_window();
			});
		size_button->set_sound(manager->get_sound_buffer("Test Sound"));

		out.push_back(size_button);

		y_temp += 100;

	}


	return out;
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