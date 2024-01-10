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
    
    return z;
}
 
int main(){
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        
        string str = t + "$" + s + s;
        
        vector<int> v1 = func(str);
        int temp = -1;
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] == t.length()){
                temp = i - t.length() - 1;
                break;
            }
        }
        
        cout<<temp<<endl;
 
    }
 
}