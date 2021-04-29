
#include <bits/stdc++.h>
using namespace std;


void sort012(int a[], int n)
{
	int l = 0;
	int h = n - 1;
	int m= 0;

	
	while (m <= h) {
		 {
	if(a[m]==0)
			{swap(a[l], a[m]);
			l++;
            m++;}

	if(a[m]==1)
			m++;

	if(a[m]==2)
			{swap(a[m], a[h]);
			h--;}
		}
	}
}


void printArray(int arr[], int arr_size)
{
	
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort012(arr, n);

	cout << "array after segregation ";

	printArray(arr, n);

	return 0;
}

// This code is contributed by Shivi_Aggarwal
