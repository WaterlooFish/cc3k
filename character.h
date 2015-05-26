#ifndef _CHARACTER__H_
#define _CHARACTER__H_
#include <iostream>
#include <string>

class Character {
  protected:
    int Hp;
    int Atk;
    int Def;
    int maxHp;
    bool dead;
    std::string race;
  public:
    int getHp();
    int getAtk();
    int getDef();
    void updateHp(int boost);
    void updateAtk(int boost);
    void updateDef(int boost);
    bool isDead() const;
    std::string getRace() const;
    int getMaxHp() const;
    Character();
    Character(std::string race, bool dead);
    virtual ~Character();
};
#endif
