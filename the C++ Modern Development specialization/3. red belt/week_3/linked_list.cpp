template <typename T>
class LinkedList {
public:
    struct Node {
        Node (const T& value_, Node* next_): value(value_), next(next_) {}
        T value;
        Node* next = nullptr;
    };

    ~LinkedList() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        return;
    }

    void PushFront(const T& value) {
        Node* new_ = new Node(value, head);
        head = new_;
        return;
    }
    void InsertAfter(Node* node, const T& value) {
        if (node == nullptr) {
            PushFront(value);
        } else {
            Node* new_ = new Node(value, node->next);
            node->next = new_;
            return;
        }
    }
    void RemoveAfter(Node* node) {
        if (node == nullptr) {
            PopFront();
            return;
        } else if (node->next == nullptr) {
            return;
        }
        Node* tmp = node->next;
        node->next = node->next->next;
        delete tmp;
        return;
    }
    void PopFront() {
        if (head == nullptr) {
            return;
        } else {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
    }

    Node* GetHead() {
        return head;
    }
    const Node* GetHead() const {
        return head;
    }

private:
   Node* head = nullptr;
};