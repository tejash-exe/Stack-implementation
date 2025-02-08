#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node* next;
    int value;

    Node(int val){
        this -> next = NULL;
        this -> value = val;
    }
};

class Stack{
  private:
    Node* head;
    int length;

    Node* findMid(Node* head){
        //Time complexity = O(n/2)
        //Space complexity = O(1)

        if(head == NULL) return head;

        Node* fast = head;
        Node* mid = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            if(fast != NULL){
                mid = mid -> next;
            }
        }

        return mid;
    }

    void merge(Node* &head1, Node* &head2){
        //Time complexity = O(n)
        //Space complexity = O(1)

        Node* dummy = new Node(-1);
        Node* temp3 = dummy;
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> value <= temp2 -> value){
                temp3 -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                temp3 -> next = temp2;
                temp2 = temp2 -> next;
            }
            temp3 = temp3 -> next;
        }

        if(temp1 != NULL){
            temp3 -> next = temp1;
        }

        if(temp2 != NULL){
            temp3 -> next = temp2;
        }

        head1 = dummy -> next;
        delete dummy;
    }

    void mergeSort(Node* &head){
        //Time complexity = O(nlogn)
        //Space complexity = O(1)

        //Base case
        if(head == NULL || head -> next == NULL){
            return;
        }

        //Find mid
        Node* mid = findMid(head);
        Node* head2 = mid -> next;
        mid -> next = NULL;

        //Sort left
        mergeSort(head);

        //Sort right
        mergeSort(head2);

        //Merge
        merge(head, head2);
    }
  
  public:
    Stack(){
        this -> head = NULL;
        this -> length = 0;
    }

    void push(int val){
        //Time complexity = O(1)
        //Space complexity = O(1)

        Node* node = new Node(val);
        node -> next = head;
        head = node;
        length++;
    }

    void pop(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(head == NULL){
            return;
        }

        Node* temp = head;
        head = head -> next;
        delete temp;
        length--;
    }

    int top(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(head == NULL){
            return -1;
        }

        return head -> value;
    }

    int size(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        return this -> length;
    }

    bool empty(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(head == NULL){
            return true;
        }

        return false;
    }

    void reverse(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL){
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    void sort(){
        //Time complexity = O(nlogn)
        //Space complexity = O(1)

        mergeSort(head);
    }

    void clear(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        while(head != NULL){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }

        length = 0;
    }

    void print(){
        //Time complexity = O(n)
        //Space complexity = O(n)

        vector<int> values;
        Node* temp = head;

        while(temp != NULL){
            values.push_back(temp -> value);
            temp = temp -> next;
        }

        for(int i = values.size() - 1; i >= 0; i--){
            cout << values[i] << " ";
        }

        cout << endl;
    }

    ~Stack(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        clear();
    }
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