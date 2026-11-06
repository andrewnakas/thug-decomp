struct Node_0018B148 {
    int m0;
    void* m4;
    int m8;
    Node_0018B148* mC;
    Node_0018B148* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

struct Item_0018B148 {
    char pad0[0x1C];
    int m_key;
};

class It_0018B148 {
public:
    int m0;
    Node_0018B148* cur;
    int m8;
    int m_key;
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_0018B148* h)
    {
        cur = h;
        return Next();
    }
    Item_0018B148* FindFirst(Node_0018B148* head, int key);
    Item_0018B148* FindNext();
};

Item_0018B148* It_0018B148::FindNext()
{
    Item_0018B148* d = (Item_0018B148*)Next();
    while (d) {
        if (d->m_key == m_key) {
            return d;
        }
        d = (Item_0018B148*)Next();
    }
    return d;
}
