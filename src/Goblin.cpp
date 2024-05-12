#include "Goblin.hpp"
#include "Rectangle.hpp"
#include <raylib.h>

const int Goblin::placeholderRadius = 15;

const int Goblin::health { 10 };
const int Goblin::damage { 1 };
const float Goblin::damageCooldown { 1 };
const float Goblin::speed { 80 };
const raylib::Rectangle Goblin::collider { -placeholderRadius, -placeholderRadius, placeholderRadius * 2, placeholderRadius * 2 };
raylib::Texture* Goblin::texture { nullptr };

Goblin::Goblin(Game* game) : Enemy(game, collider, texture, health, damage, damageCooldown, speed) {}

void Goblin::update(float dt) {
	Enemy::update(dt);
}

void Goblin::draw() {
	DrawCircleV(getPos(), 15, BLUE);
}

float Goblin::timeToSpawn = 0.0f;
const float Goblin::spawnCooldown = 1.0f;