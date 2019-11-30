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
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class Drawable {
	public:
		virtual ~Drawable() = default;


		//Utility functions.
		virtual void resize(const float delta_x, const float delta_y) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void draw(sf::RenderWindow& window, sf::Event& event) = 0;


		//Setters.
		virtual void set_text(const std::string& new_text) = 0;

		virtual void set_volume(const unsigned int volume) = 0;


		//Game drawables specific functions.
		virtual const sf::Sprite* get_sprite() = 0;

		virtual void move(const float delta_x, const float delta_y) = 0;

		virtual void play_sound() = 0;

		virtual Drawable* clone() = 0;
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class Image : public Drawable {
	private:
		sf::Sprite sprite;

	public:
		Image(const float x,
			  const float y,
			  const float delta_x,
			  const float delta_y,
			  const sf::Texture& texture);


		Image(const Image&) = delete;
		Image(Image&&) = delete;
		Image& operator=(const Image&) = delete;
		Image& operator=(Image&&) = delete;
		~Image() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override {}


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		Image* clone() override { return nullptr; }
	};

	//====================================================================================================================================

	class Label : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Text text;

	public:
		Label(const float x,
			  const float y,
			  const float delta_x,
			  const float delta_y,
			  const sf::Texture& texture,
			  const float text_x,
			  const float text_y,
			  const sf::Font& font,
			  const unsigned int text_size,
			  const sf::Color text_color,
			  const std::string& _text);


		Label(const Label&) = delete;
		Label(Label&&) = delete;
		Label& operator=(const Label&) = delete;
		Label& operator=(Label&&) = delete;
		~Label() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override;

		void set_volume(const unsigned int volume) override {}


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		Label* clone() override { return nullptr; }
	};

	//====================================================================================================================================

	class Button : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		std::function<void()> function;
		sf::Sound sound;

	public:
		Button(const float x,
			   const float y,
			   const float delta_x,
			   const float delta_y,
			   const sf::Texture& texture,
			   const sf::Texture& hl_texture,
			   std::function<void()> _function,
			   const sf::SoundBuffer& sound_buffer,
			   const unsigned int volume);


		Button(const Button&) = delete;
		Button(Button&&) = delete;
		Button& operator=(const Button&) = delete;
		Button& operator=(Button&&) = delete;
		~Button() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override;


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		Button* clone() override { return nullptr; }
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	
	//TO DO: Add the eNement specific menu drawables. Like the spell selectors and the plus buttons.

	class EntityDrawable : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sound sound;

	public:
		EntityDrawable(const float x,
					   const float y,
					   const float delta_x,
					   const float delta_y,
					   const sf::Texture& texture,
					   const sf::SoundBuffer& sound_buffer,
					   const unsigned int volume);


		EntityDrawable(const EntityDrawable& other);


		EntityDrawable(EntityDrawable&&) = delete;
		EntityDrawable& operator=(const EntityDrawable&) = delete;
		EntityDrawable& operator=(EntityDrawable&&) = delete;
		~EntityDrawable() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override;


		const sf::Sprite* get_sprite() override;

		void move(const float delta_x, const float delta_y) override;

		void play_sound() override;

		EntityDrawable* clone() override;
	};

	//====================================================================================================================================

	class SpellDrawable : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sound sound;

	public:
		SpellDrawable(const float x,
					  const float y,
					  const float delta_x,
					  const float delta_y,
					  const sf::Texture& texture,
					  const sf::SoundBuffer& sound_buffer,
					  const unsigned int volume);


		SpellDrawable(const SpellDrawable& other);


		SpellDrawable(SpellDrawable&&) = delete;
		SpellDrawable& operator=(const SpellDrawable&) = delete;
		SpellDrawable& operator=(SpellDrawable&&) = delete;
		~SpellDrawable() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override;


		const sf::Sprite* get_sprite() override;

		void move(const float delta_x, const float delta_y) override;

		void play_sound() override;

		SpellDrawable* clone() override;
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

} //"en" namespace END.

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================