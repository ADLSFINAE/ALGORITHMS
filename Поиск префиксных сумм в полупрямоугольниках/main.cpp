#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    ++n;
    ++m;
 
    vector<vector<int>> mx(n, vector<int>(m, 0));
 
	//Итеративный подсчет префиксных сумм
    for(int y = 1 ; y < n; ++y){
        for(int x = 1 ; x < m; ++x)
        {
            int val;
            std::cin >> val;
            mx[y][x] = val + mx[y - 1][x] + mx[y][x - 1] - mx[y - 1][x - 1];
        }
    }
    
	//Вывод
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<mx[i][j]<<" ";
        }
        cout<<endl;
    }
        
    int k;
    cin>>k;
    int a, b, c, d;
    for(int i = 0; i < k; ++i)
    {
        cin >> b >> a >> d >> c;
		//Отрезочная формула для двумерного случая 
        cout << mx[d][c] + mx[b - 1][a - 1] - mx[d][a - 1] - mx[b - 1][c] << "\n";
    }
 
    return 0;
}