# Stack Implementation 🚀

## Overview 📌
This repository contains implementations of stack data structures using different approaches: arrays, linked lists, and queues. Each implementation is stored in a separate folder with its own README file explaining its functionality.

## Features ✨
- 📥 **Push (`push`)**
- 🗑️ **Pop (`pop`)**
- 🔝 **Top (`top`)**
- 📏 **Size (`size`)**
- ❓ **Check If Stack is Empty (`empty`)**
- 🔄 **Reverse Stack (`reverse`)**
- 🔢 **Sort Stack (`sort`)**
- 🧹 **Clear Stack (`clear`)**
- 🖨️ **Print Stack (`print`)**

## Implementations 📂
This repository contains three different implementations of a stack:

1. **Array-Based Stack** 📂 [`array_stack/`](array_stack/Readme.md)
2. **Linked List-Based Stack** 📂 [`linkedlist_stack/`](linkedlist_stack/Readme.md)
3. **Queue-Based Stack** 📂 [`queue_stack/`](queue_stack/Readme.md)

Each folder contains a README file explaining its respective implementation in detail.

## Time and Space Complexities ⏳

| Function   | Array_Stack (TC, SC) | LinkedList_Stack (TC, SC) | Queue_Stack (TC, SC) |
|------------|----------------------|---------------------------|----------------------|
| `push`     | O(1), O(1)           | O(1), O(1)                | O(n), O(1)           |
| `pop`      | O(1), O(1)           | O(1), O(1)                | O(1), O(1)           |
| `top`      | O(1), O(1)           | O(1), O(1)                | O(1), O(1)           |
| `size`     | O(1), O(1)           | O(1), O(1)                | O(1), O(1)           |
| `empty`    | O(1), O(1)           | O(1), O(1)                | O(1), O(1)           |
| `reverse`  | O(n), O(1)           | O(n), O(1)                | O(n), O(n) (recursion stack)|
| `sort`     | O(nlogn), O(1)       | O(nlogn), O(1)            | O(nlogn), O(n)       |
| `clear`    | O(n), O(1)           | O(n), O(1)                | O(n), O(1)           |
| `print`    | O(n), O(1)           | O(n), O(n)                | O(n), O(n)           |

## Usage 🛠️
```cpp
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
```

## Feedback & Contributions 🙌
Feel free to fork the repository, report issues, or submit pull requests.
I welcome feedback and suggestions to improve the project!

## Connect with Me 🌟 

- **GitHub**: [My GitHub Profile](https://github.com/tejash-exe)  
- **LinkedIn**: [My LinkedIn Profile](https://www.linkedin.com/in/aditya-choudhary-31137b291/)  

Made with ❤️ by [Aditya](https://github.com/tejash-exe)