#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

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
		Button1() {}

		Button1(const Button1&) {
			std::cout << "YUP";
		}

		Button1* clone() override {
			std::cout << "Clone call.";
			return new Button1(*this);
		}
	};
} //Include drawable here.



//====================================================================================================================================
/*
namespace en {

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
		void add_font(const std::string& file_path, const std::string& font_name);
		void add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name);

		const sf::Texture& get_texture(const std::string& texture_name) const;
		const sf::Font& get_font(const std::string& font_name) const;
		const sf::SoundBuffer& get_sound_buffer(const std::string& sound_buffer_name) const;


		void add_drawable(Drawable* drawable, const std::string& drawable_name);

		Drawable* get_drawable(const std::string& drawable_name) const;


		std::unordered_map<std::string, Drawable*>& get_all_drawables();
	};

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

	struct Layer {
		std::vector<Drawable*> static_drawables{};

		std::unordered_map<std::string, Drawable*> dynamic_drawables{};


		~Layer();
	};

	struct Frame {
		std::map<int, Layer> layers{};

		std::vector<Drawable*> pop_up_drawables{};


		void add_static_drawable(Drawable* drawable, const int layer);
		void add_dynamic_drawable(const std::string& name, Drawable* drawable, const int layer);
		void delete_dynamic_drawable(const std::string& name);

		void add_pop_up_drawable(Drawable* drawable);
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


		void set_window(const unsigned int _width,
						const unsigned int _height,
						const sf::Uint32 style,
						const unsigned int _frames,
						const unsigned int _volume,
						const std::string& name);

		void draw(const Frame& frame);

		void pop_up_draw(const Frame& frame);

		void on_resize_event(Frame& frame);
	};

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

} //"en" namespace END.
*/
//====================================================================================================================================