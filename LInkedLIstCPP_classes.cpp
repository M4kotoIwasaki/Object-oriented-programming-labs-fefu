#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

class List 
{
private:
    class Node 
    {
    public:
        Node* pNext;
        Node* pPrev;
        int data;
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr)
            : data(data), pNext(pNext), pPrev(pPrev) {}
    };

public:
    List();
    ~List();

    void pop_front();
    void pop_back();
    void push_back(int data);
    void clear();
    void unitee(const List& other);
    void remove_all(int value);
    int size();
    bool isEmpty();
    void print();
    Node* head;
};

List::List() : head(nullptr) {}

List::~List() 
{
    clear();
}

void List::pop_front() 
{
    if (head) 
    {
        Node* temp = head;
        head = head->pNext;
        if (head)
            head->pPrev = nullptr;
        delete temp;
    }
}

void List::pop_back() 
{
    if (!head) return;

    Node* current = head;
    while (current->pNext) 
    {
        current = current->pNext;
    }

    if (current->pPrev) 
    {
        current->pPrev->pNext = nullptr;
    }
    else 
    {
        head = nullptr;
    }

    delete current;
}

void List::push_back(int data) 
{
    Node* node = new Node(data);
    if (!head) 
    {
        head = node;
    }
    else 
    {
        Node* current = head;
        while (current->pNext) 
        {
            current = current->pNext;
        }
        current->pNext = node;
        node->pPrev = current;
    }
}

void List::clear() 
{
    while (head) 
    {
        pop_front();
    }
}

int List::size() 
{
    int Size = 0;
    Node* current = head;
    while (current) 
    {
        Size++;
        current = current->pNext;
    }
    return Size;
}

bool List::isEmpty() 
{
    return head == nullptr;
}

void List::unitee(const List& other) 
{
    Node* current = other.head;
    while (current) 
    {
        this->push_back(current->data);
        current = current->pNext;
    }
}

void List::remove_all(int value) 
{
    Node* current = head;
    while (current) 
    {
        if (current->data == value) 
        {
            Node* to_delete = current;
            if (current->pPrev) 
            {
                current->pPrev->pNext = current->pNext;
            }
            else 
            {
                head = current->pNext;
            }
            if (current->pNext) 
            {
                current->pNext->pPrev = current->pPrev;
            }
            current = current->pNext;
            delete to_delete;
        }
        else 
        {
            current = current->pNext;
        }
    }
}

void List::print() 
{
    Node* current = head;
    while (current) 
    {
        std::cout << current->data << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}

List list1;
List list2;

void Initialization(int listChoise)
{
    int numel;
    std::cout << "Введите количество элементов: ";
    std::cin >> numel;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка типа данных!\n";
        return;
    }

    List* list = (listChoise == 1) ? &list1 : &list2;
    list->clear();

    for (int i = 0; i < numel; i++) 
    {
        list->push_back(rand() % 100);
    }
}

void Menu() 
{
    int choise;
    do 
    {
        std::cout << "\n1. Создание списка\n2. Добавление элемента в конец\n"
            << "3. Удаление всех вхождений элемента\n4. Объединение двух списков\n"
            << "5. Очистка памяти\n6. Печать\n0. Выход\n";
        std::cout << "Выберите пункт меню: ";
        std::cin >> choise;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка типа данных!\n";
            continue;
        }

        int listChoise, elem;
        switch (choise) {
        case 1:
            std::cout << "Выберите список для работы (1 или 2): ";
            std::cin >> listChoise;
            if (listChoise == 1 || listChoise == 2) {
                Initialization(listChoise);
            }
            else {
                std::cout << "Нет такого.\n";
            }
            break;
        case 2:
            std::cout << "Выберите список для работы (1 или 2): ";
            std::cin >> listChoise;
            std::cout << "Введите элемент: ";
            std::cin >> elem;
            (listChoise == 1 ? list1 : list2).push_back(elem);
            break;
        case 3:
            std::cout << "Выберите список для работы (1 или 2): ";
            std::cin >> listChoise;
            std::cout << "Введите элемент для удаления: ";
            std::cin >> elem;
            (listChoise == 1 ? list1 : list2).remove_all(elem);
            break;
        case 4:
            list1.unitee(list2);
            std::cout << "Списки объединены. Результат:\n";
            list1.print();
            break;
        case 5:
            std::cout << "Выберите список для очистки (1 или 2): ";
            std::cin >> listChoise;
            (listChoise == 1 ? list1 : list2).clear();
            break;
        case 6:
            std::cout << "Список 1: ";
            list1.print();
            std::cout << "Список 2: ";
            list2.print();
            break;
        case 0:
            std::cout << "Выход.\n";
            break;
        default:
            std::cout << "Нет такого пункта.\n";
            break;
        }
    } while (choise != 0);
}

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    Menu();
    return 0;
}
