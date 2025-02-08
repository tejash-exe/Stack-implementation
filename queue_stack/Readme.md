# 🚀 Stack Implementation in C++ (Queue-Based)

A dynamic Stack implementation in C++ using a **queue**, supporting various operations such as push, pop, reverse, sort, and more.

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
| Push      | O(n)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Top       | O(1)           | O(1)             |
| Size      | O(1)           | O(1)             |
| Empty     | O(1)           | O(1)             |
| Reverse   | O(n)           | O(n) (recurion stack)|
| Sort      | O(n log n)     | O(n)             |
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
```