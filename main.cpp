#include "iostream"
#include "sprite.h"
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <ncurses.h>
#include <sstream>
#include <fstream>

using namespace std;

const int TICK_DELAY = 1000 * 100;
std::string SMOKE_SPRITE_PATH = "assets/smoke_sprite.txt";
std::string CANNON_PIC_PATH = "assets/cannon.txt";

int main(void) {
  int height = 30;
  int width = height*2;
  std::cout << height << "X" << width << "\n";
  Sprite sprite = Sprite(SMOKE_SPRITE_PATH);
  std::string frame;
  ifstream spriteFile(CANNON_PIC_PATH, std::ios_base::binary);
  stringstream buffer;
  buffer << spriteFile.rdbuf();
  std::string cannon = buffer.str();
  initscr();
  noecho();
  curs_set(FALSE);
  clear();
  WINDOW *cannonWin, *smokeWin;
  refresh();
  cannonWin = newwin(height, width, 2, 0);
  smokeWin = newwin(height, width, 0, 21);
  mvwaddstr(cannonWin, 1, 1, cannon.c_str());
  wrefresh(cannonWin);
  for (uint i = 0; i < sprite.framesCache.size() - 1; i++) {
    frame = sprite.printNextFrame();
    mvwaddstr(smokeWin, 0, 0, frame.c_str());
    usleep(TICK_DELAY);
    wrefresh(smokeWin);
  }
  delwin(cannonWin);
  delwin(smokeWin);
  endwin();
  return 0;
}