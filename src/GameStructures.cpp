#include "GameStructures.h"
#include "Drawable/Drawable.h"
#include "ResourceManager/ResourceManager.h"



//====================================================================================================================================


//====================================================================================================================================
//====================================================================================================================================

en::SpellEntity::~SpellEntity() {
	delete drawable;
}

en::SpellEntity* en::SpellEntity::make_spell(const SpellType type, PlayerEntity* player, ResourceManager* resource_manager) {
	switch (type) {
		case SpellType::Empty:
			return nullptr;
			break;
		case SpellType::Fire:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Water:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Wind:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Earth:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Ice:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Lightning:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Light:
			return new FireSpell(player, resource_manager);
			break;
		case SpellType::Dark:
			return new FireSpell(player, resource_manager);
			break;
	}
	return nullptr;
}

//====================================================================================================================================
//====================================================================================================================================

en::FireSpell::FireSpell(PlayerEntity* player, ResourceManager* resource_manager) {

}

//====================================================================================================================================
