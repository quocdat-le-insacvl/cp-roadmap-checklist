//
// Created by Night Fury on 10/5/2021.
//
#include <bits/stdc++.h>
#include "csv.hpp"

using namespace csv;

using namespace std;

const string open_box = "<ul><li>[ ] ", close_box = "</li></ul>";
//bool isNull = false;

void write_to_file(ostream &out, string_view s, int i) {
    if (i == 1 || i == 2 || i == 15) {
        out << s << " | ";
    } else if (i == 3 || i == 5 || i == 7 || i == 9 || i == 11 | i == 13) {
//        if (s == "") {
//            isNull = true;
//        } else {
//            isNull = false;
//            out << open_box;
//        }
        out << " [" << s << ']';
    } else if (i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14) {
        out << '(' << s << ")";
//        if (!isNull) {
//            isNull = false;
//            out << close_box;
//        }
    }
    if (i == 6 || i == 10 || i == 14) {
        out << " | ";
    }
    if (i == 2) {
       out << open_box << close_box << " | ";
    }
}

int main() {
    CSVReader reader("../run_results.csv");
    string header = "Id | Name | Done |  Resources | Problems | Code | Difficulty\n---|---|---|---|---|---|---|\n";
    vector <ofstream> list_file;
    ofstream math("../Math.md", ofstream::trunc);
    list_file.push_back(move(math));
    ofstream number_theory("../NumberTheory.md", ofstream::trunc);
    list_file.push_back(move(number_theory));
    ofstream graph_theory("../GraphTheory.md", ofstream::trunc);
    list_file.push_back(move(graph_theory));
    ofstream data_structure("../DataStructure.md", ofstream::trunc);
    list_file.push_back(move(data_structure));
    ofstream strings("../Strings.md", ofstream::trunc);
    list_file.push_back(move(strings));
    ofstream dp("../DP.md", ofstream::trunc);
    list_file.push_back(move(dp));
    ofstream geometry("../Geometry.md", ofstream::trunc);
    list_file.push_back(move(geometry));
    ofstream game_theory("../GameTheory.md", ofstream::trunc);
    list_file.push_back(move(game_theory));
    ofstream miscellaneous("../Miscellaneous.md", ofstream::trunc);
    list_file.push_back(move(miscellaneous));
    ofstream important_links("../ImportantLinks.md", ofstream::trunc);
    list_file.push_back(move(important_links));
    for (auto &os: list_file) os << header;
    int j = 0;
    for (CSVRow &row: reader) { // Input iterator
        vector<bool> used(list_file.size());
        j++;
//        cout << j << '|';
        int i = 0;
        for (CSVField &field: row) {
//            if (i == 0) cout << field.get<std::string_view>();
            int k;
            if (j <= 458 && j >= 454) k = 9;
            else if (433 <= j && j <= 453) k = 8;
            else if (427 <= j && j <= 432) k = 7;
            else if (341 <= j && j <= 426) k = 6;
            else if (312 <= j && j <= 340) k = 5;
            else if (285 <= j && j <= 311) k = 4;
            else if (217 <= j && j <= 284) k = 3;
            else if (117 <= j && j <= 216) k = 2;
            else if (56 <= j && j <= 116) k = 1;
            else if (1 <= j && j <= 55) k = 0;
            else {
                k = 10;
//                write_to_file(cout, field.get<string_view>(), i);
            }
            if (k != 10) {
                write_to_file(list_file[k], field.get<string_view>(), i);
                used[k] = true;
            }
            i++;
        }
        for (int z = 0; z < (int) used.size(); z++) {
            if (used[z]) list_file[z] << '\n';
        }
    }
    for (auto &os: list_file) os.close();
    return 0;
}
