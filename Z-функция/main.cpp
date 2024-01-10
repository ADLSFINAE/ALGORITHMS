#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n = str.size();
    int l = 0;
    int r = 0;

    vector<int> z(n, 0);

    for(int i = 1; i < n; i++){
        if(r >= i){
            if(z[i - l] < r - i + 1){
                z[i] = z[i - l];
            }
            else{
                z[i] = r - i + 1;
                while(z[i] + i < n && str[z[i]] == str[z[i] + i]){
                    z[i]++;
                }
            }
        }
        else{
            while(z[i] + i < n && str[z[i]] == str[z[i] + i]){
                z[i]++;
            }
        }
        if(r < i + z[i] - 1){
            l = i;
            r = i + z[i] - 1;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;

}
