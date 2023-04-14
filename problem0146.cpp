#include <iostream>
#include <unordered_map>

using std::cout, std::endl, std::unordered_map;

class Node
{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
};

class LRUCache
{
    public:
        int capacity;
        int count;
        Node* head = nullptr;
        unordered_map<int, Node*> index;

        LRUCache(int capacity)
        {
            this->capacity = capacity;
            this->count = 0;
            this->index = {};
        }

        int put(int key, int value)
        {
            auto node = index.find(key) == index.end() ? nullptr : index[key];

            //inserting new key
            if (node == nullptr)
            {
                //LRU is empty
                if (count == 0)
                {
                    head = new Node();
                    head->key = key;
                    head->value = value;
                    count = 1;
                    index[key] = head;
                    return head->value;
                }

                if (count == 1 && capacity == 1)
                {
                    index.erase(head->key);
                    head = new Node();
                    head->key = key;
                    head->value = value;
                    count = 1;
                    index[key] = head;
                    return head->value;
                }

                //only head in LRU
                if (count == 1)
                {
                    auto node = new Node();
                    node->key = key;
                    node->value = value;
                    node->next = head;
                    node->prev = head;
                    head->next = node;
                    head->prev = node;
                    head = node;
                    count++;
                    index[key] = node;
                    return node->value;
                }

                //LRU is not full
                if (count < capacity)
                {
                    auto node = new Node();
                    node->key = key;
                    node->value = value;
                    node->next = head;
                    node->prev = head->prev;

                    auto tail = head->prev;

                    tail->next = node;
                    head->prev = node;

                    head = node;

                    count++;
                    
                    index[key] = node;
                    return node->value;
                }
                //LRU is full
                else
                {
                    index.erase(head->prev->key);
                    auto node = new Node();
                    node->key = key;
                    node->value = value;
                    node->next = head;
                    node->prev = head->prev->prev;

                    head->prev = node;
                    head->prev->prev->next = node;

                    head = node;

                    index[key] = node;
                    return node->value;
                }
            }

            //key exists

            //it is head
            if (node == head)
            {
                head->value = value;
                return head->value;
            }

            //is it tail
            if (node == head->prev)
            {
                head = head->prev;
                head->value = value;
                return head->value;
            }          

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head;
            node->prev = head->prev;

            head = node;
            head->prev->next = head;
            head->next->prev = head;
            
            node->value = value;
            return node->value;
        }

        int get(int key)
        {
            auto node = index.find(key) == index.end() ? nullptr : index[key];
            if (node == nullptr)
            {
                //Print();
                return -1;
            }
            if (node == head)
            {
                //Print();
                return node->value;
            }
            if (node == head->prev)
            {
                head = head->prev;
                //Print();
                return head->value;
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head;
            node->prev = head->prev;

            head = node;
            head->prev->next = head;
            head->next->prev = head;
            //Print();
            return node->value;
        }

        void Print()
        {
            if (count == 0)
            {
                cout << "empty" << endl;
                return;
            }
            auto node = head;
            cout << node->key << '=' << node->value << ' ';
            node = node->next;
            while(node != nullptr && node != head)
            {
                cout << node->key << '=' << node->value << ' ';
                node = node->next;
            }
            cout << endl;
        }
};

int main()
{
    // auto lru = new LRUCache(2);
    // lru->put(1, 1); lru->Print();
    // lru->put(2, 2); lru->Print();
    // cout << lru->get(1) << endl;
    // lru->put(3, 3); lru->Print();
    // cout << lru->get(2) << endl;
    // lru->put(4, 4); lru->Print();
    // cout << lru->get(1) << endl;
    // cout << lru->get(3) << endl;
    // cout << lru->get(4) << endl;
    // delete lru;

    auto lru = new LRUCache(1);
    cout << lru->get(1) << endl;
    lru->put(2, 1);
    cout << lru->get(2) << endl;
    lru->put(3, 2);
    cout << lru->get(2) << endl;
    cout << lru->get(3) << endl;
    delete lru;
}