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

	core->manager->add_texture("assets/images/Start Menu/Back_Button.png", "Back Button");
	core->manager->add_texture("assets/images/Start Menu/Back_Button_HL.png", "Back Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_font("assets/fonts/TNR.ttf", "Test Font");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Options Menu:

	//------------------------------------------------------------------------------------------------------------------------------------
	
	core->manager->add_texture("assets/images/Options Menu/Options_Menu_Background.png", "Options Menu Background");

	core->manager->add_texture("assets/images/Options Menu/Arrow_Left.png", "Arrow Left");
	core->manager->add_texture("assets/images/Options Menu/Arrow_Left_HL.png", "Arrow Left HL");

	core->manager->add_texture("assets/images/Options Menu/Arrow_Right.png", "Arrow Right");
	core->manager->add_texture("assets/images/Options Menu/Arrow_Right_HL.png", "Arrow Right HL");
	
	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Chapter:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Chapter/Chapter_Background.png", "Chapter Background");

	core->manager->add_texture("assets/images/Chapter/Chapter_Start_Button.png", "Chapter Start Button");
	core->manager->add_texture("assets/images/Chapter/Chapter_Start_Button_HL.png", "Chapter Start Button HL");

	core->manager->add_texture("assets/images/Chapter/Chapter_Spells_Button.png", "Chapter Spells Button");
	core->manager->add_texture("assets/images/Chapter/Chapter_Spells_Button_HL.png", "Chapter Spells Button HL");

	core->manager->add_texture("assets/images/Chapter/Chapter_Stats_Button.png", "Chapter Stats Button");
	core->manager->add_texture("assets/images/Chapter/Chapter_Stats_Button_HL.png", "Chapter Stats Button HL");

	core->manager->add_texture("assets/images/Chapter/Chapter_Main_Menu_Button.png", "Chapter Main Menu Button");
	core->manager->add_texture("assets/images/Chapter/Chapter_Main_Menu_Button_HL.png", "Chapter Main Menu Button HL");

	core->manager->add_texture("assets/images/Chapter/Chapter_Scene1.png", "Chapter Scene 1");
	core->manager->add_texture("assets/images/Chapter/Chapter_Scene2.png", "Chapter Scene 2");

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
												  core->manager->get_texture("Back Button"),
												  core->manager->get_texture("Back Button HL"),
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

	Drawable* options_menu_background = new Image(0,
												  0,
												  core->manager->get_texture("Options Menu Background"));
	core->manager->add_drawable(options_menu_background, "Options Menu Background");
	
	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* options_menu_resolution_label = new Label(1000,
														400,
														sf::Texture(),
														1000,
														400,
														core->manager->get_font("Test Font"),
														50, sf::Color::White,
														"");
	core->manager->add_drawable(options_menu_resolution_label, "Options Menu Resolution Label");

	Drawable* options_menu_resolution_button_left = new Button(900,
															   400,
															   core->manager->get_texture("Arrow Left"),
															   core->manager->get_texture("Arrow Left HL"),
															   [&core = core, &sizes = sizes, &sizes_at = sizes_at, options_menu_resolution_label]()
															   {
																if (sizes_at == 99u) {
																	sizes_at = 0;
																	core->set_window(sizes[sizes_at].first, sizes[sizes_at].second);
																	options_menu_resolution_label->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
																}
																else if (sizes_at > 0u) {
																	--sizes_at;
																	core->set_window(sizes[sizes_at].first, sizes[sizes_at].second);
																	options_menu_resolution_label->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
																}
															   },
															   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_resolution_button_left, "Options Menu Resolution Button Left");

	Drawable* options_menu_resolution_button_right = new Button(1200,
																400,
																core->manager->get_texture("Arrow Right"),
																core->manager->get_texture("Arrow Right HL"),
																[&core = core, &sizes = sizes, &sizes_at = sizes_at, options_menu_resolution_label]()
																{
																	if (sizes_at == 99u) {
																		sizes_at = 0;
																		core->set_window(sizes[sizes_at].first, sizes[sizes_at].second);
																		options_menu_resolution_label->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
																	}
																	else if (sizes_at < (sizes.size() - 1)) {
																		++sizes_at;
																		core->set_window(sizes[sizes_at].first, sizes[sizes_at].second);
																		options_menu_resolution_label->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
																	}
																},
																core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_resolution_button_right, "Options Menu Resolution Button Right");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* options_menu_frames_label = new Label(1000,
													540,
													sf::Texture(),
													1000,
													540,
													core->manager->get_font("Test Font"),
													50, sf::Color::White,
													"");
	core->manager->add_drawable(options_menu_frames_label, "Options Menu Frames Label");

	Drawable* options_menu_frames_button_left = new Button(900,
														   540,
														   core->manager->get_texture("Arrow Left"),
														   core->manager->get_texture("Arrow Left HL"),
														   [&frames = core->frames, &window = core->window, options_menu_frames_label]()
														   {
															if (frames != 30u) {
																frames /= 2u;
																window.setFramerateLimit(frames);
																options_menu_frames_label->set_text(std::to_string(frames));
															}
														   },
														   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_frames_button_left, "Options Menu Frames Button Left");

	Drawable* options_menu_frames_button_right = new Button(1200,
															540,
															core->manager->get_texture("Arrow Right"),
															core->manager->get_texture("Arrow Right HL"),
															[&frames = core->frames, &window = core->window, options_menu_frames_label]()
															{
																if (frames != 240u) {
																	frames *= 2u;
																	window.setFramerateLimit(frames);
																	options_menu_frames_label->set_text(std::to_string(frames));
																}
															},
															core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_frames_button_right, "Options Menu Frames Button Right");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* options_menu_volume_label = new Label(1000,
													700,
													sf::Texture(),
													1000,
													700,
													core->manager->get_font("Test Font"),
													50, sf::Color::White,
													"");
	core->manager->add_drawable(options_menu_volume_label, "Options Menu Volume Label");

	Drawable* options_menu_volume_button_left = new Button(900,
														   700,
														   core->manager->get_texture("Arrow Left"),
														   core->manager->get_texture("Arrow Left HL"),
														   [&core = core, options_menu_volume_label]()
														   {
															if (core->volume != 0u) {
																core->volume -= 5u;
																core->manager->change_volume(core->volume);
																options_menu_volume_label->set_text(std::to_string(core->volume));
														   	}
														   },
														   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_volume_button_left, "Options Menu Volume Button Left");

	Drawable* options_menu_volume_button_right = new Button(1200,
															700,
															core->manager->get_texture("Arrow Right"),
															core->manager->get_texture("Arrow Right HL"),
															[&core = core, options_menu_volume_label]()
															{
																if (core->volume != 100u) {
																	core->volume += 5u;
																	core->manager->change_volume(core->volume);
																	options_menu_volume_label->set_text(std::to_string(core->volume));
																}
															},
															core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_volume_button_right, "Options Menu Volume Button Right");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* options_menu_back_button = new Button(1500,
													900,
													core->manager->get_texture("Back Button"),
													core->manager->get_texture("Back Button HL"),
													[&application_state = application_state]()
													{
														application_state = MAIN_MENU;
													},
													core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(options_menu_back_button, "Options Menu Back Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Chapter:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_background = new Image(0,
											 0,
											 core->manager->get_texture("Chapter Background"));
	core->manager->add_drawable(chapter_background, "Chapter Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_scene_1 = new Image(0,
										  0,
										  core->manager->get_texture("Chapter Scene 1"));
	core->manager->add_drawable(chapter_scene_1, "Chapter Scene 1");

	Drawable* chapter_scene_2 = new Image(0,
										  0,
										  core->manager->get_texture("Chapter Scene 2"));
	core->manager->add_drawable(chapter_scene_2, "Chapter Scene 2");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_start_button = new Button(1000,
												880,
												core->manager->get_texture("Chapter Start Button"),
												core->manager->get_texture("Chapter Start Button HL"),
												[&game_state = game_state]()
												{
													game_state = FIGHT;
												},
												core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(chapter_start_button, "Chapter Start Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_spells_button = new Button(1420,
												 20,
												 core->manager->get_texture("Chapter Spells Button"),
												 core->manager->get_texture("Chapter Spells Button HL"),
												 [&game_state = game_state]()
												 {
												 	game_state = SPELLS;
												 },
												 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(chapter_spells_button, "Chapter Spells Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_stats_button = new Button(1720,
												20,
												core->manager->get_texture("Chapter Stats Button"),
												core->manager->get_texture("Chapter Stats Button HL"),
												[&game_state = game_state]()
												{
													game_state = STATS;
												},
												core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(chapter_stats_button, "Chapter Stats Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_main_menu_button = new Button(1420,
													300,
													core->manager->get_texture("Chapter Main Menu Button"),
													core->manager->get_texture("Chapter Main Menu Button HL"),
													[&application_state = application_state]()
													{
														application_state = MAIN_MENU;
													},
													core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(chapter_main_menu_button, "Chapter Main Menu Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* chapter_lore_label = new Label(1450,
											 500,
											 sf::Texture(),
											 1450,
											 500,
											 core->manager->get_font("Test Font"),
											 30,
											 sf::Color::Black,
											 "");
	core->manager->add_drawable(chapter_lore_label, "Chapter Lore Label");

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
			sizes_at = 99;
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
			sizes_at = 99;
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
	}
}

void en::Game::options_menu_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Options Menu Background"),

		core->manager->get_drawable("Options Menu Resolution Label"),
		core->manager->get_drawable("Options Menu Resolution Button Left"),
		core->manager->get_drawable("Options Menu Resolution Button Right"),

		core->manager->get_drawable("Options Menu Frames Label"),
		core->manager->get_drawable("Options Menu Frames Button Left"),
		core->manager->get_drawable("Options Menu Frames Button Right"),

		core->manager->get_drawable("Options Menu Volume Label"),
		core->manager->get_drawable("Options Menu Volume Button Left"),
		core->manager->get_drawable("Options Menu Volume Button Right"),

		core->manager->get_drawable("Options Menu Back Button")
	};


	core->manager->get_drawable("Options Menu Resolution Label")->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
	core->manager->get_drawable("Options Menu Frames Label")->set_text(std::to_string(core->frames));
	core->manager->get_drawable("Options Menu Volume Label")->set_text(std::to_string(core->volume));


	while (application_state == OPTIONS_MENU) {

		core->draw(static_frame);


		core->window.pollEvent(core->event);
		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event();
			core->manager->get_drawable("Options Menu Resolution Label")->set_text(std::to_string(core->width) + "x" + std::to_string(core->height));
			sizes_at = 99;
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
	}
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
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Chapter Background"),

		core->manager->get_drawable("Chapter Scene " + std::to_string(current_save->chapter)),

		core->manager->get_drawable("Chapter Start Button"),

		core->manager->get_drawable("Chapter Spells Button"),

		core->manager->get_drawable("Chapter Stats Button"),

		core->manager->get_drawable("Chapter Main Menu Button"),

		core->manager->get_drawable("Chapter Lore Label"),
	};


	core->manager->get_drawable("Chapter Lore Label")->set_text(lores[current_save->chapter - 1u]);


	while (application_state == GAME && game_state == CHAPTER) {

		core->draw(static_frame);


		core->window.pollEvent(core->event);
		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event();
			sizes_at = 99;
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
	}
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