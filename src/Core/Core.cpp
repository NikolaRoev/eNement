#include "Core.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Core::set_delta_values() {
	en::DELTA_X = 1 - (((native_width - static_cast<float>(window_width)) / (native_width / 100.0f)) / 100.0f);
	en::DELTA_Y = 1 - (((native_height - static_cast<float>(window_height)) / (native_height / 100.0f)) / 100.0f);
}

//====================================================================================================================================

void en::Core::set_window() {
	window.create(sf::VideoMode{settings.width, settings.height, 32}, "eNement", settings.style);
	window.setFramerateLimit(settings.frames);

	const char icon_data[1]{1};
	sf::Image icon;
	icon.loadFromMemory(icon_data, sizeof(icon_data));
	window.setIcon(32, 32, icon.getPixelsPtr());

	set_delta_values();
}

void en::Core::on_resize_event() {
	/*
	//dont forget to set the settings
	//probably just give the user all supported sizes

	sf::Vector2u new_size = window.getSize();

	sf::FloatRect visibleArea(0, 0, static_cast<float>(new_size.x), static_cast<float>(new_size.y));
	window.setView(sf::View(visibleArea));

	window_width = new_size.x;
	window_height = new_size.y;

	float old_delta_x = 1 / cn::DELTA_X;
	float old_delta_y = 1 / cn::DELTA_Y;

	set_delta_values();

	preloaded_years.begin()->second.months_menu.background->resize(cn::DELTA_X * old_delta_x, cn::DELTA_Y * old_delta_y);
	*/
}

//====================================================================================================================================