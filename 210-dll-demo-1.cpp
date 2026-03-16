#include <iostream>
#include <string>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
const int SIZE = 15;

class Goat{
private:
    int age;
    string name, color;
    string names[SIZE] = {
        "Luna", "Milo", "Daisy", "Rocky", "Willow",
        "Jasper", "Nala", "Finn", "Hazel", "Coco",
        "Poppy", "Rex", "Ivy", "Atlas", "Zoe"
    };
    string colors[SIZE] = {
        "White", "Black", "Brown", "Gray", "Tan",
        "Cream", "Golden", "Silver", "Spotted", "Speckled",
        "Chestnut", "Caramel", "Ivory", "Mocha", "Blue"
    };
public:
    //constructors
    Goat(){
        age = (rand() % 20) + 1;
        name = names[rand() % SIZE];
        color = colors[rand() % SIZE];
    }
    Goat(int ag, string nam, string colo){
        age = ag;
        name = nam;
        color = colo;
    }
    //setter getters
    string get_name()         {return name;}
    int get_age()             {return age;}
    string get_color()        {return color;}           
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }


    void print() {
        Node* current = head;
        if (!current){
            cout << "List is empty.";
            return;
        } 
        while (current) {
            Goat goat = current->data;
            cout << goat.get_name() << " (" << goat.get_color() << ", ";
            cout << goat.get_age() << ")" << endl;
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current){
            cout << "List is empty.";
            return;
        } 
        while (current) {
            Goat goat = current->data;
            cout << goat.get_name() << " (" << goat.get_color() << ", ";
            cout << goat.get_age() << ")" << endl;
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i) {
        Goat temp;
        list.push_back(temp);
    }
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

   
    return 0;
}
