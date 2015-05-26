#ifndef _ENEMY_H__
#define _ENEMY_H__
#include <string>
#include "character.h"

class Enemy : public Character {
  protected:
    std::string effect;
    int drop;
    int x;
    int y;
  public:
    static bool merchAtk;
    int getDrop() const;
    int getX() const;
    int getY() const;
    void updateX(int x);
    void updateY(int y);
    Enemy();
    Enemy(std::string race, int drop, int x, int y);
};
#endif

