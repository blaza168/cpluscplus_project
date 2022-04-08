//
// Created by jan on 08.04.22.
//

#ifndef PROJECT_NEW_DATA_H
#define PROJECT_NEW_DATA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class data {
    string key;
    string value;

public:
    data() {

    }
    data(string key, string value) {
        this->key = key;
        this->value = value;
    }
    string& get_key() {
        return this->key;
    }
    string& get_value() {
        return this->value;
    }

    void set_key(string key) {
        this->key = key;
    }
    void set_value(string value) {
        this->value = value;
    }

    friend ostream& operator << (ostream& out, data& data) {
        out << data.key << ":" << data.value;
        return out;
    }
};


#endif //PROJECT_NEW_DATA_H
