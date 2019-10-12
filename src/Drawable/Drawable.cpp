#include "Drawable.h"
#include "../Core/Core.h"
#include "../Collision/Collision.h"

#include <functional>
#include <string>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

//====================================================================================================================================

en::Image::Image(const float x, const float y, const sf::Texture& texture) {
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

void en::Image::draw(sf::RenderWindow& window, sf::Event& event) {
	window.draw(sprite);
}

//====================================================================================================================================

en::Label::Label(const float x, const float y, const sf::Texture& texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text) {
	text_x_original = text_x;
	text_y_original = text_y;
	
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

void en::Label::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	text.setPosition(text_x_original * DELTA_X, text_y_original * DELTA_Y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::Label::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(text);
}

void en::Label::draw(sf::RenderWindow& window, sf::Event& event) {
	window.draw(sprite);
	window.draw(text);
}

void en::Label::set_text(const std::string& new_text) {
	text.setString(new_text);
}

//====================================================================================================================================

en::Button::Button(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	hl_sprite.scale(DELTA_X, DELTA_Y);

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
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

void en::Button::draw(sf::RenderWindow& window, sf::Event& event) {
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

void en::Button::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================

en::TextButton::TextButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	text_x_original = text_x;
	text_y_original = text_y;
	
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

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
}

void en::TextButton::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);

	text.setPosition(text_x_original * DELTA_X, text_y_original * DELTA_Y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::TextButton::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(text);
}

void en::TextButton::draw(sf::RenderWindow& window, sf::Event& event) {
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

void en::TextButton::set_text(const std::string& new_text) {
	text.setString(new_text);
}

void en::TextButton::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================

en::ToggleButton::ToggleButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const bool _pressed, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	hl_sprite.scale(DELTA_X, DELTA_Y);

	pressed_sprite.setTexture(pressed_texture);
	pressed_sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	pressed_sprite.scale(DELTA_X, DELTA_Y);

	pressed = _pressed;

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
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

void en::ToggleButton::draw(sf::RenderWindow& window, sf::Event& event) {
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

void en::ToggleButton::set_volume() {
	sound.setVolume(VOLUME);
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::Player::Player(const float x, const float y, const sf::Texture& texture) {
	sprite.setTexture(texture);
	sprite.setPosition(x * DELTA_X, y * DELTA_Y);
	sprite.scale(DELTA_X, DELTA_Y);
}

void en::Player::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void en::Player::draw(sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect temp = sprite.getGlobalBounds();

	//TO DO: Increment this many times with a check everytime if you want it to be smooth.
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (temp.left > 0) {
			sprite.move(-10, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (temp.left < (WIDTH - temp.width)) {
			sprite.move(10, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (temp.top > 0) {
			sprite.move(0, -10);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (temp.top < (HEIGHT - temp.height)) {
			sprite.move(0, 10);
		}
	}

	window.draw(sprite);
}

const sf::Sprite* en::Player::get_sprite() {
	return &sprite;
}

//====================================================================================================================================

en::PlayerSpell::PlayerSpell(const float x, const float y, const std::vector<sf::Texture>& move_animation, const std::vector<sf::Texture>& cast_animation, const std::vector<sf::Texture>& hit_animation, const sf::SoundBuffer& sound_buffer) {
	for (const auto& each : move_animation) {
		move_vector.push_back(sf::Sprite());
		move_vector.back().setTexture(each);
		move_vector.back().scale(DELTA_X, DELTA_Y);
	}

	for (const auto& each : cast_animation) {
		cast_vector.push_back(sf::Sprite());
		cast_vector.back().setTexture(each);
		cast_vector.back().setPosition(x, y);
		cast_vector.back().scale(DELTA_X, DELTA_Y);
	}

	for (const auto& each : hit_animation) {
		hit_vector.push_back(sf::Sprite());
		hit_vector.back().setTexture(each);
		hit_vector.back().scale(DELTA_X, DELTA_Y);
	}

	sound.setBuffer(sound_buffer);
	sound.setVolume(VOLUME);
}

void en::PlayerSpell::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = current_sprite.getGlobalBounds();
	current_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	current_sprite.scale(resize_delta_x, resize_delta_y);

	for (auto& each : move_vector) {
		each.scale(resize_delta_x, resize_delta_y);
	}

	for (auto& each : cast_vector) {
		temp = each.getGlobalBounds();
		each.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
		each.scale(resize_delta_x, resize_delta_y);
	}

	for (auto& each : hit_vector) {
		each.scale(resize_delta_x, resize_delta_y);
	}
}

void en::PlayerSpell::draw(sf::RenderWindow& window) {
	window.draw(current_sprite);
}

void en::PlayerSpell::draw(sf::RenderWindow& window, sf::Event& event) {
	//TO DO:
}

void en::PlayerSpell::set_volume() {
	sound.setVolume(VOLUME);
}

bool en::PlayerSpell::out_of_bounds_check() {
	//TO DO:
	return false;
}

bool en::PlayerSpell::hit_check(const sf::Sprite* target) {
	return Collision::PixelPerfectTest(*target, current_sprite);
}

void en::PlayerSpell::move() {
	//TO DO:
}

//====================================================================================================================================
