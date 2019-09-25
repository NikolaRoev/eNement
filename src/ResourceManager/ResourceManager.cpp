#include "ResourceManager.h"
#include "../Collision/Collision.h"

#include <string>
#include <utility>
#include <unordered_map>

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
	sf::Texture temp;
	textures.insert(std::make_pair(texture_name, temp));
	
	Collision::CreateTextureAndBitmask(textures.find(texture_name)->second, file_path);
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