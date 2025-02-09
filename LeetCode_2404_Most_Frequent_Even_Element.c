int mostFrequentEven(int* nums, int numsSize) {
    int target=-1,max=0;
    int freq[100001]={0};
    for (int i=0;i<numsSize;++i) {
        if (*(nums+i)%2==0) {
            freq[*(nums+i)]++;
        }
    }
    for (int j=0;j<100001;++j) {
        if ((freq[j]>max) ||((freq[j]==max) && (j<target))) {
            target=j;
            max=freq[j];
        }
    }
    return target;
}