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

vector<int> SlidingWindow(const string& T, int l) {
    int Tsize = T.length();
    std::vector<int> result;
    //for (int k = 0; k < Tsize - l; k++) {//every substring
        string p = T.substr(0, l);//k or 0
        cout << p << endl;
        for (int i = 0; i < Tsize - l + 1; i++) {//k or 0
            string s = T.substr(i, l);
            cout << i << " :" << s << endl;
            int distance = 0;
            for (int j = 0; j < l; j++) {
                distance += (p[j] != s[j]) ? 1 : 0;
            }
            result.push_back(distance);
        }
    //}
    return result;
}

int main() {
    int l = 4; //4, 8, 16, 32, 64

    //string filename = "dna_500M.txt"; // 檔案名稱
    //ifstream infile(filename);       // 以讀取模式打開檔案

    //// 檢查檔案是否成功打開
    //if (!infile) {
    //    cerr << "無法打開檔案 " << filename << endl;
    //    return 1;
    //}

    //stringstream buffer;
    //buffer << infile.rdbuf();  // 將檔案內容讀入到 stringstream 中

    //string T = buffer.str();  // 將 stringstream 中的內容轉換為 string
    //string atcgStr2 = T;

    string T = "GAGTCAGAGTA";
    int Tsize = T.length();
    double at = 0;
    int distance = 0;
    std::vector<int> result;
    for (int j = 0; j < 1; j++) {
        // 開始計時
        auto start = chrono::high_resolution_clock::now();
        // 計算漢明距離
        result = SlidingWindow(T,l);
        // 結束計時
        auto end = chrono::high_resolution_clock::now();
        // 計算經過的時間
        chrono::duration<double> duration = end - start;
        // 輸出結果
        /*cout << "漢明距離: " << distance << endl;
        cout << duration.count() << endl;*/
        at += duration.count();

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

    for (int i = 0; i < result.size(); ++i) {// one substring
        cout << result[i] << " ";
    }

    cout << endl;
    cout << "長度為 " << T.length()<< " L=" << l<< " time : " << at << endl;
    return 0;
}
