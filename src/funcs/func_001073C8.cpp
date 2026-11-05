/* sym: _vt$11It_001073C8 = 0x0035AE38 */
struct Node_001073C8 {
    int m0;
    void* m4;
    int m8;
    Node_001073C8* mC;
    Node_001073C8* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_001073C8 {
public:
    int m0;
    Node_001073C8* cur;
    It_001073C8() {}
    virtual ~It_001073C8() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_001073C8* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_001073C8* h)
    {
        cur = h;
        return Next();
    }
};

extern "C" void func_00107F18(void* obj);

struct Owner_001073C8 {
    int m0;
    Node_001073C8 m_list;
    void ForEach();
};

void Owner_001073C8::ForEach()
{
    It_001073C8 it;
    void* d = it.First(&m_list);
    if (d) {
        It_001073C8* p = &it;
        do {
            func_00107F18(d);
            d = p->Advance(it.cur);
        } while (d);
    }
}
