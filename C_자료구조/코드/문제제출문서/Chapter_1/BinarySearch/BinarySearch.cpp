#include <iostream>
using namespace std;

int BSearch(int arr[], int first, int last, int target)
{
		int mid;
		if (first > last)
			return -1;
		mid = (first + last) / 2;

		if (target == arr[mid])
		{
			return mid;
		}
		else
		{
			if (target < arr[mid])
				return BSearch(arr, first, mid - 1, target);
			else
				return BSearch(arr, mid + 1, last, target);
		}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int)-1, 7);

	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º : " << idx << endl;

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int)-1, 4);

	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º : " << idx << endl;

	return 0;
}