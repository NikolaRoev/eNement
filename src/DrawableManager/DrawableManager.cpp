#include "DrawableManager.h"
#include "../Drawable/Drawable.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::DrawableManager::add_drawable(Drawable& drawable, const std::string& drawable_name) {
	drawables.insert(std::make_pair(drawable_name, &drawable));
}

en::Drawable* en::DrawableManager::get_drawable(const std::string& drawable_name) {
	return drawables.find(drawable_name)->second;
}

//====================================================================================================================================

void en::DrawableManager::add_vector_of_drawables(Drawable& drawable, const std::string& vector_name) {
	vectors_of_drawables.insert(vector_name, {});
	auto it = vectors_of_drawables.find(vector_name);
	it->second.push_back(&drawable);
}

std::vector<en::Drawable*>& en::DrawableManager::get_vector_of_drawables(const std::string& vector_name) {
	return vectors_of_drawables.find(vector_name)->second;
}

//====================================================================================================================================
