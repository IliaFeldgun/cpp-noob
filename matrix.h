#ifndef NOOB_MATRIX_H
#define NOOB_MATRIX_H
class Matrix {
public:
  char **topLeft;
  int height;
  int width;
  Matrix(int height, int width);
  void print();
};

#endif //NOOB_MATRIX_H