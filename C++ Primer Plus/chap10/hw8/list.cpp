//
// Created by hty on 2021/8/12.
//

#include "list.h"
#include <iostream>

List::List()
{
    head->number = 0;
    head->next = NULL;
}

List::~List()
{
    Node *p, *next;
    for (p = head; p != NULL; )
    {
        next = p->next;
        delete p;
        p = next;
    }
}

bool List::isEmpty()
{
    return head->number == 0;
}

bool List::isFull()
{
    return head->number == MaxNum;
}

void List::insert(Item & item, int n = MaxNum)
{
    if (head->number == MaxNum)
    {
        std::cout << "The list is full. Cannot insert new item.\n";
    }
    else
    {
        Node *p = head, *insertNode = new Node;
        if (n > head->number + 1)
            n = head->number + 1;
        if (n <= 0)
        {
            insertNode->next = head->next;
            head->next = insertNode;
        }
        else
        {
            for (int i = 0; i < n - 1; i++, p = p->next);
            insertNode->next = p->next;
            p->next = insertNode;
        }
        insertNode->number = n;
        insertNode->item = item;
        for (p = insertNode->next; p != NULL; p = p->next)
        {
            p->number += 1;
        }
        head->number++;
        if (isFull())
            std::cout << "The list is full now!\n";
    }
}

void List::delete_one(int n = MaxNum)
{
    Node *p = head;
    if (n > head->number)
        n = head->number;
    if (n <= 0)
        n = 1;
    for (int i = 0; i < n - 1; i++, p = p->next);
    Node *deleteNode = p->next;
    p->next = p->next->next;
    delete deleteNode;
    for (p = p->next; p != NULL; p = p->next)
    {
        p->number -= 1;
    }
    head->number--;
    if (isEmpty())
        std::cout << "The list is empty now!\n";
}

//void List::exchange(int n1, int n2);   //交换两项

void List::show()
{
    using namespace std;
    cout << "total: " << head->number << endl;
    for (Node *p = head->next; p != NULL; p = p->next)
    {
        cout << "number: " << p->number << "  item: " << p->item << endl;
    }
}