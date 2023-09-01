#include "sprite.h"
#include <fstream>
#include <ncurses.h>
#include <sstream>
#include <iostream>
#include <string>


using namespace std;
const std::string SEPARATOR = "\n;\n";
const int MAX_FRAMES = 100;
Sprite::Sprite(const std::string filePath) {
  spritePath = filePath;
  index = 0;
  ifstream spriteFile(spritePath, std::ios_base::binary);
  cout << "Sprite file " << spritePath << " loaded.\n";
  stringstream buffer;
  buffer << spriteFile.rdbuf();
  std::string allFrames = buffer.str();
  int frameLength = allFrames.find(SEPARATOR);
  while (frameLength != -1 && frameLength != 0) {
    framesCache.push_back(allFrames.substr(0, frameLength));
    allFrames = allFrames.substr(frameLength + SEPARATOR.length());
    frameLength = allFrames.find(SEPARATOR);
  }
  framesCache.push_back(allFrames);
}

std::string Sprite::getNextFrame() {
  if (index < framesCache.size()) {
    std::string frame = framesCache[index];
    index++;
    return frame;
  } else {
    return "\\0";
  }
}

std::string Sprite::printNextFrame() {
  index++;
  return framesCache[index];
}
