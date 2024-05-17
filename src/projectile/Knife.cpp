#include "Knife.hpp"
#include "../Game.hpp"
#include "Projectile.hpp"

Knife::Knife(Game* game, float speed, int damage, raylib::Vector2 direction) : Projectile(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 10, 10), nullptr, damage, speed), dir(direction) {
	setPos(game->getPlayer()->getCenter() - raylib::Vector2(5, 5));
}

void Knife::update(float dt) {
	setPos(getPos() + dir * dt * getSpeed());
	Projectile::update(dt);
}

void Knife::draw() {
	DrawCircleV(getPos() + raylib::Vector2(5, 5), 5, ORANGE);
}