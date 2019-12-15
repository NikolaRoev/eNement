#include "GameStructures.h"

#include "Drawable/Drawable.h"
#include "eNgine\\eNgine.h"



//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

void en::EnemySpell::collision_detection(PlayerEntity& player, ResourceManager* manager, const unsigned int window_width, const unsigned int window_height) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *player.drawable->get_sprite())) {
		drawable->play_sound();
		player.drawable->play_sound();

		--player.barriers;

		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
	}
	else {
		sf::Vector2f position = drawable->get_sprite()->getPosition();

		if ((position.x < 0.0f) || (position.x > window_width)) {
			drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		}
		if ((position.y < 0.0f) || (position.y > window_height)) {
			drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		}
	}
}

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

en::PlayerSpell* en::PlayerSpell::make_spell(const unsigned type, const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key key) {
	switch (type) {
		case SpellType::Empty:
			return nullptr;
			break;
		case SpellType::Fire:
			return new FireSpell(cooldown_time, manager, key);
			break;
		case SpellType::Water:
			return new WaterSpell(cooldown_time, manager, key);
			break;
		case SpellType::Wind:
			return new WindSpell(cooldown_time, manager, key);
			break;
		case SpellType::Earth:
			return new EarthSpell(cooldown_time, manager, key);
			break;
		case SpellType::Ice:
			return new IceSpell(cooldown_time, manager, key);
			break;
		case SpellType::Lightning:
			return new LightningSpell(cooldown_time, manager, key);
			break;
		case SpellType::Light:
			return new LightSpell(cooldown_time, manager, key);
			break;
		case SpellType::Dark:
			return new DarkSpell(cooldown_time, manager, key);
			break;
	}
	return nullptr;
}

//====================================================================================================================================
//====================================================================================================================================

en::FireSpell::FireSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;
	
	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Fire")->clone();
}

void en::FireSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;
	
	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::FireSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::FireSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::WaterSpell::WaterSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Water")->clone();
}

void en::WaterSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::WaterSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::WaterSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::WindSpell::WindSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Wind")->clone();
}

void en::WindSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::WindSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::WindSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::EarthSpell::EarthSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Earth")->clone();
}

void en::EarthSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::EarthSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::EarthSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::IceSpell::IceSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Ice")->clone();
}

void en::IceSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::IceSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::IceSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::LightningSpell::LightningSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Lightning")->clone();
}

void en::LightningSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::LightningSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::LightningSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::LightSpell::LightSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Light")->clone();
}

void en::LightSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position.x, player_position.y - drawable->get_sprite()->getGlobalBounds().height);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::LightSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	static float timer = 500.0f;
	
	if (timer > 0.0f) {
		timer -= time.asMilliseconds();
	}
	else {
		timer = 500.0f;
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
	}
}

void en::LightSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================

en::DarkSpell::DarkSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key) {
	key = _key;

	cooldown = cooldown_time;

	drawable = manager->get_drawable("Spell Dark")->clone();
}

void en::DarkSpell::generate(sf::Vector2f player_position, sf::Time time) {
	static float cooldown_hold = cooldown;

	if (cooldown <= 0.0f) {
		if (sf::Keyboard::isKeyPressed(key)) {
			drawable->get_sprite()->setPosition(player_position);

			cooldown = cooldown_hold;

			drawable->play_sound();
		}
	}
	else if (cooldown > 0.0f) {
		cooldown -= time.asMilliseconds();
	}
}

void en::DarkSpell::move(const float delta_x, const float delta_y, sf::Time time) {
	float move_y = 1000 * delta_y * time.asSeconds();
	drawable->move(0, -move_y);
}

void en::DarkSpell::collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) {
	if (manager->pixel_perfect_test(*drawable->get_sprite(), *enemy.drawable->get_sprite())) {
		drawable->get_sprite()->setPosition(-1000.0f, -1000.0f);
		drawable->play_sound();
		enemy.drawable->play_sound();

		//Do the effects here, like damage and stuff.
	}
}

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================