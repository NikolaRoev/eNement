#include "Drawable.h"
#include "..\\Core\Core.h"

#include <functional>
#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Image::setup(const sf::Texture& texture, const float x, const float y) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);
}

void en::Image::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Image::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void en::Image::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	window.draw(sprite);
}

//====================================================================================================================================

void en::Label::setup(const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) {
	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x * DELTA_X, text_y * DELTA_Y);
	text.setString(_text);
	text.scale(DELTA_X, DELTA_Y);
}

void en::Label::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = text.getGlobalBounds();
	text.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::Label::draw(sf::RenderWindow& window) {
	window.draw(text);
}

void en::Label::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	window.draw(text);
}

void en::Label::set_text(const std::string& new_text) {
	text.setString(new_text);
}

//====================================================================================================================================

void en::ImageLabel::setup(const sf::Texture& texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);
	
	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x * DELTA_X, text_y * DELTA_Y);
	text.setString(_text);
	text.scale(DELTA_X, DELTA_Y);
}

void en::ImageLabel::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = text.getGlobalBounds();
	text.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::ImageLabel::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(text);
}

void en::ImageLabel::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	window.draw(sprite);
	window.draw(text);
}

void en::ImageLabel::set_text(const std::string& new_text) {
	text.setString(new_text);
}

//====================================================================================================================================

void en::Button::setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	hl_sprite.scale(DELTA_X, DELTA_Y);
}

void en::Button::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Button::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void en::Button::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	window.draw(sprite);

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				window.waitEvent(event);
				if (event.type == sf::Event::MouseButtonReleased) {
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(window);
			}
		}
		window.draw(hl_sprite);
	}
}

void en::Button::set_function(std::function<void()> _function) {
	function = _function;
}

void en::Button::set_sound(const sf::SoundBuffer& sound_buffer) {
	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
}

void en::Button::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================

void en::TextButton::setup(const sf::Texture& texture, const sf::Texture& hl_texture, const float x, const float y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const float text_x, const float text_y, const std::string& _text) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	hl_sprite.scale(DELTA_X, DELTA_Y);

	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x * DELTA_X, text_y * DELTA_Y);
	text.setString(_text);
	text.scale(DELTA_X, DELTA_Y);
}

void en::TextButton::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);

	temp = text.getGlobalBounds();
	text.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::TextButton::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(text);
}

void en::TextButton::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	window.draw(sprite);
	window.draw(text);

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				window.waitEvent(event);
				if (event.type == sf::Event::MouseButtonReleased) {
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(window);
			}
		}
		window.draw(hl_sprite);
	}
}

void en::TextButton::set_function(std::function<void()> _function) {
	function = _function;
}

void en::TextButton::set_sound(const sf::SoundBuffer& sound_buffer) {
	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
}

void en::TextButton::set_text(const std::string& new_text) {
	text.setString(new_text);
}

void en::TextButton::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================

void en::ToggleButton::setup(const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const float x, const float y, const bool press) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	hl_sprite.scale(DELTA_X, DELTA_Y);

	pressed_sprite.setTexture(pressed_texture);
	pressed_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	pressed_sprite.scale(DELTA_X, DELTA_Y);

	if (press) pressed = true;
}

void en::ToggleButton::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);

	temp = pressed_sprite.getGlobalBounds();
	pressed_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	pressed_sprite.scale(resize_delta_x, resize_delta_y);
}

void en::ToggleButton::draw(sf::RenderWindow& window) {
	if (!pressed) {
		window.draw(sprite);
	}
	else {
		window.draw(pressed_sprite);
	}
}

void en::ToggleButton::draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	if (!pressed) {
		window.draw(sprite);
	}
	else {
		window.draw(pressed_sprite);
	}

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				window.waitEvent(event);
				if (event.type == sf::Event::MouseButtonReleased) {
					pressed = !pressed;
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(window);
			}
		}
		window.draw(hl_sprite);
	}
}

void en::ToggleButton::set_function(std::function<void()> _function) {
	function = _function;
}

void en::ToggleButton::set_sound(const sf::SoundBuffer& sound_buffer) {
	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
}

void en::ToggleButton::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================
