#pragma once
#include <string>
#include <vector>
#include <string>
#include <ncurses.h>

class Sprite {
public:
  std::string spritePath;
  std::vector<std::string> framesCache;
  uint index = 0;
  bool isFinished = false;
  Sprite(const std::string filePath);
  std::string getNextFrame();
  std::string printNextFrame();
};
