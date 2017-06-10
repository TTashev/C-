#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Vector2D.h"

using namespace std;

int main()
{
    int NumberOfTowns;
    cin >> NumberOfTowns;
    vector<string> Towns;
    vector<double> TownCoordinatesX;
    vector<double> TownCoordinatesY;
    cin.ignore();
    string input;
    for(int i = 0; i < NumberOfTowns; i++)
    {
        getline(cin, input);
        int firstWhiteSpaceIndex = input.find(' ');
        string City = input.substr(0,firstWhiteSpaceIndex);
        int coordinateCount = 0;
        double x, y;
        x = y = 0;
        coordinateCount = -1;
        stringstream Coordinates(input);
        string word;
        while(Coordinates >> word)
        {
            istringstream num(word);
            if(coordinateCount < 1)
            {
                num >> x;
            }
            else
            {
                num >> y;
            }
            coordinateCount++;
        }
        Towns.push_back(City);
        TownCoordinatesX.push_back(x);
        TownCoordinatesY.push_back(y);
    }
    double DistanceOfClosestTowns = (double)INT_MAX;
    double CurrentDistanceOfClosestTowns = (double)INT_MAX;
    vector<string> ClosestTowns;
    for(int t = 0; t < Towns.size(); t++)
    {
        string CurrTown = Towns[t];
        for(int c = t + 1; c < Towns.size(); c++)
        {
            string SecondCurrTown = Towns[c];
            CurrentDistanceOfClosestTowns = sqrt(((TownCoordinatesX[c] - TownCoordinatesX[t]) * (TownCoordinatesX[c] - TownCoordinatesX[t])) + ((TownCoordinatesY[c] - TownCoordinatesY[t]) * (TownCoordinatesY[c] - TownCoordinatesY[t])));
            if(CurrentDistanceOfClosestTowns < DistanceOfClosestTowns)
            {
                DistanceOfClosestTowns = CurrentDistanceOfClosestTowns;
                if(ClosestTowns.empty())
                {
                    ClosestTowns.push_back(Towns[t] + "-" + Towns[c]);
                }
                else
                {
                    ClosestTowns.pop_back();
                    ClosestTowns.push_back(Towns[t] + "-" + Towns[c]);
                }
            }
        }
    }
    for(int a = 0; a < ClosestTowns.size(); a++)
    {
        cout << ClosestTowns[a] << endl;
    }
    return 0;
}
