#pragma once
#include "Drawable/Drawable.h"
#include "eNgine\\eNgine.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include <iostream>

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

namespace en {

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	struct SaveFile {
		unsigned int chapter{ 0 };

		unsigned int first_spell{ 0 };
		unsigned int second_spell{ 0 };

		unsigned int points{ 2000 };

		unsigned int barrier_strength{ 0 };
		unsigned int magic_power{ 0 };
		unsigned int spell_mastery{ 0 };
		unsigned int magic_proficiency{ 0 };
	};

	//====================================================================================================================================

	enum SpellType : unsigned int {
		Empty,
		Fire,
		Water,
		Wind,
		Earth,
		Ice,
		Lightning,
		Light,
		Dark,
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class PlayerEntity;

	class EnemySpell {
	private:

	public:
		Drawable* drawable{ nullptr };

		std::function<void(Drawable* drawable, const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time)> move;


		void collision_detection(PlayerEntity& player, ResourceManager* manager, const unsigned int window_width, const unsigned int window_height);
	};

	//====================================================================================================================================

	class EnemyEntity {
	private:

	public:
		float health{ 1.0f };
		float defense{ 1.0f };
		float movement_speed{ 1.0f };
		float cast_speed{ 1.0f };

		Drawable* drawable{ nullptr };
		Drawable* spell_drawable{ nullptr };


		std::function<void(EnemyEntity& enemy, const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time)> move;

		std::function<void(std::vector<EnemySpell>& enemy_spell_frame, EnemyEntity& enemy, sf::Time time)> generate;
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	class PlayerEntity {
	private:

	public:
		unsigned int first_spell{ SpellType::Empty };
		unsigned int second_spell{ SpellType::Empty };


		unsigned int points{ 0 };

		unsigned int barrier_strength{ 0 };
		unsigned int magic_power{ 0 };
		unsigned int spell_mastery{ 0 };
		unsigned int magic_proficiency{ 0 };


		int barriers{ 0u };							//Each point is a barrier.
		float damage{ 0.0f };					    //Each point is a point of damage.
		float cooldown_time{ 0.0f };				//Each point is time in milliseconds.
		float secondary_effect_increase{ 0.0f };	//each point is a percent.


		Drawable* drawable{ nullptr };


		void move(const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time);
	};

	//====================================================================================================================================

	class PlayerSpell {
	private:
		
	public:
		sf::Keyboard::Key key;

		float cooldown{ 0.0f };

		Drawable* drawable{ nullptr };


		virtual ~PlayerSpell();

		
		virtual void generate(sf::Vector2f player_position, sf::Time time) = 0;

		virtual void move(const float delta_x, const float delta_y, sf::Time time) = 0;

		virtual void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) = 0;


		static PlayerSpell* make_spell(const unsigned type, const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key key);
	};

	//====================================================================================================================================
	//====================================================================================================================================

	class FireSpell : public PlayerSpell {
	private:

	public:
		FireSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class WaterSpell : public PlayerSpell {
	private:

	public:
		WaterSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class WindSpell : public PlayerSpell {
	private:

	public:
		WindSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class EarthSpell : public PlayerSpell {
	private:

	public:
		EarthSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class IceSpell : public PlayerSpell {
	private:

	public:
		IceSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class LightningSpell : public PlayerSpell {
	private:

	public:
		LightningSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class LightSpell : public PlayerSpell {
	private:

	public:
		LightSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================

	class DarkSpell : public PlayerSpell {
	private:

	public:
		DarkSpell(const float cooldown_time, const ResourceManager* manager, const sf::Keyboard::Key _key);


		void generate(sf::Vector2f player_position, sf::Time time) override;

		void move(const float delta_x, const float delta_y, sf::Time time) override;

		void collision_detection(PlayerEntity& player, EnemyEntity& enemy, ResourceManager* manager) override;
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

	inline std::vector<std::string> lores{
		//Chapter 1.
		R"(Lore 1)",

		//Chapter 2.
		R"(Lore 2)",
	};

	//====================================================================================================================================

	struct Stats {
		float health{ 1.0f };
		float defense{ 1.0f };
		float movement_speed{ 1.0f };
		float cast_speed{ 1000.0f };
	};

	inline std::vector<Stats> enemy_stats{
		//Chapter 1.
		{100.0f, 1.0f, 1.0f, 1000.0f},

		//Chapter 2.
		{100.0f, 1.0f, 1.0f, 1000.0f},

	};

	//====================================================================================================================================

	inline std::vector<std::function<void(EnemyEntity & enemy,
										  const unsigned int window_width,
										  const unsigned int window_height,
										  const float delta_x,
										  const float delta_y,
										  sf::Time time)>> enemy_move_functions{
		//Chapter 1.
		[](EnemyEntity& enemy, const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time)
		{
			static int direction = 0;

			if (direction == 0) {
				float move_x = 1000 * delta_x * time.asSeconds() * enemy.movement_speed;
				enemy.drawable->move(-move_x, 0);

				if (enemy.drawable->get_sprite()->getPosition().x < (100.0f * delta_x)) {
					direction = 1;
				}
			}

			if (direction == 1) {
				float move_x = 1000 * delta_x * time.asSeconds() * enemy.movement_speed;
				enemy.drawable->move(move_x, 0);

				if (enemy.drawable->get_sprite()->getPosition().x > (1800.0f * delta_x)) {
					direction = 0;
				}
			}
		},

		//Chapter 2.
		[](EnemyEntity& enemy, const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time time)
		{
			static int direction = 0;

			if (direction == 0) {
				float move_x = 1000 * delta_x * time.asSeconds() * enemy.movement_speed;
				enemy.drawable->move(-move_x, 0);

				if (enemy.drawable->get_sprite()->getPosition().x < (100.0f * delta_x)) {
					direction = 1;
				}
			}

			if (direction == 1) {
				float move_x = 1000 * delta_x * time.asSeconds() * enemy.movement_speed;
				enemy.drawable->move(move_x, 0);

				if (enemy.drawable->get_sprite()->getPosition().x > (1800.0f * delta_x)) {
					direction = 0;
				}
			}
		},

	};

	//====================================================================================================================================

	inline std::vector<std::function<void(std::vector<EnemySpell>& enemy_spell_frame,
										  EnemyEntity & enemy,
										  sf::Time time)>> enemy_generate_functions{

		[](std::vector<EnemySpell>& enemy_spell_frame, EnemyEntity& enemy, sf::Time time)
		{
			auto move_function_for_enemy_spell = [](Drawable* drawable, const unsigned int window_width, const unsigned int window_height, const float delta_x, const float delta_y, sf::Time _time)
			{
				float move_y = 1000 * delta_x * _time.asSeconds();
				drawable->move(0, move_y);
			};

			static float timer = 1000.0f;

			if (timer <= 0.0f) {
				EnemySpell temp_enemy_spell;
				temp_enemy_spell.drawable = enemy.spell_drawable->clone();
				temp_enemy_spell.drawable->get_sprite()->setPosition(enemy.drawable->get_sprite()->getPosition());
				temp_enemy_spell.move = move_function_for_enemy_spell;
				temp_enemy_spell.drawable->play_sound();

				enemy_spell_frame.push_back(std::move(temp_enemy_spell));

				timer = 1000.0f;
			}
			else {
				timer -= time.asMilliseconds();
			}
		},
	};

	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================
	//====================================================================================================================================

} //"en" namespace END.

//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================
