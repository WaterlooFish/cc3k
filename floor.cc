#include "floor.h"

using namespace std;

string Floor::getCurrentFloor() const {
  return currentFloor;
}

void Floor::updateFloor(string newFloor) {
  this->currentFloor = newFloor;
}

Floor::Floor(const char *fileName) : currentFloor("floor1"), start(false) {
  // create input stream with filename
  ifstream input(fileName);

  char tile;

  for (int i = 0; i < 20; i++) {
    itemList[i] = NULL;
    itemList1[i] = NULL;
    itemList2[i] = NULL;
    itemList3[i] = NULL;
    itemList4[i] = NULL;
    itemList5[i] = NULL;
    enemyList[i] = NULL;
  }

  int k = 0;
  // add first floor to floor1 array
   for (int i = 0; i < 25; i++) {
     for (int j = 0; j < 80; j++) {
       tile = input.get();
       if (tile == '0') {
          tile = 'P';
          itemList1[k] = new Item("RH", j, i);
          k++;
       }
       else if (tile == '1') {
          tile = 'P';
          itemList1[k] = new Item("BA", j, i);
          k++;
       }
       else if (tile == '2') {
          tile = 'P';
          itemList1[k] = new Item("BD", j, i);
          k++;
       }
       else if (tile == '3') {
          tile = 'P';
          itemList1[k] = new Item("PH", j, i);
          k++;
       }
       else if (tile == '4') {
          tile = 'P';
          itemList1[k] = new Item("WA", j, i);
          k++;
       }
       else if (tile == '5') {
          tile = 'P';
          itemList1[k] = new Item("WD", j, i);
          k++;
       }
       else if (tile == '6') {
          tile = 'G';
          itemList1[k] = new Item("2gold", j, i);
          k++;
       }
       else if (tile == '7') {
          tile = 'G';
          itemList1[k] = new Item("1gold", j, i);
          k++;
       }
       else if (tile == '8') {
          tile = 'G';
          itemList1[k] = new Item("4gold", j, i);
          k++;
       }
       else if (tile == '9') {
          tile = 'G';
          itemList1[k] = new Item("6gold", j, i);
          k++;
       }
       floor1[i][j] = tile;
      }
    }
    k = 0;
   // add second floor to floor2 array  
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
        tile = input.get();
       if (tile == '0') {
          tile = 'P';
          itemList2[k] = new Item("RH", j, i);
          k++;
       }
       else if (tile == '1') {
          tile = 'P';
          itemList2[k] = new Item("BA", j, i);
          k++;
       }
       else if (tile == '2') {
          tile = 'P';
          itemList2[k] = new Item("BD", j, i);
          k++;
       }
       else if (tile == '3') {
          tile = 'P';
          itemList2[k] = new Item("PH", j, i);
          k++;
       }
       else if (tile == '4') {
          tile = 'P';
          itemList2[k] = new Item("WA", j, i);
          k++;
       }
       else if (tile == '5') {
          tile = 'P';
          itemList2[k] = new Item("WD", j, i);
          k++;
       }
       else if (tile == '6') {
          tile = 'G';
          itemList2[k] = new Item("2gold", j, i);
          k++;
       }
       else if (tile == '7') {
          tile = 'G';
          itemList2[k] = new Item("1gold", j, i);
          k++;
       }
       else if (tile == '8') {
          tile = 'G';
          itemList2[k] = new Item("4gold", j, i);
          k++;
       }
       else if (tile == '9') {
          tile = 'G';
          itemList2[k] = new Item("6gold", j, i);
          k++;
       }
       floor2[i][j] = tile;
      }
    }
    k = 0;
   // add third floor to floor3 array
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
       tile = input.get();
       if (tile == '0') {
          tile = 'P';
          itemList3[k] = new Item("RH", j, i);
          k++;
       }
       else if (tile == '1') {
          tile = 'P';
          itemList3[k] = new Item("BA", j, i);
          k++;
       }
       else if (tile == '2') {
          tile = 'P';
          itemList3[k] = new Item("BD", j, i);
          k++;
       }
       else if (tile == '3') {
          tile = 'P';
          itemList3[k] = new Item("PH", j, i);
          k++;
       }
       else if (tile == '4') {
          tile = 'P';
          itemList3[k] = new Item("WA", j, i);
          k++;
       }
       else if (tile == '5') {
          tile = 'P';
          itemList3[k] = new Item("WD", j, i);
          k++;
       }
       else if (tile == '6') {
          tile = 'G';
          itemList3[k] = new Item("2gold", j, i);
          k++;
       }
       else if (tile == '7') {
          tile = 'G';
          itemList3[k] = new Item("1gold", j, i);
          k++;
       }
       else if (tile == '8') {
          tile = 'G';
          itemList3[k] = new Item("4gold", j, i);
          k++;
       }
       else if (tile == '9') {
          tile = 'G';
          itemList3[k] = new Item("6gold", j, i);
          k++;
       }
       floor3[i][j] = tile;
      }
    }
   k = 0;
   // add fourth floor to floor4 array
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
       tile = input.get();
       if (tile == '0') {
          tile = 'P';
          itemList4[k] = new Item("RH", j, i);
          k++;
       }
       else if (tile == '1') {
          tile = 'P';
          itemList4[k] = new Item("BA", j, i);
          k++;
       }
       else if (tile == '2') {
          tile = 'P';
          itemList4[k] = new Item("BD", j, i);
          k++;
       }
       else if (tile == '3') {
          tile = 'P';
          itemList4[k] = new Item("PH", j, i);
          k++;
       }
       else if (tile == '4') {
          tile = 'P';
          itemList4[k] = new Item("WA", j, i);
          k++;
       }
       else if (tile == '5') {
          tile = 'P';
          itemList4[k] = new Item("WD", j, i);
          k++;
       }
       else if (tile == '6') {
          tile = 'G';
          itemList4[k] = new Item("2gold", j, i);
          k++;
       }
       else if (tile == '7') {
          tile = 'G';
          itemList4[k] = new Item("1gold", j, i);
          k++;
       }
       else if (tile == '8') {
          tile = 'G';
          itemList4[k] = new Item("4gold", j, i);
          k++;
       }
       else if (tile == '9') {
          tile = 'G';
          itemList4[k] = new Item("6gold", j, i);
          k++;
       }
       floor4[i][j] = tile;
      }
    }
    k = 0;
   // add fifth floor to floor5 array
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
       tile = input.get();
       if (tile == '0') {
          tile = 'P';
          itemList5[k] = new Item("RH", j, i);
          k++;
       }
       else if (tile == '1') {
          tile = 'P';
          itemList5[k] = new Item("BA", j, i);
          k++;
       }
       else if (tile == '2') {
          tile = 'P';
          itemList5[k] = new Item("BD", j, i);
          k++;
       }
       else if (tile == '3') {
          tile = 'P';
          itemList5[k] = new Item("PH", j, i);
          k++;
       }
       else if (tile == '4') {
          tile = 'P';
          itemList5[k] = new Item("WA", j, i);
          k++;
       }
       else if (tile == '5') {
          tile = 'P';
          itemList5[k] = new Item("WD", j, i);
          k++;
       }
       else if (tile == '6') {
          tile = 'G';
          itemList5[k] = new Item("2gold", j, i);
          k++;
       }
       else if (tile == '7') {
          tile = 'G';
          itemList5[k] = new Item("1gold", j, i);
          k++;
       }
       else if (tile == '8') {
          tile = 'G';
          itemList5[k] = new Item("4gold", j, i);
          k++;
       }
       else if (tile == '9') {
          tile = 'G';
          itemList5[k] = new Item("6gold", j, i);
          k++;
       }
       floor5[i][j] = tile;
      }
    }

    updateBoard();
}

// desctuctor
Floor::~Floor() {
  for (int i = 0; i < 20; i++) {
    if (enemyList[i]) {
      delete enemyList[i];
    }
    if (itemList1[i]) {
      delete itemList1[i];
    }
    if (itemList2[i]) {
      delete itemList2[i];
    }
    if (itemList3[i]) {
      delete itemList3[i];
    }
    if (itemList4[i]) {
      delete itemList4[i];
    }
    if (itemList5[i]) {
      delete itemList5[i];
    }
  }
}


void Floor::updateBoard() {
  // for adding to enemy and item array
  int enemyIndex = 0;
  int itemIndex = 0;
  
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
      if (currentFloor == "floor1") {
        board[i][j] = floor1[i][j];
      }
      else if (currentFloor == "floor2") {
        board[i][j] = floor2[i][j];
      }
      else if (currentFloor == "floor3") {
        board[i][j] = floor3[i][j];
      }
      else if (currentFloor == "floor4") {
        board[i][j] = floor4[i][j];
      }
      else if (currentFloor == "floor5") {
        board[i][j] = floor5[i][j];
      }
    }
  }
  
  for (int i = 0; i < 20; i++) {
    if (currentFloor == "floor1") {
      itemList[i] = itemList1[i];
    }
    else if (currentFloor == "floor2") {
      itemList[i] = itemList2[i];
    }
    else if (currentFloor == "floor3") {
      itemList[i] = itemList3[i];
    }
    else if (currentFloor == "floor4") {
      itemList[i] = itemList4[i];
    }
    else if (currentFloor == "floor5") {
      itemList[i] = itemList5[i];
    }
  }

  // add first floor to board
 for (int i = 0; i < 25; i++) {
   for (int j = 0; j < 80; j++) {
      if (board[i][j] == 'H') {
        enemyList[enemyIndex] = new Enemy("Human", 2, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'W') {
        enemyList[enemyIndex] = new Enemy("Dwarf", 2, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'E') {
        enemyList[enemyIndex] = new Enemy("Elf", 2, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'O') {
        enemyList[enemyIndex] = new Enemy("Orc", 1, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'M') {
        enemyList[enemyIndex] = new Enemy("Merchant", 4, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'D') {
        enemyList[enemyIndex] = new Enemy("Dragon", 0, j , i);
        enemyIndex++;
      }
      else if (board[i][j] == 'L') {
        enemyList[enemyIndex] = new Enemy("Halfling", 1, j , i);
        enemyIndex++;
      }
    }
  }
}

// output overloader
ostream &operator<<(ostream &out, const Floor &f) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++) {
        cout << f.board[i][j];
    }
  }
  cout << "";
}
