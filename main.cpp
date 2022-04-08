#include <iostream>
#include "config.h"

using namespace std;

int main() {
    config config("/home/jan/Desktop/directory/school/4/cplusplus/project_new/files/input1.txt");
    cout << config;
    config.save("/home/jan/Desktop/directory/school/4/cplusplus/project_new/files/out1.txt");
}
