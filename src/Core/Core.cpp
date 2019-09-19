#include "Core.h"
#include "../Drawable/Drawable.h"

#include <fstream>
#include <ios>
#include <vector>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Core::set_delta_values() {
	en::DELTA_X = 1 - (((native_width - static_cast<float>(settings.width)) / (native_width / 100.0f)) / 100.0f);
	en::DELTA_Y = 1 - (((native_height - static_cast<float>(settings.height)) / (native_height / 100.0f)) / 100.0f);
}

//====================================================================================================================================

void en::Core::set_window() {
	window.create(sf::VideoMode{settings.width, settings.height, 32}, "eNement", settings.style);
	window.setFramerateLimit(settings.frames);

	//const char icon_data;
	//sf::Image icon;
	//icon.loadFromMemory(icon_data, sizeof(icon_data));
	//window.setIcon(32, 32, icon.getPixelsPtr());

	set_delta_values();
}

void en::Core::load_settings() {
	std::ifstream is("settings.bin", std::ios::binary | std::ios::in);

	if (is.is_open()) {
		is.read((char*)& settings.width, sizeof(unsigned int));
		is.read((char*)& settings.height, sizeof(unsigned int));
		is.read((char*)& settings.style, sizeof(uint32_t));
		is.read((char*)& settings.frames, sizeof(unsigned int));
		is.read((char*)& settings.volume, sizeof(float));
		VOLUME = settings.volume;
	}

	is.close();
}

void en::Core::save_settings() {
	std::ofstream os("settings.bin", std::ios::binary | std::ios::out);
	os.write((char*)& settings.width, sizeof(unsigned int));
	os.write((char*)& settings.height, sizeof(unsigned int));
	os.write((char*)& settings.style, sizeof(uint32_t));
	os.write((char*)& settings.frames, sizeof(unsigned int));
	os.write((char*)& settings.volume, sizeof(float));

	os.flush();
	os.close();
}

void en::Core::on_resize_event(const std::vector<std::shared_ptr<Drawable>>& in_frame) {
	sf::Vector2u new_size = window.getSize();

	sf::FloatRect visibleArea(0, 0, static_cast<float>(new_size.x), static_cast<float>(new_size.y));
	window.setView(sf::View(visibleArea));

	settings.width = new_size.x;
	settings.height = new_size.y;

	float old_delta_x = 1 / DELTA_X;
	float old_delta_y = 1 / DELTA_Y;

	set_delta_values();

	for (const auto each : in_frame) {
		each->resize(old_delta_x * DELTA_X, old_delta_y * DELTA_Y);
	}
}

//====================================================================================================================================