#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
//#define OPEN freopen("input.txt","r",stdin);
using namespace std;

int main() {
//	OPEN;
	int n,m,k,x,y,cost,test;
	long int d,sum;
	scanf("%d",&test);
//	vector < pair<long,int> > arr;
//	vector <pair<long,int> > dum;
	while(test--){ 
		
		sum=0;
		scanf("%d %d %d",&n,&k,&m);
		vector < pair<long,int> > arr;
		vector <pair<long,int> > dum;
		for(int i=0;i<n;i++) {
			scanf("%ld",&d);
			arr.push_back(make_pair(d,999));
			sum += d;
		}
		for(int i=0;i<m;i++) {
			scanf("%d %d %d",&x,&y,&cost);
			for(int j=x-1;j<y;j++) {
				arr[j].second = arr[j].second>cost?cost:arr[j].second;
			}
		}
		int con = 0;
		for(int i=0;i<n;i++) {
			if(arr[i].first<0) {
				dum.push_back(arr[i]);
				con++;
			}
		}
		sort(dum.begin(),dum.end());
		if(con>0){
		long int dp[con+1][k+1];
		for(int i=0;i<=con;i++) {
			for(int w = 0; w<= k;w++) {
				if(i==0 || w==0){ 
					dp[i][w]=0;
					continue;
				}
				if(dum[i-1].second<=w)
					dp[i][w] = min(dum[i-1].first+dp[i-1][w-dum[i-1].second],dp[i-1][w]);
				else
				dp[i][w] = dp[i-1][w]; 
			}
		}
		//cout<<dp[con-1][k]<<"----"<<sum<<endl;

		printf("%ld\n",sum-dp[con][k]);
		}
		else printf("%ld\n",sum);

	        //arr.clear();
               vector<pair <long,int> >().swap( arr );
               vector<pair <long,int> >().swap( dum );

		//dum.clear();
	}
	return 0;
}

		