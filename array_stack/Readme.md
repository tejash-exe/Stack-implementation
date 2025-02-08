# 🚀 Stack Implementation in C++ (Arrays)

A simple Stack implementation in C++ using `vector`, supporting various operations such as push, pop, reverse, sort, and more.

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
| Print     | O(n)           | O(1)             |

## Feedback & Contributions 🙌
Feel free to fork the repository, report issues, or submit pull requests.
I welcome feedback and suggestions to improve the project!

## Connect with Me 🌟 

- **GitHub**: [My GitHub Profile](https://github.com/tejash-exe)  
- **LinkedIn**: [My LinkedIn Profile](https://www.linkedin.com/in/aditya-choudhary-31137b291/)  

Made with ❤️ by [Aditya](https://github.com/tejash-exe)

## Implementation 🔧
```cpp
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
```