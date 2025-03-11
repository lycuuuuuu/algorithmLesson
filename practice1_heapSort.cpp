//
// Created by lyc on 2025/3/11.
//
#include "iostream"
#define MIN (-10000000)
using namespace std;

/*
 * 堆排序, 这里我选择大顶堆
 */

/**
 * @func  构建大顶堆, 递归实现, 第x个元素和2x、2x+1个元素进行比较, 最大者做父结点
 * @param data      待排序数组
 * @param location  当前父结点位置, 即第x个元素
 * @param size      传入数组的大小
 */
void makeMaxHeap(double *data, int location, int size){
    if(2 * location <= size){
        /* 当没有遍历到最后两片叶子时, 对子结点进行遍历 */
        makeMaxHeap(data, location * 2, size);

        if(2 * location + 1 <= size)
            /* 判断当前结点是否有右子结点, 有的话对其进行遍历 */
            makeMaxHeap(data, location * 2 + 1, size);

        else{
            /* 当前父结点只有左子结点的情况 */
            if(data[location - 1] < data[2 * location -1])
                /* 如果父结点小于左子结点, 交换 */
                swap(data[location-1], data[2 * location - 1]);
                return;
        }

        /* 对于正常结点（左右孩子都在），找出最大结点做父结点 */
        double max = data[location -1];
        int whoIsMax = 1;   /*  1: 父结点最大; 2: 左子结点最大; 3: 右子结点最大  */

        if(data[2 * location - 1] > max) { max = data[2 * location - 1]; whoIsMax = 2; }
        if(data[2 * location] > max) { max = data[2 * location]; whoIsMax = 3; }

        switch (whoIsMax) {
            case 2: {
                swap(data[location - 1], data[2 * location -1]);
                break;
            }
            case 3: {
                swap(data[location - 1], data[2 * location]);
                break;
            }
        }
    }
}



/**
 * func: 堆排序, 一直构造大顶堆, 然后取首元素(当前最大值)放入临时数组
 * @param data  待排数组
 * @param size  数组大小
 */
void heapSort(double *data, int size){
    double tempData[size];  /* 临时数组用来存放结果 */

    for(int i = 0; i < size; i++){
        makeMaxHeap(data, 1, size);
        tempData[i] = data[0];

        /* 此时data[0]的元素没用了, 用一个极小的值替代 */
        data[0] = MIN;
    }

    /* 排好序后, 将结果放回data */
    for(int j = 0; j < size; j++){
        data[j] = tempData[j];
    }
}