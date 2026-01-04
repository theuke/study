// manually transpose a 3x3 matrix
/*
    a  b  c     a  d  g
    d  e  f  ~  b  e  h
    g  h  i     c  f  i
*/

#include <iostream>
#include <vector>

typedef std::vector< std::vector<int> > matrix;

matrix A = { {1, 2, 3}, 
             {4, 5, 6},
             {7, 8, 9} };

void swap(int& _x, int& _y)  // any swap function will do, I just recycled this function from the last problem
{
    _x = _x - _y;
    _y = _x + _y;
    _x = _y - _x;
}

void print_mat(matrix B)
{
    for ( int i = 0; i < 3; ++i )
        std::cout << B[i][0] << "  " << B[i][1] << "  " << B[i][2] <<  std::endl;
    std::cout << std::endl;
}

int main ()
{
    print_mat(A);

    // 3x3 transpose
    swap(A[1][0], A[0][1]);
    swap(A[2][0], A[0][2]);
    swap(A[2][1], A[1][2]);

    print_mat(A);
}