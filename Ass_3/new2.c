#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_length = 0; // Length of the longest subsequence
    int start_index = 0; // Start index of the longest subsequence
    int curr_length = 1; // Current length of the subsequence
    int curr_start_index = 0; // Start index of the current subsequence

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            curr_length++;
        } else {
            if (curr_length > max_length) {
                max_length = curr_length;
                start_index = curr_start_index;
            }
            curr_length = 1;
            curr_start_index = i;
        }
    }

    // Check if the last subsequence is the longest
    if (curr_length > max_length) {
        max_length = curr_length;
        start_index = curr_start_index;
    }

    printf("%d\n", max_length);
    for (int i = start_index; i < start_index + max_length; i++) {
        printf("%d ", i - max_length + 1);
    }
    printf("\n");

    free(arr);

    return 0;
}
