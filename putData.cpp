//
// Created by lyc on 2025/3/12.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 函数：将 vector<double> 写入 CSV 文件（单列）
bool putData(const vector<double>& data, const string& filename, const string& header = "") {
    ofstream file(filename);

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "open failed: " << filename << endl;
        return false; // 返回 false 表示写入失败
    }

    // 写入标题行（可选）
    if (!header.empty()) {
        file << header << endl;
    }

    // 写入数据
    for (const double& value : data) {
        file << value << endl; // 每行写入一个 double 值
    }

    // 关闭文件
    file.close();

    cout << "put success: " << filename << endl;
    return true; // 返回 true 表示写入成功
}
