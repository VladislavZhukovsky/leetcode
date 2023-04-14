#include <iostream>

using std::cout, std::endl;

class Node
{
    public:
        char value;
        Node* next;
        Node* prev;
};

class LRU
{
    private:
        int capacity;
        int count;
        
    public:
        Node* head = nullptr;

        LRU(int capacity)
        {
            this->capacity = capacity;
            this->count = 0;
        }

        void Print()
        {
            if (count == 0)
            {
                cout << "empty" << endl;
                return;
            }
            auto node = head;
            cout << head->value << ' ';
            node = node->next;
            while(node != nullptr && node != head)
            {
                cout << node->value << ' ';
                node = node->next;
            }
            cout << endl;
        }

        char Get(char value)
        {
            if (count == 0)
            {
                head = new Node();
                head->value = value;
                count = 1;
                
                Print();
                return head->value;
            }

            if (count == 1)
            {
                if (head->value == value)
                {
                    
                    Print();
                    return head->value;
                }
                else
                {
                    auto node = new Node();
                    node->value = value;
                    node->next = head;
                    node->prev = head;
                    head->next = node;
                    head->prev = node;
                    head = node;
                    count++;
                    
                    Print();
                    return node->value;
                }
            }

            auto node = FindNode(value);

            if (node == head)
            {
                Print();
                return head->value;
            }

            if (node == head->prev)
            {
                head = head->prev;
                Print();
                return head->value;
            }

            //add new
            if (node == nullptr)
            {
                if (count < capacity)
                {
                    auto node = new Node();
                    node->value = value;
                    node->next = head;
                    node->prev = head->prev;

                    auto tail = head->prev;

                    tail->next = node;
                    head->prev = node;

                    head = node;

                    count++;
                    
                    Print();
                    return node->value;
                }
                else
                {
                    auto node = new Node();
                    node->value = value;
                    node->next = head;
                    node->prev = head->prev->prev;

                    head->prev = node;
                    head->prev->prev->next = node;

                    head = node;

                    Print();
                    return node->value;
                }
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head;
            node->prev = head->prev;

            head = node;
            head->prev->next = head;
            head->next->prev = head;
            
            Print();
            return node->value;
        }

    private:
        Node* FindNode(char value)
        {
            auto node = head;
            if (node->value == value)
            {
                return node;
            }
            node = node->next;
            while (node != head)
            {
                if (node->value == value)
                    return node;
                node = node->next;
            }
            return nullptr;
        }
};

int main()
{
    auto lru = new LRU(4);
    lru->Get('A');
    lru->Get('B');
    lru->Get('C');
    lru->Get('D');
    lru->Get('B');
    lru->Get('E');
    lru->Get('B');
}