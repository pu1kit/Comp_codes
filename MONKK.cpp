#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int test;
	int x,y;
	char c;
	vector< vector<int> >vec;
	scanf("%d",&test);
	while(test--) {
		scanf("%d %d",&x,&y);
		vec.resize(x,vector<int>(y,0));
		for(int i=0;i<x;i++) {
			for(int j=0;j<y;j++) {
				scanf("%c",&c);
				if (c=='B'){
					vec[i][j] = 1;
				}
				else if(c=='T') {
					vec[i][j] = -1;
					}
				else {
					vec[i][j] =0;
					}
				}
			}
		int total = 0;
		int rows[x]={};
		int cols[y]={};
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++) {
				total += vec[i][j];
				row[i] += vec[i][j];
				
				}
		}

		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++) {
				col[i] += vec[j][i];
				}
			}
	   int mx_sq = (x>y)?y:x;


		
		 

					

				
		