#include <iostream>
#include "config.h"

using namespace std;

int main() {
    config con("/home/jan/Desktop/directory/school/4/cplusplus/project_new/files/input1.txt");
    config c2("/home/jan/Desktop/directory/school/4/cplusplus/project_new/files/input2.txt");
    con["key5"] = "new key 5";
    c2.insert("insert_test", "value");
    c2.update("insert_test", "updated");

    config sum;
    sum = c2 + con;

    sum.save("/home/jan/Desktop/directory/school/4/cplusplus/project_new/files/out1.txt");
}
