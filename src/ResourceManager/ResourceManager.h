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

	class ResourceManager {
	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, std::vector<sf::Texture>> animation_textures;
		std::unordered_map<std::string, sf::Font> fonts;
		std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;

		std::unordered_map<std::string, Drawable*> drawables;

	public: //TO DO: Maybe add a delete texture and/or drawable function.
		void add_texture(const std::string& file_path, const std::string& texture_name);
		void add_texture_for_pixel_perfect(const std::string& file_path, const std::string& texture_name);
		
		void add_animation(const std::vector<std::string>&file_paths, const std::string& animation_name);
		void add_animation_for_pixel_perfect(const std::vector<std::string>& file_paths, const std::string& animation_name);

		void add_font(const std::string& file_path, const std::string& font_name);
		void add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name);

		const sf::Texture& get_texture(const std::string& texture_name) const;
		const std::vector<sf::Texture>& get_animation(const std::string& animation_name) const;
		const sf::Font& get_font(const std::string& font_name) const;
		const sf::SoundBuffer& get_sound_buffer(const std::string& sound_buffer_name) const;


		//====================================================================================================================================

		void add_drawable(Drawable& drawable, const std::string& drawable_name);
		Drawable* get_drawable(const std::string& drawable_name) const;

		void resize_all(const float d_x, const float d_y);
		void change_volume_for_all();
	};

}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================