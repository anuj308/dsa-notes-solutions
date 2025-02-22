#include <bits/stdc++.h>
using namespace std;
// ctrl shift b

void explainPair()
{
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}};

    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << arr[1].second << endl;
}

void explainVector()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // same as push_back but faster
    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.emplace_back(5, 6); // syntax is different

    vector<int> v1(5, 100); // 0 to 5 all index values are 100

    vector<int> v2(5); // size is 5 and values depend on container

    vector<int> v3(v2); // to copy v2 to v3

    cout << v1.back() << endl;

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    // auto - auto assiging like int,double etc
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it : v1)
    {
        cout << it << " ";
    }
    cout << endl;

    v1.erase(v1.begin() + 1); // will delete  1 index and reshuffle the vector

    v1.erase(v1.begin() + 2, v1.begin() + 4); // start , end

    v1.insert(v1.begin(), 300);       // insert 300 at 0 index
    v1.insert(v1.begin() + 1, 2, 10); // insert 10 10 at index 1 & 2

    cout << v1.size();
    v.pop_back(); // pop the front element

    v1.swap(v2);
    v1.clear(); // erase the entire vector

    cout << v.empty() << endl;
}

void explainList()
{
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);

    // ls.emplace_front();
    // rest are same as vector
}

void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    // rest are same as vector
}

void explainStack()
{
    // LIFO
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.emplace(4);

    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;

    stack<int> st1;
    st1.swap(st);
}

void explainQueue()
{
    // FIFO
    queue<int> q;
    q.push(1);    //{1}
    q.push(2);    // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;     //{1,2,9}
    cout << q.back();  // print 9
    cout << q.front(); // print 1

    q.pop();           //{2,9}
    cout << q.front(); // pirnt 2
}

void explainPriorityQueue()
{
    // max heap below
    priority_queue<int> pq;

    pq.push(5);  // {5}
    pq.push(2);  // {5,2}
    pq.push(8);  // {8,5,2}
    pq.push(10); // {10,8,5,2}

    cout << pq.top(); // print 10

    // size swap empty are same as others

    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     //{5}
    pq.push(2);     // {2,5}
    pq.push(8);     // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top(); // print 2
}

void explainSet()
{
    //  sorted and unique
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(4);  // {1,2,4}
    st.insert(3);  // {1,2,3,4}

    // begin(), end(), rbegin(), rend(), size(), empty() & swap() are same as others

    auto it = st.find(3); // return an iterator
    // {1,2,3,4}
    auto it = st.find(6); // retrun st.end() as 6 is not present in the set

    st.erase(4); // erase 4 & maintain the sorted order

    int c = st.count(1); // if 1 is there it will return 1 or 0

    auto it = st.find(3);
    st.erase(it); // can give iterator also

    // {1,2,3,4}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1,4}  (first,end)

    // lower_bound()  and upper_bound()

    // {1,2,4}
    auto it3 = st.lower_bound(2); // will return 2 iterator
    auto it3 = st.lower_bound(3); // will return 2 iterator as 3 is not there 2 is less than 3 and closest

    auto it4 = st.upper_bound(3);  // will retrun 4 iterator as 3 is not there and 4 is more than 3 and closest
}

void explainMultiSet(){
    // everything is same as set
    // only stores duplicate element also

    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1);// all 1's erased

    int cnt = ms.count(1);

    ms.erase(ms.find(1));// only a single one erased

    ms.erase(ms.find(1),ms.find(1)+2);

    // rest all function are same
}

void explainUnOrderedSet(){
    // unique and unOrder
    unordered_set<int> st;
    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above, it does not stores in any particular order it has a better complexity than set in most cases, except some when collision happen
}

void explainMap(){
    // unique key , store in key values which can be any data type
    // it stores unique keys in storted order
    map<int,int> mp;
    map<pair<int, int>, int> mpp;

    mp[1]=2;
    mp[3]=7;
    // mp.emplace({3,1});

    mp.insert({2,4});
    mpp[{1,2}] =10;

    // for(auto it : mpp){
    //     cout <<  it.second << " " << it.first << endl;
    // }

    cout << mp[1];

    auto it = mp.find(3);
    // cout << *(it).second;

    auto it1 = mp.find(5);

    auto it2 = mp.lower_bound(1);
    auto it3 = mp.upper_bound(3);

    // erase, swap, size, empty, are same as above

}

void explainMultiMap(){
    // everything same as map,only it can store multiple keys or duplicate keys
    // only mpp[key] cannot be used here
}

void explainUnorderedMap(){
    // unordered keys only difference
}
 

 bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // they are same
    if(p1.first > p2.first) return true;
    // if(p1.first < p2.first) return false; // or below same function
    return false;
 }
void explainExtra(){
    int n=10;
    int a[n];
    sort(a,a+n);
    sort(v.begin(), v.end());
    // a - [2,7,9,2,3,6]
    sort(a+2,a+4);

    sort(a, a+n, greater<int>);

    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    //sort it according to second element
    // if second element is same, then sort
    // if according to first element but in descending

    sort(a,a+n,comp); // comp our self written function

    int num = 7;
    int cnt = __builtin_popcount(); // it returns n of ones (1) in a binary digit

    long long cnt = __builtin_popcountll();

    string s = "123";
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(),s.end()));

    int maxi = *max_element(a,a+n);
}

int main()
{
    cout << "anuj";
    explainPair();
    explainVector();
    explainList();


    return 0;
}