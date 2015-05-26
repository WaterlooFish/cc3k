#ifndef _PLAYER_H__
#define _PLAYER_H__
#include <string>
#include "character.h"

class Player : public Character {
  protected:
    std::string effect;
    int maxHp;
    int gold;
    int x;
    int y;
    char prevTile;
    char currTile;
    std::string message;
    bool attack;
  public:
    void applyEffect();
    int getMaxHp() const;
    int getGold() const;
    void updateGold(int g);
    int getX() const;
    int getY() const;
    void updateX(int x);
    void updateY(int y);
    char getPrevTile() const;
    char getCurrentTile() const;
    void updatePrevTile(char t);
    void updateCurrTile(char t);
    std::string getMessage() const;
    void updateMessage(std::string m);
    bool getAttack() const;
    void updateAttack(bool v);
    Player(std::string race, int x, int y, char prevTile, char currTile, std::string message, bool attack);
};
#endif
