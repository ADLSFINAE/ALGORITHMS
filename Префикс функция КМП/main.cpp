#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    vector<int> p(n, 0);

    for(int i = 1; i < n; i++){
        int j = p[i - 1];

        while(j > 0 && str[i] != str[j]){
            j = p[j - 1];
        }

        if(str[i] == str[j]){
            p[i] = j + 1;
        }
        else{
            p[i] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
