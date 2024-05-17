#include "FireStaff.hpp"
#include "../Game.hpp"
#include "../projectile/Fireball.hpp"

FireStaff::FireStaff(Game* game, float fireSpeed) : Weapon(game, "Fire Staff", fireSpeed) {}

void FireStaff::update(float dt) {
	setTimeToFire(getTimeToFire() - dt);
	if (getTimeToFire() <= 0) {
		setTimeToFire(getFireSpeed());
		getGame()->addObject(new Fireball(getGame(), 100, 5));
	}
}