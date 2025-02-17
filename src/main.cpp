#include <DoubleLinkedList.hpp>
#include <string.h>

/*
 This function showcases the creation and manipulation of two double-linked lists:
 one containing integers and the other containing strings. The operations include
 inserting elements, deleting elements, reversing the list, and printing the list contents and size.
 */

int main() {
    
    /* Demonstrating operations on an integer list.*/

    jb::DoubleLinkedList<int> num_list;

    // Adding Nodes to the integer list
    num_list.insert_back(10);
    num_list.insert_back(20);
    num_list.insert_front(5);
    num_list.print(); ///< Out: 5 10 20

    num_list.insert_at_position(30,3);
    num_list.print(); ///< Out: 5 10 30 20

    num_list.reverse();
    num_list.print(); ///< Out: 20 30 10 5
    
    // Displaying the size of the list 
    std::cout << "List size: " << num_list.getSize() << std::endl;

    // Deleating elements from the integer list
    num_list.delete_element(3);
    num_list.print(); ///< Out: 20 30 5

    num_list.delete_front();
    num_list.print(); ///< Out: 30 5

    num_list.delete_back();
    num_list.print(); ///< Out: 30

    // Displaying the size of the list
    std::cout << "List size: " << num_list.getSize() << std::endl;

    /* Demonstrating operations on a string list. */ 

    jb::DoubleLinkedList<std::string> str_list;
    
    // Adding Nodes to the string list
    str_list.insert_front("One");
    str_list.insert_back("Two");
    str_list.insert_back("Four");
    str_list.print(); ///< Out: One Two Four

    str_list.insert_at_position("Three",3);
    str_list.print(); ///< Out: One Two Three Four

    str_list.reverse();
    str_list.print(); ///< Out: Four Three Two One

    std::cout << "List size: " << str_list.getSize() << std::endl;

    // Deleating elements from the string list
    str_list.delete_element(2);
    str_list.print(); ///< Out: Four Two One

    str_list.delete_front();
    str_list.print(); ///< Out: Two One

    str_list.delete_back();
    str_list.print(); ///< Out: Two

    return 0;
}
