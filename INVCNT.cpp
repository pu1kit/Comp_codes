#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int mergesort(int arr[],int size) {
	int *temp = (int *)malloc(sizeof(int)*size);
	return _mergeSort(arr,temp,0,size-1);
	}
int _mergeSort(int arr[],int temp[],int left, int right) {
	int mid, inv_count=0;
	if(right>left) {
		mid = (right+left)/2;
		inv_count = _mergeSort(arr,temp,left,mid);
		inv_count += _mergeSort(arr,temp,mid+1,right);
		inv_count += merge(arr,temp,left,mid+1,right);
		}
	return inv_count;
	}
int merge(int arr[],int temp[],int left,int mid,int right) {
	int i,j,k;
	int inv_count = 0;
	i = left;
	j = mid;
	k = left;
	while((i<=mid-1)&&(j<=right)) {
		if(arr[i]<= arr[j]) {
			temp[k++] = arr[i++];
			}
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count+(mid-i);
			}
		}
	while(i<=mid-1)
		temp[k++] = arr[i++];
	while(j<=right) 
		temp[k++] = arr[j++];
	for(i=left;i<=right;i++)
		arr[i] = temp[i];
	return inv_count;
}

				

int main(){
	int test;
	scanf("%d",&test);
	while(test--) {
		int n1;
		scanf("%d",&n1);
		int arr[n1];
		for(int i=0;i<n1;i++){
			scanf("%d",&arr[i]);
			}
		printf("%d\n"mergeSort(arr,n1));
		return 0;
}

	
	


	