#include "Drawable.h"

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

en::Image::Image(const float x, const float y, const sf::Texture& texture) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void en::Image::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
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
	sprite.setPosition(x, y);

	text.setFont(font);
	text.setCharacterSize(text_size);
	text.setFillColor(text_color);
	text.setPosition(text_x, text_y);
	text.setString(_text);
}

void en::Label::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
	

	text.setPosition(text_x_original * delta_x, text_y_original * delta_y);
	text.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
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
	sprite.setPosition(x, y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x, y);

	function = _function;

	sound.setBuffer(sound_buffer);
}

void en::Button::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
	

	hl_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	hl_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
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

void en::Button::set_volume(const unsigned int volume) {
	sound.setVolume(static_cast<float>(volume));
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::DeleteButton::DeleteButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, std::function<void()> _function, const sf::SoundBuffer& sound_buffer, unsigned int& _watcher) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x, y);

	function = _function;

	sound.setBuffer(sound_buffer);

	watcher = &_watcher;
}

void en::DeleteButton::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);


	hl_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	hl_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
}

void en::DeleteButton::draw(sf::RenderWindow& window) {
	if (*watcher != 0u) {
		window.draw(sprite);
	}
}

void en::DeleteButton::draw(sf::RenderWindow& window, sf::Event& event) {
	if (*watcher != 0u) {
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
}

void en::DeleteButton::set_volume(const unsigned int volume) {
	sound.setVolume(static_cast<float>(volume));
}

//====================================================================================================================================

en::SpellIcon::SpellIcon(const float x, const float y, const sf::Texture& texture_empty, const sf::Texture& texture_fire, const sf::Texture& texture_water, const sf::Texture& texture_wind, const sf::Texture& texture_earth, const sf::Texture& texture_ice, const sf::Texture& texture_lightning, const sf::Texture& texture_light, const sf::Texture& texture_dark, unsigned int& _watcher) {
	sprites[0].setTexture(texture_empty);
	sprites[0].setPosition(x, y);

	sprites[1].setTexture(texture_fire);
	sprites[1].setPosition(x, y);

	sprites[2].setTexture(texture_water);
	sprites[2].setPosition(x, y);

	sprites[3].setTexture(texture_wind);
	sprites[3].setPosition(x, y);

	sprites[4].setTexture(texture_earth);
	sprites[4].setPosition(x, y);

	sprites[5].setTexture(texture_ice);
	sprites[5].setPosition(x, y);

	sprites[6].setTexture(texture_lightning);
	sprites[6].setPosition(x, y);

	sprites[7].setTexture(texture_light);
	sprites[7].setPosition(x, y);

	sprites[8].setTexture(texture_dark);
	sprites[8].setPosition(x, y);

	watcher = &_watcher;
}

void en::SpellIcon::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprites[0].getGlobalBounds();
	sf::Vector2 current_scale = sprites[0].getScale();

	for (auto& each : sprites) {
		each.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
		each.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
	}
	
}

void en::SpellIcon::draw(sf::RenderWindow& window) {
	window.draw(sprites[*watcher]);
}

void en::SpellIcon::draw(sf::RenderWindow& window, sf::Event& event) {
	window.draw(sprites[*watcher]);
}

//====================================================================================================================================

en::SpellButton::SpellButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, const sf::Texture& pressed_texture, const sf::Texture& unavailable_texture, const sf::SoundBuffer& sound_buffer, const unsigned int _type, unsigned int& _watcher1, unsigned int& _watcher2) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x, y);

	pressed_sprite.setTexture(pressed_texture);
	pressed_sprite.setPosition(x, y);

	unavailable_sprite.setTexture(unavailable_texture);
	unavailable_sprite.setPosition(x, y);

	sound.setBuffer(sound_buffer);

	type = _type;

	watcher1 = &_watcher1;
	watcher2 = &_watcher2;
}

void en::SpellButton::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);

	hl_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	hl_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);

	pressed_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	pressed_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);

	unavailable_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	unavailable_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
}

void en::SpellButton::draw(sf::RenderWindow& window) {
	if (pressed) {
		window.draw(pressed_sprite);
	}
	else if (*watcher1 == 0u || *watcher2 == 0u) {
		window.draw(sprite);
	}
	else {
		window.draw(unavailable_sprite);
	}
}

void en::SpellButton::draw(sf::RenderWindow& window, sf::Event& event) {
	if (!pressed && ((*watcher1 == type) || (*watcher2 == type))) {
		pressed = true;
	}
	
	if (!pressed && ((*watcher1 == 0u) || (*watcher2 == 0u))) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		window.draw(sprite);

		if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
					window.waitEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						sound.play();
						pressed = true;
						if (*watcher1 == 0u) {
							*watcher1 = type;
						}
						else {
							*watcher2 = type;
						}
						break;
					}
					mouse_position = sf::Mouse::getPosition(window);
				}
			}
			window.draw(hl_sprite);
		}
	}
	else if (pressed) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		window.draw(pressed_sprite);

		if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
					window.waitEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						sound.play();
						pressed = false;
						if (*watcher1 == type) {
							*watcher1 = 0u;
						}
						else {
							*watcher2 = 0u;
						}
						break;
					}
					mouse_position = sf::Mouse::getPosition(window);
				}
			}
			window.draw(hl_sprite);
		}
	}
	else {
		window.draw(unavailable_sprite);
	}
}

void en::SpellButton::set_volume(const unsigned int volume) {
	sound.setVolume(static_cast<float>(volume));
}

//====================================================================================================================================

en::PlusButton::PlusButton(const float x, const float y, const sf::Texture& texture, const sf::Texture& hl_texture, std::function<void()> _function, const sf::SoundBuffer& sound_buffer, unsigned int& _points_watcher, unsigned int& _stat_watcher) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	hl_sprite.setTexture(hl_texture);
	hl_sprite.setPosition(x, y);

	function = _function;

	sound.setBuffer(sound_buffer);

	points_watcher = &_points_watcher;
	stat_watcher = &_stat_watcher;
}

void en::PlusButton::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);


	hl_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	hl_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
}

void en::PlusButton::draw(sf::RenderWindow& window) {
	if (*points_watcher != 0u) {
		window.draw(sprite);
	}
}

void en::PlusButton::draw(sf::RenderWindow& window, sf::Event& event) {
	if ((*points_watcher != 0u) && (*stat_watcher < 100u)) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		window.draw(sprite);

		if (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				while (sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y))) {
					window.waitEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						sound.play();
						--(*points_watcher);
						++(*stat_watcher);
						function();
						break;
					}
					mouse_position = sf::Mouse::getPosition(window);
				}
			}
			window.draw(hl_sprite);
		}
	}
}

void en::PlusButton::set_volume(const unsigned int volume) {
	sound.setVolume(static_cast<float>(volume));
}

//====================================================================================================================================

en::BarrierIndicator::BarrierIndicator(const float x, const float y, const sf::Texture& texture, int& _barrier_watcher) {
	float delta_x = x;
	
	for (auto& sprite : sprites) {
		sprite.setTexture(texture);
		sprite.setPosition(delta_x, y);

		delta_x += texture.getSize().x;
	}
	

	barriers_watcher = &_barrier_watcher;
}

void en::BarrierIndicator::resize(const float delta_x, const float delta_y) {
	for (auto& sprite : sprites) {
		sf::FloatRect current_position = sprite.getGlobalBounds();
		sf::Vector2 current_scale = sprite.getScale();

		sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
		sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
	}
}

void en::BarrierIndicator::draw(sf::RenderWindow& window) {
	for (int i = 0; i < *barriers_watcher; ++i) {
		window.draw(sprites[i]);
	}
}

void en::BarrierIndicator::draw(sf::RenderWindow& window, sf::Event& event) {
	for (int i = 0; i < *barriers_watcher; ++i) {
		window.draw(sprites[i]);
	}
}

//====================================================================================================================================

en::SpellIndicator::SpellIndicator(const float x, const float y, const sf::Texture& texture, const sf::Texture& on_cooldown_texture) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	on_cooldown_sprite.setTexture(on_cooldown_texture);
	on_cooldown_sprite.setPosition(x, y);
}

void en::SpellIndicator::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);

	on_cooldown_sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	on_cooldown_sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
}

void en::SpellIndicator::draw(sf::RenderWindow& window) {
	window.draw(*current_sprite);
}

void en::SpellIndicator::cooldown_draw(sf::RenderWindow& window, const float& cooldown) {
	if (cooldown > 0.0f) {
		current_sprite = &on_cooldown_sprite;
	}
	else {
		current_sprite = &sprite;
	}
	window.draw(*current_sprite);
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::ObjectDrawable::ObjectDrawable(const float x, const float y, const sf::Texture& texture, const sf::SoundBuffer& sound_buffer) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	sound.setBuffer(sound_buffer);
}

en::ObjectDrawable::ObjectDrawable(const ObjectDrawable& other) : sprite{ other.sprite }, sound{other.sound} {
}

void en::ObjectDrawable::resize(const float delta_x, const float delta_y) {
	sf::FloatRect current_position = sprite.getGlobalBounds();
	sf::Vector2 current_scale = sprite.getScale();

	sprite.setPosition((current_position.left * (1 / current_scale.x)) * delta_x, (current_position.top * (1 / current_scale.y)) * delta_y);
	sprite.scale((1 / current_scale.x) * delta_x, (1 / current_scale.y) * delta_y);
}

void en::ObjectDrawable::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void en::ObjectDrawable::draw(sf::RenderWindow& window, sf::Event& event) {
	window.draw(sprite);
}

void en::ObjectDrawable::set_volume(const unsigned int volume) {
	sound.setVolume(static_cast<float>(volume));
}

sf::Sprite* en::ObjectDrawable::get_sprite() {
	return &sprite;
}

void en::ObjectDrawable::move(const float delta_x, const float delta_y) {
	sprite.move(delta_x, delta_y);
}

void en::ObjectDrawable::play_sound() {
	sound.play();
}

en::ObjectDrawable* en::ObjectDrawable::clone()
{
	return new ObjectDrawable(*this);
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================