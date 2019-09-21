#include "Game.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "DrawableManager/DrawableManager.h"
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

void en::Game::set_resources() {

	//====================================================================================================================================
	//Main Menu:

	resource_manager->add_texture("assets/images/Main Menu/Main_Menu_Background.png", "Main Menu Background");
	resource_manager->add_texture("assets/images/Main Menu/New_Game_Button.png", "New Game Button");
	resource_manager->add_texture("assets/images/Main Menu/New_Game_Button_HL.png", "New Game Button HL");
	resource_manager->add_texture("assets/images/Main Menu/Load_Game_Button.png", "Load Game Button");
	resource_manager->add_texture("assets/images/Main Menu/Load_Game_Button_HL.png", "Load Game Button HL");
	resource_manager->add_texture("assets/images/Main Menu/Options_Button.png", "Options Button");
	resource_manager->add_texture("assets/images/Main Menu/Options_Button_HL.png", "Options Button HL");
	resource_manager->add_texture("assets/images/Main Menu/Quit_Button.png", "Quit Button");
	resource_manager->add_texture("assets/images/Main Menu/Quit_Button_HL.png", "Quit Button HL");

	resource_manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");

	//====================================================================================================================================

	//====================================================================================================================================
	//Options Menu:

	resource_manager->add_texture("assets/images/Options Menu/Options_Menu_Background.png", "Options Menu Background");
	resource_manager->add_texture("assets/images/Options Menu/Size_Button.png", "Size Button");
	resource_manager->add_texture("assets/images/Options Menu/Size_Button_HL.png", "Size Button HL");
	resource_manager->add_texture("assets/images/Options Menu/Full_Screen_Button.png", "Fullscreen Button");
	resource_manager->add_texture("assets/images/Options Menu/Full_Screen_Button_HL.png", "Fullscreen Button HL");
	resource_manager->add_texture("assets/images/Options Menu/Full_Screen_Button_Clicked.png", "Fullscreen Button Clicked");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left.png", "Volume Arrow Left");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left_HL.png", "Volume Arrow Left HL");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right.png", "Volume Arrow Right");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right_HL.png", "Volume Arrow Right HL");
	resource_manager->add_texture("assets/images/Options Menu/Back_Button.png", "Back Button");
	resource_manager->add_texture("assets/images/Options Menu/Back_Button_HL.png", "Back Button HL");

	resource_manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");
	resource_manager->add_font("assets/fonts/TNR.ttf", "Test Font");

	//====================================================================================================================================

}

void en::Game::set_drawables() {

	//====================================================================================================================================
	//Main Menu:

	Drawable* main_menu_background = new Image;
	main_menu_background->setup(resource_manager->get_texture("Main Menu Background"), 0, 0);
	drawable_manager->add_drawable(*main_menu_background, "Main Menu Background");


	Drawable* main_menu_new_game = new Button();
	main_menu_new_game->setup(resource_manager->get_texture("New Game Button"), resource_manager->get_texture("New Game Button HL"), 400, 350);
	main_menu_new_game->set_function([]()
		{
			std::cout << "new game\n";
		});
	main_menu_new_game->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*main_menu_new_game, "Main Menu New Game Button");


	Drawable* main_menu_load_game = new Button();
	main_menu_load_game->setup(resource_manager->get_texture("Load Game Button"), resource_manager->get_texture("Load Game Button HL"), 400, 550);
	main_menu_load_game->set_function([]()
		{
			std::cout << "load game\n";
		});
	main_menu_load_game->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*main_menu_load_game, "Main Menu Load Game Button");


	Drawable* main_menu_options = new Button();
	main_menu_options->setup(resource_manager->get_texture("Options Button"), resource_manager->get_texture("Options Button HL"), 400, 750);
	main_menu_options->set_function([&]()
		{
			application_state = OPTIONS_MENU;
		});
	main_menu_options->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*main_menu_options, "Main Menu Options Button");


	Drawable* main_menu_quit = new Button();
	main_menu_quit->setup(resource_manager->get_texture("Quit Button"), resource_manager->get_texture("Quit Button HL"), 400, 950);
	main_menu_quit->set_function([&]()
		{
			application_state = EXIT;
		});
	drawable_manager->add_drawable(*main_menu_quit, "Main Menu Quit Button");

	//====================================================================================================================================

	//====================================================================================================================================
	//Options Menu:

	std::vector<sf::VideoMode> fullscreen_modes = get_fullscreen_modes();

	Drawable* options_menu_background = new Image;
	options_menu_background->setup(resource_manager->get_texture("Options Menu Background"), 0, 0);
	drawable_manager->add_drawable(*options_menu_background, "Options Menu Background");


	bool temp_full_screen_check = false;
	if (core->settings.style == 8) {
		temp_full_screen_check = true;
	}
	Drawable* full_screen_button = new ToggleButton;
	full_screen_button->setup(resource_manager->get_texture("Fullscreen Button"), resource_manager->get_texture("Fullscreen Button HL"), resource_manager->get_texture("Fullscreen Button Clicked"), 1000, 500, temp_full_screen_check);
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
	full_screen_button->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*full_screen_button, "Full Screen Button");


	Drawable* volume_label = new Label;
	volume_label->setup(resource_manager->get_font("Test Font"), 30, sf::Color::White, 1200, 700, std::to_string(core->settings.volume));
	drawable_manager->add_drawable(*volume_label, "Volume Label");


	Drawable* volume_arrow_left = new Button;
	volume_arrow_left->setup(resource_manager->get_texture("Volume Arrow Left"), resource_manager->get_texture("Volume Arrow Left HL"), 900, 700);
	volume_arrow_left->set_function([&]()
		{
			if (VOLUME > 0) {
				VOLUME -= 5;
				core->settings.volume -= 5;

				auto temp_volume_label = drawable_manager->get_drawable("Volume Label");
				temp_volume_label->set_text(std::to_string(core->settings.volume));
				drawable_manager->change_volume_for_all();
			}
		});
	volume_arrow_left->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*volume_arrow_left, "Volume Arrow Left");


	Drawable* volume_arrow_right = new Button;
	volume_arrow_right->setup(resource_manager->get_texture("Volume Arrow Right"), resource_manager->get_texture("Volume Arrow Right HL"), 1400, 700);
	volume_arrow_right->set_function([&]()
		{
			if (VOLUME < 100) {
				VOLUME += 5;
				core->settings.volume += 5;

				auto temp_volume_label = drawable_manager->get_drawable("Volume Label");
				temp_volume_label->set_text(std::to_string(core->settings.volume));
				drawable_manager->change_volume_for_all();
			}
		});
	volume_arrow_right->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*volume_arrow_right, "Volume Arrow Right");


	Drawable* back_button = new Button;
	back_button->setup(resource_manager->get_texture("Back Button"), resource_manager->get_texture("Back Button HL"), 1400, 900);
	back_button->set_function([&]()
		{
			application_state = MAIN_MENU;
		});
	back_button->set_sound(resource_manager->get_sound_buffer("Test Sound"));
	drawable_manager->add_drawable(*back_button, "Back Button");


	float y_temp = 400;
	for (const auto each : fullscreen_modes) {

		Drawable* size_button = new TextButton;
		size_button->setup(resource_manager->get_texture("Size Button"), resource_manager->get_texture("Size Button HL"), 400, y_temp, resource_manager->get_font("Test Font"), 40, sf::Color::White, 400, y_temp + 20, std::to_string(each.width) + "X" + std::to_string(each.height));
		size_button->set_function([&, each]()
			{
				core->settings.width = each.width;
				core->settings.height = each.height;
				core->set_window();
			});
		size_button->set_sound(resource_manager->get_sound_buffer("Test Sound"));

		y_temp += 100;

		drawable_manager->add_vector_of_drawables(*size_button, "Size Buttons");
	}

	//====================================================================================================================================


}

//====================================================================================================================================

void en::Game::main_menu_loop() {
	std::vector<Drawable*> in_frame = {
		drawable_manager->get_drawable("Main Menu Background"),
		drawable_manager->get_drawable("Main Menu New Game Button"),
		drawable_manager->get_drawable("Main Menu Load Game Button"),
		drawable_manager->get_drawable("Main Menu Options Button"),
		drawable_manager->get_drawable("Main Menu Quit Button")
	};

	
	while (application_state == MAIN_MENU) {

		for (const auto& each : in_frame) {
			each->draw(core->window, core->event, core->mouse);
		}

		core->window.display();
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event(drawable_manager);
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
	std::vector<Drawable*> in_frame = {
		drawable_manager->get_drawable("Options Menu Background"),
		drawable_manager->get_drawable("Full Screen Button"),
		drawable_manager->get_drawable("Volume Arrow Left"),
		drawable_manager->get_drawable("Volume Label"),
		drawable_manager->get_drawable("Volume Arrow Right"),
		drawable_manager->get_drawable("Back Button"),
	};
	auto temp_insert_vector = drawable_manager->get_vector_of_drawables("Size Buttons");
	in_frame.insert(in_frame.end(), temp_insert_vector.begin(), temp_insert_vector.end());


	while (application_state == OPTIONS_MENU) {

		for (const auto& each : in_frame) {
			each->draw(core->window, core->event, core->mouse);
		}

		core->window.display();
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event(drawable_manager);
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

	resource_manager = new ResourceManager;
	set_resources();

	drawable_manager = new DrawableManager;
	set_drawables();


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