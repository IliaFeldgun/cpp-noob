#include "iostream"
#include "sprite.h"
#include <fstream>
#include <ncurses.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;

const int TICK_DELAY = 1000 * 100;
std::string SMOKE_SPRITE_PATH = "assets/smoke_sprite.txt";
std::string CANNON_SPRITE_PATH = "assets/cannon_sprite.txt";

int main(void) {
  int height = 30;
  int width = height * 2;
  std::cout << height << "X" << width << "\n";
  Sprite smoke = Sprite(SMOKE_SPRITE_PATH);
  Sprite cannon = Sprite(CANNON_SPRITE_PATH);
  std::string smokeFrame;
  std::string cannonFrame;
  initscr();
  noecho();
  curs_set(FALSE);
  clear();
  WINDOW *cannonWin, *smokeWin;
  refresh();
  cannonWin = newwin(height, width, 2, 0);
  smokeWin = newwin(height, width -21, 0, 21);
  for (uint i = 0; i < smoke.framesCache.size() - 1; i++) {
    cannonFrame = cannon.getNextFrame();
    mvwaddstr(cannonWin, 1, 1, cannonFrame.c_str());
    wrefresh(cannonWin);
    smokeFrame = smoke.getNextFrame();
    mvwaddstr(smokeWin, 0, 1, smokeFrame.c_str());
    wrefresh(smokeWin);
    usleep(TICK_DELAY);
  }
  delwin(cannonWin);
  delwin(smokeWin);
  endwin();
  return 0;
}