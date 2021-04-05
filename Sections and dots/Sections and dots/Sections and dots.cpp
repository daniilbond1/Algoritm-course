#include <iostream>
#include <utility>
#include <vector>
#include <algorithm> 
using namespace std;

typedef pair <int, int> Segment;


vector <int> get_covering_set(std::vector <Segment> segments) {
    vector <int> result;  
    sort(segments.begin(), segments.end());
    int  min_second = segments[0].second;

    for (int i = 0;i < segments.size();i++) {

        if (segments[i].second <= min_second) {
            min_second = segments[i].second;
        }
        if (segments[i].first > min_second||i== segments.size()-1) {
                result.push_back(min_second);
                if (segments[i].first > min_second && i == segments.size() - 1) {
                    result.push_back(segments[i].first);
                }
            min_second = segments[i].second;
        }
    }

    return result;
}

int main(void) {
    int segments_count;
    cin >> segments_count;
    vector <Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector <int> points = get_covering_set(segments);
    cout << points.size() << endl;
    for (size_t i = 0; i < points.size(); i++) {
        cout << points[i] << " ";
    }
    cout << endl;
}