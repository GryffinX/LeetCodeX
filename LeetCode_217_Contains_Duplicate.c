int com(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


bool containsDuplicate(int* nums, int numsSize) {
    if (sizeof(nums)<2) return false;
    qsort(nums,numsSize,sizeof(int),com);
    for (int i=1;i<numsSize;++i) {
        if (*(nums+i)==*(nums+i-1)) return true;
    }
    return false;
}