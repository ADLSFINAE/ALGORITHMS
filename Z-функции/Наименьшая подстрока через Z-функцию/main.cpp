#include <iostream>
#include <vector>
using namespace std;
 
vector<int> func(string str){
 
 
    int n = str.size();
    int l = 0;
    int r = 0;
 
    vector<int> z(n, 0);
 
    for(int i = 1; i < n; i++){
        if(r >= i){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(z[i] + i < n && str[z[i]] == str[z[i] + i]){
            z[i]++;
        }
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    /*for(int i = 0; i < n; i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;*/
    return z;
}
 
int main(){
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        vector<int> vec = func(str);
        int top = -1;
        for(int i = 0; i < vec.size(); i++){
            if(i + vec[i] == vec.size()){
                top = i + vec[i];
                for(int j = 0; j < i; j++){
                    cout<<str[j];
                }
                cout<<endl;
                break;
            }
        }
        if(top == -1){
            cout<<str<<endl;
        }
        
    }
 
}