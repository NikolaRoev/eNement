#pragma once
#include "../Drawable/Drawable.h"

#include <vector>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {
	inline float DELTA_X;
	inline float DELTA_Y;

	inline float VOLUME;
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================

	struct Settings {
		unsigned int width{ 1024 };
		unsigned int height{ 576 };
		uint32_t style{ 7 };
		unsigned int frames{ 30 };
		unsigned int volume{ 100 };
	};

	//====================================================================================================================================

	class Core {
	private:
		const float native_width{ 1920 };
		const float native_height{ 1080 };


		void set_delta_values();

	public:
		sf::RenderWindow window;
		sf::Event event{ sf::Event::MouseMoved };;
		sf::Mouse mouse;

		Settings settings;


		void set_window();

		void load_settings();

		void save_settings();

		void on_resize_event(const std::vector<std::shared_ptr<Drawable>>& in_frame);
	};
}


//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================