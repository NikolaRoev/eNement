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
	auto it = vectors_of_drawables.find(vector_name);

	if (it == vectors_of_drawables.end()) {
		vectors_of_drawables.insert(std::make_pair(vector_name, std::vector<Drawable*>{&drawable}));
	}
	else {
		it->second.push_back(&drawable);
	}


}

std::vector<en::Drawable*>& en::DrawableManager::get_vector_of_drawables(const std::string& vector_name) {
	return vectors_of_drawables.find(vector_name)->second;
}

//====================================================================================================================================

void en::DrawableManager::resize_all(const float d_x, const float d_y) {
	for (const auto& each : drawables) {
		each.second->resize(d_x, d_y);
	}
	for (const auto& each_vector : vectors_of_drawables) {
		for (const auto& each : each_vector.second) {
			each->resize(d_x, d_y);
		}
	}
}

void en::DrawableManager::change_volume_for_all() {
	for (const auto& each : drawables) {
		each.second->set_volume();
	}
	for (const auto& each_vector : vectors_of_drawables) {
		for (const auto& each : each_vector.second) {
			each->set_volume();
		}
	}
}

//====================================================================================================================================