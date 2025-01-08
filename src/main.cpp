#include <DoubleLinkedList.hpp>
#include <string.h>

int main() {
    jb::DoubleLinkedList<int> num_list;

    // Adding elements
    num_list.insert_back(10);
    num_list.insert_back(20);
    num_list.insert_front(5);
    num_list.print(); //  5 10 20
    num_list.insert_at_position(30,3);
    num_list.print(); // 5 10 30 20

    num_list.reverse();
    num_list.print(); // 20 30 10 5
     // list size
    std::cout << "List size: " << num_list.getSize() << std::endl; // 4

    // deleating elements
    num_list.delete_element(3);
    num_list.print(); // 20 30 5

    num_list.delete_front();
    num_list.print(); // 30 5

    num_list.delete_back();
    num_list.print(); // 30

    // list size
    std::cout << "List size: " << num_list.getSize() << std::endl; // 1
    
    jb::DoubleLinkedList<std::string> str_list;
    str_list.insert_front("One");
    str_list.insert_back("Two");
    str_list.insert_back("Four");
    str_list.print(); //  One Two Four
    str_list.insert_at_position("Three",3);
    str_list.print(); // One Two Three Four

    str_list.reverse();
    str_list.print(); // Four Three Two One
     // list size
    std::cout << "List size: " << str_list.getSize() << std::endl; // 4

    // deleating elements
    str_list.delete_element(2);
    str_list.print(); // Four Two One

    str_list.delete_front();
    str_list.print(); // Two One

    str_list.delete_back();
    str_list.print(); // Two

    return 0;
}
