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

int main(int argc, char *argv[]){
	int N;
	cin >> N;
	char farm[100][100];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> farm[i][j];
		}
	}

	int best_area = 0;
	int Js;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (farm[i][j] != 'B'){
				for (int a = 1; a < std::min(N - j, N - i); a++){
					for (int b = 0; b < std::min(i + 1, N - j); b++){
						if ((i + a - b < 0) || (j + b + a > N - 1))
							continue;
						Js = 0;
						Js += (farm[i][j] == 'J') ? 1 : 0;
						if (farm[i - b][j + a] == 'B') continue;
						Js += (farm[i - b][j + a] == 'J') ? 1 : 0;
						if (farm[i + a][j + b] == 'B') continue;
						Js += (farm[i + a][j + b] == 'J') ? 1 : 0;
						if (farm[i + a - b][j + a + b] == 'B') continue;
						Js += (farm[i + a - b][j + a + b] == 'J') ? 1 : 0;
						if (Js >= 3 && a*a + b*b > best_area){
							best_area = a*a + b*b;
						}
					}
				}
			}
		}
	}
	cout << best_area;
}