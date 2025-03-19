#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input;
    int number;
    while(cin >> number){
        input.push_back(number);
    }

    cin.clear(); // if any break occures clean it
    cin.ignore();

    for(auto numebr : input){
        cout<<numebr<<", ";
    }
}