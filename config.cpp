//
// Created by jan on 08.04.22.
//

#include <iostream>
#include <fstream>
#include "config.h"

using namespace std;

config::config(string filename) {
    ifstream file(filename);
    if (!file.is_open())
        throw ("File not found");

    string line;
    string delimeter = "=";
    while (getline(file, line)) {
        string key = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());
        data d(key, line);
        v.push_back(d);
    }
}

config::config(config &c) {
    vector<data>::iterator it;
    for (it = c.v.begin(); it != c.v.end(); ++it) {
        data d(it->get_key(), it->get_value());
        this->v.push_back(d);
    }
}

void config::save(string filename) {
    ofstream of(filename);
    if (!of.is_open())
        throw ("File is not writable");

    vector<data>::iterator it;
    for (it = this->v.begin(); it != this->v.end(); it++) {
        of << *it << endl;
    }
    of.close();
}

ostream &operator<<(ostream &out, config &conf) {
    vector<data>::iterator it;
    for (it = conf.v.begin(); it != conf.v.end(); it++) {
        cout << *it << endl;
    }
    return out;
}

bool config::contains_key(string key) {
    vector<data>::iterator it;
    for (it = this->v.begin(); it != this->v.end(); it++) {
        if (it->get_key() == key)
            return true;
    }
    return false;
}
