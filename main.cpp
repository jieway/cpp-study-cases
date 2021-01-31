#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream ofs;
    ofs.open("test.txt",ios::out);

    ofs << "test" << endl;

    ofs.close();
    return 0;
}