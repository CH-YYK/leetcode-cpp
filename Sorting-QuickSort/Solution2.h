#include <vector>

using namespace std;

template <class T> // template to swap values in the vector
void test_swap(T &x, T &y){
    T tmp = x;
    x = y;
    y = tmp;
}

class Solution2 {
public:
    void quickSort(vector<int> &array) {
        quickSort(array, 0, (int)array.size()-1);
    }

    void quickSort(vector<int> &array, int left, int right) {
        if(left < right) {
            int pivot = partition(array, left, right);
            quickSort(array, left, pivot-1);
            quickSort(array, pivot+1, right);
        }
    }

    int partition(vector<int> &array, int left, int right) {
        // use the last index as pivot
        int pivot = array[right];
        int i = left;

        // i will stop at every element that greater than pivot
        for(int j = left; j < right; j++)
            if(array[j] < pivot) test_swap(array[i++], array[j]);

        // move pivot value to the middle
        test_swap(array[i], array[right]);
        return i;
    }
};