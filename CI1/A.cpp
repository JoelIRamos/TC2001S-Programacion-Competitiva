// Several and Bus
// Autor: Joel Ramos - A01245083
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, pair<int, int>> iii;
typedef priority_queue<iii, vector<iii>, greater<iii>> pq;

// Function to find the bus that arrives first when Several is at the station
// Complexity: O(n)
int findBus(pq buses, int t){
    while (!buses.empty()){
        iii min = buses.top();
        buses.pop();
        // If the bus arrives after Several, return the bus 
        if (t <= min.first){
            return min.second.second;
        }// If not update the bus cycle
        else{
            buses.push(make_pair(min.first + min.second.first, min.second));
        }
    }
    throw runtime_error("Error in the inputs");
}

int main(){
    // n -> number of buses, t -> time Several arrives to the station 
    int n , t;
    cin >> n >> t;

    // min heap of buses, sructure of pairs <next arrival time, <interval, number of bus>>
    pq buses;
    
    // Read the arrival times of the buses
    for (int i=1; i<=n; i++) {
        // s -> arrival time of the bus, d -> interval between the buses 
        int s, d;
        cin >> s >> d;

        // Insert them to the vector
        buses.push(make_pair(s,make_pair(d, i)));
    }

    try{
        // The bus that arrives first when Several is at the station
    cout << findBus(buses, t) << endl;
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }
    
    return 0;
}
