#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#pragma once
#include <iostream>

namespace jb{

template <typename T>
class DoubleLinkedList {
private:

    class Node {
        public:
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* m_head;
    Node* m_tail;
    size_t m_size;

public:
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~DoubleLinkedList() {
        clear();
    }

    // Add element on the front
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

    // Add element on the end 
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
    // Add element to the specific place in list
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
        // Check if position is not out of range
        if (temp == nullptr) {
            std::cout << "Position greater than length of the list." << std::endl;
            return;
        }
        
        // Add new node at the specified position.
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        ++m_size;
    }

    // Delete element from front
    void delete_front() {
        if (m_head == nullptr) return;

        delete_element(1);
    }

    // Delete element from end
    void delete_back() {
        if (m_tail == nullptr) return;

        delete_element(m_size);
    }
    // Delete element
    void delete_element(int position) {
        if (position < 1){
            std::cout<<"Position can't be lower than 1." << std::endl;
            return;
        }
        
        Node* temp = m_head;

        for (int i = 1; temp != nullptr && i < position; i++){
            temp = temp->next;
        }

        // Check if position is not out of range
        if (temp == nullptr) {
            std::cout << "Position greater than length of the list." << std::endl;
            return;
        }

        // Delete new node at the specified position.
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

    // Deleting all elements
    void clear() {
        while (m_head) {
            delete_front();
        }
    }
    
    void reverse(){
        Node* current = m_head;
        Node* temp = nullptr;

        while(current){
            // Swap the next and prev pointers
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;    
        }

        temp = m_head;
        m_head = m_tail;
        m_tail = temp;
    }

    // Display list
    void print() const {
        Node* current = m_head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // List size
    size_t getSize() const {
        return m_size;
    }
};

}// jb

#endif // DOUBLE_LINKED_LIST_H