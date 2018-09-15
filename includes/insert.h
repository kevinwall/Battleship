#include <iostream>
#include <algorithm>
#include <fstream>

int * validate_position_col( int col);

int * validate_position_lin( int lin);

bool colision_1(int **A, int b, int c, int boat, int lin, int col, int k);

bool colision_2(int **A, int b, int c, int boat, int lin, int col, int k);

bool negate_area(int ** A, int b, int c, int boat, int lin, int col, int k);

void insert_boat(int ** A, int B, int C, int boat, int k);

bool test_position( int ** A , int * B, int * C, int lin, int col, int boat);