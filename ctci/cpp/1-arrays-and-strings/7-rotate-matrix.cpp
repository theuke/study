/* Rotate Matrix:
 * Given an image represented by an N X N matrix, where each pixel in the image is
 * represented by an integer, write a method to rotate the image 90 degrees.
 * Can you do this in place?
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Solution {
public:
    enum Direction {
        LEFT,
        RIGHT
    };
private:
    // Caller is expected to only provide a the top row. Hence row is both the row as well as acts as the start col.
    void rotateElement(int *m, const int n, const int subN, const int row, const int col, const Direction direction) {
        const int nOffset = subN - 1;
        const int colOffest = col - row;
        const int bottomOrRightEdge = nOffset + row;

        int indices[4][2];
        indices[0][0] = row;
        indices[0][1] = col;

        indices[1][0] = row + nOffset - colOffest;
        indices[1][1] = row;

        indices[2][0] = bottomOrRightEdge;
        indices[2][1] = bottomOrRightEdge - colOffest;

        indices[3][0] = row + colOffest;
        indices[3][1] = bottomOrRightEdge;

        int values[4];
        for (int i = 0; i < 4; ++i)
            values[i] = m[indices[i][0]*n + indices[i][1]];

        if (direction == LEFT) {
            for (int i = 0; i < 4; ++i) {
                int nextIdx = i + 1;
                if (nextIdx == 4)
                    nextIdx = 0;
                m[indices[nextIdx][0]*n + indices[nextIdx][1]] = values[i];
            }
        } else {
            for (int i = 3; i >= 0; --i) {
                int nextIdx = i - 1;
                if (nextIdx == -1)
                    nextIdx = 3;
                m[indices[nextIdx][0]*n + indices[nextIdx][1]] = values[i];
            } 
        }
    }
public:
    int *rotateMatrix(int *m, const int n, const Direction direction) {
        // The obvious soluton is to use a temporary matrix in order and then go
        // row by row and move it to its appropriate column.

        // Doing this procedure in place is more involved. The approach is to
        // view the matrix as an onion and perform the transpose operation
        // layer by layer until. For example.

        int numLayers = (n + 1)/2;
        int subN = n;

        for (int i = 0; i < numLayers; ++i) {
            int maxColInLayer = n - 1 - i;
            for (int j = i; j < maxColInLayer; ++j) {
                rotateElement(m, n, subN, i, j, direction);
            }
            subN -= 2;
        }

        return m;
    }
};

struct TestCase {
    int *input;
    int size;
    Solution::Direction direction;
    int *output;
};

int main() {
    Solution solution;
    int input1[][4] = {
        0,   1,  2,  3,
        4,   5,  6,  7,
        8,   9, 10, 11,
        12, 13, 14, 15
    };
     int output1[][4] = {
        3, 7, 11, 15,
        2, 6, 10, 14,
        1, 5,  9, 13,
        0, 4,  8, 12
    };
    std::vector<TestCase> cases = {
        {
            (int *)&input1[0][0],
            4,
            Solution::Direction::LEFT,
            (int *)&output1[0][0]
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        int *output = solution.rotateMatrix(testCase->input, testCase->size, testCase->direction);
        for (int i = 0; i < testCase->size; ++i) {
            for (int j = 0; j < testCase->size; ++j) {
                assert(output[i * testCase->size + j] == testCase->output[i * testCase->size + j]);
            }
        }
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}