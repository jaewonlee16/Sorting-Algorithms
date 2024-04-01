#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;
using std::chrono::system_clock;

bool check_sorted(int* arr, int n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void print_arr(int* arr, int n) {
    for (size_t i = 0; i < n; i++) {
        if (i) cout << ", ";
        cout << arr[i];
    }
    cout << endl;
}

int* gen_data(int n, int seed = 0) {
    int* arr = new int[n];
    mt19937 rs(seed);
    uniform_int_distribution<int> dist(0, INT32_MAX);

    for (size_t i = 0; i < n; i++) {
        arr[i] = dist(rs);
    }
    return arr;
}

// copy this template and implement your algorihtm
int* mysort(int* arr, int n) {
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    // implement your algorithm

    return sorted;
}

int* insertion_sort(int* arr, int n) {
    int* sorted = new int[n];
    for (size_t i = 1; i < n; i++) {
        int current_number = arr[i];
        int idx = i - 1;
        while (idx > 0 && sorted[idx] > current_number){
            sorted[idx + 1] = sorted[idx];
            idx--;
        }
        sorted[idx + 1] = current_number;
    }

    return sorted;
}

int* merge_sort(int* arr, int n) {
    // implement your algorithm
    int* sorted = new int[n];

    // base case
    if (n == 1){
        sorted[0] = arr[0];
        return sorted;
    }

    int l = n / 2;
    int r = n - l;

    int* left_sorted = merge_sort(arr, l);
    int* right_sorted = merge_sort(arr + l, r);

    // merge
    int sorted_idx = 0;
    int left_sorted_idx = 0;
    int right_sorted_idx = 0;

    while (left_sorted_idx < l && right_sorted_idx < r){
        if (left_sorted[left_sorted_idx] < right_sorted[right_sorted_idx]){
            sorted[sorted_idx] = left_sorted[left_sorted_idx];
            left_sorted_idx++;
        }
        else{
            sorted[sorted_idx] = right_sorted[right_sorted_idx];
            right_sorted_idx++;
        }
        sorted_idx++;
    }

    while (left_sorted_idx < l){
        sorted[sorted_idx] = left_sorted[left_sorted_idx];
        left_sorted_idx++;
        sorted_idx++;
    }

    while (right_sorted_idx < r){
        sorted[sorted_idx] = right_sorted[right_sorted_idx];
        right_sorted_idx++;
        sorted_idx++;
    }

    // free
    delete[] left_sorted;
    delete[] right_sorted;

    return sorted;
}

int last_partition(int* arr, int n){
    int pivot = arr[n - 1];
    int temp;
  
    int i = -1;
    
    for(int j = 0; j < n; j++){
      if(arr[j] < pivot){
        i++;
        // swap
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    //swap
    temp = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = temp;

    return (i + 1);
}

int* quick_sort_rand_piv(int* arr, int n) {
    // implement your algorithm

    // allocate memory only at first call of function
    static bool first = true;
    if (first == true){
        int* sorted = new int[n];
        for (size_t i = 0; i < n; i++) {
            sorted[i] = arr[i];
        }
        arr = sorted;
        first = false;
    }

    // base case
    if (n == 0)
        return arr;

    // swap random and last pivot
    int random_idx = rand() % n;
    int tmp = arr[random_idx];
    arr[random_idx] = arr[n - 1];
    arr[n - 1] = tmp;

    int left_idx = last_partition(arr, n);

    quick_sort_rand_piv(arr, left_idx);
    quick_sort_rand_piv(arr + left_idx + 1, n - left_idx - 1);

    return arr;
}

int* quick_sort_last_piv(int* arr, int n) {
    // implement your algorithm

    // allocate memory only at first call of function
    static bool first = true;
    if (first == true){
        int* sorted = new int[n];
        for (size_t i = 0; i < n; i++) {
            sorted[i] = arr[i];
        }
        arr = sorted;
        first = false;
    }


    // base case
    if (n == 0)
        return arr;
        
    int left_idx = last_partition(arr, n);

    quick_sort_last_piv(arr, left_idx);
    quick_sort_last_piv(arr + left_idx + 1, n - left_idx - 1);

    return arr;
}

void MAX_HEAPIFY(int* arr, int i, int arr_size){
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    int largest = i;

    if ((L < arr_size) && (arr[L] > arr[largest]))
        largest = L;
    if ((R < arr_size) && (arr[R] > arr[largest]))
        largest = R;

    if (largest != i){
        // swap largest and i
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        MAX_HEAPIFY(arr, largest, arr_size);
    }
}

void BUILD_MAX_HEAP(int* arr, int arr_size){
    int largest_parent_idx = (arr_size - 2) / 2;
    for (int i = largest_parent_idx; i >= 0; i--){
        MAX_HEAPIFY(arr, i, arr_size);
    }
}

int* heap_sort(int* arr, int n) {
    // implement your algorithm
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    arr = sorted;
    BUILD_MAX_HEAP(arr, n);

    int temp;
    for (int i = n - 1; i > 0; i--){
        // swap 0 and i
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        MAX_HEAPIFY(arr, 0, i);
    }    

    return arr;
}

int* count_sort(int* arr, int n, int exp){
    int* sorted = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++){
        count[(arr[i]/exp) % 10]++;
    }

    // Prefix sum
    for (int i = 1; i < 10; i++){
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    return sorted;
}

int* radix_sort(int* arr, int n) {
    // implement your algorithm
    int exp = 1;
    int* sorted;
    for (int i = 0; i < 10; i++){
        sorted = count_sort(arr, n, exp);
        exp *= 10;
        if (i > 0)
            delete[] arr;
        arr = sorted;
    }
    return sorted;
}

int* stooge_sort(int* arr, int n) {
    // implement your algorithm

    // allocate memory only at first call of function
    static bool first = true;
    if (first == true){
        int* sorted = new int[n];
        for (size_t i = 0; i < n; i++) {
            sorted[i] = arr[i];
        }
        arr = sorted;
    }
    first = false;

    // base case
    if (n == 0)
        return arr; 
    
    // swap first and last
    if (arr[0] > arr[n - 1]){
        int temp = arr[n - 1];
        arr[n - 1] = arr[0];
        arr[0] = arr[n - 1];
    }

    // Recursion
    int one_third = n / 3;
    if (n > 2){
        stooge_sort(arr, n - one_third);
        stooge_sort(arr + one_third, n - one_third);
        stooge_sort(arr, n -  one_third);
    }
    
    return arr;
}

int main(void) {
    system_clock::time_point begin;
    double duration;
    bool is_sorted;
    int* arr;
    int n;

    // example of gen_data
    arr = gen_data(10, 2);
    cout << "Example: ";
    print_arr(arr, 10);
    delete[] arr;

    n = 10000000;
    begin = system_clock::now();
    arr = gen_data(n);
    duration = duration_cast<milliseconds>(system_clock::now() - begin).count() / 1000.0;
    cout << "Time for gen data: " << duration << "s" << endl;

    begin = system_clock::now();
    int* sorted = quick_sort_rand_piv(arr, n);
    duration = duration_cast<milliseconds>(system_clock::now() - begin).count() / 1000.0;
    cout << "Time for sort: " << duration << "s" << endl;

    is_sorted = check_sorted(sorted, n);
    cout << "Sorted(1: true, 0:false): " << check_sorted(sorted, n) << endl;
    if (!is_sorted) {
        cout << "Try the implementation again" << endl;
    }
    delete[] sorted;

    delete[] arr;
    return 0;
}