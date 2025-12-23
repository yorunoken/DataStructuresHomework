#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSide = mid - left + 1;
    int rightSide = right - mid;

    std::vector<int> tempL(leftSide), tempR(rightSide);

    // verileri temp vektorlere kopyala
    for (int i = 0; i < leftSide; i++) tempL[i] = arr[left + i];
    for (int j = 0; j < rightSide; j++) tempR[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSide && j < rightSide) {
        if (tempL[i] <= tempR[j]) {
            arr[k] = tempL[i];
            i++;
        } else {
            arr[k] = tempR[j];
            j++;
        }
        k++;
    }

    while (i < leftSide) {
        arr[k] = tempL[i];
        i++;
        k++;
    }

    while (j < rightSide) {
        arr[k] = tempR[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printVector(std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arrayToSort = {10, 2, 5, 6, 45, 1, 7, 8, 9, 42};
    std::cout << "siralanacak liste: \n";
    printVector(arrayToSort);

    // array'i sirala
    mergeSort(arrayToSort, 0, arrayToSort.size() - 1);

    std::cout << "siralanmis liste: \n";
    printVector(arrayToSort);

    return 0;
}