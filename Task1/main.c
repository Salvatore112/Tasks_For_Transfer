#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEST_LENGTH 10

// Function that checks if the given array sorted.
bool isSorted(int array[], int length){
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

// Auxilary function that swaps the values of two elements.
void swap(int *oneValue, int *anotherValue) {
    int temp = *oneValue;
    *oneValue = *anotherValue;
    *anotherValue = temp;
}

// Auxilary function for quickSort that moves the pivot to the right position and returns its index.
int partition(int array[], int low, int high) {
    int pivotValue = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] < pivotValue) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

// Function that sorts the array using quickSort algorithm
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, 0, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// Function that return the most frequent element in the array.
int mostFrequentElement(int array[], int length) {
    
    int mostFrequent = array[0];
    int count = 1;
    int maxCount = 1;
    for (int i = 1; i < length - 1; i++) {
        if (array[i] == array[i - 1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
                mostFrequent = array[i];
            }
        }
        else {
            count = 1;
        }
    }
    return mostFrequent;
}

bool quickSortTests() {
    int test1[TEST_LENGTH] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    quickSort(test1, 0, TEST_LENGTH - 1);
    if (!isSorted(test1, TEST_LENGTH)) {
        printf("QuickSort tests failed on the array {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}\n");
        return false;
    }

    int test2[TEST_LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(test2, 0, TEST_LENGTH - 1);
    if (!isSorted(test2, TEST_LENGTH)) {
        printf("QuickSort tests failed on the array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}\n");
        return false;
    }

    int test3[TEST_LENGTH] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(test3, 0, TEST_LENGTH - 1);
    if (!isSorted(test3, TEST_LENGTH)) {
        printf("QuickSort tests failed on the array {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}\n");
        return false;
    }

    int test4[TEST_LENGTH] = {400, 350, 300, 250, 200, 150, 100, 50, 12, 5};
    quickSort(test4, 0, TEST_LENGTH - 1);
    if (!isSorted(test4, TEST_LENGTH)) {
        printf("QuickSort tests failed on the array {400, 350, 300, 250, 200, 150, 100, 50, 12, 5}\n");
        return false;
    }

    int test5[TEST_LENGTH] = {5, 12, 50, 100, 150, 200, 250, 300, 350, 400};
    quickSort(test5, 0, TEST_LENGTH - 1);
    if (!isSorted(test5, TEST_LENGTH)) {
        printf("QuickSort tests failed on the array {5, 12, 50, 100, 150, 200, 250, 300, 350, 400}\n");
        return false;
    }
    return true;
}

bool frequentElementSearchTests() {
    int test1[1] = { 1 };
    if (mostFrequentElement(test1, 1) != 1) {
        printf("FrequentElementSearch tests failed on the array { 1 }\n");
        return false;
    }
    
    int test2[TEST_LENGTH] = {4, 4, 4, 1, 1, 1, 1, 1, 1, 1};
    if (mostFrequentElement(test2, TEST_LENGTH) != 1) {
        printf("FrequentElementSearch tests failed on the array {4, 4, 4, 1, 1, 1, 1, 1, 1, 1}\n");
        return false;
    }
    
    int test3[TEST_LENGTH] = {3, 3, 3, 3, 3, 3, 7, 7, 7, 7};
    if (mostFrequentElement(test3, TEST_LENGTH) != 3)  {
        printf("FrequentElementSearch tests failed on the array {3, 3, 3, 3, 3, 3, 7, 7, 7, 7}\n");
        return false;
    }

    return true;
}

int main(void) {
    if (!quickSortTests() || !frequentElementSearchTests()) {
        return -1;
    }
}