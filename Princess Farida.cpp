//https://www.spoj.com/problems/FARIDA/

#include <iostream> 
#include <algorithm> 
using namespace std;

int main() 
{
	long n,t;
	cin >> n;
	long gold[n];
	for(int i = 0; i < n; i++){
		cin >> t;
		long monsterGold[10000], mostGold[10000];
		for(int j = 0; j < t; j++){
			cin >> monsterGold[j];
		}
        mostGold[0] = monsterGold[0];
        if(mostGold[0] > monsterGold[1]){
            mostGold[1] = mostGold[0];
        }
        else{
            mostGold[1] = monsterGold[1];
        }
        for(int j = 2; j < t; j++){
            if(mostGold[j-1] > monsterGold[j] + mostGold[j-2]){
                mostGold[j] = mostGold[j-1];
            }
            else{
                mostGold[j] = monsterGold[j] + mostGold[j-2];
            }
        }
        gold[i] = mostGold[t-1];
    }
    for(int i = 0; i < n; i++){
        cout << "Case " << i+1 << ": " << gold[i] << endl;
    }
}
