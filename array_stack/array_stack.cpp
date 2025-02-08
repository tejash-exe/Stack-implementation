#include <bits/stdc++.h>
using namespace std;

class Stack {
  private:
    int topIndex;
    vector<int> arr;

  public:
    Stack(){
        this -> topIndex = -1;
    }

    void push(int value){
        //Time complexity = O(1)
        //Space complexity = O(1)

        arr.push_back(value);
        topIndex++;
    }

    void pop(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(topIndex == -1){
            return;
        }

        arr.pop_back();
        topIndex--;
    }

    int top(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(this -> topIndex == -1){
            return -1;
        }

        return arr[this -> topIndex];
    }

    int size(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        return arr.size();
    }

    bool empty(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(topIndex == -1) return true;

        return false;
    }

    void reverse(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        if(topIndex == -1) return;

        int i = 0;
        int j = topIndex;
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    void sort(){
        //Time complexity = O(nlogn)
        //Space complexity = O(1)

        std::sort(arr.rbegin(), arr.rend());
    }

    void clear(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        while(arr.size() != 0){
            arr.pop_back();
        }
    }

    void print(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        for(auto i : arr){
            cout << i << " ";
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
}