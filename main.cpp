#include <iostream>
#include "practice1_mergeSort.cpp" // 包含头文件
#include "practice1_heapSort.cpp"
#include "practice1_quickSort.cpp"
#include <cstdlib>   // 包含 rand() 和 srand()
#include <ctime>     // 包含 time()
#include <chrono>

using namespace std; // 方便使用 cout
using namespace chrono;

//int main() {
//    // 随机生成很大的数组进行测试
//    const int arraySize = 1000; // 数组大小
//    double Data[arraySize];
//
//    // 初始化随机数种子
//    srand(time(0)); //  time(0) 返回当前时间，作为随机数种子
//
//    for (int i = 0; i < arraySize; ++i) {
//        Data[i] = rand() % 1000; // 生成 0 到 999 之间的随机整数，并转换为 double
//    }
//
//    auto start = high_resolution_clock ::now();
//
//    mergeSort(Data, 1, arraySize);  // 注意这里的索引
//
//    auto end = high_resolution_clock ::now();
//
//    auto time = duration_cast<microseconds>(end - start);
//
//    cout << "After sorting: ";
//    for (int i = 0; i < arraySize; ++i) {
//        cout << Data[i] << " ";
//    }
//    cout << endl;
//    cout << "mergeSort run time : " << time.count() << "ms" <<endl;
//
//    return 0;
//}


//int main(){
//    // 随机生成 100 个整数进行测试
//    const int arraySize = 100;
//    double Data[arraySize];
//
//    // 初始化随机数种子
//    srand(time(0));
//
//    // 生成 0 到 999 之间的随机整数
//    for (int i = 0; i < arraySize; ++i) {
//        Data[i] = rand() % 1000;
//    }
//
//
//    auto start = high_resolution_clock :: now();
//
//    heapSort(Data, arraySize); // 传递数组和大小
//
//    auto end = high_resolution_clock :: now();
//    auto time = duration_cast<microseconds>(end - start);
//

//    cout << "After sorting: "; // 打印排序后所有元素
//    for (int i = 0; i < arraySize; ++i) {
//        cout << Data[i] << " ";
//    }
//    cout << endl;
//
//    // (可选) 验证排序结果
//    bool isSorted = true;
//    for (int i = 1; i < arraySize; ++i) {
//        if (Data[i] > Data[i - 1]) { // 检查是否非递减
//            cout << "this location is err: " << i << endl;
//            isSorted = false;
//            break;
//        }
//    }
//
//    if (isSorted) {
//        cout << "The array is sorted correctly." << endl;
//    } else {
//        cout << "The array is NOT sorted correctly!" << endl;
//    }
//
//    cout << "heapSort run time : " << time << endl;

//    return 0;
//}


//int main(){
//        // 随机生成 100 个整数进行测试
//    const int arraySize = 100;
//    double Data[arraySize];
//
//    // 初始化随机数种子
//    srand(time(0));
//
//    // 生成 0 到 999 之间的随机整数
//    for (int i = 0; i < arraySize; ++i) {
//        Data[i] = rand() % 1000;
//    }
//
//
//    auto start = high_resolution_clock ::now();
//
//    quickSort(Data, 1, arraySize); // 传递数组和大小
//
//    auto end = high_resolution_clock ::now();
//    auto time = duration_cast<microseconds>(end - start);
//
//    cout << "After sorting: "; // 打印排序后所有元素
//    for (int i = 0; i < arraySize; ++i) {
//        cout << Data[i] << " ";
//    }
//    cout << endl;
//
//    // (可选) 验证排序结果
//    bool isSorted = true;
//    for (int i = 1; i < arraySize; ++i) {
//        if (Data[i] < Data[i - 1]) { // 检查是否非递减
//            cout << "this location is err: " << i << endl;
//            isSorted = false;
//            break;
//        }
//    }
//
//    if (isSorted) {
//        cout << "The array is sorted correctly." << endl;
//    } else {
//        cout << "The array is NOT sorted correctly!" << endl;
//    }
//
//
//    cout << "quickSort run time : " << time.count() << endl;
//
//    return 0;
//
//}