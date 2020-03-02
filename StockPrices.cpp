#include <iostream>
//#include <chrono>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;
//iusing namespace std::chrono;


int maxProfit(float stockPrices[], int length){

	float min = 0.0;
	float max = 0.0;
	float oldprofit = 0.0;
	float newprofit = 0.0;

	for ( int i = 0; i < length; i++ ){
		min = stockPrices[i];
		for ( int j = i; j < length; j++){
			max = stockPrices[j];
			newprofit = max - min;
			if (newprofit > oldprofit){
				oldprofit = newprofit;
			}
		}
	}
	
	return oldprofit;
}			

int main(void){
	time_t start, end;
	time(&start);
	int length = 100000;
	float stockPrices[length] = {1,2,0,4,5,6,7,8,9,10,
				 11,12,13,14,15,16,17,
				 18,19,20};

	cout <<  maxProfit(stockPrices, length) << "\n";

	time(&end);
	double time_taken = double(end - start);
	cout << "Execution time: " << fixed << time_taken << setprecision(1);
	cout << "sec" << endl;
	return 0;
}
