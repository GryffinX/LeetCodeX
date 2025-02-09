#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int*p=(int*)malloc((digitsSize+1)*sizeof(int));
    int carry=1;
    int k=digitsSize-1;
    while (k>=0) {
        int sum=digits[k]+carry;
        if (sum>=10) {
            carry=1;
            *(p+k+1)=sum-10;
        }
        else {
            carry=0;
            *(p+k+1)=sum;
        }
        k--;
    }
    if (carry) {
        *p=carry;
        *returnSize=digitsSize+1;
    }
    else {
        for (int i=0;i<digitsSize;++i) {
            *(p+i)=*(p+i+1);
        }
        *returnSize=digitsSize;
    }
    return p;
}