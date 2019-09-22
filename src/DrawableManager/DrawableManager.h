#pragma once
#include "../Drawable/Drawable.h"

#include <string>
#include <unordered_map>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {
	class DrawableManager {
	private:
		std::unordered_map<std::string, Drawable*> drawables;
	public:
		void add_drawable(Drawable& drawable, const std::string& drawable_name);
		Drawable* get_drawable(const std::string& drawable_name);

		void resize_all(const float d_x, const float d_y);
		void change_volume_for_all();
	};
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================