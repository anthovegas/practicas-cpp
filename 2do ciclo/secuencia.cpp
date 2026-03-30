#include <iostream>
#include "secuencia.h"
using namespace std;

void encontrarSecuenciaImpar(int* arr, int n){
    int indices[100];
    int count = 0;
    
    for(int*p=arr; p<arr+n;p++){
        if(*p % 2 != 0){
            indices[count] = p - arr;
            count ++;
        }
    }
    if(count == 0){
        cout<<"No existe secuencia impar. "<<endl;
        return;
    }
    int dp[100] = {0};
    int prev[100];
    int max_len = 0;
    int max_index = -1;

    for(int i = 0; i<count; i++){
        dp[i] = 1;
        prev[i] = -1;
        for(int j = 0; j<i; j++){
            if(indices[i] - indices [j] > 1){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if(dp[i] > max_len){
            max_len = dp[i];
            max_index = i;
        }
    }
    int secuencia[100];
    int sec_len = 0;
    int actual = max_index;

    while(actual != -1){
        secuencia[sec_len] = indices[actual];
        sec_len++;
        actual = prev[actual];
    }

    for(int i=0; i<sec_len/2; i++){
        int temp = secuencia[i];
        secuencia[i] = secuencia[sec_len - 1 -i];
        secuencia[sec_len - 1 -i] = temp;
    }
    cout<<"La secuencia impar mas larga es: [";
    for(int i=0; i<sec_len; i++){
        cout << arr[secuencia[i]];
        if(i<sec_len - 1){
            cout <<", ";
        }
    }
    cout <<"]"<<endl;
}