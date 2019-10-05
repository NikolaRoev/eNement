#include "GameStructures.h"
#include "Drawable/Drawable.h"



//====================================================================================================================================


//====================================================================================================================================
//====================================================================================================================================

en::SpellEntity* en::SpellEntity::make_spell(const SpellType type, const PlayerEntity* player) {
	switch (type) {
		case SpellType::Empty:
			return nullptr;
			break;
		case SpellType::Fire:
			return new FireSpell(player);
			break;
		case SpellType::Water:
			return new FireSpell(player);
			break;
		case SpellType::Wind:
			return new FireSpell(player);
			break;
		case SpellType::Earth:
			return new FireSpell(player);
			break;
		case SpellType::Ice:
			return new FireSpell(player);
			break;
		case SpellType::Lightning:
			return new FireSpell(player);
			break;
		case SpellType::Light:
			return new FireSpell(player);
			break;
		case SpellType::Dark:
			return new FireSpell(player);
			break;
	}
}

//====================================================================================================================================

