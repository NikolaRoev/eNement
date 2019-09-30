#pragma once

#include <functional>
#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================

	class Drawable {
	public:
		virtual ~Drawable() = default;

		//Image. //Player.
		virtual void setup(const sf::Texture& texture, const float x, const float y) = 0;

		//Label.
		virtual void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) = 0;

		//ImageLabel.
		virtual void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) = 0;

		//Button.
		virtual void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) = 0;

		//Text button.
		virtual void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) = 0;

		//Toggle button.
		virtual void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) = 0;

		//Utility functions.
		virtual void resize(const float resize_delta_x, const float resize_delta_y) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void draw(sf::RenderWindow& window, sf::Event& event) = 0;

		virtual void set_function(std::function<void()> _function) = 0;

		virtual void set_sound(const sf::SoundBuffer& sound_buffer) = 0;

		virtual void set_text(const std::string& new_text) = 0;

		virtual void set_volume() = 0;

		//Game drawables specific functions.

		//TO DO:
	};

	//====================================================================================================================================

	class Image : public Drawable {
	private:
		sf::Sprite sprite;

	public:
		void setup(const sf::Texture& texture, const float x, const float y) override;

		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override {}

		void set_volume() override {}
	};

	//====================================================================================================================================

	class Label : public Drawable {
	private:
		sf::Text text;

	public:
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override;

		void set_volume() override {}
	};

	//====================================================================================================================================

	class ImageLabel : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Text text;

	public:
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override;

		void set_volume() override {}
	};

	//====================================================================================================================================

	class Button : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		std::function<void()> function;
		sf::Sound sound;

	public:
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override {}

		void set_volume() override;
	};

	//====================================================================================================================================

	class TextButton : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		sf::Text text;
		std::function<void()> function;
		sf::Sound sound;

	public:
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override;

		void set_volume() override;
	};

	//====================================================================================================================================

	class ToggleButton : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		sf::Sprite pressed_sprite;
		bool pressed{ false };
		std::function<void()> function;
		sf::Sound sound;

	public:
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override {}

		void set_volume() override;
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	
	class Player : public Drawable {
	private:
		sf::Sprite sprite;

	public:

		void setup(const sf::Texture& texture, const float x, const float y) override;

		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override {}

		void set_volume() override {}
	};

	//====================================================================================================================================

	class PlayerSpell : public Drawable {
	private:
		//TO DO: All of these.
	public:

	};

	//====================================================================================================================================

	class Enemy : public Drawable {
	private:

	public:

	};

	//====================================================================================================================================

	class EnemySpell : public Drawable {
	private:

	public:

	};

	//====================================================================================================================================
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================