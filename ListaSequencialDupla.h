class DoubleVector{
    private:
        int m_size;
        int m_tail;
        int m_head;
        int m_capacity;
        int * m_list;
    public:
        DoubleVector();
        DoubleVector(int n);
        ~DoubleVector();
        int size();
        bool empty();
        void push_back(int value);
        int pop_back();
        void push_front(int value);
        int pop_front();
        int at(int k);
        void resize();
        void left_shift();
        void right_shift();
        void remove(int k);
        void removeAll(int value);
        void print();
        void printReverse();
        void concat(DoubleVector& lst);
        bool equal(DoubleVector& lst);

};