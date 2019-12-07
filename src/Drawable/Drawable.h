#pragma once

#include <array>
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

	class Image : public Drawable {
	private:
		sf::Sprite sprite;

	public:
		Image(const float x,
			  const float y,
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

		float text_x_original{ 0.0f };
		float text_y_original{ 0.0f };

	public:
		Label(const float x,
			  const float y,
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
			   const sf::Texture& texture,
			   const sf::Texture& hl_texture,
			   std::function<void()> _function,
			   const sf::SoundBuffer& sound_buffer);


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
	
	class DeleteButton : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		std::function<void()> function;
		sf::Sound sound;

		unsigned int* watcher{ nullptr };

	public:
		DeleteButton(const float x,
					 const float y,
					 const sf::Texture& texture,
					 const sf::Texture& hl_texture,
					 std::function<void()> _function,
					 const sf::SoundBuffer& sound_buffer,
					 unsigned int& _watcher);


		DeleteButton(const DeleteButton&) = delete;
		DeleteButton(DeleteButton&&) = delete;
		DeleteButton& operator=(const DeleteButton&) = delete;
		DeleteButton& operator=(DeleteButton&&) = delete;
		~DeleteButton() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override;


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		DeleteButton* clone() override { return nullptr; }
	};

	//====================================================================================================================================

	class SpellIcon : public Drawable {
	private:
		std::array<sf::Sprite, 9> sprites;
		
		unsigned int* watcher{ nullptr };

	public:
		SpellIcon(const float x,
				  const float y,
				  const sf::Texture& texture_empty,
				  const sf::Texture& texture_fire,
				  const sf::Texture& texture_water,
				  const sf::Texture& texture_wind,
				  const sf::Texture& texture_earth,
				  const sf::Texture& texture_ice,
				  const sf::Texture& texture_lightning,
				  const sf::Texture& texture_light,
				  const sf::Texture& texture_dark,
				  unsigned int& _watcher);


		SpellIcon(const SpellIcon&) = delete;
		SpellIcon(SpellIcon&&) = delete;
		SpellIcon& operator=(const SpellIcon&) = delete;
		SpellIcon& operator=(SpellIcon&&) = delete;
		~SpellIcon() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override {}


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		SpellIcon* clone() override { return nullptr; }
	};

	//====================================================================================================================================

	class SpellButton : public Drawable {
	private:
		bool pressed{ false };

		sf::Sprite sprite;
		sf::Sprite hl_sprite;
		sf::Sprite pressed_sprite;
		sf::Sprite unavailable_sprite;
		sf::Sound sound;

		unsigned int type{ 0 };

		unsigned int* watcher1{ nullptr };
		unsigned int* watcher2{ nullptr };

	public:
		SpellButton(const float x,
					const float y,
					const sf::Texture& texture,
					const sf::Texture& hl_texture,
					const sf::Texture& pressed_texture,
					const sf::Texture& unavailable_texture,
					const sf::SoundBuffer& sound_buffer,
					const unsigned int _type, 
					unsigned int& _watcher1,
					unsigned int& _watcher2);


		SpellButton(const SpellButton&) = delete;
		SpellButton(SpellButton&&) = delete;
		SpellButton& operator=(const SpellButton&) = delete;
		SpellButton& operator=(SpellButton&&) = delete;
		~SpellButton() = default;


		void resize(const float delta_x, const float delta_y) override;

		void draw(sf::RenderWindow& window) override;

		void draw(sf::RenderWindow& window, sf::Event& event) override;


		void set_text(const std::string& new_text) override {}

		void set_volume(const unsigned int volume) override;


		const sf::Sprite* get_sprite() override { return nullptr; }

		void move(const float delta_x, const float delta_y) override {}

		void play_sound() override {}

		SpellButton* clone() override { return nullptr; }
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class EntityDrawable : public Drawable {
	private:
		sf::Sprite sprite;
		sf::Sound sound;

	public:
		EntityDrawable(const float x,
					   const float y,
					   const sf::Texture& texture,
					   const sf::SoundBuffer& sound_buffer);


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
					  const sf::Texture& texture,
					  const sf::SoundBuffer& sound_buffer);


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
	//====================================================================================================================================
	//====================================================================================================================================

} //"en" namespace END.

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================