#ifndef problems_h
#define problems_h

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <stdexcept>
using namespace std;


int safeAccess(vector<int>& v, int index) {
    try {
        return v.at(index);
    } catch (const out_of_range& e) {
        cout << "Index out of range!" << endl;
        return -1;
    }
}


template <typename T, typename U>
class PairHolder {
private:
    T first;
    U second;

public:
    PairHolder(T f, U s) : first(f), second(s) {}
    
    T get_first() {
        return first;
    }
    
    U get_second() {
        return second;
    }
    
    bool isSame(const PairHolder<T, U>& other) {
        return (first == other.first && second == other.second);
    }
};

// Task 3
bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    
    return st.empty();
}

queue<int> unionQueues(queue<int> q1, queue<int> q2) {
    queue<int> result;
    
    while (!q1.empty()) {
        result.push(q1.front());
        q1.pop();
    }
    
    while (!q2.empty()) {
        result.push(q2.front());
        q2.pop();
    }
    
    return result;
}

#endif // problems_h
