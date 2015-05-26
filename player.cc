#include "player.h"
using namespace std;

void Player::applyEffect() {
  if (effect == "default") {
    // do nothing
  }
}

int Player::getGold() const {
  return gold;
}

int Player::getX() const {
  return x;
}

int Player::getY() const {
  return y;
}

void Player::updateX(int x) {
  this->x = x;
}

void Player::updateY(int y) {
  this->y = y;
}

void Player::updateGold(int g) {
  this->gold += g;
}

char Player::getPrevTile() const {
  return prevTile;
}

char Player::getCurrentTile() const {
  return currTile;
}

void Player::updatePrevTile(char t) {
  this->prevTile = t;
}

void Player::updateCurrTile(char t) {
  this->currTile = t;
}

void Player::updateMessage(string m) {
  if (this->message == "") {
    this->message = m;
  }
  else if (m == "") {
    this->message = "";
  }
  else {
    this->message = this->message + ". " + m;
  }
  
}

string Player::getMessage() const {
  return message;
}

bool Player::getAttack() const {
  return attack;
}

void Player::updateAttack(bool v) {
  attack = v;
}

Player::Player(string race, int x, int y, char prevTile, char currTile, string message, bool attack): Character(race, false), 
x(x), y(y), prevTile(prevTile), currTile(currTile), message(message), attack(attack), gold(0) {}
