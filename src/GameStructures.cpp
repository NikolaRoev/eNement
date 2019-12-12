#include "GameStructures.h"

#include "Drawable/Drawable.h"



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

void en::PlayerEntity::move(const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time) {
	sf::FloatRect position = drawable->get_sprite()->getGlobalBounds();

	//TO DO: Increment this many times with a check everytime if you want it to be smooth.

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (position.left > 0) {
			float move_x = 1000 * delta_x * time.asSeconds();
			drawable->move(-move_x, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (position.left < (window_width - position.width)) {
			float move_x = 1000 * delta_x * time.asSeconds();
			drawable->move(move_x, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (position.top > 0) {
			float move_y = 1000 * delta_x * time.asSeconds();
			drawable->move(0, -move_y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (position.top < (window_height - position.height)) {
			float move_y = 1000 * delta_x * time.asSeconds();
			drawable->move(0, move_y);
		}
	}
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

en::PlayerSpell::~PlayerSpell() {
	delete drawable;
}

en::PlayerSpell* en::PlayerSpell::make_spell(const SpellType type) {
	switch (type) {
		case SpellType::Empty:
			return nullptr;
			break;
		case SpellType::Fire:
			return new FireSpell();
			break;
		case SpellType::Water:
			return new FireSpell();
			break;
		case SpellType::Wind:
			return new FireSpell();
			break;
		case SpellType::Earth:
			return new FireSpell();
			break;
		case SpellType::Ice:
			return new FireSpell();
			break;
		case SpellType::Lightning:
			return new FireSpell();
			break;
		case SpellType::Light:
			return new FireSpell();
			break;
		case SpellType::Dark:
			return new FireSpell();
			break;
	}
	return nullptr;
}

//====================================================================================================================================
//====================================================================================================================================

en::FireSpell::FireSpell() {

}

//====================================================================================================================================





//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================