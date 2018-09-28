
#include "SimpleArray.h"

#include <stdio.h>
#include <iostream>
using namespace std;

#define HEAP_SIZE 100
#define TEST_SIZE 20
#define TEST_COUNT 1000

int main(int argc, char * argv[]) {
    printf("Test SimpleArray\n");

    /**
     * Test functions
     */
    int i;

    SimpleArray<uint8_t, int> arr1(HEAP_SIZE);
    for (i = 0; i < TEST_SIZE; i++) {
        arr1.append(i);
    }
    SimpleArray<uint8_t, int> arr2(HEAP_SIZE);
    arr2.append(arr1);

    if (arr1 == arr2)
        printf("arr1 equal arr2\n");

    printf("Remove arr2 from 2 to 2+%d = %d units\n", TEST_SIZE, arr2.remove(2, TEST_SIZE));
    for (i = 0; i < arr2.length(); i ++)
        printf("%d ", arr2[i]);
    printf("\n");

    if (arr1 != arr2)
        printf("arr1 not equal arr2\n");

    /**
     * Test reliability
     */
    for (int t = 0; t < TEST_COUNT; t++) {
        uint8_t tmp = arr1[1];
        arr1.remove(1, 10);
        for (int j = tmp; j < tmp+10; j++) {
            if (j < TEST_SIZE)
                arr1.append(j);
            else
                arr1.append(j-TEST_SIZE + 1);
        }

        if (t % 100 == 0) {
            printf("arr1 after %d tests.. ", t);
            for (i = 0; i < TEST_SIZE; i++)
                printf("%d ", arr1[i]);
            printf("\n");
        }
    }

    return 0;
}
