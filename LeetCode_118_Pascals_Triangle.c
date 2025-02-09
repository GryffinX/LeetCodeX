/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows; // Set the return size
    int** p = (int**)malloc(numRows * sizeof(int*)); // Allocate memory for the rows
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int)); // Allocate memory for column sizes

    for (int i = 0; i < numRows; ++i) {
        p[i] = (int*)malloc((i + 1) * sizeof(int)); // Allocate memory for each row
        (*returnColumnSizes)[i] = i + 1; // Set the size of the current row

        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                p[i][j] = 1; // First and last elements are always 1
            } else {
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j]; // Sum of the two elements above
            }
        }
    }
    return p; // Return the generated Pascal's Triangle
}