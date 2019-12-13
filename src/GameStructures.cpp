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

en::PlayerSpell* en::PlayerSpell::make_spell(const unsigned type, const ResourceManager* manager) {
	switch (type) {
		case SpellType::Empty:
			return nullptr;
			break;
		case SpellType::Fire:
			return new FireSpell(manager);
			break;
		case SpellType::Water:
			return new WaterSpell(manager);
			break;
		case SpellType::Wind:
			return new WindSpell(manager);
			break;
		case SpellType::Earth:
			return new EarthSpell(manager);
			break;
		case SpellType::Ice:
			return new IceSpell(manager);
			break;
		case SpellType::Lightning:
			return new LightningSpell(manager);
			break;
		case SpellType::Light:
			return new LightSpell(manager);
			break;
		case SpellType::Dark:
			return new DarkSpell(manager);
			break;
	}
	return nullptr;
}

//====================================================================================================================================
//====================================================================================================================================

en::FireSpell::FireSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Fire")->clone();
}

void en::FireSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {		
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::FireSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::WaterSpell::WaterSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Water")->clone();
}

void en::WaterSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::WaterSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::WindSpell::WindSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Wind")->clone();
}

void en::WindSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::WindSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::EarthSpell::EarthSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Earth")->clone();
}

void en::EarthSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::EarthSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::IceSpell::IceSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Ice")->clone();
}

void en::IceSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::IceSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::LightningSpell::LightningSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Lightning")->clone();
}

void en::LightningSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::LightningSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::LightSpell::LightSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Light")->clone();
}

void en::LightSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::LightSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================

en::DarkSpell::DarkSpell(const ResourceManager* _manager) {
	manager = _manager;

	drawable = manager->get_drawable("Spell Dark")->clone();
}

void en::DarkSpell::generate(PlayerEntity& player, sf::Time time, const sf::Keyboard::Key key) {
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player.drawable->get_sprite()->getPosition());

			cooldown = player.cooldown_time;
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::DarkSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	if (drawable) {
		float move_y = 1000 * delta_y * time.asSeconds();
		drawable->move(0, -move_y);
	}
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================