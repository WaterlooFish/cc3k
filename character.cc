#include "character.h"
using namespace std;

int Character::getHp() {
  return Hp;
}

int Character::getAtk() {
  return Atk;
}

int Character::getDef() {
  return Def;
}

void Character::updateHp(int boost) {	
  Hp += boost;
  if (Hp < 0) {
  	Hp = 0;
  	dead = true;
  }
  if (Hp > maxHp) {
    Hp = maxHp;
  }
}

void Character::updateAtk(int boost) {
  Atk += boost;
  if (Atk < 0) {
    Atk = 0;
  }
}

void Character::updateDef(int boost) {
  Def += boost;
  if (Def < 0) {
    Def = 0;
  }
}

bool Character::isDead() const {
  return dead;
}

string Character::getRace() const {
  return race;
}

int Character::getMaxHp() const {
  return maxHp;
}

Character::Character() : Hp(0), Atk(0), Def(0) {}

Character::Character(string race, bool dead): race(race), dead(dead) {
  if (race == "Shade") {
    maxHp = 125;
    Hp = 125;
    Atk = 25;
    Def = 25;
  }
  else if (race == "Drow") {
    maxHp = 150;
    Hp = 150;
    Atk = 25;
    Def = 15;
  }
  else if (race == "Vampire") {
    maxHp = 10000;
    Hp = 50;
    Atk = 25;
    Def = 25;
  }
  else if (race == "Troll") {
    maxHp = 120;
    Hp = 120;
    Atk = 25;
    Def = 15;    
  }
  else if (race == "Goblin") {
    maxHp = 110;
    Hp = 110;
    Atk = 15;
    Def = 20;    
  }

  if (race == "Human") {
    maxHp = 140;
    Hp = 140;
    Atk = 20;
    Def = 20;
  }
  else if (race == "Dwarf") {
    maxHp = 100;
    Hp = 100;
    Atk = 20;
    Def = 30;
  }
  else if (race == "Elf") {
    maxHp = 140;
    Hp = 140;
    Atk = 30;
    Def = 10;
  }
  else if (race == "Orc") {
    maxHp = 180;
    Hp = 180;
    Atk = 30;
    Def = 35;
  }
  else if (race == "Merchant") {
    maxHp = 30;
    Hp = 30;
    Atk = 70;
    Def = 5;
  }
  else if (race == "Dragon") {
    maxHp = 150;
    Hp = 150;
    Atk = 20;
    Def = 20;
  }
  else if (race == "Halfling") {
    maxHp = 100;
    Hp = 100;
    Atk = 15;
    Def = 20;
  }
}

Character::~Character() {}
