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
    string p =T.substr(0, l);
    int Tsize=T.length();
    std::vector<int> result;
    cout << Tsize - l + 1 << endl;
    for (int i = 0; i < Tsize - l + 1; i++) {
        string s = T.substr(i, l);
        cout <<i<<" :" << s << endl;
        int distance = 0;
        for (int j = 0; j < l; j++) {
            distance += (p[j] != s[j]) ? 1 : 0;
        }
        result.push_back(distance);
    }
    return result;
}

int main() {
    int l = 4; // 8, 16, 32, 64

    //string filename = "dna_1G.txt"; // 檔案名稱
    //ifstream infile(filename);       // 以讀取模式打開檔案

    //// 檢查檔案是否成功打開
    //if (!infile) {
    //    cerr << "無法打開檔案 " << filename << endl;
    //    return 1;
    //}

    //stringstream buffer;
    //buffer << infile.rdbuf();  // 將檔案內容讀入到 stringstream 中

    //string atcgStr1 = buffer.str();  // 將 stringstream 中的內容轉換為 string
    //string atcgStr2 = atcgStr1;

    string T = "GAGTCAGAGTA";

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
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    //cout << "長度為 " << atcgStr1.length() << " time : " << at << endl;
    return 0;
}
