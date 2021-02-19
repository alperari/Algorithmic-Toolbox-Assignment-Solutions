#include <iostream>
#include <vector>

using namespace std;
int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
    int counter = 0;
    int current = 0; 
    int global_index = 0;
    int flag = false;
    for (int i = 0;i < stops.size()-1; i++)
    {
        if (stops[i + 1] - stops[i] > tank)
        {
            return -1;
        }
    }
    //cout << "now you are at : " << current << endl;;

    while (current < dist)
    {
        flag = true;

        current += tank;
        //cout << "now you are at : " << current << endl;;

        for (int i = global_index; i < stops.size()&& flag; i++)
        {
            if (stops[i] > current)
            {
                flag = false;
                global_index = i - 1;
                current = stops[i - 1];
                counter++;
                //cout << "REFILL- you are at stop " << global_index << endl;
                //cout << "CURRENT BECAME " << current << endl;
            }
        }

    }
    return counter;

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
