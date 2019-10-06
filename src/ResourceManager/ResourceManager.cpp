#include "ResourceManager.h"
#include "../Collision/Collision.h"
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

void en::ResourceManager::add_texture(const std::string& file_path, const std::string& texture_name) {
	sf::Texture temp;
	temp.loadFromFile(file_path);

	textures.insert(std::make_pair(texture_name, temp));
}

void en::ResourceManager::add_texture_for_pixel_perfect(const std::string& file_path, const std::string& texture_name) {
	textures.insert(std::make_pair(texture_name, sf::Texture()));
	
	Collision::CreateTextureAndBitmask(textures.find(texture_name)->second, file_path);
}

void en::ResourceManager::add_animation(const std::vector<std::string>& file_paths, const std::string& animation_name) {
	auto[it, inserted] = animation_textures.insert(std::make_pair(animation_name, std::vector<sf::Texture>()));
	if (inserted) {
		for (const auto& each : file_paths) {
			sf::Texture temp;
			temp.loadFromFile(each);
			it->second.push_back(temp);
		}
	}
}

void en::ResourceManager::add_animation_for_pixel_perfect(const std::vector<std::string>& file_paths, const std::string& animation_name) {
	auto [it, inserted] = animation_textures.insert(std::make_pair(animation_name, std::vector<sf::Texture>()));
	if (inserted) {
		for (const auto& each : file_paths) {
			it->second.push_back(sf::Texture());
			Collision::CreateTextureAndBitmask(it->second.back(), each);
		}
	}
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

void en::ResourceManager::add_drawable(Drawable& drawable, const std::string& drawable_name) {
	drawables.insert(std::make_pair(drawable_name, &drawable));
}

en::Drawable* en::ResourceManager::get_drawable(const std::string& drawable_name) const {
	return drawables.find(drawable_name)->second;
}

//====================================================================================================================================

void en::ResourceManager::resize_all(const float d_x, const float d_y) {
	for (const auto& each : drawables) {
		each.second->resize(d_x, d_y);
	}
}

void en::ResourceManager::change_volume_for_all() {
	for (const auto& each : drawables) {
		each.second->set_volume();
	}
}

//====================================================================================================================================