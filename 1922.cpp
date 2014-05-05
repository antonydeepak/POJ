#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
#include<math.h>
#include<algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
//Our intent to to know the fastest guy because charley will finish along with the fastest guy.
int main(int argc, char *argv[]){
	cout.setf(std::ios::unitbuf);
	while (true){
		int n;
		cin >> n;
		if (n == 0)
			return EXIT_SUCCESS;
		int rider_speed,setoff_time;
		float rider_time, best_time = INT_MAX;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &rider_speed, &setoff_time);
			if (setoff_time >= 0){ //we don't need the guys who are ahead of us because they have either raced or we will eventually race them
				rider_time = (4.5 * 3600 / rider_speed)+ setoff_time;
				best_time = std::min(rider_time, best_time);
			}
		}
		cout << (int)ceil(best_time) <<endl;
	}
}

