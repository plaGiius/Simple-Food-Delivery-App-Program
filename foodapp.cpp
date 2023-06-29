#include<bits/stdc++.h>
using namespace std;
class foodapp{
    public:
        queue<priority_queue<pair<int, string> > > chain;
        priority_queue<pair<int, string> > last_req;
        foodapp(){
            chain.push(last_req);
        }
        void insert(int time, string restaurant);
        void delate();
        bool find(int time, string restaurant);
};

void foodapp::insert(int time, string restaurant){
    chain.back().push(make_pair(time, restaurant));
    return;
}

void foodapp::delate(){
    chain.front().pop();
    return;
}

bool foodapp::find(int time, string restaurant){
    priority_queue<pair<int, string> > cur = chain.front();
    if(cur.top().first==-time && cur.top().second==restaurant){
        return true;
    }
    return false;
}
int main(){
    foodapp swiggy;
    int n,i;
    cout << "Enter the number of requests: ";
    cin >> n;
    int time[n];
    string res[n];
    for(i=0; i<n; i++){
        cout << "Enter the estimated time:";
        cin >> time[i];
        cout << "Enter the name of restaurant:";
        cin >> res[i];
        swiggy.insert(-time[i],res[i]);
    }
    char ch;
    cout << "Do you wish to delete any number of requests? (y/n)";
    cin >> ch;
    if(ch=='y'){
        cout << "Enter the number of requests to be deleted: ";
        int m;
        cin >> m;
        while(m--){
            swiggy.delate();
        }
    }
    cout << "Do you wish to search for a restaurant and estimated time taken?";
    cin >> ch;
    if(ch=='y'){
        cout << "Enter the time and restaurant: ";
        int t;
        string re;
        cin >> t >> re;
        if(swiggy.find(t,re))   cout << "Found in our chain!";
        else cout << "Not found in our chain!\n";
    }
    cout << "Have a good day!";
    return 0;
}
