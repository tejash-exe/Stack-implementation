#include <bits/stdc++.h>
using namespace std;

class Stack{
  private:
    queue<int> q;

    void reverseQueue(queue<int> &q){
        //Time complexity = O(n)
        //Space complexity = O(n) [due to recursion stack]

        //Base case
        if(q.empty()) return;

        int temp = q.front();
        q.pop();
        reverseQueue(q);
        q.push(temp);
    }
  
  public:
    Stack() = default;

    void push(int val){
        //Time complexity = O(n)
        //Space complexity = O(1)

        q.push(val);
        int n = q.size();

        for(int i = 0; i < n - 1; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    void pop(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(q.size() == 0){
            return;
        }

        q.pop();
    }

    int top(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(q.size() == 0){
            return -1;
        }

        return q.front();
    }

    int size(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        return q.size();
    }

    bool empty(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        return q.empty();
    }

    void reverse(){
        //Time complexity = O(n)
        //Space complexity = O(n) [due to recursion stack]

        reverseQueue(q);
    }

    void sort(){
        //Time complexity = O(nlogn)
        //Space complexity = O(n)

        vector<int> values;

        while(!q.empty()){
            values.push_back(q.front());
            q.pop();
        }

        std::sort(values.begin(), values.end());

        for(auto i : values){
            q.push(i);
        }
    }

    void clear(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        while(!q.empty()){
            q.pop();
        }
    }

    void print(){
        //Time complexity = O(n)
        //Space complexity = O(n)
        
        vector<int> v;

        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }

        for(int i = 0; i < v.size(); i++){
            q.push(v[i]);
        }

        for(int i = v.size() - 1; i >= 0; i--){
            cout << v[i] << " ";
        }

        cout << endl;
    }

    ~Stack() = default;
};

int main(){
    //INITIALIZE
    Stack s;

    //PUSH INTO STACK
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.print();
    
    //POP FROM STACK
    s.pop();

    //TOP ELEMENT
    cout << "Stack top element = " << s.top() << endl;

    //SIZE
    cout << "Stack size = " << s.size() << endl;

    //IS-EMPTY
    cout << (s.empty() ? "Stack is empty!" : "Stack is not empty!") << endl;

    //REVERSE
    s.reverse();
    s.print();

    //SORT IN ASCENDING ORDER (TOP IS MINIMUM)
    s.sort();
    s.print();

    //CLEAR STACK
    s.clear();

    //PRINT STACK
    s.print();
    return 0;
};