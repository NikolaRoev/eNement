#include "eNgine.h"
#include "..\\Drawable\Drawable.h"

#include <fstream>
#include <ios>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
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

/*
 * File:   collision.h/.cpp
 * Authors: Nick Koirala (original version), ahnonay (SFML2 compatibility)
 *
 * Collision Detection and handling class
 * For SFML2.

Notice from the original version:

(c) 2009 - LittleMonkey Ltd

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.

 *
 * Created on 30 January 2009, 11:02
 */

//Altered.

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::ResourceManager::~ResourceManager() {
	for (auto& each : drawables) {
		delete each.second;
	}
}

void en::ResourceManager::add_texture(const std::string& file_path, const std::string& texture_name) {
	sf::Texture temp;
	temp.loadFromFile(file_path);

	textures.insert(std::make_pair(texture_name, temp));
}

void en::ResourceManager::add_texture_for_pixel_perfect(const std::string& file_path, const std::string& texture_name) {
	textures.insert(std::make_pair(texture_name, sf::Texture()));

	create_texture_and_bitmask(textures.find(texture_name)->second, file_path);
}

void en::ResourceManager::add_font(const std::string& file_path, const std::string& font_name) {
	sf::Font temp;
	temp.loadFromFile(file_path);

	fonts.insert(std::make_pair(font_name, temp));
}

void en::ResourceManager::add_sound_buffer(const std::string& file_path, const std::string& sound_buffer_name) {
	sf::SoundBuffer temp;
	temp.loadFromFile(file_path);

	sound_buffers.insert(std::make_pair(sound_buffer_name, temp));
}

void en::ResourceManager::add_drawable(Drawable* drawable, const std::string& drawable_name) {
	drawables.insert(std::make_pair(drawable_name, drawable));
}

//====================================================================================================================================

const sf::Texture& en::ResourceManager::get_texture(const std::string& texture_name) const {
	return textures.find(texture_name)->second;
}

const sf::Font& en::ResourceManager::get_font(const std::string& font_name) const {
	return fonts.find(font_name)->second;
}

const sf::SoundBuffer& en::ResourceManager::get_sound_buffer(const std::string& sound_buffer_name) const {
	return sound_buffers.find(sound_buffer_name)->second;
}

en::Drawable* en::ResourceManager::get_drawable(const std::string& drawable_name) const {
	return drawables.find(drawable_name)->second;
}

std::unordered_map<std::string, en::Drawable*>& en::ResourceManager::get_all_drawables() {
	return drawables;
}

//====================================================================================================================================

class BitmaskManager {
public:
	~BitmaskManager() {
		std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = Bitmasks.end();
		for (std::map<const sf::Texture*, sf::Uint8*>::const_iterator iter = Bitmasks.begin(); iter != end; ++iter) {
			delete[] iter->second;
		}
	}


	sf::Uint8 GetPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y) {
		if (x > tex->getSize().x || y > tex->getSize().y) {
			return 0;
		}

		return mask[x + y * tex->getSize().x];
	}

	sf::Uint8* GetMask(const sf::Texture* tex) {
		sf::Uint8* mask;
		std::map<const sf::Texture*, sf::Uint8*>::iterator pair = Bitmasks.find(tex);
		if (pair == Bitmasks.end()) {
			sf::Image img = tex->copyToImage();
			mask = CreateMask(tex, img);
		}
		else {
			mask = pair->second;
		}

		return mask;
	}

	sf::Uint8* CreateMask(const sf::Texture* tex, const sf::Image& img) {
		sf::Uint8* mask = new sf::Uint8[tex->getSize().y * tex->getSize().x];

		for (unsigned int y = 0; y < tex->getSize().y; y++) {
			for (unsigned int x = 0; x < tex->getSize().x; x++) {
				mask[x + y * tex->getSize().x] = img.getPixel(x, y).a;
			}
		}

		Bitmasks.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex, mask));

		return mask;
	}

private:
	std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
};

BitmaskManager Bitmasks;

bool en::ResourceManager::pixel_perfect_test(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit) {
	sf::FloatRect Intersection;

	if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
		sf::IntRect O1SubRect = Object1.getTextureRect();
		sf::IntRect O2SubRect = Object2.getTextureRect();

		sf::Uint8* mask1 = Bitmasks.GetMask(Object1.getTexture());
		sf::Uint8* mask2 = Bitmasks.GetMask(Object2.getTexture());

		// Loop through our pixels
		for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++) {
			for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++) {

				sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(i, j);
				sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);

				// Make sure pixels fall within the sprite's subrect
				if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
					o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
					o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

					if (Bitmasks.GetPixel(mask1, Object1.getTexture(), (int)(o1v.x) + O1SubRect.left, (int)(o1v.y) + O1SubRect.top) > AlphaLimit&&
						Bitmasks.GetPixel(mask2, Object2.getTexture(), (int)(o2v.x) + O2SubRect.left, (int)(o2v.y) + O2SubRect.top) > AlphaLimit)
						return true;

				}
			}
		}
	}
	return false;
}

bool en::ResourceManager::create_texture_and_bitmask(sf::Texture& LoadInto, const std::string& Filename) {
	sf::Image img;

	if (!img.loadFromFile(Filename)) {
		return false;
	}
	if (!LoadInto.loadFromImage(img)) {
		return false;
	}

	Bitmasks.CreateMask(&LoadInto, img);
	return true;
}

void en::ResourceManager::scale_drawables(const float delta_x, const float delta_y) {
	for (auto& each : drawables) {
		each.second->resize(delta_x, delta_y);
	}
}

void en::ResourceManager::change_volume(const unsigned int volume) {
	for (auto& each : drawables) {
		each.second->set_volume(volume);
	}
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

void en::Core::set_delta_values() {
	delta_x = 1 - (((native_width - static_cast<float>(width)) / (native_width / 100.0f)) / 100.0f);
	delta_y = 1 - (((native_height - static_cast<float>(height)) / (native_height / 100.0f)) / 100.0f);
}

en::Core::Core(const float _native_width, const float _native_height) {
	native_width = _native_width;
	native_height = _native_height;

	manager = new ResourceManager;
}

en::Core::~Core() {
	delete manager;
	window.close();
}

void en::Core::set_window() {
	window.create(sf::VideoMode{ width, height, 32 }, "eNement", sf::Style::Default);
	window.setFramerateLimit(frames);

	//const char icon_data;
	//sf::Image icon;
	//icon.loadFromMemory(icon_data, sizeof(icon_data));
	//window.setIcon(32, 32, icon.getPixelsPtr());

	set_delta_values();
}

void en::Core::set_window(unsigned int _width, unsigned int _height) {
	window.create(sf::VideoMode{ _width, _height, 32 }, "eNement", sf::Style::Default);
	window.setFramerateLimit(frames);

	//const char icon_data;
	//sf::Image icon;
	//icon.loadFromMemory(icon_data, sizeof(icon_data));
	//window.setIcon(32, 32, icon.getPixelsPtr());

	on_resize_event();
}

void en::Core::load_settings() {
	std::ifstream is("settings.bin", std::ios::binary);

	if (is.is_open()) {
		is.read((char*)&width, sizeof(unsigned int));
		is.read((char*)&height, sizeof(unsigned int));
		is.read((char*)&frames, sizeof(unsigned int));
		is.read((char*)&volume, sizeof(unsigned int));
	}

	is.close();
}

void en::Core::save_settings() {
	std::ofstream os("settings.bin", std::ios::binary);
	os.write((char*)&width, sizeof(unsigned int));
	os.write((char*)&height, sizeof(unsigned int));
	os.write((char*)&frames, sizeof(unsigned int));
	os.write((char*)&volume, sizeof(unsigned int));

	os.flush();
	os.close();
}

void en::Core::adjust_drawables() {
	manager->scale_drawables(delta_x, delta_y);
	manager->change_volume(volume);
}

void en::Core::draw(const std::vector<Drawable*>& static_frame) {
	for (const auto& each : static_frame) {
		each->draw(window, event);
	}

	window.display();
}

void en::Core::draw(const std::vector<Drawable*>& static_frame, const std::vector<Drawable*>& enemy_spell_frame, const std::vector<Drawable*>& ui_frame, const std::vector<Drawable*>& spell_indicator_frame, const float& cooldown1, const float& cooldown2) {
	for (const auto& each : static_frame) {
		each->draw(window, event);
	}

	for (const auto& each : enemy_spell_frame) {
		each->draw(window, event);
	}

	for (const auto& each : ui_frame) {
		each->draw(window, event);
	}

	spell_indicator_frame[0]->cooldown_draw(window, cooldown1);
	spell_indicator_frame[1]->cooldown_draw(window, cooldown2);

	window.display();
}

void en::Core::on_resize_event() {
	sf::Vector2u new_size = window.getSize();

	if ((new_size.x != width) || (new_size.y != height)) {
		sf::FloatRect visibleArea(0, 0, static_cast<float>(new_size.x), static_cast<float>(new_size.y));
		window.setView(sf::View(visibleArea));

		width = new_size.x;
		height = new_size.y;

		set_delta_values();

		manager->scale_drawables(delta_x, delta_y);
	}
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================