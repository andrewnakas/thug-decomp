/* sym: _vt$11It_00107318 = 0x0035AE38 */
struct Node_00107318 {
    int m0;
    void* m4;
    int m8;
    Node_00107318* mC;
    Node_00107318* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00107318 {
public:
    int m0;
    Node_00107318* cur;
    It_00107318() {}
    virtual ~It_00107318() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00107318* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00107318* h)
    {
        cur = h;
        return Next();
    }
};

extern "C" void func_00107E70(void* obj);

struct Owner_00107318 {
    int m0;
    Node_00107318 m_list;
    void ForEach();
};

void Owner_00107318::ForEach()
{
    It_00107318 it;
    void* d = it.First(&m_list);
    if (d) {
        It_00107318* p = &it;
        do {
            func_00107E70(d);
            d = p->Advance(it.cur);
        } while (d);
    }
}
