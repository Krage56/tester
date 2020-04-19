#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main() {
    string name("./lagrange_tests/test");
    string type(".in");
    string type1(".out");
    ifstream my_answer, correct_answer;
    unsigned long long ans1 = 0, ans2 = 0;
    for(int i = 1; i <= 8; ++i){
        string temp = "./Cnk " + name + to_string(i) + type;
        FILE* tmp = popen(temp.c_str(), "r");
        pclose(tmp);
        temp = name + to_string(i) + type1;
        correct_answer.open(temp);
        my_answer.open("./answer.txt");
        correct_answer >> ans2;
        my_answer >> ans1;
        cout << name + to_string(i) << flush;
        if(ans1 == ans2){
            cout << " correct\n" << flush;
        }
        else{
            cout << " incorrect\n" << flush;
        }
        my_answer.close();
        correct_answer.close();
    }


    return 0;
}