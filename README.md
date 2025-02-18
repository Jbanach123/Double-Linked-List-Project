
# Double Linked List Library

The project "Double Linked List Library" is an implementation of a dynamic data structure known as a doubly linked list. Each node in the list contains data and pointers to both the previous and next elements, allowing easy traversal in both directions.

The library is designed as a universal template class in C++, enabling operations on any data type. It provides efficient list management with functions for adding, removing, and manipulating elements, offering versatility and flexibility in various applications.

Example Use Cases:
- Implementation of stacks and queues
- Navigation systems requiring forward and backward traversal
- Memory structures, such as circular buffers


## Project Structure:

The project consists of three files:

- DoubleLinkedList.hpp – Defines the template class DoubleLinkedList along with all its methods. Located in the include directory.
- main.cpp – A demonstration file showcasing the functionality of the DoubleLinkedList class. Located in the src directory.
- CMakeLists.txt – Configuration file for the CMake build system.

## Available Operations:
Adding Elements:
- At the beginning of the list (insert_front)
- At the end of the list (insert_back)
- At a specific position (insert_at_position)
Removing Elements:
- From the beginning of the list (delete_front)
- From the end of the list (delete_back)
- From a specific position (delete_element)
Auxiliary Operations:
- Displaying the list contents (print)
- Reversing the order of elements (reverse)
- Clearing all elements (clear)
- Getting the size of the list (getSize)

## Compilation and Execution Example:

In the project directory, create a build folder and navigate to it:

```bash
mkdir build  
cd build 
```

Configure the project using CMake:

```bash
cmake ..  
```

Compile the project:

```bash
mingw32-make  
```

Run the executable:

```bash
./ProjectExecutable  
```

