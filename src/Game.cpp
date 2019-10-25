#include "Game.h"
#include "AI/AI.h"
#include "Core/Core.h"
#include "Drawable/Drawable.h"
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

	manager->add_texture("assets/images/Main Menu/Main_Menu_Background.png", "Main Menu Background");
	manager->add_texture("assets/images/Main Menu/Load_Game_Button.png", "Load Game Button");
	manager->add_texture("assets/images/Main Menu/Load_Game_Button_HL.png", "Load Game Button HL");
	manager->add_texture("assets/images/Main Menu/Options_Button.png", "Options Button");
	manager->add_texture("assets/images/Main Menu/Options_Button_HL.png", "Options Button HL");
	manager->add_texture("assets/images/Main Menu/Quit_Button.png", "Quit Button");
	manager->add_texture("assets/images/Main Menu/Quit_Button_HL.png", "Quit Button HL");

	manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");

	//====================================================================================================================================

	//====================================================================================================================================
	//Options Menu:

	manager->add_texture("assets/images/Options Menu/Options_Menu_Background.png", "Options Menu Background");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left.png", "Volume Arrow Left");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left_HL.png", "Volume Arrow Left HL");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right.png", "Volume Arrow Right");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right_HL.png", "Volume Arrow Right HL");
	manager->add_texture("assets/images/Options Menu/Back_Button.png", "Back Button");
	manager->add_texture("assets/images/Options Menu/Back_Button_HL.png", "Back Button HL");

	manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");

	manager->add_font("assets/fonts/TNR.ttf", "Test Font");

	//====================================================================================================================================

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	//====================================================================================================================================
	//Fight:

	manager->add_texture("assets/images/Game/Fight_Background.png", "Fight Background");

	manager->add_texture_for_pixel_perfect("assets/images/Game/Player.png", "Player");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Spell0.png", "Spell0");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Spell1.png", "Spell1");

	manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0.png", "Enemy0");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0_Attack.png", "Enemy0 Attack");


	//====================================================================================================================================

}

void en::Game::set_drawables() {

	//====================================================================================================================================
	//Main Menu:

	Drawable* main_menu_background = new Image(0, 0, manager->get_texture("Main Menu Background"));
	manager->add_drawable(*main_menu_background, "Main Menu Background");



	Drawable* main_menu_load_game = new Button(400, 550, manager->get_texture("Load Game Button"), manager->get_texture("Load Game Button HL"),
		[&]()
		{
			application_state = START_MENU;
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*main_menu_load_game, "Main Menu Load Game Button");


	Drawable* main_menu_options = new Button(400, 750, manager->get_texture("Options Button"), manager->get_texture("Options Button HL"),
		[&]()
		{
			application_state = OPTIONS_MENU;
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*main_menu_options, "Main Menu Options Button");


	Drawable* main_menu_quit = new Button(400, 950, manager->get_texture("Quit Button"), manager->get_texture("Quit Button HL"),
		[&]()
		{
			application_state = EXIT;
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*main_menu_quit, "Main Menu Quit Button");

	//====================================================================================================================================

	//====================================================================================================================================
	//Options Menu:

	Drawable* options_menu_background = new Image(0, 0, manager->get_texture("Options Menu Background"));
	manager->add_drawable(*options_menu_background, "Options Menu Background");


	Drawable* volume_label = new Label(0, 0, sf::Texture(), 1200, 700, manager->get_font("Test Font"), 30, sf::Color::White, std::to_string(core->settings.volume));
	manager->add_drawable(*volume_label, "Volume Label");


	Drawable* volume_arrow_left = new Button(900, 700, manager->get_texture("Volume Arrow Left"), manager->get_texture("Volume Arrow Left HL"),
		[&]()
		{
			if (core->settings.volume > 0) {
				core->settings.volume -= 5;

				auto temp_volume_label = manager->get_drawable("Volume Label");
				temp_volume_label->set_text(std::to_string(core->settings.volume));

				auto temp_drawables = manager->get_all_drawables();
				for (const auto& each : temp_drawables) {
					each.second->set_volume();
				}
			}
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*volume_arrow_left, "Volume Arrow Left");


	Drawable* volume_arrow_right = new Button(1400, 700, manager->get_texture("Volume Arrow Right"), manager->get_texture("Volume Arrow Right HL"),
		[&]()
		{
			if (core->settings.volume < 100) {
				core->settings.volume += 5;

				auto temp_volume_label = manager->get_drawable("Volume Label");
				temp_volume_label->set_text(std::to_string(core->settings.volume));
				
				auto temp_drawables = manager->get_all_drawables();
				for (const auto& each : temp_drawables) {
					each.second->set_volume();
				}
			}
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*volume_arrow_right, "Volume Arrow Right");


	Drawable* back_button = new Button(1400, 900, manager->get_texture("Back Button"), manager->get_texture("Back Button HL"),
		[&]()
		{
			application_state = MAIN_MENU;
		},
		manager->get_sound_buffer("Test Sound"));

	manager->add_drawable(*back_button, "Back Button");

	//====================================================================================================================================

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	//====================================================================================================================================
	//Fight:

	Drawable* fight_background = new Image(0, 0, manager->get_texture("Fight Background"));
	manager->add_drawable(*fight_background, "Fight Background");

	Drawable* player_drawable = new Player(0, 0, manager->get_texture("Player"));
	manager->add_drawable(*player_drawable, "Player");


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
		manager->get_drawable("Main Menu Background"),
		manager->get_drawable("Main Menu Load Game Button"),
		manager->get_drawable("Main Menu Options Button"),
		manager->get_drawable("Main Menu Quit Button")
	};

	
	while (application_state == MAIN_MENU) {

		for (const auto& each : in_frame) {
			each->draw();
		}

		core->window.display();
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			auto[resize_d_x, resize_d_y] = core->on_resize_event();
			
			auto temp_drawables = manager->get_all_drawables();
			for (const auto& each : temp_drawables) {
				each.second->resize(resize_d_x, resize_d_y);
			}
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}

	}

}

void en::Game::start_menu_loop() {
	//TO DO:
	if (player) {
		delete player->drawable;
		delete player;
	}

	
	application_state = GAME;
	player = new PlayerEntity;
	player->drawable = manager->get_drawable("Player");
}

void en::Game::options_menu_loop() {
	std::vector<Drawable*> in_frame = {
		manager->get_drawable("Options Menu Background"),
		manager->get_drawable("Volume Arrow Left"),
		manager->get_drawable("Volume Label"),
		manager->get_drawable("Volume Arrow Right"),
		manager->get_drawable("Back Button"),
	};


	while (application_state == OPTIONS_MENU) {

		for (const auto& each : in_frame) {
			each->draw();
		}

		core->window.display();
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			auto [resize_d_x, resize_d_y] = core->on_resize_event();

			auto temp_drawables = manager->get_all_drawables();
			for (const auto& each : temp_drawables) {
				each.second->resize(resize_d_x, resize_d_y);
			}
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

void en::Game::spells_loop() {
	//TO DO:
}

void en::Game::fight_loop() {
	std::vector<Drawable*> in_frame_static = {
		manager->get_drawable("Fight Background"),

	};

	if (current_enemy) {
		delete current_enemy->drawable;
		delete current_enemy;
	}

	//TO DO: Set the current enemy and his drawable pointer here.
	current_enemy = new EnemyEntity;

	std::vector<SpellEntity*> player_spells{SpellEntity::make_spell(player->first_spell), SpellEntity::make_spell(player->second_spell) };
	
	std::vector<Drawable*> enemy_spells;


	while (game_state == FIGHT && application_state == GAME) {
		core->time = core->clock.restart();
		//std::cout << TIME.asMicroseconds() << '\n';
		

		//Handle events. Generate player spells. Generate enemy spells.
		core->window.pollEvent(core->event);

		if (core->event.type == sf::Event::Resized) {
			auto [resize_d_x, resize_d_y] = core->on_resize_event();

			auto temp_drawables = manager->get_all_drawables();
			for (const auto& each : temp_drawables) {
				each.second->resize(resize_d_x, resize_d_y);
			}
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}

		//TO DO: Add the player spells generation from key press here and the current enemy generate spells function also.

		//------------------------------------------------------------------------------------------------------------------------------------


		//Draws.
		for (const auto& each : in_frame_static) {
			each->draw();
		}

		player->drawable->draw();

		//current_enemy->drawable->draw(core->window);

		//for (const auto& each : enemy_spells) {
			//each->draw(core->window);
		//}

		//for (const auto& each : player_spells) {
			//each->drawable->draw(core->window);
		//}


		core->window.display();
		//------------------------------------------------------------------------------------------------------------------------------------

		
		//Hit checks.
		//for (const auto& each : enemy_spells) {
			//if (each->hit_check(player->drawable->get_sprite())) {
				//Call a do damage function from current enemy.
			//}
		//}

		//for (const auto& each : player_spells) {
			//if (each->drawable->hit_check(current_enemy->drawable->get_sprite())) {
				//TO DO: Add a player spell entity do dmg function here.
			//}
		//}

		//------------------------------------------------------------------------------------------------------------------------------------


		//Health check, for player and enemy.

		//TO DO:

		//------------------------------------------------------------------------------------------------------------------------------------


		//Move spells and enemy.
		//for (const auto& each : enemy_spells) {
			//each->move();
		//}

		//for (const auto& each : player_spells) {
			//each->drawable->move();
		//}

		//current_enemy->drawable->move();

		//------------------------------------------------------------------------------------------------------------------------------------


		//Clear out of bounds enemy spells.
		std::for_each(std::begin(enemy_spells), std::end(enemy_spells), DrawableDeleter());
		std::vector<Drawable*>::iterator new_end = std::remove(std::begin(enemy_spells), std::end(enemy_spells), static_cast<Drawable*>(nullptr));
		enemy_spells.erase(new_end, std::end(enemy_spells));
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

	manager = new ResourceManager;

	set_resources();
	set_drawables();

	while (application_state != EXIT) {
		switch (application_state) {
			case MAIN_MENU:
				main_menu_loop();
				break;
			case START_MENU:
				start_menu_loop();
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
	delete core;
	delete manager;
}

//====================================================================================================================================