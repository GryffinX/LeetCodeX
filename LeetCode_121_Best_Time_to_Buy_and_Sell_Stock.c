int maxProfit(int* prices, int pricesSize) {
    int min=*prices, max=0;
    for (int i=0;i<pricesSize;++i) {
        if (min>*(prices+i)) {
            min=*(prices+i);
        }
        int price=*(prices+i)-min;
        if (price>max) {
            max=price;
        }
    }
    return max;
}