#include <iostream>
#include <vector>
using namespace std;
#define ll long long


int main()
{
    string str = {"babaabbb"};
    vector<int> vec;
    vec.push_back(0);
    for(int i = 1; i < str.length(); i++){
        string s(str.begin() + i, str.end());
        int temp = 0;
        for(int j = 0; j < s.length(); j++){
            if(str[j] == s[j]){
                temp++;
            }
            else{
                break;
            }
        }
        vec.push_back(temp);
    }

    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
