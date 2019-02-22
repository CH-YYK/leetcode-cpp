#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    void mergeSort(vector<int> &array){
        int helper[array.size()-1];
        mergesort(array, helper, 0, (int)array.size()-1);
    }

    void mergesort(vector<int> &array,int helper[],  int low, int high){
        // ----- Divide the array into halves ------
        if(low < high){
            int mid = (low + high) / 2;
            mergesort(array, helper, low, mid);
            mergesort(array, helper, mid+1, high);
            merge(array, helper, low, mid, high);
        }
    }

    void merge(vector<int> &array, int helper[], int low, int mid, int high) {
        // ----- Merge two sorted (assumed) array -----
        // Initialize "helper" array
        for (int i = low; i <= high; i++) helper[i] = array[i];

        // Merge two sorted array
        int helperLeft = low, helperRight = mid + 1;
        int curr = low;
        // jump out when left pointer end
        while(helperRight <= high){
            array[curr++] = helperLeft <= mid && helper[helperLeft] < helper[helperRight] ?
                    helper[helperLeft++] : helper[helperRight++];
        }
        // compensate the array with the rest part of left half
        while(helperLeft <= mid)
            array[curr++] = helper[helperLeft++];
    }
};