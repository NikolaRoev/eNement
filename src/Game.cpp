#include "Game.h"
#include "Drawable\\Drawable.h"
#include "GameStructures.h"


#include <algorithm>
#include <cstdio>
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

	core->manager->add_texture("assets/images/Start Menu/Start_Menu_Background.png", "Start Menu Background");

	core->manager->add_texture("assets/images/Start Menu/Start_Load_Button.png", "Start Menu Start Load Button");
	core->manager->add_texture("assets/images/Start Menu/Start_Load_Button_HL.png", "Start Menu Start Load Button HL");

	core->manager->add_texture("assets/images/Start Menu/Delete_Button.png", "Start Menu Delete Button");
	core->manager->add_texture("assets/images/Start Menu/Delete_Button_HL.png", "Start Menu Delete Button HL");

	core->manager->add_texture("assets/images/Start Menu/Back_Button.png", "Start Menu Back Button");
	core->manager->add_texture("assets/images/Start Menu/Back_Button_HL.png", "Start Menu Back Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_font("assets/fonts/TNR.ttf", "Test Font");

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

	Drawable* start_menu_background = new Image(0,
												0,
												core->manager->get_texture("Start Menu Background"));
	core->manager->add_drawable(start_menu_background, "Start Menu Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_0 = new Button(300,
														  400,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[0];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_0, "Start Menu Start Load Button 0");

	Drawable* start_menu_save_label_0 = new Label(300,
												  400,
												  sf::Texture(),
												  310,
												  410,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_0, "Start Menu Save Label 0");

	Drawable* start_menu_delete_button_0 = new DeleteButton(700,
															400,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_0, &saves = saves]()
															{
																start_menu_save_label_0->set_text("New Game");
																saves[0] = {};
																std::remove("save0.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[0].chapter);
	core->manager->add_drawable(start_menu_delete_button_0, "Start Menu Delete Button 0");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_1 = new Button(1000,
														  400,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[1];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_1, "Start Menu Start Load Button 1");

	Drawable* start_menu_save_label_1 = new Label(1000,
												  400,
												  sf::Texture(),
												  1010,
												  410,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_1, "Start Menu Save Label 1");

	Drawable* start_menu_delete_button_1 = new DeleteButton(1400,
															400,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_1, &saves = saves]()
															{
																start_menu_save_label_1->set_text("New Game");
																saves[1] = {};
																std::remove("save1.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[1].chapter);
	core->manager->add_drawable(start_menu_delete_button_1, "Start Menu Delete Button 1");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_2 = new Button(300,
														  600,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[2];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_2, "Start Menu Start Load Button 2");

	Drawable* start_menu_save_label_2 = new Label(300,
												  600,
												  sf::Texture(),
												  310,
												  610,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_2, "Start Menu Save Label 2");

	Drawable* start_menu_delete_button_2 = new DeleteButton(700,
															600,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_2, &saves = saves]()
															{
																start_menu_save_label_2->set_text("New Game");
																saves[2] = {};
																std::remove("save2.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[2].chapter);
	core->manager->add_drawable(start_menu_delete_button_2, "Start Menu Delete Button 2");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_3 = new Button(1000,
														  600,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[3];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_3, "Start Menu Start Load Button 3");

	Drawable* start_menu_save_label_3 = new Label(1000,
												  600,
												  sf::Texture(),
												  1010,
												  610,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_3, "Start Menu Save Label 3");

	Drawable* start_menu_delete_button_3 = new DeleteButton(1400,
															600,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_3, &saves = saves]()
															{
																start_menu_save_label_3->set_text("New Game");
																saves[3] = {};
																std::remove("save3.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[3].chapter);
	core->manager->add_drawable(start_menu_delete_button_3, "Start Menu Delete Button 3");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_4 = new Button(300,
														  800,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[4];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_4, "Start Menu Start Load Button 4");

	Drawable* start_menu_save_label_4 = new Label(300,
												  800,
												  sf::Texture(),
												  310,
												  810,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_4, "Start Menu Save Label 4");

	Drawable* start_menu_delete_button_4 = new DeleteButton(700,
															800,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_4, &saves = saves]()
															{
																start_menu_save_label_4->set_text("New Game");
																saves[4] = {};
																std::remove("save4.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[4].chapter);
	core->manager->add_drawable(start_menu_delete_button_4, "Start Menu Delete Button 4");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_start_load_button_5 = new Button(1000,
														  800,
														  core->manager->get_texture("Start Menu Start Load Button"),
														  core->manager->get_texture("Start Menu Start Load Button HL"),
														  [&application_state = application_state, &saves = saves, &current_save = current_save]()
														  {
														  	current_save = &saves[5];
															current_save->chapter = 1u;
														  	application_state = GAME;
														  },
														  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_start_load_button_5, "Start Menu Start Load Button 5");

	Drawable* start_menu_save_label_5 = new Label(1000,
												  800,
												  sf::Texture(),
												  1010,
												  810,
												  core->manager->get_font("Test Font"),
												  50,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(start_menu_save_label_5, "Start Menu Save Label 5");

	Drawable* start_menu_delete_button_5 = new DeleteButton(1400,
															800,
															core->manager->get_texture("Start Menu Delete Button"),
															core->manager->get_texture("Start Menu Delete Button HL"),
															[start_menu_save_label_5, &saves = saves]()
															{
																start_menu_save_label_5->set_text("New Game");
																saves[5] = {};
																std::remove("save5.bin");
															},
															core->manager->get_sound_buffer("Test Sound"),
															saves[5].chapter);
	core->manager->add_drawable(start_menu_delete_button_5, "Start Menu Delete Button 5");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* start_menu_back_button = new Button(1500,
												  900,
												  core->manager->get_texture("Start Menu Back Button"),
												  core->manager->get_texture("Start Menu Back Button HL"),
												  [&application_state = application_state]()
												  {
													application_state = MAIN_MENU;
												  },
												  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(start_menu_back_button, "Start Menu Back Button");

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
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Start Menu Background"),

		core->manager->get_drawable("Start Menu Start Load Button 0"),
		core->manager->get_drawable("Start Menu Save Label 0"),
		core->manager->get_drawable("Start Menu Delete Button 0"),

		core->manager->get_drawable("Start Menu Start Load Button 1"),
		core->manager->get_drawable("Start Menu Save Label 1"),
		core->manager->get_drawable("Start Menu Delete Button 1"),

		core->manager->get_drawable("Start Menu Start Load Button 2"),
		core->manager->get_drawable("Start Menu Save Label 2"),
		core->manager->get_drawable("Start Menu Delete Button 2"),

		core->manager->get_drawable("Start Menu Start Load Button 3"),
		core->manager->get_drawable("Start Menu Save Label 3"),
		core->manager->get_drawable("Start Menu Delete Button 3"),

		core->manager->get_drawable("Start Menu Start Load Button 4"),
		core->manager->get_drawable("Start Menu Save Label 4"),
		core->manager->get_drawable("Start Menu Delete Button 4"),

		core->manager->get_drawable("Start Menu Start Load Button 5"),
		core->manager->get_drawable("Start Menu Save Label 5"),
		core->manager->get_drawable("Start Menu Delete Button 5"),

		core->manager->get_drawable("Start Menu Back Button")
	};

	int i = 0;
	for (auto& each : saves) {
		if (each.chapter != 0u) {
			core->manager->get_drawable("Start Menu Save Label " + std::to_string(i))->set_text("Chapter " + std::to_string(each.chapter));
		}
		else {
			core->manager->get_drawable("Start Menu Save Label " + std::to_string(i))->set_text("New Game");
		}

		++i;
	}


	while (application_state == START_MENU) {

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
	application_state = START_MENU;
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
	load_save_files();

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