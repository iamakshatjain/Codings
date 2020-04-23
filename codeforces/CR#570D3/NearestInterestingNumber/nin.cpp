#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int calculate_sum_of_digits(int a){
	int sum = 0;
	while(a){
		int r = a%10;
		sum+=r;
		a = a/10;
	}
	return sum;
}

int nearest_interesting_number(int a){
	int sum = calculate_sum_of_digits(a);
	int number = a;
	if(sum%4 == 3)
		number+=1;
	if(sum%4 == 2)
		number+=2;
	if(sum%4 == 1)
		number+=3;

	int nc = calculate_sum_of_digits(number);
	if(nc%4 == 0)
		return number;
	else
		return nearest_interesting_number(number);
}

int main(){

	int a;
	cin>>a;
	cout<<nearest_interesting_number(a)<<endl;

	return 0;
}