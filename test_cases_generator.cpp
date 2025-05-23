#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = {INPUT_VALUE};         
    const int MAX_VAL = 200000;

    mt19937 rng({SEED});       
    uniform_int_distribution<int> dist(1, MAX_VAL);

    cout<<N<<'\n';
    for(int i=0; i<N; ++i){
        int x,y;
        do{
            x=dist(rng);
            y=dist(rng);
        } while(__gcd(x, y) != 1);  
        cout<<x<<" "<<y<< '\n';
    }

    return 0;
}
