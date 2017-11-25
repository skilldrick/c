#include <stdio.h>

int binsearchA(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}

int binsearchB(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return low == x ? low : -1;
}

int main()
{
  int size = 1000000;
  int arr[size];
  for (int i = 0; i < 1000000; i++) {
    binsearchB(3, arr, size);
  }
}
