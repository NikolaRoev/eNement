#pragma once
#include "..\\Drawable\Drawable.h"

#include <map>
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
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	struct DynamicFrame {
		std::unordered_map<std::string, Drawable*> dynamic_drawables{};


		~DynamicFrame();


		void add_dynamic_drawable(const std::string& name, Drawable* drawable);
		void delete_dynamic_drawable(const std::string& name);
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class ResourceManager {
	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, sf::Font> fonts;
		std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;

		std::unordered_map<std::string, Drawable*> drawables;

	public:
		~ResourceManager();

		void add_texture(const std::string& file_path, const std::string& texture_name);
		void add_texture_for_pixel_perfect(const std::string& file_path, const std::string& texture_name);
		void add_font(const std::string& file_path, const std::string& font_name);
		void add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name);
		void add_drawable(Drawable* drawable, const std::string& drawable_name);

		const sf::Texture& get_texture(const std::string& texture_name) const;
		const sf::Font& get_font(const std::string& font_name) const;
		const sf::SoundBuffer& get_sound_buffer(const std::string& sound_buffer_name) const;
		Drawable* get_drawable(const std::string& drawable_name) const;
		std::unordered_map<std::string, Drawable*>& get_all_drawables();

		//Collision.
		bool pixel_perfect_test(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
		bool create_texture_and_bitmask(sf::Texture& LoadInto, const std::string& Filename);

		//Scale functions.
		void scale_drawables(const float delta_x, const float delta_y);
		void scale_drawables(const float delta_x, const float delta_y, DynamicFrame& dynamic_frame);
		void change_volume(const unsigned int volume);
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class Core {
	private:
		float native_width{ 1920.0f };
		float native_height{ 1080.0f };

		
		float delta_x{ 1.0f };
		float delta_y{ 1.0f };

		
		void set_delta_values();

	public:
		unsigned int width{ 1024u };
		unsigned int height{ 576u };
		unsigned int frames{ 60u };
		unsigned int volume{ 50u };

		sf::RenderWindow window;
		sf::Event event{ sf::Event::MouseMoved };
		sf::Clock clock;
		sf::Time time;


		ResourceManager* manager{ nullptr };


		Core(const float _native_width, const float _native_height);

		Core(const Core&) = delete;

		Core(Core&&) = delete;

		Core& operator=(const Core&) = delete;

		Core& operator=(Core&&) = delete;

		~Core();


		void set_window();

		void set_window(unsigned int _width, unsigned int _height);

		void load_settings();

		void save_settings();

		void adjust_drawables();

		void draw(const std::vector<Drawable*>& static_frame);

		void draw(const std::vector<Drawable*>& static_frame, const DynamicFrame& dynamic_frame);

		void draw(const std::vector<Drawable*>& static_frame, const DynamicFrame& dynamic_frame, const std::vector<Drawable*>& pop_up_frame);

		void on_resize_event();

		void on_resize_event(DynamicFrame& dynamic_frame);
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

} //"en" namespace END.

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================