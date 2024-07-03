## README: Sorting Algorithms Comparison

### Introduction

This project provides a comprehensive comparison of various sorting algorithms based on their time complexities. The algorithms studied include:

- Insertion Sort
- Merge Sort
- Quick Sort (randomized pivot)
- Quick Sort (last element pivot)
- Heap Sort
- Radix Sort
- Stooge Sort

The time complexities are evaluated both theoretically and experimentally by measuring the average sorting times in C++ code with varying seeds of randomly generated data.

### Time Complexities

Theoretical time complexities for the algorithms are listed below:

| Sorting Algorithm                | Average Case Complexity | Worst Case Complexity |
|----------------------------------|-------------------------|-----------------------|
| Insertion Sort                   | O(n²)                   | O(n²)                 |
| Merge Sort                       | O(n log n)              | O(n log n)            |
| Quick Sort (Random Pivot)        | O(n log n)              | O(n²)                 |
| Quick Sort (Last Pivot)          | O(n log n)              | O(n²)                 |
| Heap Sort                        | O(n log n)              | O(n log n)            |
| Radix Sort                       | O(nk)                   | O(nk)                 |
| Stooge Sort                      | O(n².709)               | O(n².709)             |

### Methods

The experiments were conducted using the following steps:

1. **Compilation and Execution**:
   - The C++ code implementing the sorting algorithms was compiled using `g++` with optimization level `-Ofast`.
   - The code generated JSON files with sorting times, which were then converted to pandas DataFrames in Python.

2. **Data Analysis**:
   - The data was grouped and averaged using `pandas.DataFrame.groupby().mean()`.
   - The average sorting times were then unstacked and displayed in a table format.

3. **Visualization**:
   - The data was plotted using `pandas.DataFrame.plot()` to visualize the average sorting times.

### Results

The results showed the following:

- **Insertion Sort and Stooge Sort**: Both have significantly higher time complexities compared to other algorithms.
- **Heap Sort**: Among the algorithms with O(n log n) complexity, Heap Sort was found to be the slowest due to a higher constant factor.
- **Radix Sort**: Though having a complexity of O(nk), it performed similarly to O(n log n) algorithms for the tested data range.

### Discussion

- **High Complexity Algorithms**: Insertion Sort and Stooge Sort were the least efficient.
- **Heap Sort**: Although theoretically similar to other O(n log n) algorithms, it showed slower performance due to a larger constant factor.
- **Radix Sort**: The time complexity O(nk) was similar to O(n log n) in practical tests, due to the digit range of the test data (0 to MAXINT_32).

### Conclusion

This project measured and compared the average sorting times of various algorithms, validating their theoretical time complexities with experimental data. The findings illustrate the practical performance of these sorting algorithms and highlight the impact of their constant factors and input characteristics on their efficiency.

### Files

- `sorting_algorithms.cpp`: C++ implementation of the sorting algorithms.
- `results.json`: JSON file containing the sorting times.
- `analysis.py`: Python script for data analysis and visualization using pandas.

### How to Run

1. **Compile the C++ code**:
   ```bash
   g++ -Ofast sorting_algorithms.cpp -o sorting_algorithms
   ```
2. **Run the executable to generate the JSON results**:
   ```bash
   ./sorting_algorithms
   ```
3. **Analyze and plot results using the Python script**:
   ```bash
   python analysis.py
   ```

### Dependencies

- **C++ Compiler**: g++
- **Python Libraries**: pandas, matplotlib

This README provides an overview of the project, including its purpose, methods, results, and instructions for replication. The focus is on understanding the performance and efficiency of different sorting algorithms through both theoretical analysis and experimental validation.
