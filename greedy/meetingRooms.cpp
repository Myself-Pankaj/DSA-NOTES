#include <bits/stdc++.h>
using namespace std;

class Data {
public:
    int startTime, endTime, pos;
    
    // Constructor
    Data(int s, int e, int p) {
        startTime = s;
        endTime = e;
        pos = p;
    }
};

// Comparator for sorting based on end time (and then position if tie)
bool comparator(Data a, Data b) {
    if(a.endTime == b.endTime) {
        return a.pos < b.pos;
    }
    return a.endTime < b.endTime;
}

class MeetingRoomProblem {
public:
    // Variation 1: Max meetings in one room
    int nMeetingOneRoom(vector<int> &startTime, vector<int> &endTime, int n) {
       
        vector<Data> meetings;
        
        for(int i = 0; i < n; i++) {
            meetings.push_back(Data(startTime[i], endTime[i], i+1));
        }
        vector<int>Order;
        // Sort by end time
        sort(meetings.begin(), meetings.end(), comparator);

        int count = 1; // Always select the first meeting
        int endLimit = meetings[0].endTime;
        Order.push_back(meetings[0].pos);
        for(int i = 1; i < n; i++) {
            if(meetings[i].startTime > endLimit) {
                count++;
                endLimit = meetings[i].endTime;
                Order.push_back(meetings[i].pos);
            }
        }
        
        return count;
    }
    
};
