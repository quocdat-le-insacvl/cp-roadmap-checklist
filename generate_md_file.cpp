//
// Created by Night Fury on 10/5/2021.
//
#include <bits/stdc++.h>
//#include "csv.hpp"
#include "lazycsv.hpp"
//using namespace csv;

using namespace std;

int main() {
//    ifstream fi("../run_results.csv");
//    string s;
    lazycsv::parser parser{ "../run_results.csv" };
    for (const auto row : parser)
    {
        const auto [id, name, phone] = row.cells(0, 1, 4); // indexes must be in ascending order
    }
//    for (int i=0; i<5; i++) {
//        getline(fi, s);
//
//        cout << "|"<< s << "|\n";
//    }
//    CSVReader reader("example.csv");
//
//    for (CSVRow& row: reader) { // Input iterator
//        for (CSVField& field: row) {
//            // By default, get<>() produces a std::string.
//            // A more efficient get<string_view>() is also available, where the resulting
//            // string_view is valid as long as the parent CSVRow is alive
//            std::cout << field.get<>() << '\n';
//        }
//    }
    return 0;
}
