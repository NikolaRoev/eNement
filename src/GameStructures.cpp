#include "GameStructures.h"

#include "Core/Core.h"
#include "Drawable/Drawable.h"
#include "ResourceManager/ResourceManager.h"



//====================================================================================================================================


//====================================================================================================================================
//====================================================================================================================================

en::SpellEntity::~SpellEntity() {
	delete drawable;
}

en::SpellEntity* en::SpellEntity::make_spell(const SpellType type) {
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
