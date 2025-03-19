#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input;
    int number;
    while(cin>>number){
        input.push_back(number);
    }

    for(auto numebr : input){
        cout<<numebr<<", ";
    }
}