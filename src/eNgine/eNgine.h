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


namespace en {
	class Drawable1 {
	public:
		Drawable1() = default;
		Drawable1(const Drawable1&) = delete;
		Drawable1(Drawable1&&) = delete;
		Drawable1& operator=(const Drawable1&) = delete;
		Drawable1& operator=(Drawable1&&) = delete;
		virtual ~Drawable1() = default;

		virtual Drawable1* clone() = 0;
	};

	class Button1 : public Drawable1 {
	private:

	public:
		Button1() {

		}
		Button1(const Button1&) {

		}
		Button1(Button1&&) = delete;
		Button1& operator=(const Button1&) = delete;
		Button1& operator=(Button1&&) = delete;
		~Button1() {

		}

		Button1* clone() override {
			return new Button1(*this);
		}
	};
}



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
		bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
		bool CreateTextureAndBitmask(sf::Texture& LoadInto, const std::string& Filename);

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
		double native_width{ 1920.0 };
		double native_height{ 1080.0 };

		unsigned int width{ 1024 };
		unsigned int height{ 576 };
		unsigned int frames{ 60 };
		unsigned int volume{ 50 };

		float delta_x{ 1.0f };
		float delta_y{ 1.0f };

		sf::RenderWindow window;
		sf::Event event{ sf::Event::MouseMoved };
		sf::Clock clock;
		sf::Time time;


		void set_delta_values();

	public:
		ResourceManager* manager{ nullptr };


		Core(const double _native_width, const double _native_height);

		Core(const Core&) = delete;

		Core(Core&&) = delete;

		Core& operator=(const Core&) = delete;

		Core& operator=(Core&&) = delete;

		~Core();


		void set_window();

		void load_settings();

		void save_settings();

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