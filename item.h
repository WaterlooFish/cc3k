#ifndef _ITEM__H_
#define _ITEM__H_
#include <string>

class Item {
  protected:
    std::string value;
    int x;
    int y;
  public:
    static std::string hasSeen;
    std::string getValue();
    int getX();
    int getY();
    Item();
    Item(std::string value, int x, int y);
    Item &operator=(const Item &o);
    virtual ~Item();
};

#endif
