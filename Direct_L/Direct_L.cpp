#include <iostream>
#include <chrono>
#include <string>

#include <fstream>
#include <sstream>

#include <vector>
using namespace std;

// 計算簡易漢明距離
int hammingDistance(const string& str1, const string& str2) {

    int distance = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        distance += (str1[i] != str2[i]) ? 1 : 0;
    }
    return distance;
}

void SlidingWindow(const string& T,int *result, int l) {
    int Tsize = T.length();
    //for (int k = 0; k < Tsize - l; k++) {//every substring
        string p = T.substr(0, l);//k or 0
        //cout << p << endl;
        for (int i = 0; i < Tsize - l + 1; i++) {//k or 0
            string s = T.substr(i, l);
            //cout << i << " :" << s << endl;
            int distance = 0;
            for (int j = 0; j < l; j++) {
                distance += (p[j] != s[j]) ? 1 : 0;
            }
            result[i]=distance;
        }
    //}
}

int main() {
    // 開始計時
    auto sw = chrono::high_resolution_clock::now();
    int l = 16; //4, 8, 16, 32, 64

    string filename = "dna_1G.txt"; // 檔案名稱
    ifstream infile(filename);       // 以讀取模式打開檔案

    // 檢查檔案是否成功打開
    if (!infile) {
        cerr << "無法打開檔案 " << filename << endl;
        return 1;
    }

    stringstream buffer;
    buffer << infile.rdbuf();  // 將檔案內容讀入到 stringstream 中

    string T = buffer.str();  // 將 stringstream 中的內容轉換為 string
    string atcgStr2 = T;

    //string T = "GAGTCAGAGTA";
    int Tsize = T.length();
    double at = 0;
    int distance = 0;
    int ans_sizes = Tsize - l + 1;
    int *result=new int [ans_sizes];
    
    // 結束計時
    auto ew = chrono::high_resolution_clock::now();

    chrono::duration<double> dur = ew - sw;
    double read= dur.count();
    for (int j = 0; j < 1; j++) {
        // 開始計時
        auto start = chrono::high_resolution_clock::now();
        // 計算漢明距離
        SlidingWindow(T, result,l);
        // 結束計時
        auto end = chrono::high_resolution_clock::now();
        // 計算經過的時間
        chrono::duration<double> duration = end - start;
        // 輸出結果
        /*cout << "漢明距離: " << distance << endl;
        cout << duration.count() << endl;*/
        at += duration.count();

        //std::ofstream outFile("output.txt");
        //// 檢查文件是否成功打開
        //if (outFile.is_open()) {
        //    // 將陣列的每個元素寫入文件，並用空格分隔
        //    for (int i = 0; i < ans_sizes; ++i) {
        //        outFile << result[i];
        //    }
        //    outFile.close(); // 完成後關閉文件
        //    std::cout << "陣列已成功寫入 output.txt 文件！" << std::endl;
        //}
        //else {
        //    std::cout << "無法打開文件。" << std::endl;
        //}

    }
    //cout << " T : " << T << endl;

    ////print 每個L-substring
    //int count = Tsize - l + 1;  // 初始換行間隔為8
    //int index = 0;  // 用來跟蹤元素位置
    //while (index < result.size()) {
    //    // 打印 `count` 個元素
    //    for (int i = 0; i < count && index < result.size(); ++i) {
    //        std::cout << result[index] << " ";
    //        ++index;
    //    }

    //    std::cout << std::endl;  // 換行

    //    // 下一次的換行間隔遞減
    //    if (count > 1) {
    //        --count;
    //    }
    //}

    //for (int i = 0; i < ans_sizes; ++i) {// one substring
    //    cout << result[i] << " ";
    //}

    cout << endl;
    cout <<" L=" << l<< "Distance time : " << at << endl;
    cout <<" L=" << l<< "readfile time : " << read << endl;
    return 0;
}
