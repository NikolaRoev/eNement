#include "Game.h"
#include "AI/AI.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "DrawableManager/DrawableManager.h"
#include "GameStructures.h"
#include "ResourceManager/ResourceManager.h"


#include <algorithm>
#include <functional>
#include <vector>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

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
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left.png", "Volume Arrow Left");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left_HL.png", "Volume Arrow Left HL");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right.png", "Volume Arrow Right");
	resource_manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right_HL.png", "Volume Arrow Right HL");
	resource_manager->add_texture("assets/images/Options Menu/Back_Button.png", "Back Button");
	resource_manager->add_texture("assets/images/Options Menu/Back_Button_HL.png", "Back Button HL");

	resource_manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");
	resource_manager->add_font("assets/fonts/TNR.ttf", "Test Font");

	//====================================================================================================================================

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	//====================================================================================================================================
	//Fight:

	resource_manager->add_texture("assets/images/Game/Fight_Background.png", "Fight Background");

	resource_manager->add_texture_for_pixel_perfect("assets/images/Game/Player.png", "Player");
	resource_manager->add_texture_for_pixel_perfect("assets/images/Game/Spell0.png", "Spell0");
	resource_manager->add_texture_for_pixel_perfect("assets/images/Game/Spell1.png", "Spell1");

	resource_manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0.png", "Enemy0");
	resource_manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0_Attack.png", "Enemy0 Attack");


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
	main_menu_new_game->set_function([&]()
		{
			application_state = NEW_GAME;
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

	Drawable* options_menu_background = new Image;
	options_menu_background->setup(resource_manager->get_texture("Options Menu Background"), 0, 0);
	drawable_manager->add_drawable(*options_menu_background, "Options Menu Background");


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

	//====================================================================================================================================

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	//====================================================================================================================================
	//Fight:

	Drawable* fight_background = new Image;
	fight_background->setup(resource_manager->get_texture("Fight Background"), 0, 0);
	drawable_manager->add_drawable(*fight_background, "Fight Background");

	Drawable* player_drawable = new Player;
	player_drawable->setup(resource_manager->get_texture("Player"), 0, 0);
	drawable_manager->add_drawable(*player_drawable, "Player");


	//====================================================================================================================================


}

void en::Game::load_save_file() {
	//TO DO: Set the PlayerEntity here.
}

void en::Game::save_save_file() {
	//TO DO:
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
			each->draw(core->window, core->event);
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
	application_state = GAME;
}

void en::Game::load_game_loop() {
	//TO DO:
}

void en::Game::options_menu_loop() {
	std::vector<Drawable*> in_frame = {
		drawable_manager->get_drawable("Options Menu Background"),
		drawable_manager->get_drawable("Volume Arrow Left"),
		drawable_manager->get_drawable("Volume Label"),
		drawable_manager->get_drawable("Volume Arrow Right"),
		drawable_manager->get_drawable("Back Button"),
	};


	while (application_state == OPTIONS_MENU) {

		for (const auto& each : in_frame) {
			each->draw(core->window, core->event);
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

//====================================================================================================================================
//====================================================================================================================================

void en::Game::map_loop() {
	//TO DO:
}

void en::Game::fight_loop() {
	std::vector<Drawable*> in_frame_static = {
		drawable_manager->get_drawable("Fight Background"),

	};

	Drawable* temp_player_drawable = drawable_manager->get_drawable("Player");

	//TO DO: Set the current enemy and his drawable pointer here.

	std::vector<Drawable*> player_spells;

	std::vector<Drawable*> enemy_spells;


	while (game_state == FIGHT && application_state != EXIT) {
		TIME = core->clock.restart();
		//std::cout << TIME.asMicroseconds() << '\n';
		

		//Generate spells.

		//TO DO:

		//------------------------------------------------------------------------------------------------------------------------------------


		//Draws.
		for (const auto& each : in_frame_static) {
			each->draw(core->window, core->event);
		}

		temp_player_drawable->draw(core->window, core->event);

		current_enemy->enemy_drawable->draw(core->window);

		for (const auto& each : enemy_spells) {
			each->draw(core->window);
		}

		for (const auto& each : player_spells) {
			each->draw(core->window);
		}


		core->window.display();
		//------------------------------------------------------------------------------------------------------------------------------------

		
		//Hit checks.
		for (const auto& each : enemy_spells) {
			if (each->hit_check(temp_player_drawable->get_sprite())) {
				//Call a do damage function from current enemy.
			}
		}

		for (const auto& each : player_spells) {
			each->hit_check(current_enemy);
		}

		//------------------------------------------------------------------------------------------------------------------------------------


		//Health check, for player and enemy.

		//TO DO:

		//------------------------------------------------------------------------------------------------------------------------------------


		//Move spells and enemy.
		for (const auto& each : enemy_spells) {
			each->move();
		}

		for (const auto& each : player_spells) {
			each->move();
		}

		current_enemy->enemy_drawable->move();

		//------------------------------------------------------------------------------------------------------------------------------------


		//SFML stuff.
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event(drawable_manager);
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
		//------------------------------------------------------------------------------------------------------------------------------------


		//Clear out of bounds spells.
		std::for_each(std::begin(enemy_spells), std::end(enemy_spells), DrawableDeleter());
		std::vector<Drawable*>::iterator new_end = std::remove(std::begin(enemy_spells), std::end(enemy_spells), static_cast<Drawable*>(nullptr));
		enemy_spells.erase(new_end, std::end(enemy_spells));

		std::for_each(std::begin(player_spells), std::end(player_spells), DrawableDeleter());
		new_end = std::remove(std::begin(player_spells), std::end(player_spells), static_cast<Drawable*>(nullptr));
		player_spells.erase(new_end, std::end(player_spells));
		//------------------------------------------------------------------------------------------------------------------------------------
	}

}

void en::Game::win_screen_loop() {
	//TO DO:
}

void en::Game::loss_screen_loop() {
	//TO DO:
}

void en::Game::pause_loop() {
	//TO DO:
	//This loop can be called in every game sub-loop. With a vector of the current drawables passed to it.
	//When this loops is over, we either exit, not saving data for fight loop, or we resume whatever loop we are in.
}

//====================================================================================================================================
//====================================================================================================================================

void en::Game::game_loop() {

	while (application_state == GAME) {
		switch (game_state) {
			case MAP:
				map_loop();
				break;
			case FIGHT:
				fight_loop();
				break;
			case WIN_SCREEN:
				win_screen_loop();
				break;
			case LOSS_SCREEN:
				loss_screen_loop();
				break;
		}
	}

	save_save_file();
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
	core->window.close();
	delete drawable_manager;
	delete resource_manager;
	delete core;
}

//====================================================================================================================================