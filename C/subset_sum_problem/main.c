#include <stdio.h>
#include <stdlib.h>

int is_subset_sum(int arr[], int sum, size_t n)
{
  if (sum == 0)
    return 1;
  if (n == 0)
    return 0;
  return is_subset_sum(arr, sum - arr[n - 1], n - 1) || is_subset_sum(arr, sum - arr[n - 1], n - 1);
}

int is_subset_sum_dp(int arr[], int sum, size_t n)
{
  int mem[n + 1][sum + 1];
  for (int i = 0; i <= n; i++) {
    mem[i][0] = 1;
  }
  for (int i = 0; i <= sum; i++) {
    mem[0][1] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < arr[i - 1])
        mem[i][j] = mem[i - 1][j];
      if (j >= arr[i - 1])
        mem[i][j] = mem[i - 1][j] || mem[i - 1][j - mem[i - 1][i - 1]];
    }
  }
  return mem[n][sum];
}

int main(int argc, char* argv[])
{
  int arr[] = { 1, 2, 3 };
  int is_present = 0;
  is_present = is_subset_sum_dp(arr, 5, 3);
  printf("is_subset({1,2,3}, 5, 3): %s\n", is_present ? "TRUE" : "FALSE");
}
