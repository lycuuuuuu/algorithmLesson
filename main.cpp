#include <iostream>
#include "practice1_mergeSort.cpp" // 包含头文件
#include "practice1_heapSort.cpp"
#include "practice1_quickSort.cpp"
#include "getData.cpp"
#include "putData.cpp"
#include <cstdlib>   // 包含 rand() 和 srand()
#include <ctime>     // 包含 time()
#include <chrono>

//#define DATA_TEMP 1

//#define DATA_RANDOM 1
//
//#define DATA_ORDER 1
//
//#define DATA_REVERSED_ORDER 1

using namespace std;
using namespace chrono;



int main(){
#ifdef DATA_TEMP

    string fileName = "D:\\ClionProject\\data\\city_temperature.csv";

#elif DATA_RANDOM

    string fileName = "D:\\ClionProject\\data\\tourism_dataset.csv";

#elif DATA_ORDER

    string fileName = "D:\\ClionProject\\data\\temp_order.csv";

#elif DATA_REVERSED_ORDER
    string fileName = "D:\\ClionProject\\data\\temp_reOrder.csv";

#endif

    vector<double> Data_quick = getData(fileName);
    vector<double> Data_merge = getData(fileName);
    vector<double> Data_heap = getData(fileName);



    /* 快排 */
    auto start_quick = high_resolution_clock ::now();

    quickSort(Data_quick.data(), 1, Data_quick.size());

    auto end_quick = high_resolution_clock ::now();

    auto time_quick = duration_cast<microseconds>(end_quick - start_quick);

    cout << "quickSort run time : " << time_quick.count() << endl;







    /* 归并排序 */
    auto start_merge = high_resolution_clock ::now();

    mergeSort(Data_merge.data(), 1, Data_merge.size());

    auto end_merge = high_resolution_clock ::now();

    auto time_merge = duration_cast<microseconds>(end_merge - start_merge);

    cout << "mergeSort run time : " << time_merge.count() << endl;





    /* 堆排序 */
    auto start_heap = high_resolution_clock ::now();

    mergeSort(Data_heap.data(), 1, Data_heap.size());

    auto end_heap = high_resolution_clock ::now();

    auto time_heap = duration_cast<microseconds>(end_heap - start_heap);

    cout << "heapSort run time : " << time_heap.count() << endl;


    /* 存放排序后数据 */
#ifdef DATA_TEMP

    string newFileName_quick = "D:\\ClionProject\\data\\quickSort\\city_temperature_sorted.csv";
    putData(Data_quick, newFileName_quick, "data_sorted");


    string newFileName_merge = "D:\\ClionProject\\data\\mergeSort\\city_temperature_sorted.csv";
    putData(Data_merge, newFileName_merge, "data_sorted");

    string newFileName_heap = "D:\\ClionProject\\data\\heapSort\\city_temperature_sorted.csv";
    putData(Data_heap, newFileName_heap, "data_sorted");

#elif DATA_RANDOM

    string newFileName_quick = "D:\\ClionProject\\data\\quickSort\\random_sorted.csv";
    putData(Data_quick, newFileName_quick, "data_sorted");


    string newFileName_merge = "D:\\ClionProject\\data\\mergeSort\\random_sorted.csv";
    putData(Data_merge, newFileName_merge, "data_sorted");

    string newFileName_heap = "D:\\ClionProject\\data\\heapSort\\random_sorted.csv";
    putData(Data_heap, newFileName_heap, "data_sorted");

#elif DATA_ORDER

    string newFileName_quick = "D:\\ClionProject\\data\\quickSort\\order_sorted.csv";
    putData(Data_quick, newFileName_quick, "data_sorted");


    string newFileName_merge = "D:\\ClionProject\\data\\mergeSort\\order_sorted.csv";
    putData(Data_merge, newFileName_merge, "data_sorted");

    string newFileName_heap = "D:\\ClionProject\\data\\heapSort\\order_sorted.csv";
    putData(Data_heap, newFileName_heap, "data_sorted");

#elif DATA_REVERSED_ORDER
    string newFileName_quick = "D:\\ClionProject\\data\\quickSort\\reOrder_sorted.csv";
    putData(Data_quick, newFileName_quick, "data_sorted");


    string newFileName_merge = "D:\\ClionProject\\data\\mergeSort\\reOrder_sorted.csv";
    putData(Data_merge, newFileName_merge, "data_sorted");

    string newFileName_heap = "D:\\ClionProject\\data\\heapSort\\reOrder.csv";
    putData(Data_heap, newFileName_heap, "data_sorted");

#endif



    return 0;
}