#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    srand(time(nullptr));

    int n = 10;
    vector<int> service_time(n);
    for (int i = 0; i < service_time.size(); i++) {
        service_time[i] = rand() % 100 + 20;
        cout << service_time[i] << ends;
    }
    cout << endl;

    vector<int> wait_time(n);
    int curr_time = 0;
    for (int i = 0; i < wait_time.size(); i++) {
        if (curr_time <= 60 * i) {
            wait_time[i] = 0;
            curr_time = 60 * i + service_time[i];
        }
        else {
            wait_time[i] = curr_time - 60 * i;
            curr_time += service_time[i];
        }
    }

    for (int t: wait_time) {
        cout << t << ends;
    }
    cout << endl;

    int min_service_time = INT_MAX;
    int min_service_time_index = -1;
    int max_wait_time = -1;
    int max_wait_time_index = -1;
    for (int i = 0; i < n; i++) {
        if (service_time[i] < min_service_time) {
            min_service_time = service_time[i];
            min_service_time_index = i;
        }
        if (wait_time[i] > max_wait_time) {
            max_wait_time = wait_time[i];
            max_wait_time_index = i;
        }
    }
    cout << min_service_time_index << ends << min_service_time << endl;
    cout << max_wait_time_index << ends << max_wait_time << endl;

    return 0;
}
