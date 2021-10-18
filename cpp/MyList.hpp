#pragma once
#include <algorithm>
#include <cstdint>
#include <type_traits>

/*
Umjesto standardne dvostruko povezane liste, ja sam odlucio da pokusam napraviti
specijalni tip dvostruko povezane liste tzv XOR povezanu listu. Glavna razlika
je to sto je u ovom slucaju potreban samo jedan pointer po Node-u, a prethodnike
i sljedbenike tog Node-a dobijamo XOR operacijom trenutnog pointera.
Funkcijalnost je u konacnici ista, medjutim ovaj oblik liste koristi duplo manje
memorije jer cuva samo jedan pointer (umjesto dva).
*/

// Potrebne su konverzije izmedju pointer i int tipa jer
// XOR operacije nisu moguce nad standardnim pointerima
#define ptoi(p) reinterpret_cast<uintptr_t>((void *)(p)) //pointer to integer konverzija
#define itop(i) reinterpret_cast<Node *>((i))            //integer to pointer konverzija

template <typename T>
class MyList
{
private:
    struct Node
    {
        friend MyList;
        uintptr_t link_;
        T data_;
        Node(const T &d) : link_{0}, data_{d} {}
        Node(T &&d) : link_{0}, data_{std::move(d)} {}
        Node(const Node &other) : link_{other.link_}, data_{other.data_} {}
        // void connectNodes(Node *x, Node *y) - Ovaj metod kreira novu vezu ili
        // prekida postojecu vezu izmedju dva Node objekta
        friend void connectNodes(Node *x, Node *y)
        {
            if (x)
            {
                x->link_ ^= ptoi(y);
            }
            if (y)
            {
                y->link_ ^= ptoi(x);
            }
        }
        /* static Node *traverse(Node *curr, Node *prev) - Ovaj metod se koristi za
        kretanje naprijed ili nazad kroz listu u zavisnosti  od redoslijeda
        proslijedjenih argumenata*/
        static Node *traverse(Node *curr, Node *prev)
        {
            if (curr == nullptr)
            {
                return nullptr;
            }

            Node *n = itop(ptoi(prev) ^ curr->link_);
            if (n)
            {
                return n;
            }
            else
            {
                return nullptr;
            }
        }
        // Node *connect(Node *newNode) - Kreira vezu izmedju trenutnog (this)
        // Node-a i  proslijedjenog Node-a
        Node *connect(Node *newNode)
        {
            connectNodes(this, newNode);
            return newNode;
        }
        /*
        void disconnectNodes(Node *a, Node *b, Node *c, Node *d) - Prekida vezu dva
        Node-a od ostatka liste. b i c su pointeri na Node-ove koje zelimo da
        otpojimo od ostatka liste. Koristi se konkretno za prekid veze head i tail
        Node-a prilikom brisanja (destructor). Potrebno je da prvo otpojimo Node-ove
        prije nego sto ih obrisemo jer bez prethodnog Node-a nemoguce je znati
        adresu sljedeceg Node-a i obratno.
        */
        friend void disconnectNodes(Node *a, Node *b, Node *c, Node *d)
        {
            if (a)
            {
                a->link_ ^= ptoi(b);
                a->link_ ^= ptoi(d);
            }
            if (d)
            {
                d->link_ ^= ptoi(c);
                d->link_ ^= ptoi(a);
            }
            b->link_ ^= ptoi(a);
            c->link_ ^= ptoi(d);
        }
    };
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    size_t size_ = 0;

    class iterator_ : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        friend MyList;
        Node *prev_ = nullptr;
        Node *curr_ = nullptr;

    public:
        iterator_(Node *prev, Node *curr) : prev_{prev}, curr_{curr} {}
        iterator_(const iterator_ &another)
            : prev_{another.prev_}, curr_{another.curr_} {}

        T operator*() const
        {
            if (curr_ != nullptr)
            {
                return curr_->data_;
            }
        }

        iterator_ &operator++()
        {
            Node *nextNode = Node::traverse(curr_, prev_);
            prev_ = curr_;
            curr_ = nextNode;
            return *this;
        }

        iterator_ operator++(int)
        {
            iterator_ tempIt = iterator_(prev_, curr_);
            operator++();
            return tempIt;
        }

        iterator_ &operator--()
        {
            Node *previousNode = Node::traverse(prev_, curr_);
            curr_ = prev_;
            prev_ = previousNode;
            return *this;
        }

        iterator_ operator--(int)
        {
            iterator_ tempIt = iterator_(prev_, curr_);
            operator--();
            return tempIt;
        }
        bool operator==(const iterator_ &other) const
        {
            return curr_ == other.curr_ && prev_ == other.prev_;
        }
        bool operator!=(const iterator_ &other) const
        {
            return curr_ != other.curr_ || prev_ != other.prev_;
        }
    };

public:
    MyList() = default;

    MyList(const T &d) : size_{1}
    {
        Node *n = new Node(d);
        head_ = n;
        tail_ = head_;
    }

    MyList(T &&d) : size_{1}
    {
        Node *n = new Node(d);
        head_ = n;
        tail_ = head_;
    }

    MyList(MyList &&another)
    {
        head_ = another.head_;
        tail_ = another.tail_;
        size_ = another.size_;
        another.head_ = nullptr;
        another.tail_ = nullptr;
        another.size_ = 0;
    }
    MyList(const MyList &other) : MyList(other.begin(), other.end()) {}

    MyList &operator=(const MyList &other)
    {
        MyList newList(other);
        std::swap(head_, newList.head_);
        std::swap(tail_, newList.tail_);
        std::swap(size_, newList.size_);
        return *this;
    }

    MyList &operator=(MyList &&other)
    {
        std::swap(head_, other.head_);
        std::swap(tail_, other.tail_);
        std::swap(size_, other.size_);
        return *this;
    }

    template <typename it>
    MyList(it begin, it end)
    {
        Node *newbegin = nullptr, *newend = nullptr, *newnext = nullptr;
        size_t size = 0;

        if (begin != end)
        {
            newbegin = new Node(*begin);
            newend = newbegin;

            ++begin;
            ++size;

            while (begin != end)
            {
                newnext = new Node(*begin);
                newend = newend->connect(newnext);
                ++begin;
                ++size;
            }

            head_ = newbegin;
            tail_ = newend;
            size_ = size;
        }
    }

    MyList(std::initializer_list<T> inputList)
        : MyList(inputList.begin(), inputList.end()) {}
    ~MyList() { erase(begin(), end()); }

    void erase(iterator_ from, iterator_ to)
    {
        if (from == to)
        {
            return;
        }

        Node *head = from.curr_; // Pointer na prvi element koji brisemo
        Node *tail = to.prev_;   // Pointer na zadnji element koji brisemo
        Node *prev = from.prev_;
        Node *next = to.curr_;

        if (!prev)
        {
            head_ = next;
        }
        if (!next)
        {
            tail_ = prev;
        }

        // Otpajamo prvi i zadnji Node od ostatka liste
        // a njihove prethodnike i sljedbenike prespajamo
        disconnectNodes(prev, head, tail, next);
        from.prev_ = nullptr;
        to.curr_ = nullptr;

        // Brisemo sve Node-ove izmedju prvog i zadnjeg pointera
        while (from.curr_ != to.curr_)
        {
            Node *markedNode = from.curr_;
            ++from;
            markedNode->data_.~T();
            delete markedNode;
            --size_;
        }
    }
    iterator_ begin() { return iterator_(nullptr, head_); }
    iterator_ end() { return iterator_(tail_, nullptr); }
    iterator_ begin() const { return iterator_(nullptr, head_); }
    iterator_ end() const { return iterator_(tail_, nullptr); }
    void push_back(Node *node)
    {
        if (!tail_)
        {
            head_ = node;
            tail_ = head_;
        }
        else
        {
            tail_ = tail_->connect(node);
        }
        ++size_;
    }

    void push_back(const T &v)
    {
        Node *newNode = new Node(v);
        push_back(newNode);
    }

    void push_back(T &&v)
    {
        Node *newNode = new Node(std::move(v));
        push_back(newNode);
    }

    void push_front(Node *node)
    {
        if (!head_)
        {
            head_ = node;
            tail_ = head_;
        }
        else
        {
            head_ = head_->connect(node);
        }
        ++size_;
    }

    void push_front(const T &v)
    {
        Node *newNode = new Node(v);
        push_front(newNode);
    }

    void push_front(T &&v)
    {
        Node *newNode = new Node(std::move(v));
        push_front(newNode);
    }

    void remove(iterator_ pos)
    {
        iterator_ next = pos;
        ++next;
        erase(pos, next);
    }

    void pop_back() { remove(--end()); }

    void pop_front() { remove(begin()); }

    // void insert(iterator_ pos, const T &value) - Insertuje vrijednost "value"
    // na mjesto prije iteratora "pos"
    void insert(iterator_ pos, const T &value)
    {
        Node *newNode = new Node(value);
        if (!pos.prev_)
        {
            head_ = newNode;
        }
        if (!pos.curr_)
        {
            tail_ = newNode;
        }

        connectNodes(pos.prev_, pos.curr_); // Otpajamo Node-ove na poziciji insertiranja
        connectNodes(pos.prev_, newNode);   // Spajamo prethodni Node na novi
        connectNodes(newNode, pos.curr_);   // Spajamo novi Node na sljedeci
    }
};
