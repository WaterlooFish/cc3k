#ifndef _FLOOR_H_
#define _FLOOR_H__
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

class Floor {
  protected:
    // current floor that PC is on
    std::string currentFloor;
  public:
    // board for each of the 5 floors
    char floor1[30][80];
    char floor2[30][80];
    char floor3[30][80];
    char floor4[30][80];
    char floor5[30][80];

    //actual board that's displayed
    char board[30][80];

    Enemy *enemyList[20];

    // items on each floor   
    Item *itemList1[20];
    Item *itemList2[20];
    Item *itemList3[20];
    Item *itemList4[20];
    Item *itemList5[20];

    // actual list
    Item *itemList[20];

    bool start;

    // get current floor
    std::string getCurrentFloor() const;

    // update current floor
    void updateFloor(std::string newFloor);

    // constructor when reading from a file
    Floor(const char *fileName);
    ~Floor();

    // when moving floors, deletes objects in enemyList and itemList
    void cleanList();

    // creates and places objects in enemyList and itemList depending on currentFloor
    void updateBoard();
};

std::ostream &operator<<(std::ostream &out, const Floor &f);
#endif
