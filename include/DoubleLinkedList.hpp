#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#pragma once
#include <iostream>

namespace jb{

/**
 * @brief A template class representing double linked list.
 * 
 * @tparam T the type of data stored in nodes of the list.
 */
template <typename T>
class DoubleLinkedList {
private:
    /**
     * @brief Inner class representing a single node in doubly linked list.
     */
    class Node {
        public:
        T data;     ///< Data stored in the node.
        Node* prev; ///< Pointer to the previous node.
        Node* next; ///< Pointer to the next node.

        /**
         * @brief Constructs a Node with the given value.
         * 
         * @param value The value to be stored in the node.
         */
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* m_head;  ///< Pointer to the first element of the list.
    Node* m_tail;  ///< Pointer to the last element of the list.
    size_t m_size; ///< The number of elements in the list.

public:
    
    /**
     * @brief Construts an empty doubly linked list.
     */
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    
    /**
     * @brief Destroys the doubly linked list and frees allocated memory.
     */
    ~DoubleLinkedList() {
        clear();
    }
    
    /**
     * @brief Inserts an new Node at the front of the list.
     * 
     * @param value The value of the Node to be inserted.
     */
    void insert_front(const T& value) {
        Node* newNode = new Node(value);
        // If list is empty
        if (m_head == nullptr) {
            m_head = m_tail = newNode;
        } else {
            newNode->next = m_head;
            m_head->prev = newNode;
            m_head = newNode;
        }
        ++m_size;
    }

    /**
     * @brief Inserts an new Node at the end of the list.
     * 
     * @param value The value of the Node to be inserted.
     */
    void insert_back(const T& value) {
        Node* newNode = new Node(value);
        // If list is empty
        if (m_tail == nullptr) {
            m_head = m_tail = newNode;
        } else {
            newNode->prev = m_tail;
            m_tail->next = newNode;
            m_tail = newNode;
        }
        ++m_size;
    }
    /**
     * @brief Inserts a new Node at the specified list position.
     * 
     * 
     * @param value The value of the Node to be inserted.
     * @param position The position where the value should be inserted (1-based index).
     */
    void insert_at_position(const T& value, int position) {
        if (position < 1){
            std::cout<<"Position can't be lower than 1." << std::endl;
            return;
        }
        if (position == 1){
            insert_front(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = m_head;

        for (int i = 1; temp != nullptr && i < position -1; i++){
            temp = temp->next;
        }
        // Checking if position is not out of range
        if (temp == nullptr) {
            std::cout << "Position greater than length of the list." << std::endl;
            return;
        }
        
        // Adding new node at the specified position.
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        ++m_size;
    }

    /**
     * @brief Deletes the first Node in the list.
     */
    void delete_front() {
        if (m_head == nullptr) return;

        delete_element(1);
    }

    /**
     * @brief Deletes the last Node in the list.
     */
    void delete_back() {
        if (m_tail == nullptr) return;

        delete_element(m_size);
    }

     /**
     * @brief Deletes a Node at a specific position.
     * 
     * @param position The position of the Node to delete (1-based index).
     */
    void delete_element(int position) {
        if (position < 1){
            std::cout<<"Position can't be lower than 1." << std::endl;
            return;
        }
        
        Node* temp = m_head;

        for (int i = 1; temp != nullptr && i < position; i++){
            temp = temp->next;
        }

        // Checking if position is not out of range
        if (temp == nullptr) {
            std::cout << "Position greater than length of the list." << std::endl;
            return;
        }

        // Deleting Node from a specific position.
        if(temp->next){
            temp->next->prev = temp->prev;
        }
        if(temp->prev){
            temp->prev->next = temp->next;
        }
        if(temp == m_head){
            m_head = temp->next;
        }
        if(temp == m_tail){
            m_tail = temp->prev;
        }
        
        delete temp;
        --m_size;    

    }

     /**
     * @brief Clears the entire list, deleting all Nodes.
     */
    void clear() {
        while (m_head) {
            delete_front();
        }
    }

    /**
    * @brief Reverses the order of elements in the list.
    */
    void reverse(){
        Node* current = m_head;
        Node* temp = nullptr;

        while(current){
            // Swaping the next and prev pointers
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;    
        }

        temp = m_head;
        m_head = m_tail;
        m_tail = temp;
    }

    /**
     * @brief Prints the values of Nodes in the list to the console.
     */
    void print() const {
        Node* current = m_head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

     /**
     * @brief Gets the size of the list.
     * 
     * @return The number of elements in the list.
     */
    size_t getSize() const {
        return m_size;
    }
};

} ///< namespace jb

#endif ///< DOUBLE_LINKED_LIST_H