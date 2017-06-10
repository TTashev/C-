#include <cstddef>
#include <cassert>
#include <iostream>
#include <sstream>

#include "list.h"


List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

List::List(const List& other)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    Node * temp = other.head;
    while(temp != nullptr)
    {
        this->add(temp->getValue());
        temp = temp->getNext();
    }
}

bool List::isEmpty() const
{
    if(head == nullptr && tail == nullptr)
    {
        return true;
    }
    else if (head == nullptr ^ tail == nullptr)
    {
        assert(false);
    }

    return false;
}

List::Node::Node(T value,
                 Node * prev = nullptr,
                 Node * next = nullptr)
                 : value(value), prev(prev), next(next)
{

}

void List::Node::setValue(T value)
{
    this->value = value;
}

T List::Node::getValue() const
{
   return this->value;
}

void List::Node::setNext(Node * next)
{
    this->next = next;
}

List::Node* List::Node::getNext() const
{
    return this->next;
}

List::Node* List::Node::getPrev() const
{
    return this->prev;
}

void List::Node::setPrev(Node * prev)
{
    this->prev = prev;
}

T List::first() const
{
    return this->head->getValue();
}

// TODO:
void List::add(T value)
{
    if(this->isEmpty())
    {
        this->head = this->tail = new Node(value, nullptr, nullptr);
    }
    else
    {
        Node * temp = new Node(value);
        this->tail->setNext(temp);
        temp->setPrev(this->tail);
        this->tail = temp;
    }
    this->size++;
}

// TODO:
void List::addAll(const List& other)
{
    Node * temp = other.head;
    while(temp != nullptr)
    {
        this->add(temp->getValue());
        temp = temp->getNext();
    }
}

void List::removeFirst()
{
    if(this->head != nullptr)
    {
        Node * temp = this->head;
        if (this->head == this->tail)
        {
            this->tail = nullptr;
            this->head = nullptr;
        }
        else
        {
           this->head = this->head->getNext();
           this->head->setPrev(nullptr);
        }
        delete temp;
    }
    else if (head == nullptr ^ tail == nullptr)
    {
        assert(false);
    }

    this->size--;
}

// TODO: optional
void List::removeAll()
{

}

size_t List::getSize() const
{
    return this->size;
}

// TODO: optional
List List::getReversed(List l)
{

}

std::string List::toString() const
{
    Node * current = this->head;
    std::ostringstream oss;
    while(current != nullptr)
    {
        oss << current->getValue() << " ";
        current = current->getNext();
    }

    return oss.str();
}

List& List::operator<<(const T& value)
{
    this->add(value);
    return *this;
}

List& List::operator<<(const List& other)
{
    this->addAll(other);
    return *this;
}

List& List::operator=(const List& other)
{
    Node * temp = this->head;
    while(temp != nullptr)
    {
        Node * deleted = temp;
        temp = temp->getNext();
        delete deleted;
    }
    this->head = this->tail = nullptr;
    this->size = 0;

    temp = other.head;
    Node * curr = this->head;
    while(temp != nullptr)
    {
        this->add(temp->getValue());
        temp = temp->getNext();
    }
}

List::~List()
{
    Node * temp = this->head;
    while(temp != nullptr)
    {
        Node * deleted = temp;
        temp = temp->getNext();
        delete deleted;
    }
    this->head = this->tail = nullptr;
    this->size = 0;
}