//
// Created by lyc on 2025/3/11.
//

#include "iostream"
using namespace std;

/**
* 快速排序: 围绕枢轴划分为左右两子数组, 然后再选枢轴, 再划分, 递归下去
* 每次都选子数组的最后一个元素作为枢轴
* 退出条件: 前面没有比枢轴大的元素
*/

/**
 * @param data  待排数组
 * @param startLocation 子数组起始位置
 * @param endLocation   子数组结束位置
 */
void quickSort(double* data, int startLocation, int endLocation){

    if(startLocation < endLocation) {
        int pivotLocation = endLocation - 1;

        int count_lessThanPivot = -1;
        for (int i = startLocation - 1; i < endLocation; i++) {
            /*
             * 先找出小于枢轴的元素, 全部排列在前面, 如果有n个, 就将枢轴元素和第n+1个元素互换位置
             * */
            if (data[i] < data[pivotLocation]) {
                count_lessThanPivot++;
                swap(data[startLocation - 1 + count_lessThanPivot], data[i]);
            }
        }
        /* 上方的for循环结束后, 所有小于它的元素(假设有n个)全都排列在了data数组前n位 */
        swap(data[pivotLocation], data[startLocation - 1 + count_lessThanPivot + 1]);
        /* 此时枢轴左都小于它, 右都大于它 */
        /* 对左右子数组进行递归 */


        quickSort(data, startLocation, startLocation + count_lessThanPivot);


        quickSort(data, startLocation + count_lessThanPivot + 2, endLocation);
    }
}