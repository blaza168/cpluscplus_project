//
// Created by jan on 08.04.22.
//

#ifndef PROJECT_NEW_CONFIG_H
#define PROJECT_NEW_CONFIG_H


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class config {
private:
    map<string, string> m;

public:
    // constructors
    config() {};
    config(string filename);
    config(config &c);

    // methods
    void save(string filename);
    bool contains_key(string key);
    void insert(string key, string value);
    void update(string key, string value);
    void delete_key(string key);

    // operators
    string& operator[] (string i);
    config operator+(config& operand);
    friend ostream& operator<<(ostream& out, config& conf);

    // Destructor
    ~config() {
        this->m.clear();
    }
};


#endif //PROJECT_NEW_CONFIG_H
