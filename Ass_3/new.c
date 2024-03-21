#include <stdlib.h>
#include <stdio.h>

// all decreasing subsets
// then we need to find the smallest element in the current subset that is greater than the largest element
// smallest element in previous subset
// if that is found count is increased by 1
// the condition for a subset to end is arr[i] < arr[i+1]
//

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[i] = x;
    }
    arr[n]=__INT_MAX__;
    int max_prev_subset = -1;
    int small_curr = -1;
    int count_subset = 0;
    int val=-1;
    // 8, 3, 4, 6, 5, 2, 0, 7, 9, 1
    for (int i = 0; i < n ; i++)
    {
        if (arr[i] < arr[i + 1]) // subset is broken and a new one starts
        {
            //printf("\n/* %d %d %d */\n",arr[i],small_curr,max_prev_subset);
            if (arr[i] >= max_prev_subset)
            {
                small_curr = arr[i];
                val=i;
            }
            // printf("%d %d %d\n",arr[i],small_curr,max_prev_subset);
            if (max_prev_subset < small_curr)
            {
                count_subset++;
                printf("%d ,", val);
                max_prev_subset = small_curr;
            }
        }
        else // subset is continued, you need to find the smallest element here that is greater than the last one
        {
            if (arr[i] >= max_prev_subset)
            {
                small_curr = arr[i];
                val=i;
            }
        }
    }
    printf("\n%d\n",count_subset);

}