#include <DoubleLinkedList.hpp>
#include <iostream>
#include <string.h>

int main() {
    jb::DoubleLinkedList<int> list;

    // Adding elements
    list.insert_back(10);
    list.insert_back(20);
    list.insert_front(5);
    list.print(); //  5 10 20
    list.insert_at_position(30,3);
    list.print(); // 5 10 30 20

    list.reverse();
    list.print(); // 20 30 10 5
     // list size
    std::cout << "List size: " << list.getSize() << std::endl; // 4

    // deleating elements
    list.delete_element(3);
    list.print(); // 20 30 5

    list.delete_front();
    list.print(); // 30 5

    list.delete_back();
    list.print(); // 30

    // list size
    std::cout << "List size: " << list.getSize() << std::endl; // 1
    
    jb::DoubleLinkedList<std::string> str_list;
    str_list.insert_front("one");
    str_list.print();

    return 0;
}
