/* sym: _vt$11It_00182CA0 = 0x00361800 */

struct Node_00182CA0 {
    int m0;
    void* m4;
    int m8;
    Node_00182CA0* mC;
    Node_00182CA0* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_00182CA0 {
public:
    int m0;
    Node_00182CA0* cur;
    It_00182CA0() { cur = 0; }
    virtual ~It_00182CA0() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* Advance(Node_00182CA0* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_00182CA0* h)
    {
        cur = h;
        return Next();
    }
};

class Item_00182CA0 {
public:
    int m0;
    int m_state;
    int m_req;
    int mC;
    int m10;
    virtual void V1();
    virtual void Start();
    virtual void Stop();
};

struct Mgr_00182CA0 {
    int m0;
    void* m_task;
    Node_00182CA0 m_list;
    int m18;
    int m1C;
    int m_dirty;
};

struct Task_00182CA0 {
    char pad[0x20];
    Mgr_00182CA0* m_owner;
};

extern "C" void func_00182CA0(Task_00182CA0* task)
{
    It_00182CA0 it;
    Mgr_00182CA0* mgr = task->m_owner;
    if (!mgr->m_dirty) {
        return;
    }
    mgr->m_dirty = 0;
    Item_00182CA0* d = (Item_00182CA0*)it.First(&mgr->m_list);
    if (d) {
        It_00182CA0* p = &it;
        do {
            Item_00182CA0* item = d;
            d = (Item_00182CA0*)p->Advance(it.cur);
            switch (item->m_state) {
            case 0:
                if (item->m_req == 1 || item->m_req == 3) {
                    item->Start();
                    item->m_state = 1;
                    item->m_req = 0;
                }
                break;
            case 1:
                if (item->m_req == 2) {
                    item->Stop();
                    item->m_state = 0;
                    item->m_req = 0;
                } else if (item->m_req == 3) {
                    item->Stop();
                    item->Start();
                    item->m_req = 0;
                }
                break;
            }
        } while (d);
    }
}
