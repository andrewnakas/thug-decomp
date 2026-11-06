/* fuzzy: 51.0 */
/* sym: _vt$11It_001FD9C8 = 0x00366AA8 */

struct Obj_001FD9C8;

struct Node_001FD9C8 {
    int m_0;
    Obj_001FD9C8* m_data;
    int m_8;
    Node_001FD9C8* m_next;
    Node_001FD9C8* m_prev;
    int m_14;

    Node_001FD9C8* Valid()
    {
        if ((int)m_data != -1) {
            return this;
        }
        return 0;
    }
    Obj_001FD9C8* GetData() { return m_data; }
};

struct It_001FD9C8 {
    int m_0;
    Node_001FD9C8* m_cur;

    It_001FD9C8() { m_cur = 0; }
    virtual void Reset();
    virtual ~It_001FD9C8() {}

    Obj_001FD9C8* Next()
    {
        m_cur = m_cur->m_next->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    Obj_001FD9C8* Advance(Node_001FD9C8* c)
    {
        m_cur = c->m_next->Valid();
        if (!m_cur) {
            return 0;
        }
        return m_cur->GetData();
    }
    Obj_001FD9C8* First(Node_001FD9C8* h)
    {
        m_cur = h;
        return Next();
    }
};

struct Info_001FD9C8 {
    unsigned char m_0;
    char m_1;
    unsigned short m_2;
    int m_4;
};

struct Obj_001FD9C8 {
    char pad0[0x19];
    unsigned char m_slot;
    char pad1A[0x24 - 0x1A];
    int m_seq;
    char pad28[4];
    Info_001FD9C8* m_info;
    virtual void V0();
    virtual ~Obj_001FD9C8();
};

struct Mgr_001FD9C8 {
    char pad0[0x480];
    int m_seq[256];
    char pad880[4];
    Node_001FD9C8 m_lists[256];
};

struct Req_001FD9C8 {
    int m_0;
    unsigned char m_4;
    unsigned long m_8;
    void* m_10;
    Mgr_001FD9C8* m_14;
    int m_18;
};

extern "C" int func_001FC488(void* q, Req_001FD9C8* r);
extern "C" void func_001FA9B0(Info_001FD9C8* info, int flags);

struct Sys_001FD9C8 {
    int m_0;
    char m_queue[4];

    void Flush(Mgr_001FD9C8* mgr);
};

void Sys_001FD9C8::Flush(Mgr_001FD9C8* mgr)
{
    It_001FD9C8 it;
    It_001FD9C8* p = &it;
    for (int i = 0; i < 256; i++) {
        Node_001FD9C8* h = &mgr->m_lists[i];
        it.m_cur = h;
        Obj_001FD9C8* o = p->Advance(h);
        if (o) {
            It_001FD9C8* q = &it;
            do {
                Obj_001FD9C8* next = q->Advance(it.m_cur);
                if (o->m_seq != mgr->m_seq[o->m_slot]) {
                    break;
                }
                Req_001FD9C8 r;
                r.m_14 = mgr;
                r.m_0 = 0;
                if (o->m_info->m_4) {
                    r.m_0 = o->m_info->m_4;
                }
                r.m_10 = this;
                r.m_18 = 0;
                r.m_4 = o->m_info->m_0;
                r.m_8 = o->m_info->m_2;
                mgr->m_seq[o->m_slot]++;
                int res = func_001FC488(m_queue, &r);
                if (res != 4) {
                    if (o->m_info) {
                        func_001FA9B0(o->m_info, 3);
                    }
                    delete o;
                }
                if (res != 1) {
                    return;
                }
                o = next;
            } while (o);
        }
    }
}
