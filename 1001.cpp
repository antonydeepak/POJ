//Exponentiation problem
#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits>
#include<math.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

#define MAX_LEN 6
int main (int argc, char *argv[])
{
	cout.setf(std::ios::unitbuf);
	char r[MAX_LEN];
	int n=0;
	while(scanf("%s %d",r,&n) != EOF){
		vector<char> number_without_decimal; 
		int dot_pos=-1;
		for(int i=MAX_LEN-1;i>=0;i--){
			char c=r[i];
			if(c == '.'){
				dot_pos = MAX_LEN-(i+1);
				continue;
			}
			number_without_decimal.push_back(atoi(&c));
		}
		dot_pos *= n;

		vector<char> result(number_without_decimal.size());
		//copy the first element in the result
		std::copy(number_without_decimal.begin(),number_without_decimal.end(),result.begin());
		while(n-1>0){
			vector<char> product_result(result.size()+number_without_decimal.size()+1,0);
			int carry;
			int val;
			for(vector<char>::size_type j=0;j<number_without_decimal.size();j++){
				carry=0;
				val=0;
				vector<char>::size_type i=0;
				for(;i<result.size();i++){
					val=(number_without_decimal[j]*result[i])+carry+product_result[i+j];
					product_result[i+j] = val%10;
					carry = val/10;
				}
				product_result[i+j]=carry;
			}
			result.resize(product_result.size());
			copy(product_result.begin(),product_result.end(),result.begin());
			n--;
		}

		if(dot_pos>0)
			result.insert(result.begin()+dot_pos,'.');
		//remove trailing zeroes
		int trailing_zeroes_to_erase=0;
		for(int i=0;i<result.size();i++){
			if(result[i] != 0 || i >= dot_pos){
				break;
			}
			trailing_zeroes_to_erase++;
		}
		result.erase(result.begin(),result.begin()+trailing_zeroes_to_erase);
		//remove trailing dot
		if(result[0]=='.')
			result.erase(result.begin());
		//remove leading zeroes and print
		bool leading_zeros=true;
		for(int i=result.size()-1;i>=0;i--){
			if(leading_zeros){
				if(result[i] == 0){
					continue; 
				}
				else{
					leading_zeros=false;
				}
			}
			if(result[i] == '.'){
				printf("%c",result[i]);
				continue;
			}
			printf("%d",result[i]);
		}
		cout<<endl;
	}
	return EXIT_SUCCESS;
}


