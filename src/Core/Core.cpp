#include "Core.h"
#include "../Drawable/Drawable.h"
#include "../ResourceManager/ResourceManager.h"

#include <fstream>
#include <ios>
#include <vector>

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
	window.create(sf::VideoMode{settings.width, settings.height, 32}, "eNement", sf::Style::Default);
	window.setFramerateLimit(settings.frames);

	//const char icon_data;
	//sf::Image icon;
	//icon.loadFromMemory(icon_data, sizeof(icon_data));
	//window.setIcon(32, 32, icon.getPixelsPtr());


	sf::VideoMode current_video_mode_temp = sf::VideoMode::getDesktopMode();
	sf::Vector2i new_position_temp = { static_cast<int>(current_video_mode_temp.width) / 2 - static_cast<int>(settings.width) / 2, static_cast<int>(current_video_mode_temp.height) / 2 - static_cast<int>(settings.height) / 2 };
	window.setPosition(new_position_temp);
	

	set_delta_values();
}

void en::Core::load_settings() {
	std::ifstream is("settings.bin", std::ios::binary | std::ios::in);

	if (is.is_open()) {
		is.read((char*)& settings.width, sizeof(unsigned int));
		WIDTH = settings.width;
		is.read((char*)& settings.height, sizeof(unsigned int));
		HEIGHT = settings.height;
		is.read((char*)& settings.frames, sizeof(unsigned int));
		is.read((char*)& settings.volume, sizeof(unsigned int));
		VOLUME = static_cast<float>(settings.volume);
	}

	is.close();
}

void en::Core::save_settings() {
	std::ofstream os("settings.bin", std::ios::binary | std::ios::out);
	os.write((char*)& settings.width, sizeof(unsigned int));
	os.write((char*)& settings.height, sizeof(unsigned int));
	os.write((char*)& settings.frames, sizeof(unsigned int));
	os.write((char*)& settings.volume, sizeof(unsigned int));

	os.flush();
	os.close();
}

void en::Core::on_resize_event(ResourceManager* resource_manager) {
	sf::Vector2u new_size = window.getSize();

	if ((new_size.x != WIDTH) || (new_size.y != HEIGHT)) {
		sf::FloatRect visibleArea(0, 0, static_cast<float>(new_size.x), static_cast<float>(new_size.y));
		window.setView(sf::View(visibleArea));

		settings.width = new_size.x;
		settings.height = new_size.y;
		WIDTH = settings.width;
		HEIGHT = settings.height;

		float old_delta_x = 1 / DELTA_X;
		float old_delta_y = 1 / DELTA_Y;

		set_delta_values();

		resource_manager->resize_all(old_delta_x * DELTA_X, old_delta_y * DELTA_Y);
	}
}

//====================================================================================================================================