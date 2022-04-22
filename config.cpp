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
        pair<string, string> pair(key, line);
        this->m.insert(pair);
    }
}

config::config(config &c) {
    map<string, string>::iterator it;
    for (it = c.m.begin(); it != c.m.end(); ++it) {
        pair<string, string> pair(it->first, it->second);
        this->m.insert(pair);
    }
}

void config::save(string filename) {
    ofstream of(filename);
    if (!of.is_open())
        throw ("File is not writable");

    map<string, string>::iterator it;
    for (it = this->m.begin(); it != this->m.end(); it++) {
        of << it->first << "=" << it->second << endl;
    }
    of.close();
}

ostream &operator<<(ostream &out, config &conf) {
    map<string, string>::iterator it;
    for (it = conf.m.begin(); it != conf.m.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
    return out;
}

bool config::contains_key(string key) {
    return this->m.count(key);
}

string &config::operator[](string i) {
    if (!this->m.count(i)) {
        pair<string, string> pair(i, "");
        this->m.insert(pair);
    }
    return this->m.at(i);
}

config config::operator+(config &operand) {
    config sum;
    map<string, string>::iterator it;

    for (it = this->m.begin(); it != this->m.end(); it++) {
        pair<string, string> pair(it->first, it->second);
        sum.m.insert(pair);
    }
    for (it = operand.m.begin(); it != operand.m.end(); it++) {
        pair<string, string> pair(it->first, it->second);
        sum.m.insert(pair);
    }

    return sum;
}

void config::insert(string key, string value) {
    pair<string, string> pair(key, value);
    this->m.insert(pair);
}

void config::update(string key, string value) {
    if (!this->m.count(key))
        throw ("Key does not exist");
    string& val = this->m.at(key);
    val = value;
}

void config::delete_key(string key) {
    if (!this->m.count(key))
        throw ("Key does not exist");
    this->m.erase(key);
}
