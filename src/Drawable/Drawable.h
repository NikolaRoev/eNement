#pragma once

#include <functional>
#include <string>
#include <vector>

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

		//Utility functions.
		virtual void resize(const float resize_delta_x, const float resize_delta_y) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void draw(sf::RenderWindow& window, sf::Event& event) = 0;


		virtual void set_text(const std::string& new_text) = 0;

		virtual void set_volume() = 0;

		//Game drawables specific functions.

		virtual bool out_of_bounds_check() = 0;

		virtual bool hit_check(const sf::Sprite* target) = 0;

		virtual void move() = 0; //TO DO: Add the move logic here.

		virtual const sf::Sprite* get_sprite() = 0;
	};

	struct DrawableDeleter {
		void operator()(Drawable*& drawable) {
			if (drawable->out_of_bounds_check()) {
				delete drawable;
				drawable = nullptr;
			}
		}
	};

	//====================================================================================================================================

	class Image : public Drawable {
	private:
		sf::Sprite sprite;

	public:
		Image(const float x, const float y, const sf::Texture& texture);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume() override {}


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================

	class Label : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Text text;

		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };

	public:
		Label(const float x, const float y, const sf::Texture& texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override;

		void set_volume() override {}


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================

	class Button : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		std::function<void()> function;
		sf::Sound sound;

	public:
		Button(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, std::function<void()> _function, const sf::SoundBuffer& sound_buffer);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume() override;


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================

	class TextButton : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		sf::Text text;
		std::function<void()> function;
		sf::Sound sound;

		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };

	public:
		TextButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text, std::function<void()> _function, const sf::SoundBuffer& sound_buffer);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override;

		void set_volume() override;


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override { return nullptr; }
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
		ToggleButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const bool _pressed, std::function<void()> _function, const sf::SoundBuffer& sound_buffer);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume() override;


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	
	class Player : public Drawable {
	private:
		sf::Sprite sprite;

	public:
		Player(const float x, const float y, const sf::Texture& texture);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume() override {}


		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override {}

		const sf::Sprite* get_sprite() override;
	};

	//====================================================================================================================================
	//TO DO: All of these.
	class PlayerSpell : public Drawable {
	private:
		sf::Sprite current_sprite;

		std::vector<sf::Sprite> move_vector;
		std::vector<sf::Sprite> cast_vector;
		std::vector<sf::Sprite> hit_vector;

		sf::Sound sound;

		bool hit{ false };

	public:
		PlayerSpell(const float x, const float y, const std::vector<sf::Texture>& move_animation, const std::vector<sf::Texture>& cast_animation, const std::vector<sf::Texture>& hit_animation, const sf::SoundBuffer& sound_buffer);


		void resize(const float resize_delta_x, const float resize_delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume() override;


		bool out_of_bounds_check() override;

		bool hit_check(const sf::Sprite* target) override;

		void move() override;

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================

	class Enemy : public Drawable {
	private:

	public:



		bool out_of_bounds_check() override { return false; }

		bool hit_check(const sf::Sprite* target) override { return false; }

		void move() override;

		const sf::Sprite* get_sprite() override;
	};

	//====================================================================================================================================

	class EnemySpell : public Drawable {
	private:

		bool hit{ false };

	public:



		bool out_of_bounds_check() override;

		bool hit_check(const sf::Sprite* target) override;

		void move() override;

		const sf::Sprite* get_sprite() override { return nullptr; }
	};

	//====================================================================================================================================
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================