#include <iostream>
using namespace std;

int solution(int n){
    int sum = 0;
    int a = 0;
    while(n > 0){
        a = n % 10;
        sum +=a;
        n = n / 10;
    }
    return sum;
};

int punishmentNumber(int n){
    int result = 1;
    
    for(int i = 2; i <= n; i++){
        printf("%d\n", i);
        if( i == (solution(i*i))){
            result+=i*i;
        }
    }

    return result;
};


int main(){

    int n;
    cin >> n;
    cout << punishmentNumber(n) << endl;


  return 0;
}