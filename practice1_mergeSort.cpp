//
// Created by lyc on 2025/3/11.
//

#include"iostream"
#define MAX 1000000000
using namespace std;
/*
 * 实现三种分治排序算法
 * 归并、快排、堆排
 * 对比在不同数据场景下的计算效率
 * 从小到大排列
 */

/*
 * 归并排序
 */
void merge(double* data, int startLocation, int midLocation, int endLocation){
    /*
     * func: 归并, 将两个子数组(s - m, m - e)进行合并(两个子数组内部有序), 合并的同时按顺序排列
     * param: data整个待排数组; startLocation: s; midLocation: m; endLocation: e
     */
    double tempData[endLocation - startLocation + 1];   /* 临时数组, 存放合并后的数组 */

    double* ptr_sub1 = &data[startLocation-1];    /* 定义两指针指向两子数组首元素*/
    double* ptr_sub2 = &data[midLocation-1];

    bool inRange_1 = true, inRange_2 = true;

    for(int i = 0; i < endLocation - startLocation + 1; i++){


        double sub1_value = *ptr_sub1;  /* 定义两个局部变量暂时存储指针对应的值, 用来比较大小 */
        double sub2_value = *ptr_sub2;

        if(!inRange_1) sub1_value = MAX;    /* 当发现哪个数组到达边界后, 直接把对应局部变量置为很大的值, 以后的比较中它都占劣势 */
        if(!inRange_2) sub2_value = MAX;

        if(sub1_value <= sub2_value){
            /* 子数组1情况 */
            tempData[i] = sub1_value;    /* 小的先放进tempData, 记住两个子数组都是有序的, 因此这里可以这样做 */

            if(ptr_sub1 == &data[midLocation - 2])  /* 判断是否到达边界 */
                inRange_1 = false;

            ptr_sub1++;
        }

        else{
            /* 子数组2情况 */
            tempData[i] = *ptr_sub2;
            if(ptr_sub2 == &data[endLocation - 1])
                inRange_2 = false;
            ptr_sub2++;
        }
    }

    /* 归并好后, 将数据从tempData中转移到data */
    for(int j = 0; j < endLocation - startLocation + 1; j++){
        data[startLocation - 1 + j] = tempData[j];
    }

}

/**
 * @func  归并排序, 先把数组递归对半分, 然后再子数组排序
 * @param data 待排数组
 * @param startLocation 归并起始位置
 * @param endLocation   归并结束位置
 */
void mergeSort(double *data, int startLocation, int endLocation){


    if(startLocation < endLocation - 1) {

        int midLocation;
        if((endLocation + startLocation) % 2 == 0) {
            midLocation = (startLocation + endLocation) / 2;
        }
        else {
            midLocation = (startLocation + endLocation) / 2 + 1;    /* 对半分, 向上取整, midLocation代表着第二子数组的首元素位置 */
        }

        /* 分 */
        mergeSort(data, startLocation, midLocation - 1);
        mergeSort(data, midLocation, endLocation);

        /* 治 */
        merge(data, startLocation, midLocation ,endLocation);

    }

    merge(data, startLocation, endLocation, endLocation);

}
