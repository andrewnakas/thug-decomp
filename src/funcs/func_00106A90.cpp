/* sym: _vt$11It_00106A90 = 0x0035AE38 */
struct Node_00106A90 {
    int m0;
    void* m4;
    int m8;
    Node_00106A90* mC;
    Node_00106A90* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00106A90 {
public:
    int m0;
    Node_00106A90* cur;
    It_00106A90() {}
    virtual ~It_00106A90() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00106A90* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00106A90* h)
    {
        cur = h;
        return Next();
    }
};

extern "C" void func_001075A8(void* obj);

struct Owner_00106A90 {
    char pad[0x20];
    Node_00106A90* m_list;
    void ForEach();
};

void Owner_00106A90::ForEach()
{
    It_00106A90 it;
    void* d = it.First(m_list);
    if (d) {
        It_00106A90* p = &it;
        do {
            func_001075A8(d);
            d = p->Advance(it.cur);
        } while (d);
    }
}
