#include "list.hpp"
#include <string>
#include <sstream>

list::list() {
  this->head = NULL;
  this->_size = 0;
}

list::list(const list& another) {
  this->head = NULL;
  this->_size = 0;
  *(this) = another;
}

list& list::operator=(const list& another) {
  if (this != &another) {
    this->clear();
    if (another.head != NULL) {
      this->head = new node(another.head->data);
      node* p = another.head->next;
      node* q = this->head;
      while (p != NULL) {
        q->next = new node(p->data);
        p = p->next;
        q = q->next;
      }
      q->next = NULL;
    }
    this->_size = another._size;
  }
  return *(this);
}

list::~list() { this->clear(); }

bool list::empty(void) const { return this->_size == 0; }

int list::size(void) const { return this->_size; }

std::string list::toString(void) const {
  node* positioner = this->head;
  std::string result;
  std::stringstream ss;
  while (positioner != NULL) {
    ss << positioner->data;
    std::string temp;
    ss >> temp;
    result += temp + "->";
    ss.clear();
    positioner = positioner->next;
  }
  result += "NULL";
  return result;
}

void list::insert(int position, const int& data) {
  if (position > this->_size || position < 0) {
    return;
  } else if (position == 0) {
    node* temp = new node(data, this->head);
    this->head = temp;
  } else {
    node* p = this->head;
    int counter = 1;
    while (counter != position) {
      p = p->next;
      counter++;
    }
    node* temp = new node(data, p->next);
    p->next = temp;
  }
  this->_size++;
}

void list::erase(int position) {
  if (position >= this->_size || position < 0) {
    return;
  } else if (position == 0) {
    node* temp = this->head;
    this->head = this->head->next;
    delete temp;
  } else {
    node* pre = this->head;
    int counter = 0;
    while (counter != position - 1) {
      counter++;
      pre = pre->next;
    }
    node* temp = pre->next;
    pre->next = temp->next;
    delete temp;
  }
  this->_size--;
}

list& list::sort(void) {
  if (this->head != NULL && this->head->next != NULL) {
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL) {
      if (fast->data >= slow->data) {
        fast = fast->next;
        slow = slow->next;
      } else {
        node* pre = this->head;
        if (this->head->data > fast->data) {
          slow->next = fast->next;
          fast->next = this->head;
          this->head = fast;
        } else {
          while (pre->next->data <= fast->data) {
            pre = pre->next;
          }
          slow->next = fast->next;
          fast->next = pre->next;
          pre->next = fast;
        }
        fast = slow->next;
      }
    }
  }
  return *(this);
}
