#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = high;
	while(i<j){
		while(arr[i]<=pivot) i++;
		while(arr[j]>pivot) j--;
		if(i<j) swap(arr[i],arr[j]);
	}
	swap(arr[low],arr[j]);
	return j;
}

void quick_sort_helper(vector<int> &arr, int low, int high){
	if(low<high){
		int mid = partition(arr,low,high);
		quick_sort_helper(arr,low,mid-1);
		quick_sort_helper(arr,mid+1,high);
	}
}

void quick_sort(vector<int> &arr){
	//arr.push_back(numeric_limits<int>::max());
	quick_sort_helper(arr,0,arr.size()-1);
	//arr.pop_back();
}

int main(){
	vector<int> nums = {10,16,8,12,15,6,3,9,5};
	quick_sort(nums);
	for(auto n: nums) cout<<n<<" ";
	cout<<endl;
}