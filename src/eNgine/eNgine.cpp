#include "eNgine.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::ResourceManager::~ResourceManager() {
	for (auto& each : drawables) {
		delete each.second;
	}
}

void en::ResourceManager::add_texture(const std::string& file_path, const std::string& texture_name) {
	sf::Texture temp;
	temp.loadFromFile(file_path);

	textures.insert(std::make_pair(texture_name, temp));
}

void en::ResourceManager::add_font(const std::string& file_path, const std::string& font_name) {
	sf::Font temp;
	temp.loadFromFile(file_path);

	fonts.insert(std::make_pair(font_name, temp));
}

void en::ResourceManager::add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name) {
	sf::SoundBuffer temp;
	temp.loadFromFile(file_path);

	sound_buffers.insert(std::make_pair(sound_buffer_name, temp));
}

//====================================================================================================================================

const sf::Texture& en::ResourceManager::get_texture(const std::string& texture_name) const {
	return textures.find(texture_name)->second;
}

const sf::Font& en::ResourceManager::get_font(const std::string& font_name) const {
	return fonts.find(font_name)->second;
}

const sf::SoundBuffer& en::ResourceManager::get_sound_buffer(const std::string& sound_buffer_name) const {
	return sound_buffers.find(sound_buffer_name)->second;
}

//====================================================================================================================================

void en::ResourceManager::add_drawable(Drawable* drawable, const std::string& drawable_name) {
	drawables.insert(std::make_pair(drawable_name, drawable));
}

en::Drawable* en::ResourceManager::get_drawable(const std::string& drawable_name) const {
	return drawables.find(drawable_name)->second;
}

std::unordered_map<std::string, en::Drawable*>& en::ResourceManager::get_all_drawables() {
	return drawables;
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::Layer::~Layer() {
	for (auto& each : dynamic_drawables) {
		delete each.second;
	}
}

void en::Frame::add_static_drawable(Drawable* drawable, const int layer) {
	std::map<int, Layer>::iterator it = layers.find(layer);
	if (it != layers.end()) {
		it->second.static_drawables.push_back(drawable->clone());
	}
	else {
		layers[layer].static_drawables.push_back(drawable->clone());
	}
}
void en::Frame::add_dynamic_drawable(const std::string& name, Drawable* drawable, const int layer) {
	std::map<int, Layer>::iterator it = layers.find(layer);
	if (it != layers.end()) {
		it->second.dynamic_drawables.insert(std::make_pair(name, drawable->clone()));
	}
	else {
		layers[layer].dynamic_drawables.insert(std::make_pair(name, drawable->clone()));
	}
}

void en::Frame::delete_dynamic_drawable(const std::string& name) {
	std::unordered_map<std::string, Drawable*>::iterator it;

	for (auto& each : layers) {
		it = each.second.dynamic_drawables.find(name);
		if (it != each.second.dynamic_drawables.end()) {
			each.second.dynamic_drawables.erase(it);
			break;
		}
	}
}

void en::Frame::add_pop_up_drawable(Drawable* drawable) {
	pop_up_drawables.push_back(drawable->clone());
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

void en::Core::set_delta_values() {
	delta_x = 1 - (((native_width - static_cast<float>(width)) / (native_width / 100.0f)) / 100.0f);
	delta_y = 1 - (((native_height - static_cast<float>(height)) / (native_height / 100.0f)) / 100.0f);
}

en::Core::Core(const double _native_width, const double _native_height) {
	native_width = _native_width;
	native_height = _native_height;

	manager = new ResourceManager;
}

void en::Core::set_window(const unsigned int _width, const unsigned int _height, const sf::Uint32 style, const unsigned int _frames, const unsigned int _volume, const std::string& name) {

}

void en::Core::draw(const Frame& frame) {

}

void en::Core::pop_up_draw(const Frame& frame) {

}

void en::Core::on_resize_event(Frame& frame) {

}

en::Core::~Core() {
	delete manager;
}
*/
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================