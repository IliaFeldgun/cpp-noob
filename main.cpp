#include "iostream"
#include "matrix.h"
#include <unistd.h>

using namespace std;

const int TICK_DELAY = 1000 * 100;

int main(void) {
  std::cout << "Hello! This is a C++ program.\n";
  int width = 15;
  int height = width;
  std::cout << height << "X" << width << "\n";
  Matrix *m = new Matrix(height, width);
  int previous_i = 0;
  int previous_j = 0;
  for (int i = 1; i < width; i++) {
    for (int j = 1; j < height; j++) {
      m->print();
      m->topLeft[i][j] = '@';
      m->topLeft[previous_i][previous_j] = ' ';
      usleep(TICK_DELAY);
      previous_j = j;
      previous_i = i;
    }
    previous_i = i;
  }
  return 0;
}