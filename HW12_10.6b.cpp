#include <iostream>
#include <cstdio>
using namespace std;

struct Time{
  float time_[3];
};

Time set_time(){
  float h, m, s;
  cout << "Enter hours, minutes, seconds: " << ends;
  cin >> h >> m >> s;
  Time my_time;
  my_time.time_[0] = h;
  my_time.time_[1] = m;
  my_time.time_[2] = s;
  return my_time;
}

void get_time(Time time1){
  cout << "\n--- Time ---" << endl;
  cout << "Hours: " << time1.time_[0] << "\nMinutes: " << time1.time_[1] << "\nSeconds: " << time1.time_[2] << ends;
}

int main() {
  Time my_time = set_time();
  get_time(my_time);
}
