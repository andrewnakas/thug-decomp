class Item_0026CD98;

class Node_0026CD98 {
public:
    int m0;
    int m4;
    int m8;
    Item_0026CD98* mC;
    Item_0026CD98* m10;
    virtual ~Node_0026CD98();
};

class Item_0026CD98 : public Node_0026CD98 {
public:
    Item_0026CD98* Valid()
    {
        Item_0026CD98* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct Head_0026CD98 {
    int m0;
    int m4;
    int m8;
    Item_0026CD98* mC;
    Item_0026CD98* FirstRaw()
    {
        if (!~mC->m4)
            return 0;
        return mC;
    }
    Item_0026CD98* First() { return FirstRaw(); }
    Item_0026CD98* Begin() { return mC->Valid(); }
};

struct List_0026CD98 {
    int m_count;
    Head_0026CD98 m_head;
    void Clear();
};

void List_0026CD98::Clear()
{
    Item_0026CD98* p = m_head.Begin();
    while (p) {
        delete p;
        p = m_head.First();
    }
    m_count = 0;
}
