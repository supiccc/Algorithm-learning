#include <iostream>  
#include <cmath>  
#include <string.h>  
  
using namespace std;  
  
int* arr;//结果有序数组  
int* temp;//中间数组  
  
// 有序合并为temp & 统计逆序对 & temp赋值回arr  
int merge_inversion(int low, int middle, int high)  
{  
	int i = low, j = middle + 1, k = low;  
	  
	while ((i <= middle) && (j <= high)) {  
		if (arr[i] <= arr[j]) {  
			temp[k++] = arr[i++];  
		}else{  
			temp[k++] = arr[j++];  
		}  
	}  
	  
	int q = 0;  
	if (i > middle) {  
		for (q = j; q <= high; q++) {  
			temp[k++] = arr[q];  
		}  
	}else{  
		for (q = i; q <= high; q++) {  
			temp[k++] = arr[q];  
		}  
	}  
	//以上有序合并为temp数组  
	  
	  
	//观察low,middle,high间的关系  
	//cout << low << "+" << middle << "+" << high << "         " << arr[low] << "---" << arr[high] << endl;  
	
	int count = 0;  
	  
	int left = low;// left，左段（还）需要比较的数的下标  
	int right = middle + 1;// right，右段（还）需要比较的数的下标  
	  
	while (left <= middle && right <= high) {  
		if (arr[left] > arr[right]) {
			// 左段首位 > 右段首位，即左段的最小都大于右段首位，则左段全都大于右段首位  
			count += middle + 1 - left;
			// middle + 1 为右段首位  
			//如2 3 8,1 6，其中1为首位  
			  
			right++;  
		}else{  
			  
			left++;  
		}  
	}//统计逆序对  
	  
	  
	// temp赋值回arr  
	for (int t = low; t <= high; t++) {//别漏了=号  
		  
		arr[t] = temp[t];  
	}  
	  
	return count;  
}  
  
// 计算逆序对数量  
int count_inversion(int low, int high)  
{  
	int count = 0, middle = 0;  
	if(low < high)  
	{  
		middle = low + (high - low) / 2;  
		count += count_inversion(low, middle);         //对左段的逆序对的递归计数  
		count += count_inversion(middle + 1, high);    //对右段的逆序对的递归计数  
		count += merge_inversion(low, middle, high);   //左段 > 右段的逆序对计数  
	}  
	  
	if (count > 0) {
		//全部有序时会出现 count < 0 的情况  
		//也可在count += middle + 1 - left;处判断  
		return count;  
	}  
	  
	return 0;  
}  
/* 
 
5 
2 3 8 6 1 
 
*/  
int main()
{  
	int n;  
	cin >> n;  
	arr = new int[n];  
	temp = new int[n];  
	  
	for (int i = 0 ; i < n; i++) {  
		cin >> arr[i];
	}  
	  
	cout << count_inversion(0, n-1); 

	cout << endl;  
	return 0;  
}  