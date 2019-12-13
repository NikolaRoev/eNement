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

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Chapter/Chapter_Scene1.png", "Chapter Scene 1");
	core->manager->add_texture("assets/images/Chapter/Chapter_Scene2.png", "Chapter Scene 2");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Spells:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Spells/Spells_Background.png", "Spells Background");

	core->manager->add_texture("assets/images/Spells/Spells_Empty_Icon.png", "Spells Empty Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Fire_Icon.png", "Spells Fire Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Water_Icon.png", "Spells Water Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Wind_Icon.png", "Spells Wind Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Earth_Icon.png", "Spells Earth Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Ice_Icon.png", "Spells Ice Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Lightning_Icon.png", "Spells Lightning Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Light_Icon.png", "Spells Light Icon");
	core->manager->add_texture("assets/images/Spells/Spells_Dark_Icon.png", "Spells Dark Icon");

	core->manager->add_texture("assets/images/Spells/Spells_Fire_Button.png", "Spells Fire Button");
	core->manager->add_texture("assets/images/Spells/Spells_Fire_Button_HL.png", "Spells Fire Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Fire_Button_PRESSED.png", "Spells Fire Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Fire_Button_UNAVAILABLE.png", "Spells Fire Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Water_Button.png", "Spells Water Button");
	core->manager->add_texture("assets/images/Spells/Spells_Water_Button_HL.png", "Spells Water Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Water_Button_PRESSED.png", "Spells Water Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Water_Button_UNAVAILABLE.png", "Spells Water Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Wind_Button.png", "Spells Wind Button");
	core->manager->add_texture("assets/images/Spells/Spells_Wind_Button_HL.png", "Spells Wind Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Wind_Button_PRESSED.png", "Spells Wind Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Wind_Button_UNAVAILABLE.png", "Spells Wind Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Earth_Button.png", "Spells Earth Button");
	core->manager->add_texture("assets/images/Spells/Spells_Earth_Button_HL.png", "Spells Earth Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Earth_Button_PRESSED.png", "Spells Earth Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Earth_Button_UNAVAILABLE.png", "Spells Earth Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Ice_Button.png", "Spells Ice Button");
	core->manager->add_texture("assets/images/Spells/Spells_Ice_Button_HL.png", "Spells Ice Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Ice_Button_PRESSED.png", "Spells Ice Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Ice_Button_UNAVAILABLE.png", "Spells Ice Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Lightning_Button.png", "Spells Lightning Button");
	core->manager->add_texture("assets/images/Spells/Spells_Lightning_Button_HL.png", "Spells Lightning Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Lightning_Button_PRESSED.png", "Spells Lightning Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Lightning_Button_UNAVAILABLE.png", "Spells Lightning Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Light_Button.png", "Spells Light Button");
	core->manager->add_texture("assets/images/Spells/Spells_Light_Button_HL.png", "Spells Light Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Light_Button_PRESSED.png", "Spells Light Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Light_Button_UNAVAILABLE.png", "Spells Light Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Dark_Button.png", "Spells Dark Button");
	core->manager->add_texture("assets/images/Spells/Spells_Dark_Button_HL.png", "Spells Dark Button HL");
	core->manager->add_texture("assets/images/Spells/Spells_Dark_Button_PRESSED.png", "Spells Dark Button PRESSED");
	core->manager->add_texture("assets/images/Spells/Spells_Dark_Button_UNAVAILABLE.png", "Spells Dark Button UNAVAILABLE");

	core->manager->add_texture("assets/images/Spells/Spells_Description_Frame.png", "Spells Description Frame");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Stats:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Stats/Stats_Background.png", "Stats Background");

	core->manager->add_texture("assets/images/Stats/Stats_Plus_Button.png", "Stats Plus Button");
	core->manager->add_texture("assets/images/Stats/Stats_Plus_Button_HL.png", "Stats Plus Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Fight:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Fight/Fight_Background.png", "Fight Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Player.png", "Player");

	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Fire.png", "Spell Fire");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Water.png", "Spell Water");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Wind.png", "Spell Wind");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Earth.png", "Spell Earth");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Ice.png", "Spell Ice");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Lightning.png", "Spell Lightning");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Light.png", "Spell Light");
	core->manager->add_texture_for_pixel_perfect("assets/images/Fight/Spell_Dark.png", "Spell Dark");

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

	core->manager->add_texture("assets/images/Win/Win_Background.png", "Win Background");

	core->manager->add_texture("assets/images/Win/Win_Next_Button.png", "Win Next Button");
	core->manager->add_texture("assets/images/Win/Win_Next_Button_HL.png", "Win Next Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Loss:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/Loss/Loss_Background.png", "Loss Background");

	core->manager->add_texture("assets/images/Loss/Loss_Retry_Button.png", "Loss Retry Button");
	core->manager->add_texture("assets/images/Loss/Loss_Retry_Button_HL.png", "Loss Retry Button HL");

	core->manager->add_texture("assets/images/Loss/Loss_Return_Button.png", "Loss Return Button");
	core->manager->add_texture("assets/images/Loss/Loss_Return_Button_HL.png", "Loss Return Button HL");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//End:

	//------------------------------------------------------------------------------------------------------------------------------------

	core->manager->add_texture("assets/images/End/End_Background.png", "End Background");

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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
															saves_at = 0u;
															saves[saves_at].chapter = 1u;
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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
														  	saves_at = 1u;
														  	saves[saves_at].chapter = 1u;
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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
														  	saves_at = 2u;
														  	saves[saves_at].chapter = 1u;
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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
														  	saves_at = 3u;
														  	saves[saves_at].chapter = 1u;
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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
														  	saves_at = 4u;
														  	saves[saves_at].chapter = 1u;
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
														  [&application_state = application_state, &saves = saves, &saves_at = saves_at]()
														  {
														  	saves_at = 5u;
														  	saves[saves_at].chapter = 1u;
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

	Drawable* spells_background = new Image(0,
											0,
											core->manager->get_texture("Spells Background"));
	core->manager->add_drawable(spells_background, "Spells Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_spell_icon_1 = new SpellIcon(200,
												  50,
												  core->manager->get_texture("Spells Empty Icon"),
												  core->manager->get_texture("Spells Fire Icon"),
												  core->manager->get_texture("Spells Water Icon"),
												  core->manager->get_texture("Spells Wind Icon"),
												  core->manager->get_texture("Spells Earth Icon"),
												  core->manager->get_texture("Spells Ice Icon"),
												  core->manager->get_texture("Spells Lightning Icon"),
												  core->manager->get_texture("Spells Light Icon"),
												  core->manager->get_texture("Spells Dark Icon"),
												  player.first_spell);
	core->manager->add_drawable(spells_spell_icon_1, "Spells Spell Icon 1");

	Drawable* spells_spell_icon_2 = new SpellIcon(700,
												  50,
												  core->manager->get_texture("Spells Empty Icon"),
												  core->manager->get_texture("Spells Fire Icon"),
												  core->manager->get_texture("Spells Water Icon"),
												  core->manager->get_texture("Spells Wind Icon"),
												  core->manager->get_texture("Spells Earth Icon"),
												  core->manager->get_texture("Spells Ice Icon"),
												  core->manager->get_texture("Spells Lightning Icon"),
												  core->manager->get_texture("Spells Light Icon"),
												  core->manager->get_texture("Spells Dark Icon"),
												  player.second_spell);
	core->manager->add_drawable(spells_spell_icon_2, "Spells Spell Icon 2");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_fire_button = new SpellButton(60,
												   380,
												   core->manager->get_texture("Spells Fire Button"),
												   core->manager->get_texture("Spells Fire Button HL"),
												   core->manager->get_texture("Spells Fire Button PRESSED"),
												   core->manager->get_texture("Spells Fire Button UNAVAILABLE"),
												   core->manager->get_sound_buffer("Test Sound"),
												   SpellType::Fire,
												   player.first_spell,
												   player.second_spell);
	core->manager->add_drawable(spells_fire_button, "Spells Fire Button");

	Drawable* spells_fire_description = new Label(60,
												  500,
												  core->manager->get_texture("Spells Description Frame"),
												  70,
												  510,
												  core->manager->get_font("Test Font"),
												  30,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(spells_fire_description, "Spells Fire Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_water_button = new SpellButton(400,
													380,
													core->manager->get_texture("Spells Water Button"),
													core->manager->get_texture("Spells Water Button HL"),
													core->manager->get_texture("Spells Water Button PRESSED"),
													core->manager->get_texture("Spells Water Button UNAVAILABLE"),
													core->manager->get_sound_buffer("Test Sound"),
													SpellType::Water,
													player.first_spell,
													player.second_spell);
	core->manager->add_drawable(spells_water_button, "Spells Water Button");

	Drawable* spells_water_description = new Label(400,
												   500,
												   core->manager->get_texture("Spells Description Frame"),
												   410,
												   510,
												   core->manager->get_font("Test Font"),
												   30,
												   sf::Color::White,
												   "");
	core->manager->add_drawable(spells_water_description, "Spells Water Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_wind_button = new SpellButton(900,
												   380,
												   core->manager->get_texture("Spells Wind Button"),
												   core->manager->get_texture("Spells Wind Button HL"),
												   core->manager->get_texture("Spells Wind Button PRESSED"),
												   core->manager->get_texture("Spells Wind Button UNAVAILABLE"),
												   core->manager->get_sound_buffer("Test Sound"),
												   SpellType::Wind,
												   player.first_spell,
												   player.second_spell);
	core->manager->add_drawable(spells_wind_button, "Spells Wind Button");

	Drawable* spells_wind_description = new Label(900,
												  500,
												  core->manager->get_texture("Spells Description Frame"),
												  910,
												  510,
												  core->manager->get_font("Test Font"),
												  30,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(spells_wind_description, "Spells Wind Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_earth_button = new SpellButton(1500,
													380,
													core->manager->get_texture("Spells Earth Button"),
													core->manager->get_texture("Spells Earth Button HL"),
													core->manager->get_texture("Spells Earth Button PRESSED"),
													core->manager->get_texture("Spells Earth Button UNAVAILABLE"),
													core->manager->get_sound_buffer("Test Sound"),
													SpellType::Earth,
													player.first_spell,
													player.second_spell);
	core->manager->add_drawable(spells_earth_button, "Spells Earth Button");

	Drawable* spells_earth_description = new Label(1500,
												   500,
												   core->manager->get_texture("Spells Description Frame"),
												   1510,
												   510,
												   core->manager->get_font("Test Font"),
												   30,
												   sf::Color::White,
												   "");
	core->manager->add_drawable(spells_earth_description, "Spells Earth Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_ice_button = new SpellButton(60,
												  700,
												  core->manager->get_texture("Spells Ice Button"),
												  core->manager->get_texture("Spells Ice Button HL"),
												  core->manager->get_texture("Spells Ice Button PRESSED"),
												  core->manager->get_texture("Spells Ice Button UNAVAILABLE"),
												  core->manager->get_sound_buffer("Test Sound"),
												  SpellType::Ice,
												  player.first_spell,
												  player.second_spell);
	core->manager->add_drawable(spells_ice_button, "Spells Ice Button");

	Drawable* spells_ice_description = new Label(60,
											     800,
											     core->manager->get_texture("Spells Description Frame"),
											     70,
											     810,
											     core->manager->get_font("Test Font"),
											     30,
											     sf::Color::White,
											     "");
	core->manager->add_drawable(spells_ice_description, "Spells Ice Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_lightning_button = new SpellButton(400,
														700,
														core->manager->get_texture("Spells Lightning Button"),
														core->manager->get_texture("Spells Lightning Button HL"),
														core->manager->get_texture("Spells Lightning Button PRESSED"),
														core->manager->get_texture("Spells Lightning Button UNAVAILABLE"),
														core->manager->get_sound_buffer("Test Sound"),
														SpellType::Lightning,
														player.first_spell,
														player.second_spell);
	core->manager->add_drawable(spells_lightning_button, "Spells Lightning Button");

	Drawable* spells_lightning_description = new Label(400,
													   800,
													   core->manager->get_texture("Spells Description Frame"),
													   410,
													   810,
													   core->manager->get_font("Test Font"),
													   30,
													   sf::Color::White,
													   "");
	core->manager->add_drawable(spells_lightning_description, "Spells Lightning Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_light_button = new SpellButton(900,
													700,
													core->manager->get_texture("Spells Light Button"),
													core->manager->get_texture("Spells Light Button HL"),
													core->manager->get_texture("Spells Light Button PRESSED"),
													core->manager->get_texture("Spells Light Button UNAVAILABLE"),
													core->manager->get_sound_buffer("Test Sound"),
													SpellType::Light,
													player.first_spell,
													player.second_spell);
	core->manager->add_drawable(spells_light_button, "Spells Light Button");

	Drawable* spells_light_description = new Label(900,
												   800,
												   core->manager->get_texture("Spells Description Frame"),
												   910,
												   810,
												   core->manager->get_font("Test Font"),
												   30,
												   sf::Color::White,
												   "");
	core->manager->add_drawable(spells_light_description, "Spells Light Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_dark_button = new SpellButton(1500,
												   700,
												   core->manager->get_texture("Spells Dark Button"),
												   core->manager->get_texture("Spells Dark Button HL"),
												   core->manager->get_texture("Spells Dark Button PRESSED"),
												   core->manager->get_texture("Spells Dark Button UNAVAILABLE"),
												   core->manager->get_sound_buffer("Test Sound"),
												   SpellType::Dark,
												   player.first_spell,
												   player.second_spell);
	core->manager->add_drawable(spells_dark_button, "Spells Dark Button");

	Drawable* spells_dark_description = new Label(1500,
												  800,
												  core->manager->get_texture("Spells Description Frame"),
												  1510,
												  810,
												  core->manager->get_font("Test Font"),
												  30,
												  sf::Color::White,
												  "");
	core->manager->add_drawable(spells_dark_description, "Spells Dark Description");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* spells_back_button = new Button(1500,
											  80,
											  core->manager->get_texture("Back Button"),
											  core->manager->get_texture("Back Button HL"),
											  [&game_state = game_state]()
											  {
											  	game_state = CHAPTER;
											  },
											  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(spells_back_button, "Spells Back Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Stats:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* stats_background = new Image(0,
										   0,
										   core->manager->get_texture("Stats Background"));
	core->manager->add_drawable(stats_background, "Stats Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* stats_barriers = new Label(400,
										 30,
										 sf::Texture(),
										 400,
										 30,
										 core->manager->get_font("Test Font"),
										 50,
										 sf::Color::White,
										 "");
	core->manager->add_drawable(stats_barriers, "Stats Barriers");

	Drawable* stats_damage = new Label(400,
									   130,
									   sf::Texture(),
									   400,
									   130,
									   core->manager->get_font("Test Font"),
									   50,
									   sf::Color::White,
									   "");
	core->manager->add_drawable(stats_damage, "Stats Damage");

	Drawable* stats_cooldown_time = new Label(400,
											  230,
											  sf::Texture(),
											  400,
											  230,
											  core->manager->get_font("Test Font"),
											  50,
											  sf::Color::White,
											  "");
	core->manager->add_drawable(stats_cooldown_time, "Stats Cooldown Time");

	Drawable* stats_secondary_effect_increase = new Label(400,
														  330,
														  sf::Texture(),
														  400,
														  330,
														  core->manager->get_font("Test Font"),
														  50,
														  sf::Color::White,
														  "");
	core->manager->add_drawable(stats_secondary_effect_increase, "Stats Secondary Effect Increase");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* stats_points = new Label(400,
		540,
		sf::Texture(),
		400,
		540,
		core->manager->get_font("Test Font"),
		50,
		sf::Color::White,
		"");
	core->manager->add_drawable(stats_points, "Stats Points");

	Drawable* stats_barrier_strength = new Label(400,
		650,
		sf::Texture(),
		400,
		650,
		core->manager->get_font("Test Font"),
		50,
		sf::Color::White,
		"");
	core->manager->add_drawable(stats_barrier_strength, "Stats Barrier Strength");

	Drawable* stats_magic_power = new Label(400,
		750,
		sf::Texture(),
		400,
		750,
		core->manager->get_font("Test Font"),
		50,
		sf::Color::White,
		"");
	core->manager->add_drawable(stats_magic_power, "Stats Magic Power");

	Drawable* stats_spell_mastery = new Label(400,
		850,
		sf::Texture(),
		400,
		850,
		core->manager->get_font("Test Font"),
		50,
		sf::Color::White,
		"");
	core->manager->add_drawable(stats_spell_mastery, "Stats Spell Mastery");

	Drawable* stats_magic_proficiency = new Label(400,
		950,
		sf::Texture(),
		400,
		950,
		core->manager->get_font("Test Font"),
		50,
		sf::Color::White,
		"");
	core->manager->add_drawable(stats_magic_proficiency, "Stats Magic Proficiency");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* stats_barrier_strength_button = new PlusButton(600,
															 650,
															 core->manager->get_texture("Stats Plus Button"),
															 core->manager->get_texture("Stats Plus Button HL"),
															 [stats_barrier_strength, stats_barriers, stats_points, &player = player]()
															 {
																stats_barrier_strength->set_text(std::to_string(player.barrier_strength));

																player.barriers = player.barrier_strength / 10u;
																stats_barriers->set_text(std::to_string(player.barriers));

																stats_points->set_text(std::to_string(player.points));
															 },
															 core->manager->get_sound_buffer("Test Sound"),
															 player.points,
															 player.barrier_strength);
	core->manager->add_drawable(stats_barrier_strength_button, "Stats Barrier Strength Button");

	Drawable* stats_magic_power_button = new PlusButton(600,
														750,
														core->manager->get_texture("Stats Plus Button"),
														core->manager->get_texture("Stats Plus Button HL"),
														[stats_magic_power, stats_damage, stats_points, &player = player]()
														{
															stats_magic_power->set_text(std::to_string(player.magic_power));

															player.damage = 10.0f + (0.1f * player.magic_power);
															stats_damage->set_text(std::to_string(player.damage));

															stats_points->set_text(std::to_string(player.points));
														},
														core->manager->get_sound_buffer("Test Sound"),
														player.points,
														player.magic_power);
	core->manager->add_drawable(stats_magic_power_button, "Stats Magic Power Button");

	Drawable* stats_spell_mastery_button = new PlusButton(600,
														  850,
														  core->manager->get_texture("Stats Plus Button"),
														  core->manager->get_texture("Stats Plus Button HL"),
														  [stats_spell_mastery, stats_cooldown_time, stats_points, &player = player]()
														  {
														  	stats_spell_mastery->set_text(std::to_string(player.spell_mastery));
														  
															player.cooldown_time = 5000.0f - (25.0f * player.spell_mastery);
														  	stats_cooldown_time->set_text(std::to_string(player.cooldown_time));

															stats_points->set_text(std::to_string(player.points));
														  },
														  core->manager->get_sound_buffer("Test Sound"),
														  player.points,
														  player.spell_mastery);
	core->manager->add_drawable(stats_spell_mastery_button, "Stats Spell Mastery Button");

	Drawable* stats_magic_proficiency_button = new PlusButton(600,
															  950,
															  core->manager->get_texture("Stats Plus Button"),
															  core->manager->get_texture("Stats Plus Button HL"),
															  [stats_magic_proficiency, stats_secondary_effect_increase, stats_points, &player = player]()
															  {
															  	stats_magic_proficiency->set_text(std::to_string(player.magic_proficiency));
															  
																player.secondary_effect_increase = 0.0f + (1.5f * player.magic_proficiency);
															  	stats_secondary_effect_increase->set_text(std::to_string(player.secondary_effect_increase));

																stats_points->set_text(std::to_string(player.points));
															  },
															  core->manager->get_sound_buffer("Test Sound"),
															  player.points,
															  player.magic_proficiency);
	core->manager->add_drawable(stats_magic_proficiency_button, "Stats Magic Proficiency Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//TO DO: Add the description labels.

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* stats_back_button = new Button(1500,
											 80,
											 core->manager->get_texture("Back Button"),
											 core->manager->get_texture("Back Button HL"),
											 [&game_state = game_state]()
											 {
											 	game_state = CHAPTER;
											 },
											 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(stats_back_button, "Stats Back Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Fight:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* fight_background = new Image(0,
										   0,
										   core->manager->get_texture("Fight Background"));
	core->manager->add_drawable(fight_background, "Fight Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* fight_player = new ObjectDrawable(960,
												800,
												core->manager->get_texture("Player"),
												core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_player, "Player");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* fight_spell_fire = new ObjectDrawable(0,
													0,
													core->manager->get_texture("Spell Fire"),
													core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_fire, "Spell Fire");

	Drawable* fight_spell_water = new ObjectDrawable(0,
													 0,
													 core->manager->get_texture("Spell Water"),
													 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_water, "Spell Water");

	Drawable* fight_spell_wind = new ObjectDrawable(0,
													0,
													core->manager->get_texture("Spell Wind"),
													core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_wind, "Spell Wind");

	Drawable* fight_spell_earth = new ObjectDrawable(0,
													 0,
													 core->manager->get_texture("Spell Earth"),
													 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_earth, "Spell Earth");

	Drawable* fight_spell_ice = new ObjectDrawable(0,
												   0,
												   core->manager->get_texture("Spell Ice"),
												   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_ice, "Spell Ice");

	Drawable* fight_spell_lightning = new ObjectDrawable(0,
														 0,
														 core->manager->get_texture("Spell Lightning"),
														 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_lightning, "Spell Lightning");

	Drawable* fight_spell_light = new ObjectDrawable(0,
													 0,
													 core->manager->get_texture("Spell Light"),
													 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_light, "Spell Light");

	Drawable* fight_spell_dark = new ObjectDrawable(0,
													0,
													core->manager->get_texture("Spell Dark"),
													core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(fight_spell_dark, "Spell Dark");

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

	Drawable* win_background = new Image(0,
										 0,
										 core->manager->get_texture("Win Background"));
	core->manager->add_drawable(win_background, "Win Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* win_next_button = new Button(960,
										   800,
										   core->manager->get_texture("Win Next Button"),
										   core->manager->get_texture("Win Next Button HL"),
										   [&game_state = game_state]()
										   {
										   	game_state = CHAPTER;
										   },
										   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(win_next_button, "Win Next Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//Loss:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* loss_background = new Image(0,
										  0,
										  core->manager->get_texture("Loss Background"));
	core->manager->add_drawable(loss_background, "Loss Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* loss_retry_button = new Button(480,
											 800,
											 core->manager->get_texture("Loss Retry Button"),
											 core->manager->get_texture("Loss Retry Button HL"),
											 [&game_state = game_state]()
											 {
											 	game_state = FIGHT;
											 },
											 core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(loss_retry_button, "Loss Retry Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* loss_return_button = new Button(1440,
											  800,
											  core->manager->get_texture("Loss Return Button"),
											  core->manager->get_texture("Loss Return Button HL"),
											  [&game_state = game_state]()
											  {
											  	game_state = CHAPTER;
											  },
											  core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(loss_return_button, "Loss Return Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//End:

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* end_background = new Image(0,
										 0,
										 core->manager->get_texture("End Background"));
	core->manager->add_drawable(end_background, "End Background");

	//------------------------------------------------------------------------------------------------------------------------------------

	Drawable* end_next_button = new Button(960,
										   800,
										   core->manager->get_texture("Win Next Button"),
										   core->manager->get_texture("Win Next Button HL"),
										   [&application_state = application_state]()
										   {
										   	application_state = MAIN_MENU;
										   },
										   core->manager->get_sound_buffer("Test Sound"));
	core->manager->add_drawable(end_next_button, "End Next Button");

	//------------------------------------------------------------------------------------------------------------------------------------

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
}

//====================================================================================================================================

void en::Game::load_player() {
	player.first_spell = saves[saves_at].first_spell;
	player.second_spell = saves[saves_at].second_spell;


	player.points = saves[saves_at].points;

	player.barrier_strength = saves[saves_at].barrier_strength;
	player.magic_power = saves[saves_at].magic_power;
	player.spell_mastery = saves[saves_at].spell_mastery;
	player.magic_proficiency = saves[saves_at].magic_proficiency;


	player.barriers = saves[saves_at].barrier_strength / 10u;

	player.damage = 10.0f + (0.1f * saves[saves_at].magic_power);

	player.cooldown_time = 5000.0f - (25.0f * saves[saves_at].spell_mastery);

	player.secondary_effect_increase = 0.0f + (1.5f * saves[saves_at].magic_proficiency);
}

void en::Game::save_player() {
	saves[saves_at].first_spell = player.first_spell;
	saves[saves_at].second_spell = player.second_spell;

	saves[saves_at].points = player.points;

	saves[saves_at].barrier_strength = player.barrier_strength;
	saves[saves_at].magic_power = player.magic_power;
	saves[saves_at].spell_mastery = player.spell_mastery;
	saves[saves_at].magic_proficiency = player.magic_proficiency;
}

void en::Game::load_save_files() {
	int i = 0;
	for (auto& each : saves) {
		std::ifstream is("save" + std::to_string(i) + ".bin", std::ios::binary);


		if (is.is_open()) {
			is.read((char*)&each.chapter, sizeof(unsigned int));

			is.read((char*)&each.first_spell, sizeof(unsigned int));
			is.read((char*)&each.second_spell, sizeof(unsigned int));

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
	save_player();


	int i = 0;
	for (auto& each : saves) {
		if (each.chapter != 0u) {
			std::ofstream os("save" + std::to_string(i) + ".bin", std::ios::binary);

			os.write((char*)&each.chapter, sizeof(unsigned int));

			os.write((char*)&each.first_spell, sizeof(unsigned int));
			os.write((char*)&each.second_spell, sizeof(unsigned int));

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
	load_player();


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

		core->manager->get_drawable("Chapter Scene " + std::to_string(saves[saves_at].chapter)),

		core->manager->get_drawable("Chapter Start Button"),

		core->manager->get_drawable("Chapter Spells Button"),

		core->manager->get_drawable("Chapter Stats Button"),

		core->manager->get_drawable("Chapter Main Menu Button"),

		core->manager->get_drawable("Chapter Lore Label"),
	};


	core->manager->get_drawable("Chapter Lore Label")->set_text(lores[saves[saves_at].chapter - 1u]);


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
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Spells Background"),

		core->manager->get_drawable("Spells Spell Icon 1"),
		core->manager->get_drawable("Spells Spell Icon 2"),

		core->manager->get_drawable("Spells Fire Button"),
		core->manager->get_drawable("Spells Fire Description"),

		core->manager->get_drawable("Spells Water Button"),
		core->manager->get_drawable("Spells Water Description"),

		core->manager->get_drawable("Spells Wind Button"),
		core->manager->get_drawable("Spells Wind Description"),

		core->manager->get_drawable("Spells Earth Button"),
		core->manager->get_drawable("Spells Earth Description"),

		core->manager->get_drawable("Spells Ice Button"),
		core->manager->get_drawable("Spells Ice Description"),

		core->manager->get_drawable("Spells Lightning Button"),
		core->manager->get_drawable("Spells Lightning Description"),

		core->manager->get_drawable("Spells Light Button"),
		core->manager->get_drawable("Spells Light Description"),

		core->manager->get_drawable("Spells Dark Button"),
		core->manager->get_drawable("Spells Dark Description"),

		core->manager->get_drawable("Spells Back Button")
	};


	core->manager->get_drawable("Spells Fire Description")->set_text("Fire");
	core->manager->get_drawable("Spells Water Description")->set_text("Water");
	core->manager->get_drawable("Spells Wind Description")->set_text("Wind");
	core->manager->get_drawable("Spells Earth Description")->set_text("Earth");
	core->manager->get_drawable("Spells Ice Description")->set_text("Ice");
	core->manager->get_drawable("Spells Lightning Description")->set_text("Lightning");
	core->manager->get_drawable("Spells Light Description")->set_text("Light");
	core->manager->get_drawable("Spells Dark Description")->set_text("Dark");


	while (application_state == GAME && game_state == SPELLS) {

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

void en::Game::stats_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Stats Background"),

		core->manager->get_drawable("Stats Barriers"),
		core->manager->get_drawable("Stats Damage"),
		core->manager->get_drawable("Stats Cooldown Time"),
		core->manager->get_drawable("Stats Secondary Effect Increase"),

		core->manager->get_drawable("Stats Points"),

		core->manager->get_drawable("Stats Barrier Strength"),
		core->manager->get_drawable("Stats Magic Power"),
		core->manager->get_drawable("Stats Spell Mastery"),
		core->manager->get_drawable("Stats Magic Proficiency"),

		core->manager->get_drawable("Stats Barrier Strength Button"),
		core->manager->get_drawable("Stats Magic Power Button"),
		core->manager->get_drawable("Stats Spell Mastery Button"),
		core->manager->get_drawable("Stats Magic Proficiency Button"),

		core->manager->get_drawable("Stats Back Button")
	};


	core->manager->get_drawable("Stats Barriers")->set_text(std::to_string(player.barriers));
	core->manager->get_drawable("Stats Damage")->set_text(std::to_string(player.damage));
	core->manager->get_drawable("Stats Cooldown Time")->set_text(std::to_string(player.cooldown_time));
	core->manager->get_drawable("Stats Secondary Effect Increase")->set_text(std::to_string(player.secondary_effect_increase));

	core->manager->get_drawable("Stats Points")->set_text(std::to_string(player.points));

	core->manager->get_drawable("Stats Barrier Strength")->set_text(std::to_string(player.barrier_strength));
	core->manager->get_drawable("Stats Magic Power")->set_text(std::to_string(player.magic_power));
	core->manager->get_drawable("Stats Spell Mastery")->set_text(std::to_string(player.spell_mastery));
	core->manager->get_drawable("Stats Magic Proficiency")->set_text(std::to_string(player.magic_proficiency));


	while (application_state == GAME && game_state == STATS) {

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

void en::Game::fight_loop() {
	//Setup.
	player.drawable = core->manager->get_drawable("Player")->clone();

	PlayerSpell* first_spell_entity = PlayerSpell::make_spell(player.first_spell, player.cooldown_time, core->manager, sf::Keyboard::Z);
	PlayerSpell* second_spell_entity = PlayerSpell::make_spell(player.second_spell, player.cooldown_time, core->manager, sf::Keyboard::X);


	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Fight Background"),

		player.drawable,

		first_spell_entity->drawable,
		second_spell_entity->drawable,
	};
	DynamicFrame dynamic_frame;
	//------------------------------------------------------------------------------------------------------------------------------------


	while (application_state == GAME && game_state == FIGHT) {
		//Time.
		core->time = core->clock.restart();
		//std::cout << core->time.asSeconds() << '\n';
		//------------------------------------------------------------------------------------------------------------------------------------
		

		//Generates.
		first_spell_entity->generate(player.drawable->get_sprite()->getPosition(), core->time);
		second_spell_entity->generate(player.drawable->get_sprite()->getPosition(), core->time);


		//------------------------------------------------------------------------------------------------------------------------------------


		//Draws.
		core->draw(static_frame, dynamic_frame);

		//------------------------------------------------------------------------------------------------------------------------------------


		//Checks.

		//------------------------------------------------------------------------------------------------------------------------------------


		//Moves.
		player.move(core->width, core->height, core->delta_x, core->delta_y, core->time);

		first_spell_entity->move(core->delta_x, core->delta_y, core->time);
		second_spell_entity->move(core->delta_x, core->delta_y, core->time);
		//------------------------------------------------------------------------------------------------------------------------------------


		//Events.
		core->window.pollEvent(core->event);
		if (core->event.type == sf::Event::Resized) {
			core->on_resize_event(dynamic_frame);
			sizes_at = 99;

			player.drawable->resize(core->delta_x, core->delta_y);

			first_spell_entity->drawable->resize(core->delta_x, core->delta_y);
			second_spell_entity->drawable->resize(core->delta_x, core->delta_y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			game_state = CHAPTER;
		}
		else if (core->event.type == sf::Event::Closed) {
			application_state = EXIT;
		}
		//------------------------------------------------------------------------------------------------------------------------------------
	}


	//Cleanup.
	delete player.drawable;

	delete first_spell_entity;
	delete second_spell_entity;
	//------------------------------------------------------------------------------------------------------------------------------------
}

void en::Game::pause_loop() {

}

void en::Game::win_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Win Background"),

		core->manager->get_drawable("Win Next Button")
	};


	while (application_state == GAME && game_state == WIN) {

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

void en::Game::loss_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("Loss Background"),

		core->manager->get_drawable("Loss Retry Button"),
		core->manager->get_drawable("Loss Return Button")
	};


	while (application_state == GAME && game_state == LOSS) {

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

void en::Game::end_loop() {
	std::vector<Drawable*> static_frame = {
		core->manager->get_drawable("End Background"),

		core->manager->get_drawable("End Next Button")
	};


	while (application_state == GAME && game_state == END) {

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

//====================================================================================================================================

void en::Game::main_loop() {
	core = new Core(1920.0f, 1080.0f);
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