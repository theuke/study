/* Zero Matrix:
 * Write an algorithim such that if an element in an M x N matrix
 * is 0, it's entire row and column is set to 0.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Solution {
public:
    int *zeroMatrix(int *m, const int numRows, const int numCols) {
        // The best solution here is to have two arrays, one for rows and one for columns,
        // whch keeps track of whether or not the row / column should be zeroed out.

        bool *rows = new bool[numRows];
        bool *cols = new bool[numCols];

        // Intialize the rows and colsd to false.
        for (int i = 0; i < numRows; ++i)
            rows[i] = false;

        for (int i = 0; i < numCols; ++i)
            cols[i] = false;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (m[i*numCols + j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < numRows; ++i)
            if (rows[i])
                for (int j = 0; j < numCols; ++j)
                    m[i*numCols + j] = 0;
        for (int i = 0; i < numCols; ++i)
            if (cols[i])
                for (int j = 0; j < numRows; ++j)
                    m[j*numCols + i] = 0;

        delete[] rows;
        delete[] cols;

        return m;
    }
};

struct TestCase {
    int *input;
    int rows;
    int cols;
    int *output;
};

int main() {
    Solution solution;
    int input1[][4] = {
        1, 1, 0, 1,
        1, 0, 0, 1,
        1, 1, 1, 1
    };
    int output1[][4] = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 0, 0, 1
    };
    std::vector<TestCase> cases = {
        {
            (int *)&input1[0][0],
            3,
            4,
            (int *)&output1[0][0]
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        int *output = solution.zeroMatrix(testCase->input, testCase->rows, testCase->cols);
        for (int i = 0; i < testCase->rows; ++i) {
            for (int j = 0; j < testCase->cols; ++j) {
                assert(output[i * testCase->rows + j] == testCase->output[i * testCase->rows + j]);
            }
        }
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}