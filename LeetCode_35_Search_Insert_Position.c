int searchInsert(int* nums, int numsSize, int target) {
    int start=0, end=numsSize-1,middle;
    while (start<=end) {
        middle=(start+end)/2;
        if (*(nums+middle)==target) return middle;
        else if (*(nums+middle)<target) {
            start=middle+1;
        }
        else {
            end=middle-1;
        }
    }
    for (int i=0;i<numsSize;++i) {
        if (*(nums+i)>target) return i;
    }
    return numsSize;
}