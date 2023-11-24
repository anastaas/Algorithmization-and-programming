﻿// 12.4.cpp
// < Горанов Анастас >
// Лабораторна робота № 12.4
// Опрацювання кільцевого однонаправленого списку
// Варіант 10

#include <iostream>
#include <time.h>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value);
Info remove(Elem*& L);
int Count(Elem* L, Info val);
void Print(Elem* L);

int main()
{

    srand((unsigned)time(NULL));
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 10; i++) {
        num = -4 + rand() % 4;
        insert(L, num);
    }

    Print(L);

    Info val;
    cout << "Enter the value of the element: "; cin >> val;
    cout << endl;
    cout << "Found " << Count(L, val) << " elements with value " << val << endl;

    while (L != NULL) {
        cout << remove(L) << " ";
    }
    cout << endl;
}

void insert(Elem*& L, Info value) // додавання елементів у список
{
    Elem* tmp = new Elem;
    tmp->info = value;

    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }

    tmp->link = L;
}

Info remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link;
    Info value = L->info;
    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }
    return value;
}

void Print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << L->info << " ";
    while (L->link != first)
    {
        L = L->link;
        cout << L->info << " ";
    }
    cout << endl;
}

int Count(Elem* L, Info val)
{
    if (L == NULL)
        return 0;

    Elem* first = L;
    int k = 0;

    while (L->link != first) // перевірка без останнього значення
    {
        if (L->info == val)
            k++;
        L = L->link;
    }

    if (L->info == val) // перевірка останнього значення
        k++;
    return k;
}
