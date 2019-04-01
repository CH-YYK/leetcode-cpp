#include <vector>
#include <utility>
using namespace std;

class MyCalendarTwo {
    vector<pair<int,int>> calendar;
    vector<pair<int,int>> overlapping;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for(auto i : overlapping) {
            if(start < i.second && end > i.first) return false;
        }

        for(auto i : calendar) {
            if(start < i.second && end > i.first) {
                overlapping.push_back(pair<int, int>(max(start, i.first), min(end, i.second)));
            }
        }
        calendar.push_back(pair<int,int>(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */