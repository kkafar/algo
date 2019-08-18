#include <iostream>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <string> 
using namespace std;
 
struct point 
{
	string name; 
	int x, y;
	long long dlug = 0; 
 
	void cdlug() {
		dlug = pow(x, 2) + pow(y, 2);
	}
};
 
bool f (point a, point b)
{
	return (a.dlug < b.dlug);
}
int main()
{
	point a; 
	vector<point> v; 
	int cases, z; 
	cin >> z; 
	for (int j = 0; j < z; ++j) {
		cin >> cases;
		for (int i = 0; i < cases; ++i) {
			cin >> a.name >> a.x >> a.y;
			a.cdlug();
			v.push_back(a);
		}
		sort(v.begin(), v.end(), f); 
		for (vector<point>::iterator i = v.begin(); i != v.end(); ++i) {
			cout << (*i).name << " " << (*i).x << " " << (*i).y << endl;
		}
		v.clear(); 
		cout << endl;
	}
	return 0; 
} 
