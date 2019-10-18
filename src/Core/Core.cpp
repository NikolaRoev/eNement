#include "Core.h"

#include <fstream>
#include <ios>
#include <tuple>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



//====================================================================================================================================

void en::Core::set_delta_values() {
	delta_x = 1 - (((native_width - static_cast<float>(settings.width)) / (native_width / 100.0f)) / 100.0f);
	delta_y = 1 - (((native_height - static_cast<float>(settings.height)) / (native_height / 100.0f)) / 100.0f);
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
		is.read((char*)& settings.height, sizeof(unsigned int));
		is.read((char*)& settings.frames, sizeof(unsigned int));
		is.read((char*)& settings.volume, sizeof(unsigned int));
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

const std::tuple<float, float> en::Core::on_resize_event() {
	sf::Vector2u new_size = window.getSize();

	if ((new_size.x != settings.width) || (new_size.y != settings.height)) {
		sf::FloatRect visibleArea(0, 0, static_cast<float>(new_size.x), static_cast<float>(new_size.y));
		window.setView(sf::View(visibleArea));

		settings.width = new_size.x;
		settings.height = new_size.y;


		float old_delta_x = 1 / delta_x;
		float old_delta_y = 1 / delta_y;

		set_delta_values();

		return { old_delta_x * delta_x, old_delta_y * delta_y };
	}
	else {
		return { 1.0f, 1.0f };
	}
}

//====================================================================================================================================