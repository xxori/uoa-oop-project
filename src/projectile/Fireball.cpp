#include "Fireball.hpp"
#include "../Game.hpp"
#include <cmath>

Fireball::Fireball(Game* game, float speed, int damage) : Projectile(game, raylib::Vector2(0, 0), raylib::Rectangle(0, 0, 20, 20), damage, speed), r(0), theta(0) {}

void Fireball::update(float dt) {
	// Increase radius and angle from player
	r += getSpeed() / 3 * dt;
	theta += getSpeed() / 20 * dt;

	// Use cos and sin to convert angle and radius into x and y
	raylib::Vector2 playerPos = getGame()->getPlayer()->getPos() + raylib::Vector2(getGame()->getPlayer()->getCollider().GetWidth() / 2, getGame()->getPlayer()->getCollider().GetHeight() / 2);
	setPos(playerPos + raylib::Vector2(r * std::cos(theta), r * std::sin(theta)));

	// Compute collisions using parent class.
	Projectile::update(dt);
}

void Fireball::draw() {
	DrawCircleV(getPos() + raylib::Vector2(10, 10), 10, RED);
}