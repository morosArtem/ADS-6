// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* head;

 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    if (isEmpty() || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next != nullptr &&
             current->next->data.prior >= item.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }

  T pop() {
    if (isEmpty()) {
      throw "Queue is empty";
    }
    Node* temp = head;
    T result = head->data;
    head = head->next;
    delete temp;
    return result;
  }

  T front() const {
    if (isEmpty()) {
      throw "Queue is empty";
    }
    return head->data;
  }

  bool isEmpty() const {
    return head == nullptr;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
