#include "matrix.h"
#include "iostream"

Matrix::Matrix(int m_height, int m_width) {
  height = m_height;
  width = m_width;
  topLeft = new char *[height]; /**/
  for (int i = 0; i < height; i++) {
    topLeft[i] = new char[width];
    for (int j = 0; j < width; j++) {
      topLeft[i][j] = '_';
      std::cout << topLeft[i][j];
    }
    std::cout << "\n";
  }
  std::cout << "Matrix " << height << "x" << width << " created.\n";
}

void corner() { std::cout << "\033[0;0H"; }

void Matrix::print() {
  corner();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << topLeft[i][j];
    }
    std::cout << "\n";
  }
}
