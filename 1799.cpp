#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

#define PI 3.14159265

int main(int argc, char *argv[]){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		float R;
		int n;
		cin >> R >> n;
		cout << "Scenario #" << i+1 << ":" << endl;
		//cout << R * sin(PI / n) / (1 + sin(PI / n)) << std::setprecision(3) << endl;
		printf("%.3f\n", R * sin(PI / n) / (1 + sin(PI / n)));
		cout << endl;
	}
}