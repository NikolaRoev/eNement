#include "Drawable.h"
#include "../Collision/Collision.h"
#include "../Core/Core.h"

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
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);
}

void en::Image::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Image::static_draw() {
	core->window.draw(sprite);
}

void en::Image::draw() {
	core->window.draw(sprite);
}

//====================================================================================================================================

en::Label::Label(const float x, const float y, const sf::Texture& texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text) {
	text_x_original = text_x;
	text_y_original = text_y;
	
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);

	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x * core->delta_x, text_y * core->delta_y);
	text.setString(_text);
	text.scale(core->delta_x, core->delta_y);
}

void en::Label::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	text.setPosition(text_x_original * core->delta_x, text_y_original * core->delta_y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::Label::static_draw() {
	core->window.draw(sprite);
	core->window.draw(text);
}

void en::Label::draw() {
	core->window.draw(sprite);
	core->window.draw(text);
}

void en::Label::set_text(const std::string& new_text) {
	text.setString(new_text);
}

//====================================================================================================================================

en::Button::Button(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * core->delta_x, y * core->delta_y);
	hl_sprite.scale(core->delta_x, core->delta_y);

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(static_cast<float>(core->settings.volume));
}

void en::Button::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Button::static_draw() {
	core->window.draw(sprite);
}

void en::Button::draw() {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(core->window);
	core->window.draw(sprite);

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (core->event.type == sf::Event::MouseButtonPressed && core->event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				core->window.waitEvent(core->event);
				if (core->event.type == sf::Event::MouseButtonReleased) {
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(core->window);
			}
		}
		core->window.draw(hl_sprite);
	}
}

void en::Button::set_volume() {
	sound.setVolume(static_cast<float>(core->settings.volume));
}

//====================================================================================================================================

en::TextButton::TextButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const float text_x, const float text_y, const sf::Font& font, const unsigned int text_size, const sf::Color text_color, const std::string& _text, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	text_x_original = text_x;
	text_y_original = text_y;
	
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * core->delta_x, y * core->delta_y);
	hl_sprite.scale(core->delta_x, core->delta_y);

	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x * core->delta_x, text_y * core->delta_y);
	text.setString(_text);
	text.scale(core->delta_x, core->delta_y);

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(static_cast<float>(core->settings.volume));
}

void en::TextButton::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);

	temp = hl_sprite.getGlobalBounds();
	hl_sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	hl_sprite.scale(resize_delta_x, resize_delta_y);

	text.setPosition(text_x_original * core->delta_x, text_y_original * core->delta_y);
	text.scale(resize_delta_x, resize_delta_y);
}

void en::TextButton::static_draw() {
	core->window.draw(sprite);
	core->window.draw(text);
}

void en::TextButton::draw() {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(core->window);
	core->window.draw(sprite);
	core->window.draw(text);

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (core->event.type == sf::Event::MouseButtonPressed && core->event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				core->window.waitEvent(core->event);
				if (core->event.type == sf::Event::MouseButtonReleased) {
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(core->window);
			}
		}
		core->window.draw(hl_sprite);
	}
}

void en::TextButton::set_text(const std::string& new_text) {
	text.setString(new_text);
}

void en::TextButton::set_volume() {
	sound.setVolume(static_cast<float>(core->settings.volume));
}

//====================================================================================================================================

en::ToggleButton::ToggleButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const bool _pressed, std::function<void()> _function, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x * core->delta_x, y * core->delta_y);
	hl_sprite.scale(core->delta_x, core->delta_y);

	pressed_sprite.setTexture(pressed_texture);
	pressed_sprite.setPosition(x * core->delta_x, y * core->delta_y);
	pressed_sprite.scale(core->delta_x, core->delta_y);

	pressed = _pressed;

	function = _function;

	sound.setBuffer(sound_buffer);
	sound.setVolume(static_cast<float>(core->settings.volume));
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

void en::ToggleButton::static_draw() {
	if (!pressed) {
		core->window.draw(sprite);
	}
	else {
		core->window.draw(pressed_sprite);
	}
}

void en::ToggleButton::draw() {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(core->window);
	if (!pressed) {
		core->window.draw(sprite);
	}
	else {
		core->window.draw(pressed_sprite);
	}

	if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
		if (core->event.type == sf::Event::MouseButtonPressed && core->event.mouseButton.button == sf::Mouse::Left) {
			while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
				core->window.waitEvent(core->event);
				if (core->event.type == sf::Event::MouseButtonReleased) {
					pressed = !pressed;
					sound.play();
					function();
					break;
				}
				mouse_position = sf::Mouse::getPosition(core->window);
			}
		}
		core->window.draw(hl_sprite);
	}
}

void en::ToggleButton::set_volume() {
	sound.setVolume(static_cast<float>(core->settings.volume));
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::Player::Player(const float x, const float y, const sf::Texture& texture) {
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);
}

void en::Player::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);
}

void en::Player::static_draw() {
	core->window.draw(sprite);
}

void en::Player::draw() {
	sf::FloatRect temp = sprite.getGlobalBounds();

	//TO DO: Increment this many times with a check everytime if you want it to be smooth.
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (temp.left > 0) {
			sprite.move(-10, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (temp.left < (core->settings.width - temp.width)) {
			sprite.move(10, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (temp.top > 0) {
			sprite.move(0, -10);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (temp.top < (core->settings.height - temp.height)) {
			sprite.move(0, 10);
		}
	}

	core->window.draw(sprite);
}

const sf::Sprite* en::Player::get_sprite() {
	return &sprite;
}

//====================================================================================================================================

en::PlayerSpell::PlayerSpell(const float x, const float y, const sf::Texture& texture, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x * core->delta_x, y * core->delta_y);
	sprite.scale(core->delta_x, core->delta_y);

	sound.setBuffer(sound_buffer);
	sound.setVolume(static_cast<float>(core->settings.volume));
}

void en::PlayerSpell::resize(const float resize_delta_x, const float resize_delta_y) {
	sf::FloatRect temp = sprite.getGlobalBounds();
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);
	sprite.scale(resize_delta_x, resize_delta_y);
}

void en::PlayerSpell::static_draw() {
	core->window.draw(sprite);
}

void en::PlayerSpell::draw() {
	core->window.draw(sprite);
}

void en::PlayerSpell::set_volume() {
	sound.setVolume(static_cast<float>(core->settings.volume));
}

bool en::PlayerSpell::out_of_bounds_check() {
	//TO DO:
	return false;
}

bool en::PlayerSpell::hit_check(const sf::Sprite* target) {
	return Collision::PixelPerfectTest(*target, sprite);
}

void en::PlayerSpell::move() {
	//TO DO:
}

//====================================================================================================================================
