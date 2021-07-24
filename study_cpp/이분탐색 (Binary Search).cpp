#include<iostream>
#include<algorithm>

using namespace std;

int binary_search_resursion(int *arr, int low, int high, int target) {

    if(high <= low) {
        return -1;
    }

    int mid = (low + high) / 2;

    if(arr[mid] > target) {
        binary_search_resursion(arr, low, mid - 1, target);
    } else if(arr[mid] < target) {
        binary_search_resursion(arr, mid + 1, high, target);
    } else {
        return mid;
    }
}

int binary_search_cus(int *arr, int low, int high, int target) {
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] > target) {
            high = mid - 1;
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
}

int main() {
    int arr[15] = { 2, 5, 9, 4, 1, 3, 10, 13, 12, 14, 6, 7, 15, 8, 11};
    sort(arr, arr + 15);    // 이진탐색은 정렬 필수!!!!!!!!!

    // 비재귀
    binary_search_cus(arr, 0, 15, 15);

    // 재귀
    // STL

}