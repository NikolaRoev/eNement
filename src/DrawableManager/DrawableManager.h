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
		std::unordered_map<std::string, std::vector<Drawable*>> vectors_of_drawables;
	public:
		void add_drawable(Drawable& drawable, const std::string& drawable_name);
		Drawable* get_drawable(const std::string& drawable_name);

		void add_vector_of_drawables(Drawable& drawable, const std::string& vector_name);
		std::vector<Drawable*>& get_vector_of_drawables(const std::string& vector_name);
	};
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================