#pragma once
#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "GameStructures.h"
#include "ResourceManager/ResourceManager.h"

#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================

	constexpr int EXIT = 0;
	constexpr int MAIN_MENU = 1;
	constexpr int START_MENU = 2;
	constexpr int OPTIONS_MENU = 3;
	constexpr int GAME = 4;

	constexpr int MAP = 0;
	constexpr int FIGHT = 1;
	constexpr int WIN_SCREEN = 2;
	constexpr int LOSS_SCREEN = 3;

	//====================================================================================================================================

	class Game {
	private:

		//====================================================================================================================================
	
		int application_state{ MAIN_MENU };

		int game_state{ FIGHT }; //TO DO: Change this when ready.

		Core* core{ nullptr };

		ResourceManager* resource_manager{ nullptr };

		//====================================================================================================================================

		PlayerEntity* player{ nullptr };

		EnemyEntity* current_enemy{ nullptr };

		//====================================================================================================================================

		void set_resources();

		void set_drawables();

		void load_save_file();

		void save_save_file();

		//====================================================================================================================================

		void main_menu_loop();

		void start_menu_loop();

		void options_menu_loop();

		//====================================================================================================================================
		//====================================================================================================================================

		void map_loop();

		void fight_loop();

		void win_screen_loop();

		void loss_screen_loop();

		void pause_loop();

		//====================================================================================================================================
		//====================================================================================================================================

		void game_loop();

		//====================================================================================================================================

	public:
		void main_loop();
	};

}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
