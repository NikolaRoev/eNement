#include "ResourceManager.h"

#include <utility>



//====================================================================================================================================

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

void en::ResourceManager::add_sound(const std::string& file_path, const std::string& sound_buffer_name) {
	sf::SoundBuffer temp;
	temp.loadFromFile(file_path);

	sound_buffers.insert(std::make_pair(sound_buffer_name, temp));
}

//====================================================================================================================================


const sf::Texture& en::ResourceManager::get_texture(const std::string& texture_name) {
	const sf::Texture& found_texture = textures.find(texture_name)->second;

	return found_texture;
}

const sf::Font& en::ResourceManager::get_font(const std::string& font_name) {
	const sf::Font& found_font = fonts.find(font_name)->second;

	return found_font;
}

const sf::SoundBuffer& en::ResourceManager::get_sound_buffer(const std::string& sound_buffer_name) {
	const sf::SoundBuffer& found_sound_buffer = sound_buffers.find(sound_buffer_name)->second;

	return found_sound_buffer;
}

//====================================================================================================================================