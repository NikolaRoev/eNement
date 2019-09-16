#pragma once

#include <functional>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace en {

	struct Drawable {
		//Image:
		virtual void setup(sf::Texture& texture, const float x, const float y) = 0;



		virtual void resize(const float resize_delta_x, const float resize_delta_y) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		virtual void draw(sf::RenderWindow& window, sf::Event& event, sf::Mouse& mouse) = 0;

		virtual void set_function(std::function<void()> _function) = 0;
	};
}