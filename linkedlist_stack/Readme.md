# 🚀 Stack Implementation in C++ (Linked List)

A dynamic Stack implementation in C++ using a **linked list**, supporting various operations such as push, pop, reverse, sort, and more.

## 📜 Features
- 🔼 **Push** elements into the stack
- 🔽 **Pop** elements from the stack
- 🎯 **Check top** element
- 📏 **Get stack size**
- ❓ **Check if stack is empty**
- 🔄 **Reverse** the stack
- 📊 **Sort** the stack in ascending order
- 🗑️ **Clear** the stack
- 🖨️ **Print** all elements in the stack

## 🛠️ Usage

### 1️⃣ Initialization
```cpp
Stack s;
```

### 2️⃣ Push elements
```cpp
s.push(10);
s.push(20);
s.push(30);
```

### 3️⃣ Pop element
```cpp
s.pop();
```

### 4️⃣ Get top element
```cpp
cout << "Top element: " << s.top() << endl;
```

### 5️⃣ Get stack size
```cpp
cout << "Stack size: " << s.size() << endl;
```

### 6️⃣ Check if stack is empty
```cpp
cout << (s.empty() ? "Stack is empty!" : "Stack is not empty!") << endl;
```

### 7️⃣ Reverse stack
```cpp
s.reverse();
```

### 8️⃣ Sort stack (ascending order)
```cpp
s.sort();
```

### 9️⃣ Clear stack
```cpp
s.clear();
```

### 🔟 Print stack elements
```cpp
s.print();
```

## 💡 Time & Space Complexity
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push      | O(1)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Top       | O(1)           | O(1)             |
| Size      | O(1)           | O(1)             |
| Empty     | O(1)           | O(1)             |
| Reverse   | O(n)           | O(1)             |
| Sort      | O(n log n)     | O(1)             |
| Clear     | O(n)           | O(1)             |
| Print     | O(n)           | O(n)             |

## Feedback & Contributions 🙌
Feel free to fork the repository, report issues, or submit pull requests.
I welcome feedback and suggestions to improve the project!

## Connect with Me 🌟 

- **GitHub**: [My GitHub Profile](https://github.com/tejash-exe)  
- **LinkedIn**: [My LinkedIn Profile](https://www.linkedin.com/in/aditya-choudhary-31137b291/)  

Made with ❤️ by [Aditya](https://github.com/tejash-exe)

## Implementation 🔧
```cpp
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
```