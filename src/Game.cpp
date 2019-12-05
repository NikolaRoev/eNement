#include "Game.h"
#include "Drawable\\Drawable.h"
#include "GameStructures.h"


#include <algorithm>
#include <fstream>
#include <functional>
#include <ios>
#include <vector>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

void en::Game::set_resources() {

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Main Menu:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Main Menu/Main_Menu_Background.png", "Main Menu Background");

	core->manager->add_texture("assets/images/Main Menu/Start_Game_Button.png", "Main Menu Start Game Button");
	core->manager->add_texture("assets/images/Main Menu/Start_Game_Button_HL.png", "Main Menu Start Game Button HL");

	core->manager->add_texture("assets/images/Main Menu/Options_Button.png", "Main Menu Options Button");
	core->manager->add_texture("assets/images/Main Menu/Options_Button_HL.png", "Main Menu Options Button HL");

	core->manager->add_texture("assets/images/Main Menu/Quit_Button.png", "Main Menu Quit Button");
	core->manager->add_texture("assets/images/Main Menu/Quit_Button_HL.png", "Main Menu Quit Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Start Menu:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Options Menu:

	//------------------------------------------------------------------------------------------------------------------------------------
	/*
	manager->add_texture("assets/images/Options Menu/Options_Menu_Background.png", "Options Menu Background");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left.png", "Volume Arrow Left");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Left_HL.png", "Volume Arrow Left HL");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right.png", "Volume Arrow Right");
	manager->add_texture("assets/images/Options Menu/Volume_Arrow_Right_HL.png", "Volume Arrow Right HL");
	manager->add_texture("assets/images/Options Menu/Back_Button.png", "Back Button");
	manager->add_texture("assets/images/Options Menu/Back_Button_HL.png", "Back Button HL");

	manager->add_sound_buffer("assets/sounds/TEST_CLICK.wav", "Test Sound");

	manager->add_font("assets/fonts/TNR.ttf", "Test Font");
	*/
	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Chapter:

	//------------------------------------------------------------------------------------------------------------------------------------

	

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Spells:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Stats:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Fight:

	//------------------------------------------------------------------------------------------------------------------------------------
	/*
	manager->add_texture("assets/images/Game/Fight_Background.png", "Fight Background");

	manager->add_texture_for_pixel_perfect("assets/images/Game/Player.png", "Player");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Spell0.png", "Spell0");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Spell1.png", "Spell1");

	manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0.png", "Enemy0");
	manager->add_texture_for_pixel_perfect("assets/images/Game/Enemy0_Attack.png", "Enemy0 Attack");
	*/
	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Pause:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Win:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Loss:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//End:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
}

void en::Game::set_drawables() {
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Main Menu:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* main_menu_background = new Image(0,
											   0,
											   core->manager->get_texture("Main Menu Background"));
	core->manager->add_drawable(main_menu_background, "Main Menu Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_game_button = new Button(500,
											 500,
											 core->manager->get_texture("Main Menu Start Game Button"),
											 core->manager->get_texture("Main Menu Start Game Button HL"),
		                                     [&application_state = application_state]()
		                                     {
												application_state = START_MENU;
		                                     },
		                                     core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_game_button, "Main Menu Start Game Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* options_button = new Button(500,
										  700,
										  core->manager->get_texture("Main Menu Options Button"),
										  core->manager->get_texture("Main Menu Options Button HL"),
										  [&application_state = application_state]()
										  {
											application_state = OPTIONS_MENU;
										  },
										  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_button, "Main Menu Options Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* quit_button = new Button(500,
									   900,
									   core->manager->get_texture("Main Menu Quit Button"),
									   core->manager->get_texture("Main Menu Quit Button HL"),
									   [&application_state = application_state]()
									   {
										application_state = EXIT;
									   },
									   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(quit_button, "Main Menu Quit Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Start Menu:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Options Menu:

	//------------------------------------------------------------------------------------------------------------------------------------


	
	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Chapter:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Spells:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Stats:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Fight:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Pause:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Win:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Loss:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//End:

	//------------------------------------------------------------------------------------------------------------------------------------



	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
}

//====================================================================================================================================

void en::Game::load_save_files() {
	int i = 0;
	for (auto& each : saves) {
		std::ifstream is("save" + std::to_string(i) + ".bin", std::ios::binary);


		if (is.is_open()) {
			is.read((char*)&each.chapter, sizeof(unsigned int));

			is.read((char*)&each.spell0, sizeof(unsigned int));
			is.read((char*)&each.spell1, sizeof(unsigned int));

			is.read((char*)&each.points, sizeof(unsigned int));
			is.read((char*)&each.barrier_strength, sizeof(unsigned int));
			is.read((char*)&each.magic_power, sizeof(unsigned int));
			is.read((char*)&each.spell_mastery, sizeof(unsigned int));
			is.read((char*)&each.magic_proficiency, sizeof(unsigned int));
		}


		++i;
		is.close();
	}
}

void en::Game::save_save_files() {
	int i = 0;
	for (auto& each : saves) {
		if (each.chapter != 0u) {
			std::ofstream os("save" + std::to_string(i) + ".bin", std::ios::binary);

			os.write((char*)&each.chapter, sizeof(unsigned int));

			os.write((char*)&each.spell0, sizeof(unsigned int));
			os.write((char*)&each.spell1, sizeof(unsigned int));

			os.write((char*)&each.points, sizeof(unsigned int));
			os.write((char*)&each.barrier_strength, sizeof(unsigned int));
			os.write((char*)&each.magic_power, sizeof(unsigned int));
			os.write((char*)&each.spell_mastery, sizeof(unsigned int));
			os.write((char*)&each.magic_proficiency, sizeof(unsigned int));

			os.flush();
			os.close();
		}

		++i;
	}
}

//====================================================================================================================================

void en::Game::main_menu_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Main Menu Background"),
		core->manager->get_drawable("Main Menu Start Game Button"),
		core->manager->get_drawable("Main Menu Options Button"),
		core->manager->get_drawable("Main Menu Quit Button")
	};

	
	while (application_state == MAIN_MENU) {

		core->draw(static_frame);


		core->window.pollEvent(core->event);
		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event();
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
	}

}

void en::Game::start_menu_loop() {
	
}

void en::Game::options_menu_loop() {
	/*
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
	*/
}

//====================================================================================================================================

void en::Game::game_loop() {

	while (application_state == GAME) {
		switch (game_state) {
			case CHAPTER:
				chapter_loop();
				break;
			case SPELLS:
				spells_loop();
				break;
			case STATS:
				stats_loop();
				break;
			case FIGHT:
				fight_loop();
				break;
			case WIN:
				win_loop();
				break;
			case LOSS:
				loss_loop();
				break;
			case END:
				end_loop();
				break;
		}
	}

	save_save_files();
}

void en::Game::chapter_loop() {

}

void en::Game::spells_loop() {

}

void en::Game::stats_loop() {

}

void en::Game::fight_loop() {
	/*
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

		//------------------------------------------------------------------------------------------------------------------------------------
	}
	*/
}

void en::Game::pause_loop() {

}

void en::Game::win_loop() {

}

void en::Game::loss_loop() {

}

void en::Game::end_loop() {

}

//====================================================================================================================================

void en::Game::main_loop() {
	core = new Core(1920.0, 1080.0);
	core->load_settings();
	core->set_window();


	set_resources();
	set_drawables();
	core->adjust_drawables();

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
	delete core;
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================