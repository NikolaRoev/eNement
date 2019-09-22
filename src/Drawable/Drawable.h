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

	struct Drawable {
		virtual ~Drawable() {}

		//Image:
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

		//TO DO: Add the other drawables setup functions here.

		//Utility functions.
		virtual void resize(const float resize_delta_x, const float resize_delta_y) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) = 0;

		//TO DO: Add a custom draw function for projectiles and if needed other drawables, maybe the player will also have a custom draw with the arrow controls being in it.

		virtual void set_function(std::function<void()> _function) = 0;

		virtual void set_sound(const sf::SoundBuffer& sound_buffer) = 0;

		virtual void set_text(const std::string& new_text) = 0;

		virtual void set_volume() = 0;
	};

	//====================================================================================================================================

	struct Image : public Drawable {
		sf::Sprite sprite;
		float sprite_x_original{ 0.0f };
		float sprite_y_original{ 0.0f };


		void setup(const sf::Texture& texture, const float x, const float y) override;

		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override {}

		void set_volume() override {}
	};

	//====================================================================================================================================

	struct Label : public Drawable {
		sf::Text text;
		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };

		
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override;

		void set_volume() override {}
	};

	//====================================================================================================================================

	struct ImageLabel : public Drawable {
		sf::Sprite sprite;
		float sprite_x_original{ 0.0f };
		float sprite_y_original{ 0.0f };
		sf::Text text;
		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };


		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override {}

		void set_sound(const sf::SoundBuffer& sound_buffer) override {}

		void set_text(const std::string& new_text) override;

		void set_volume() override {}
	};

	//====================================================================================================================================

	struct Button : public Drawable {
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		float sprite_x_original{ 0.0f };
		float sprite_y_original{ 0.0f };
		std::function<void()> function;
		sf::Sound sound;


		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override {}

		void set_volume() override;
	};

	//====================================================================================================================================

	struct TextButton : public Drawable {
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		float sprite_x_original{ 0.0f };
		float sprite_y_original{ 0.0f };
		sf::Text text;
		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };
		std::function<void()> function;
		sf::Sound sound;


		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override;

		void set_volume() override;
	};

	//====================================================================================================================================

	struct ToggleButton : public Drawable {
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		float sprite_x_original{ 0.0f };
		float sprite_y_original{ 0.0f };
		sf::Sprite pressed_sprite;
		bool pressed{ false };
		std::function<void()> function;
		sf::Sound sound;


		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press = false) override;

		void setup(const sf::Texture& texture, const float x, const float y) override {}
		void setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) override {}
		void setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) override {}

		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) override;

		void set_function(std::function<void()> _function) override;

		void set_sound(const sf::SoundBuffer& sound_buffer) override;

		void set_text(const std::string& new_text) override {}

		void set_volume() override;
	};

	//====================================================================================================================================
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================