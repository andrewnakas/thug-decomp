struct Node_0018B0C0 {
    int m0;
    void* m4;
    int m8;
    Node_0018B0C0* mC;
    Node_0018B0C0* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

struct Item_0018B0C0 {
    char pad0[0x1C];
    int m_key;
};

class It_0018B0C0 {
public:
    int m0;
    Node_0018B0C0* cur;
    int m8;
    int m_key;
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_0018B0C0* h)
    {
        cur = h;
        return Next();
    }
    Item_0018B0C0* FindFirst(Node_0018B0C0* head, int key);
    Item_0018B0C0* FindNext();
};

Item_0018B0C0* It_0018B0C0::FindFirst(Node_0018B0C0* head, int key)
{
    Item_0018B0C0* d = (Item_0018B0C0*)First(head);
    m_key = key;
    while (d) {
        if (d->m_key == key) {
            return d;
        }
        d = (Item_0018B0C0*)Next();
    }
    return d;
}
