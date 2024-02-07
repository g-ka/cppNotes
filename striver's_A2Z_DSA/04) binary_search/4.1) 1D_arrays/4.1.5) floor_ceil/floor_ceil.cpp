#include <iostream>
#include <bits/stdc++.h>

std::pair<int, int> getFloorAndCeil(std::vector<int> &a, int n, int x);

int main(){

  std::vector<int> a{3,4,4,7,8,10};

  std::pair<int, int> result = getFloorAndCeil(a, a.size(), 2);

  std::cout << result.first << " " << result.second;

  return 0;
}

std::pair<int, int> getFloorAndCeil(std::vector<int> &a, int n, int x){
	int start = 0;
	int end = n - 1;
	while(start!=end){
		int middle = (end - start)/2 + start;
		if(a[middle] < x) start = middle + 1;
		else end = middle;
	}
	if(a[start] == x) return {x, x};
	else if(a[start] > x && start == 0) return {-1, a[start]};
	else if(a[start] > x) return {a[start-1], a[start]};
	else if(a[start] < x) return {a[start], -1};
}