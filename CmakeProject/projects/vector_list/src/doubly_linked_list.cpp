#include "doubly_linked_list.hpp"
#include <iostream>

using mbr::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	if (!begin) return;
	Node* p = begin;
	while (p) {
		Node* nxt = p->next;
		delete p;
		p = nxt;
	}
	begin = nullptr;
	end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t c = 0;
    Node* p = begin;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	Node* p = begin;
	while (p) {
		if (p->value == value) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* p = begin;
	if (!begin) {
		std::cout << "[]";
		return;
	}
	std::cout << "[" << p->value;
	p = p->next;
	while (p) {
		std::cout << ", " << p->value;
		p = p->next;
	}
	std::cout << "]" << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* n = new Node(value);
	if (!n) return;
	if (begin == nullptr) {
		begin = n;
		end = n;
	} else {
		end->next = n;
		n->prev = end;
		end = n;
	}
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node* p = begin;
	if (!begin) {
		return false;
	}
	while (p) {
		if (p->value == value) {
			if (p == begin && p == end) {
				begin = end = nullptr;
			} else if (p == begin) {
				begin = p->next;
				begin->prev = nullptr;
			} else if (p == end) {
				end = p->prev;
				end->next = nullptr;
			} else {
				(p->prev)->next = p->next;
				(p->next)->prev = p->prev;
			}
			delete p;
			return true;
		}
		p = p->next;
	}
	return false;
}
