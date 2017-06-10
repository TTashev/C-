#include <iostream>
#include <stdlib.h>
#include <stack>
#include <set>
#include <queue>

using namespace std;

int main()
{
    int MineralsToBeCollected, CommandCenterX, CommandCenterY, N;
    cin >> MineralsToBeCollected;
    cin >> CommandCenterX >> CommandCenterY;
    cin >> N;
    multiset<int> Minerals;
    int MineralX, MineralY, time;
    for(int i = 0; i < N; i++)
    {
        cin >> MineralX >> MineralY;
        time = abs(CommandCenterX - MineralX) + abs(CommandCenterY - MineralY);
        Minerals.insert(time);
        if(i > MineralsToBeCollected)
        {
            Minerals.erase(--Minerals.end());
        }
    }
    int TotalTime = 0;
    int counter = 0;
    multiset<int>::iterator it;
    for ( it = Minerals.begin(); it != Minerals.end(); it++ )
    {
        if(counter == MineralsToBeCollected)
        {
            break;
        }
        int s = (*it);
        TotalTime += (*it);
        counter++;
    }
    TotalTime *= 2;
    cout << TotalTime << endl;
    return 0;
}
