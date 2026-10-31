int maxProfit(int* prices, int pricesSize) {
int i=0,profit,  minprice=prices[i];
int maxProfit=0;
for(int i=0;i<pricesSize;i++){
    if(prices[i]<minprice){
        minprice=prices[i];
    }
    profit= prices[i]- minprice;
    if(profit>maxProfit){
        maxProfit=profit;
    }
}
return maxProfit;
}