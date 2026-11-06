/* sym: _vt$11It_001FC9A0 = 0x00366A90 */

struct Node_001FC9A0 {
    int m0;
    void* m4;
    int m8;
    Node_001FC9A0* mC;
    Node_001FC9A0* m10;
    Node_001FC9A0* Valid() { if (~(int)m4 == 0) return 0; return this; }
    void* GetData() { return m4; }
};

class It_001FC9A0 {
public:
    int m0;
    Node_001FC9A0* cur;
    It_001FC9A0() {}
    virtual ~It_001FC9A0() {}
    virtual void Run();
    void* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    void* First(Node_001FC9A0* h)
    {
        cur = h;
        return Next();
    }
};

struct Rec_001FC9A0 {
    int m_size;
    int m_id;
    unsigned char m_type;
    char m_name[0x2C - 9];
    char* m_buf;
    char* m_end;
    char pad34[0x3C - 0x34];
    int m_crc;
};

class ObjBase_001FC9A0 : public Node_001FC9A0 {
public:
    virtual ~ObjBase_001FC9A0();
};

class Obj_001FC9A0 : public ObjBase_001FC9A0 {
public:
    virtual ~Obj_001FC9A0();
    Rec_001FC9A0* m_rec;
};

struct Mgr_001FC9A0 {
    char pad[0x2084];
    Node_001FC9A0 m_list;
};

struct Msg_001FC9A0 {
    char* m_data;
    unsigned char m_type;
    long m_size;
    int m10;
    Mgr_001FC9A0* m14;
    int m_flags;
};

struct Hdr_001FC9A0 {
    int m0;
    char pad4[0x20 - 4];
    int m_size;
    int m_id;
    int m_crc;
    unsigned char m_type;
    char m_data[1];
};

struct Pool_001FC9A0 {
    char pad[0xF4];
    int mF4;
};

extern Pool_001FC9A0* D_00388A70;
extern "C" void func_0010A950(Pool_001FC9A0* pool, int a);
extern "C" void func_0010A9B0(Pool_001FC9A0* pool);
extern "C" void* func_0010A638(Pool_001FC9A0* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(Pool_001FC9A0* pool, void* p);
extern "C" void* func_001046B0(int size);
extern "C" int func_001053C8(void* p, unsigned int n);
extern "C" Rec_001FC9A0* func_001FA780(void* mem);
extern "C" Obj_001FC9A0* func_001FA758(void* mem, Rec_001FC9A0* r);
extern "C" void func_001FA7A0(Rec_001FC9A0* r, int flags);
extern "C" int func_001FC488(void* a, Msg_001FC9A0* m);
extern "C" void* func_00331404(void* d, const void* s, int n);
extern "C" char* func_00331A9C(char* d, const void* s);

extern "C" int func_001FC9A0(Msg_001FC9A0* m)
{
    func_0010A950(D_00388A70, D_00388A70->mF4);
    switch (m->m_type) {
    case 0xE: {
        It_001FC9A0 it;
        Hdr_001FC9A0* h = (Hdr_001FC9A0*)m->m_data;
        Obj_001FC9A0* o;
        for (o = (Obj_001FC9A0*)it.First(&m->m14->m_list); o; o = (Obj_001FC9A0*)it.Next()) {
            if (o->m_rec->m_id == h->m_id) {
                func_0010A9B0(D_00388A70);
                return 3;
            }
        }
        Rec_001FC9A0* r = func_001FA780(func_0010A638(D_00388A70, 0x44, 1, 0));
        func_00331A9C(r->m_name, h);
        r->m_size = h->m_size;
        r->m_id = h->m_id;
        r->m_crc = h->m_crc;
        r->m_type = h->m_type;
        char* p = (char*)func_0010A638(D_00388A70, h->m_size, 1, 0);
        r->m_buf = p;
        r->m_end = p;
        int n = h->m_size;
        if (n > 0x100) n = 0x100;
        func_00331404(p, h->m_data, n);
        r->m_end += n;
        o = func_001FA758(func_001046B0(0x1C), r);
        Node_001FC9A0* l = &m->m14->m_list;
        o->m10 = l->m10;
        o->mC = l;
        l->m10->mC = o;
        l->m10 = o;
        if ((unsigned int)(r->m_end - r->m_buf) >= (unsigned int)r->m_size) {
            Msg_001FC9A0 t;
            t.m14 = m->m14;
            t.m10 = m->m10;
            t.m_flags = 0;
            t.m_type = r->m_type;
            t.m_size = r->m_size;
            t.m_data = (char*)func_0010A638(D_00388A70, r->m_size, 1, 0);
            func_00331404(t.m_data, r->m_buf, r->m_size);
            int res = func_001FC488((char*)m->m10 + 4, &t);
            if (res != 4) {
                if (o->m_rec) func_001FA7A0(o->m_rec, 3);
                delete o;
            }
            if (t.m_data) func_0010A8D8(D_00388A70, t.m_data);
            func_0010A9B0(D_00388A70);
            return res;
        }
        break;
    }
    case 0xF: {
        It_001FC9A0 it;
        int* d = (int*)m->m_data;
        Obj_001FC9A0* o;
        for (o = (Obj_001FC9A0*)it.First(&m->m14->m_list); o; o = (Obj_001FC9A0*)it.Next()) {
            Rec_001FC9A0* r = o->m_rec;
            if (r->m_id == d[0]) {
                int n = m->m_size - 4;
                func_00331404(r->m_end, d + 1, n);
                r->m_end += n;
                if ((unsigned int)(r->m_end - r->m_buf) >= (unsigned int)r->m_size) {
                    Msg_001FC9A0 t;
                    t.m14 = m->m14;
                    t.m10 = m->m10;
                    t.m_flags = 0;
                    t.m_type = r->m_type;
                    t.m_size = r->m_size;
                    t.m_data = (char*)func_0010A638(D_00388A70, r->m_size, 1, 0);
                    func_00331404(t.m_data, r->m_buf, r->m_size);
                    if (func_001053C8(t.m_data, r->m_size) != r->m_crc) t.m_flags |= 4;
                    int res = func_001FC488((char*)m->m10 + 4, &t);
                    if (res != 4) {
                        if (o->m_rec) func_001FA7A0(o->m_rec, 3);
                        delete o;
                    }
                    if (t.m_data) func_0010A8D8(D_00388A70, t.m_data);
                    func_0010A9B0(D_00388A70);
                    return res;
                }
            }
        }
        break;
    }
    }
    func_0010A9B0(D_00388A70);
    return 1;
}
