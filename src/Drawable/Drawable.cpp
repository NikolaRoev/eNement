#include "Drawable.h"

#include <functional>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



/* example
void Image::resize(const float& resize_delta_x, const float& resize_delta_y) {

	sf::FloatRect temp = sprite.getGlobalBounds();
		
	sprite.setPosition(temp.left * resize_delta_x, temp.top * resize_delta_y);

	sprite.scale(resize_delta_x, resize_delta_y);
}
*/