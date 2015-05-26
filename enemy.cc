#include "enemy.h"
using namespace std;

int Enemy::getDrop() const {
  return drop;
}

int Enemy::getX() const {
  return x;
}

int Enemy::getY() const {
  return y;
}

void Enemy::updateX(int x) {
  this->x = x;
}

void Enemy::updateY(int y) {
  this->y = y;
}

bool Enemy::merchAtk = false;

Enemy::Enemy(): Character(NULL, false) {}
Enemy::Enemy(string race, int drop, int x, int y) : Character(race, false), drop(drop), x(x), y(y) {}
