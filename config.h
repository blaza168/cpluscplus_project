//
// Created by jan on 08.04.22.
//

#ifndef PROJECT_NEW_CONFIG_H
#define PROJECT_NEW_CONFIG_H


#include "data.h"
#include <iostream>
#include <vector>

using namespace std;

class config {
private:
    vector<data> v;

public:
    // constructors
    config(string filename);
    config(config &c);

    // methods
    void save(string filename);
    bool contains_key(string key);

    // operators
    string& operator[] (string i);
    friend ostream& operator << (ostream& out, config& conf);

};


#endif //PROJECT_NEW_CONFIG_H
