#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	class ResourceManager {
	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, sf::Font> fonts;
		std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;

	public:
		void add_texture(const std::string& file_path, const std::string& texture_name);
		void add_texture_for_pixel_perfect(const std::string& file_path, const std::string& texture_name);

		void add_font(const std::string& file_path, const std::string& font_name);
		void add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name);

		const sf::Texture& get_texture(const std::string& texture_name) const;
		const sf::Font& get_font(const std::string& font_name) const;
		const sf::SoundBuffer& get_sound_buffer(const std::string& sound_buffer_name) const;
	};

}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================