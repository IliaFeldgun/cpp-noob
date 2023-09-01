#pragma once
#include <ncurses.h>
#include <string>
#include <vector>

class Sprite {
public:
  std::string spritePath;
  std::vector<std::string> framesCache;
  uint index = 0;
  bool isFinished = false;
  Sprite(const std::string filePath);
  std::string getNextFrame();
};
