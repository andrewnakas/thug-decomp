/* sym: _vt$11It_00182EB0 = 0x00361800 */

struct Node_00182EB0 {
    int m0;
    void* m4;
    int m8;
    Node_00182EB0* mC;
    Node_00182EB0* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00182EB0 {
public:
    int m0;
    Node_00182EB0* cur;
    It_00182EB0() {}
    virtual ~It_00182EB0() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00182EB0* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00182EB0* h)
    {
        cur = h;
        return Next();
    }
};

class Item_00182EB0 {
public:
    int m0;
    int m_state;
    int m8;
    int mC;
    int m10;
    virtual void V1();
    virtual void V2();
    virtual void Stop();
};

class Mgr_00182EB0 {
public:
    int m0;
    void* m_task;
    Node_00182EB0 m_list;
    void StopAll();
};

void Mgr_00182EB0::StopAll()
{
    It_00182EB0 it;
    Item_00182EB0* d = (Item_00182EB0*)it.First(&m_list);
    if (d) {
        It_00182EB0* p = &it;
        do {
            Item_00182EB0* item = d;
            d = (Item_00182EB0*)p->Advance(it.cur);
            if (item->mC == 0 && item->m_state == 1) {
                item->Stop();
                item->m8 = 0;
                item->m_state = 0;
            }
        } while (d);
    }
}
