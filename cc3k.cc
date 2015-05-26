#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "floor.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

// calculates damage done to a player/enemy
double attackDamage(int attackerAtk, int defenderDef) {
  double damage;
  double step1;
  double step2;
  double step3;

  step1 = 100 + defenderDef;
  step2 = 100 / step1;
  step3 = step2 * attackerAtk;
  return ceil(step3);
}

// when the enemy attacks PC
void enemyAtk(Enemy *e, Player *player) {
 int miss;
 int damage;
 string dealt;
 stringstream ss;
 // merchant starts off unagressive
 if (e->getRace() == "Merchant" && e->merchAtk == false) {
   return;
 }
 // if enemy is alive
 else if (e->isDead() == false) {
  // 50% change of enemy missing
   miss = rand() % 2;
   if (miss == 0) {
     // different message based on enemy race
     if (e->getRace() == "Human") {
        player->updateMessage("H attacks PC and misses");
     }
     else if (e->getRace() == "Dwarf") {
        player->updateMessage("D attacks PC and misses");
     }
     else if (e->getRace() == "Elf") {
        player->updateMessage("E attacks PC and misses");
     }
     else if (e->getRace() == "Orc") {
        player->updateMessage("O attacks PC and misses");
     }
     else if (e->getRace() == "Merchant") {
        player->updateMessage("M attacks PC and misses");
     }
     else if (e->getRace() == "Dragon") {
        player->updateMessage("D attacks PC and misses");
     }
     else if (e->getRace() == "Halfling") {
        player->updateMessage("L attacks PC and misses");
     }
   }
   else {
    // calculate damage done
     damage = attackDamage(e->getAtk(), player->getDef());

     // orcs do 2x damage to goblins
     if (e->getRace() == "Orc" && player->getRace() == "Goblin") {
      damage *= 2;
     }
     player->updateHp(-damage);
     
     ss << damage;
     dealt = ss.str();
     if (e->getRace() == "Human") {
        player->updateMessage("H deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Dwarf") {
        player->updateMessage("D deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Elf") {
        player->updateMessage("E deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Orc") {
        player->updateMessage("O deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Merchant") {
        player->updateMessage("M deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Dragon") {
        player->updateMessage("D deals " + dealt + " damage to PC");
     }
     else if (e->getRace() == "Halfling") {
        player->updateMessage("L deals " + dealt + " damage to PC");
     }
    }
  }
  if (e->getRace() == "Elf" && player->getRace() != "Drow") {
  miss = rand() % 2;
   if (miss == 0) {
     player->updateMessage("E attacks PC again and misses");
   }
   else {
     damage = attackDamage(e->getAtk(), player->getDef());
     player->updateHp(-damage);
     
     ss << damage;
     dealt = ss.str();
     player->updateMessage("E attacks again and deals " + dealt + " damage to PC");
    }
  }
}

// for when the player attacks
void playerAtk(Player *player, Enemy *e) { 
  player->updateAttack(true);
  int damage;
  string dealt;
  stringstream ss;

  string hpLeft;
  stringstream hh;

  int miss;
  // 50% chance of missing when attacking the halfling
  if (e->getRace() == "Halfling") {
    miss = rand() % 2;
    if (miss == 0) {
      player->updateMessage("L has beguiled PC and PC misses");
      return;
    }
  }
  // once you attack a merchant, they all become aggressive
  if (e->getRace() == "Merchant") {
    e->merchAtk = true;
  }
  // calculate damage
  damage = attackDamage(player->getAtk(), e->getDef());
  e->updateHp(-damage);

  ss << damage;
  dealt = ss.str();

  hh << e->getHp();
  hpLeft = hh.str();

   if (e->getRace() == "Human") {
    player->updateMessage("PC deals " + dealt + " damage to H (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Dwarf") {
      player->updateMessage("PC deals " + dealt + " damage to D (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Elf") {
      player->updateMessage("PC deals " + dealt + " damage to E (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Orc") {
      player->updateMessage("PC deals " + dealt + " damage to O (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Merchant") {
      player->updateMessage("PC deals " + dealt + " damage to M (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Dragon") {
      player->updateMessage("PC deals " + dealt + " damage to D (" + hpLeft + " HP)");
   }
   else if (e->getRace() == "Halfling") {
      player->updateMessage("PC deals " + dealt + " damage to L (" + hpLeft + " HP)");
   }

  if (player->getRace() == "Vampire") {
    if (e->getRace() == "Dwarf") {
      player->updateHp(-5);
      player->updateMessage("PC is allergic to Dwarves, loses 5 HP");
    }
    player->updateHp(5);
    player->updateMessage("PC gains 5 HP");
  }
 // enemy response attacj
  enemyAtk(e, player);
}

// prints board and inventory
void inventoryPrint(Player *player, Floor *floor) {
  string floorType;
  // converts to proper format
  if (floor->getCurrentFloor() == "floor1") { floorType = "Floor 1";}
  else if (floor->getCurrentFloor() == "floor2") { floorType = "Floor 2";}
  else if (floor->getCurrentFloor() == "floor3") { floorType = "Floor 3";}
  else if (floor->getCurrentFloor() == "floor4") { floorType = "Floor 4";}
  else if (floor->getCurrentFloor() == "floor5") { floorType = "Floor 5";}

  if (player->getMessage() == "") {
    player->updateMessage("Invalid command");
  }
  // outputs board and inventory
  cout << *floor;
  cout << "Race: " << player->getRace(); 
  cout <<  " Gold: " << player->getGold();
  cout << "                                                  " << floorType << endl;
  cout << "HP: " << player->getHp() << endl;
  cout << "Atk: " << player->getAtk() << endl;
  cout << "Def: " << player->getDef() << endl;
  cout << "Action: " << player->getMessage() << "." << endl;
  player->updateMessage("");
}

// searches area around player
char searchArea(Player *player, Floor *f, int playerX, int playerY, char tile) {
  if (f->board[playerY-1][playerX-1] == tile || f->board[playerY-1][playerX] == tile || f->board[playerY-1][playerX+1] == tile || 
    f->board[playerY][playerX+1] == tile || f->board[playerY+1][playerX+1] == tile || f->board[playerY+1][playerX] == tile || f->board[playerY+1][playerX-1] == tile || f->board[playerY][playerX-1] == tile) {
    return tile;
  }
  else {
    return 'Z';
  }
}

// moves the enemies around the board
void enemyMove(Floor *f, Player *player) {
  // monster position
  int monsterX, monsterY;
  
  // current tile
  char currentTile;

  int move;

  char enemyTile;
 
  // loops through monster array in Floor class
  for (int i = 0; i < 20; i++) {
      monsterX = f->enemyList[i]->getX();
      monsterY = f->enemyList[i]->getY();

      enemyTile = f->board[monsterY][monsterX];

      // replace dead enemy with open space
      if (f->enemyList[i]->isDead() == true) {
        f->board[f->enemyList[i]->getY()][f->enemyList[i]->getX()] = '.';
      }
      // randomly chooses movement
      move = rand() % 8;
      if (f->enemyList[i]->isDead() != true) { 
        if (searchArea(player, f, monsterX, monsterY, '@') == '@') {
          if (player->getAttack() == false) {
            enemyAtk(f->enemyList[i], player);
          }
        }
        // move nw
        else if (move == 0) {
          monsterX -= 1;
          monsterY -= 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY+1][monsterX+1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }
        }
        // move north
        else if (move == 1) {
          monsterY -= 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY+1][monsterX] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }
        }
        // move ne
        else if (move == 2) {
          monsterX += 1;
          monsterY -= 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY+1][monsterX-1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }    
        }
        // move east
        else if (move == 3) {
          monsterX += 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY][monsterX-1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }     
        }
        // move se
        else if (move == 4) {
          monsterX += 1;
          monsterY += 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY-1][monsterX-1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }    
        }
        // move south
        else if (move == 5) {
          monsterY += 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY-1][monsterX] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }     
        }
        // move sw
        else if (move == 6) {
          monsterX -= 1;
          monsterY += 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY-1][monsterX+1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }     
        }
        // move west
        else if (move == 7) {
          monsterX -= 1;
          
          currentTile = f->board[monsterY][monsterX];
          if (currentTile == '.') {
            f->board[monsterY][monsterX] = enemyTile;
            f->board[monsterY][monsterX+1] = '.';
            f->enemyList[i]->updateX(monsterX);
            f->enemyList[i]->updateY(monsterY);
          }
        }
      }
  }
}


// changes player position
// helper function for characterMove
void shift(Player *player, Floor *f, int playerX, int playerY, int offsetX, int offsetY) {
  // sets location of PC
  f->board[playerY][playerX] = '@';
  f->board[playerY+offsetY][playerX+offsetX] = player->getPrevTile();

  player->updateX(playerX);
  player->updateY(playerY);

  if (player->getCurrentTile() == 'G') { 
    // call gold update
    for (int i = 0; i < 20; i++) {
      if ((f->itemList[i]->getX() == playerX) && (f->itemList[i]->getY() == playerY)) {
        if (f->itemList[i]->getValue() == "2gold") {
          player->updateGold(2);
          player->updateMessage("PC finds 2 gold");
        }
        else if (f->itemList[i]->getValue() == "1gold") {
          player->updateGold(1);
          player->updateMessage("PC finds 1 gold");
        }
        else if (f->itemList[i]->getValue() == "4gold") {
          player->updateGold(4);
          player->updateMessage("PC finds 4 gold");
        }
        else if (f->itemList[i]->getValue() == "6gold") {
          player->updateGold(6);
          player->updateMessage("PC finds 6 gold");
        }        
      }
    }
  }
  else if (player->getPrevTile() == 'G') {
    f->board[playerY+offsetY][playerX+offsetX] = '.';
  }
  else if (player->getCurrentTile() == '\\') {
    if (f->getCurrentFloor() == "floor1") {
      f->updateFloor("floor2");
      f->start = true;
    }
    else if (f->getCurrentFloor() == "floor2") {
      f->updateFloor("floor3");
      f->start = true;
    }
    else if (f->getCurrentFloor() == "floor3") {
      f->updateFloor("floor4");
      f->start = true;
    }
    else if (f->getCurrentFloor() == "floor4") {
      f->updateFloor("floor5"); 
      f->start = true;
    }
    else if (f->getCurrentFloor() == "floor5") {
      // win
    }
    f->updateBoard();
  }
  else {
    if (searchArea(player, f, playerX, playerY, 'P') == 'P') {
      string potName = "unknown";
      for (int i = 0; i < 20; i++) {
        if (f->itemList[i] != NULL) {
        if ((f->itemList[i]->getX() == playerX) && (f->itemList[i]->getY() == playerY) && f->itemList[i]->hasSeen == f->itemList[i]->getValue()) {
          potName = f->itemList[i]->getValue();
        }
      }
      }
      player->updateMessage("PC sees an " + potName + " potion");
    }
  }
}

// determines how character moves based on command
// updates player object with new location and stats and
// floor with new character location
void characterMove(Player *player, Floor *f, string command, int playerX, int playerY) {
  // deletes potion tile if necessary
  string potionTile;
  int displaceX, displaceY;

  playerX = player->getX();
  playerY = player->getY();
  // applies troll effect
  if (player->getRace() == "Troll") {
    player->updateHp(5);
  }
  // move player, update fields as necessary
  // start attack if given command
  if (command == "no") {
    playerY -= 1;
    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves North");
      shift(player, f, playerX, playerY, 0, 1);
    }
  }
  else if (command == "so") {
    playerY += 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves South");
      shift(player, f, playerX, playerY, 0, -1);
    }
  }
  else if (command == "ea") {
    playerX += 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves East");
      shift(player, f, playerX, playerY, -1, 0);
    }
  }
  else if (command == "we") {
    playerX -= 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves West");
      shift(player, f, playerX, playerY, 1, 0);
    }
  }     
  else if (command == "ne") {
    playerX += 1;
    playerY -= 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves North-East");
      shift(player, f, playerX, playerY, -1, 1);
    }
  }
  else if (command == "nw") {
    playerX -= 1;
    playerY -= 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves North-West");
      shift(player, f, playerX, playerY, 1, 1);
    }
  }
  else if (command == "se") {
    playerX += 1;
    playerY += 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves South-East");
      shift(player, f, playerX, playerY, -1, -1);
    }
  }
  else if (command == "sw") {
    playerX -= 1;
    playerY += 1;

    if (f->board[playerY][playerX] != '.' && f->board[playerY][playerX] != 'G' && f->board[playerY][playerX] != '+' &&f->board[playerY][playerX] != '#' && f->board[playerY][playerX] != '\\') {
      player->updateMessage("PC cannot move here");
    }
    else {
      player->updatePrevTile(player->getCurrentTile());
      player->updateCurrTile(f->board[playerY][playerX]);
      player->updateMessage("PC moves South-West");
      shift(player, f, playerX, playerY, 1, -1);
    }
  }
  else if (command[0] == 'u') {
    if (searchArea(player, f, playerX, playerY, 'P') == 'P') {
      if (command == "u no") {
        displaceX = 0;
        displaceY = -1;
      }
      else if (command == "u so") {
        displaceX = 0;
        displaceY = 1;
      }
      else if (command == "u ea") {
        displaceX = 1;
        displaceY = 0;        
      }
      else if (command == "u we") {
         displaceX = -1;
        displaceY = 0;       
      }
      else if (command == "u ne") {
        displaceX = 1;
        displaceY = -1;      }
      else if (command == "u nw") {
        displaceX = -1;
        displaceY = -1;        
      }
      else if (command == "u se") {
        displaceX = 1;
        displaceY = 1;        
      }
      else if (command == "u sw") {
        displaceX = -1;
        displaceY = 1;        
      }
      for (int i = 0; i < 20; i++) {
        //f->itemList[i] = new Item("RA", 12, 12);
        if ((f->itemList[i]->getX() == (playerX + displaceX)) && (f->itemList[i]->getY() == (playerY + displaceY))) {
          f->itemList[i]->hasSeen = f->itemList[i]->getValue();
          if (f->itemList[i]->getValue() == "RH") {
            if (player->getRace() == "Drow") {
              player->updateHp(15);
            }
            player->updateHp(10);
            player->updateMessage("PC uses RH");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }

          else if (f->itemList[i]->getValue() == "BA") {
            if (player->getRace() == "Drow") {
              player->updateAtk(8);
            }
            player->updateAtk(5);
            player->updateMessage("PC uses BA");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }

          else if (f->itemList[i]->getValue() == "BD") {
            if (player->getRace() == "Drow") {
              player->updateDef(8);
            }
            player->updateDef(5);
            player->updateMessage("PC uses BD");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }

          else if (f->itemList[i]->getValue() == "PH") {
            if (player->getRace() == "Drow") {
              player->updateHp(-15);
            }
            player->updateHp(-10);
            player->updateMessage("PC uses PH");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }

          else if (f->itemList[i]->getValue() == "WA") {
            if (player->getRace() == "Drow") {
              player->updateAtk(-8);
            }
            player->updateAtk(-5);
            player->updateMessage("PC uses WA");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }

          else if (f->itemList[i]->getValue() == "WD") {
            if (player->getRace() == "Drow") {
              player->updateDef(-8);
            }
            player->updateDef(-5);
            player->updateMessage("PC uses WD");
            f->board[playerY + displaceY][playerX + displaceX] = '.';
          }
          else {
            player->updateMessage("PC cannot find a potion");
          }
        }
      }
    }                        
  }
  else if (command[0] == 'a') {
    if ((searchArea(player, f, playerX, playerY, 'H') == 'H')
        || (searchArea(player, f, playerX, playerY, 'D') == 'D')
        || (searchArea(player, f, playerX, playerY, 'E') == 'E')
        || (searchArea(player, f, playerX, playerY, 'O') == 'O')
        || (searchArea(player, f, playerX, playerY, 'M') == 'M')
        || (searchArea(player, f, playerX, playerY, 'L') == 'L')) {
      if (command == "a no") {
        displaceX = 0;
        displaceY = -1;
      }
      else if (command == "a so") {
        displaceX = 0;
        displaceY = 1;
      }
      else if (command == "a ea") {
        displaceX = 1;
        displaceY = 0;        
      }
      else if (command == "a we") {
        displaceX = -1;
        displaceY = 0;       
      }
      else if (command == "a ne") {
        displaceX = 1;
        displaceY = -1;      
      }
      else if (command == "a nw") {
        displaceX = -1;
        displaceY = -1;        
      }
      else if (command == "a se") {
        displaceX = 1;
        displaceY = 1;        
      }
      else if (command == "a sw") {
        displaceX = -1;
        displaceY = 1;        
      }
      for (int i = 0; i < 20; i++) {
        if ((f->enemyList[i]->getX() == (playerX + displaceX)) && (f->enemyList[i]->getY() == (playerY + displaceY))) {
          playerAtk(player, f->enemyList[i]);
          if (f->enemyList[i]->isDead() == true) {
            player->updateGold(f->enemyList[i]->getDrop());
            player->updateMessage("PC kills H and receives 2 gold");
            if (player->getRace() == "Goblin") {
              player->updateGold(5);
              player->updateMessage("PC steals 5 gold");
            }
          }
        }
      }
    }
    else {
      player->updateMessage("There is no enemy to attack");
    }
  } 
}

int main(int argc, char *argv[]) {
  // seeds the random number generator
  srand(time(NULL));

  // Floor object
  Floor *f;
  
  // Player location
  Player *player;
  int playerX;
  int playerY;

  // store player score
  int score;

  // string tracks player input
  string command;

  // if optional command line argument is supplied
  char *fileName;
//**** WHEN IMPLEMENTING RANDOM FLOORS, CHANGE TO IF STATEMENT*********
    fileName = argv[1];
    f = new Floor(fileName);

  // inital command entering
  cout << "Enter a race, or press q to quit." << endl;
  cin >> command;

  // exits if player chooses to quit
  if (command == "q") {
    delete f;
    return 0;
  }

  // initializes player
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 79; j++) {
      // finds player and creates object
      if (f->board[i][j] == '@') {
        if (command == "s") {
          player = new Player("Shade", j, i, '.', '.', "", false);
        }
        else if (command == "d") {
          player = new Player("Drow", j, i, '.', '.', "", false);
        }
        else if (command == "v") {
          player = new Player("Vampire", j, i, '.', '.', "", false);
        }
        else if (command == "t") {
          player = new Player("Troll", j, i, '.', '.', "", false);
        }
        else if (command == "g") {
          player = new Player("Goblin", j, i, '.', '.', "", false);
        }
      }
    }
  }

  int j = 0;
    // game loop  
  while (command != "q") {
    if (j == 0) {
      // initial message
      player->updateMessage("Player character has spawned");
      // prints board and inventory for the first time
      inventoryPrint(player, f);
      getline(cin, command);
    }
    else {
      // update board once new floor is reached
      if (f->start == true) {
        f->updateBoard();
        player->updateCurrTile('.');  
        enemyMove(f, player);
        // initializes player location
        for (int i = 0; i < 25; i++) {
          for (int j = 0; j < 79; j++) {
            // finds player and creates object
            if (f->board[i][j] == '@') {
              player->updateX(j);
              player->updateY(i);
            }
          }
        }
        f->start = false;
      }
    }
    // get command from player
    getline(cin, command);

    // exit game loop if player chooses to quit
    if (command == "q") {
      break;
    }

    // sets message to output of characterMove function
    characterMove(player, f, command, playerX, playerY);

    // randomly moves enemies
    enemyMove(f, player);

    // quit if player dies
    if (player->getHp() <= 0) {
      player->updateMessage("PC has died");

      // prints board and inventory
      inventoryPrint(player, f);
      break;
    }
    else {
      // prints board and inventory
      inventoryPrint(player, f);
    }
    j++;
  }
  // set player score
  score = player->getGold();
  if (player->getRace() == "Shade") {
    score = score * 2;
  }
  cout << "Player score is " << score << "." << endl;

  // call destructors
  delete f;
  delete player;
}
