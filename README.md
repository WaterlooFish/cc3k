# cc3k
C++ Dungeon Crawler game created for CS 246.
To compile, on a command line enter "make cc3k initialConfig.txt". Then, run using the name "cc3k".

This game is a project I created for my final CS 246 project. It is a simplified rogue-like video game run through the command line, in which you select a race to play, fight enemies, obtain gold and venture through 5 different floors.

A player must enter "s, d, v, g ,t" to select the race of Shade, Drow, Vampire, Troll or Goblin. Then, the commands "no,so,ea,we,ne,nw,se,sw" are used to move the player around the map. "u <direction>" uses the potion indicated by the direction and "a <direction>" attacks the enmy in the indicated direction. Pressing "r" restarts the game.

On the board, "@" specifies the player, "\" is for stairs, "." for walkable tiles, "G" specifies gold,  and "P" specifies a potion. Enemies are denoted by any other character.
