#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// 函数：将CSV文件的第二列读取为 double 数组
vector<double> getData(const string& filename) {
    vector<double> data;
    ifstream file(filename);
    string line;

    // 检查文件是否成功打开
    if (!file.is_open()) {
        cerr << "open failed: " << filename << endl;
        return data; // 返回空 vector
    }

    // 跳过标题行 (如果存在，可选)
    getline(file, line); // 如果文件有标题行，取消注释此行

    // 逐行读取文件
    while (getline(file, line)) {
        try {
            double temp = stod(line);
            data.push_back(temp);
        } catch (const invalid_argument& e) {
            cerr << "trans err: " << e.what() << " - row: " << line << endl;
            //可以选择忽略错误行或者采取其他错误处理方式
        } catch (const out_of_range& e) {
            cerr << "out of range: " << e.what() << " - row: " << line << endl;
            //可以选择忽略错误行或者采取其他错误处理方式
        }
    }

    // 关闭文件
    file.close();

    return data;
}