#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int rollNumber; // deklarasi variabel public untuk class Node
    string name;
    Node* next;

    Node(int rollNumber, string name) { // membuat kontruktor untuk membuat nilai di rollNumber dan name
        this->rollNumber = rollNumber;
        this->name = name;
        next = NULL; // membuat metode awal untuk next bernilai 0 karena belum ada yang diisi
    }
};

class CircularLinkedList { //membuat prosedur 
private: // private untuk Node LAST
    Node* LAST;

public:
    CircularLinkedList() { // LAST bernilai 0 karena belum ada yang diisi
        LAST = NULL;
    }
    // memmbuat  deklarasi variabel berserta parameternya
    void addNode(int rollNumber, string name); 
    bool search(int rollNumber, Node** affra, Node** wirawan);
    bool listEmpty();
    bool deleteNode(int rollNumber);
    void traverse();

};
void CircularLinkedList::addNode(int rollNumber, string name) {
    Node* newNode = new Node(rollNumber, name); // deklarsi newNode dengan nilai data dan name

    if (LAST == NULL) { // jika last = 0 maka dibuat Last berarti newNode, dan newNode dibuat newNode->next
        LAST = newNode;
        newNode->next = LAST;
    }
    else {
        Node* temp = LAST; // temp dijadikan pencarian sebelum simpul yang akan dicari
        while (temp->next != LAST) { // ketika temp tidak bernilai sama dengan last makan lanjut
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = LAST;
    }
}


bool CircularLinkedList::listEmpty() { // Mmebuat listEmpty jika tidak ada data yang diisi
    return (LAST == NULL); // lanjut jika LAST atau nilai awal bernilai 0
}
bool CircularLinkedList::search(int rollNumber, Node** affra, Node** wirawan) { // untuk mencari node yang sudah di isi
    *affra = LAST->next;
    *wirawan = LAST->next;
    while (*wirawan != LAST) {
        if (rollNumber == (*wirawan)->rollNumber) {
            return true;
        }
        *affra = *wirawan;
        *wirawan = (*wirawan)->next;
    }      if (rollNumber == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}
bool CircularLinkedList::deleteNode(int rollNumber) { //membuat kontruktor untuk menghapus node
    // deklarasi previous=affra, current = wirawan untuk mencari node yang akan di delete
    Node* affra, * wirawan; 
    // affra dan wirawan bernilai 0 karena data belum diisi
    affra = wirawan = NULL;

    if (search(rollNumber, &affra, &wirawan) == false) { // jika tidak ada data akan lanjut dan bernilai salah
        return false;
    }

    if (wirawan == LAST) { // jika current sama dengan LAST
        Node* temp = LAST; // temp untuk mencari/ menyimpan node sebelum node yang akan dihapus
        while (temp->next != LAST) {// ketika tidak bernilai LAST makan akan dilanjutkan
            temp = temp->next;
        }
        temp->next = LAST->next;
        LAST = LAST->next;
    }
    else {
        affra->next = wirawan->next; // jika sudah ada data yang diisi maka previuos dan current langsung berjalan
    }

    delete wirawan; // untuk node yang akan dihapus(current)
    return true; 
}

void CircularLinkedList::traverse() { // untuk mencari node yang sudah diisi  atau belum
    if (listEmpty()) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";     
        Node* currentNode = LAST->next;         
        while (currentNode != LAST) {
            cout << currentNode->rollNumber << "   " << currentNode->name << endl;        
            currentNode = currentNode->next;
        }   cout << LAST->rollNumber << "   " << LAST->name << endl;
    }
}

int main() {
 
    CircularLinkedList list;
    int ch, rollNumber;
    string name;

    while (true) {
        cout << "Circular Linked List Menu:" << endl;
        cout << "1. Add a record to the list" << endl;
        cout << "2. Delete a record from the list" << endl;
        cout << "3. check for list empty or not" << endl;
        cout << "4. View all the records in the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5) : ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter rollNumber and name: ";
            cin >> rollNumber >> name;
            list.addNode(rollNumber, name);
            break;
        case 2:
            cout << "Enter rollNumber of node to delete: "; // mencari node yang didelete 
            cin >> rollNumber;
            if (list.deleteNode(rollNumber)) {
                cout << "Node deleted successfully." << endl;
            }
            else {
                cout << "Node not found." << endl;
            }
            break;
        case 3:
            if (list.listEmpty()) {
                cout << "List is empty." << endl;
            }
            else {
                cout << "List is not empty." << endl;
            }
            break;
        case 4:
            list.traverse();
            break;
        case 5:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid Option" << endl;
            break;
        }

        cout << endl;
    }
    return 0;
}