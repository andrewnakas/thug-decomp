/* fuzzy: 99.2 */
/* sym: _vt$14Guard_001FCE48 = 0x00366A48 */
struct Heap_001FCE48 {
    char pad0[0xF4];
    int mF4;
};

extern Heap_001FCE48* D_00388A70;
extern "C" void func_0010A950(Heap_001FCE48* heap, int ctx);
extern "C" void func_0010A9B0(Heap_001FCE48* heap);
extern "C" void* func_0010A638(Heap_001FCE48* heap, int size, int a, int b);
extern "C" void* func_001046B0(int size);
extern "C" void* func_001FA918(void* mem, unsigned char flags, unsigned short len, unsigned char* data, unsigned char id);
extern "C" void func_001FA9B0(void* data, int in_chrg);

class Guard_001FCE48 {
public:
    int m0;
    int m4;
    Guard_001FCE48() { m4 = 0; }
    virtual void Run();
    virtual ~Guard_001FCE48() {}
};

struct Stamp_001FCE48 {
    unsigned char b[4];
};

struct Header_001FCE48 {
    unsigned char id;
    unsigned char flags;
    union {
        unsigned int stamp;
        Stamp_001FCE48 raw;
    };
};

class Msg_001FCE48;

class Link_001FCE48 {
public:
    int m0;
    int m4;
    int m8;
    Msg_001FCE48* mC;
    Msg_001FCE48* m10;
    virtual ~Link_001FCE48();
    void InsertBefore(Msg_001FCE48* m);
};

class Msg_001FCE48 : public Link_001FCE48 {
public:
    unsigned char m18;
    unsigned char m19;
    char pad1A[2];
    int m1C;
    int m20;
    unsigned int m24;
    int m28;
    void* m2C;
    Msg_001FCE48* Valid() { return ~m4 ? this : 0; }
};

inline void Link_001FCE48::InsertBefore(Msg_001FCE48* m)
{
    Msg_001FCE48* prev = m10;
    m->mC = (Msg_001FCE48*)this;
    m->m10 = prev;
    m10->mC = m;
    m10 = m;
}

extern "C" Msg_001FCE48* func_001FA720(void* mem, void* data);

struct Queue_001FCE48 {
    char pad0[0x480];
    unsigned int m480[0x101];
    Msg_001FCE48 m884[1];
};

struct Conn_001FCE48 {
    unsigned char* m0;
    int m4;
    long m8;
    int m10;
    Queue_001FCE48* m14;
    int Handle();
};

int Conn_001FCE48::Handle()
{
    Guard_001FCE48 guard;
    unsigned char* p = m0;
    Header_001FCE48 h;
    h.id = *p++;
    h.raw = *(Stamp_001FCE48*)p;
    p += 4;
    if (h.stamp < m14->m480[h.id]) {
        return 1;
    }
    func_0010A950(D_00388A70, D_00388A70->mF4);
    unsigned short len = m8 - 6;
    h.flags = *p++;
    void* data = func_001FA918(func_0010A638(D_00388A70, 0x14, 1, 0), h.flags, len, p, h.id);
    Msg_001FCE48* m = func_001FA720(func_001046B0(0x30), data);
    m->m8 = h.stamp;
    m->m20 = 0;
    m->m1C = 0;
    m->m19 = h.id;
    m->m24 = h.stamp;
    func_0010A9B0(D_00388A70);
    Msg_001FCE48* list = (Msg_001FCE48*)(h.id * 0x18 + (char*)m14 + 0x884);
    int stamp = m->m8;
    bool added;
    Msg_001FCE48* c = list->mC;
    Msg_001FCE48* n;
    while ((n = c->Valid()) != 0) {
        if (n->m8 == stamp) {
            added = false;
            goto done;
        }
        if (stamp < n->m8) {
            n->InsertBefore(m);
            added = true;
            goto done;
        }
        c = n->mC;
    }
    list->InsertBefore(m);
    added = true;
done:
    if (!added) {
        if (m->m2C) {
            func_001FA9B0(m->m2C, 3);
        }
        delete m;
        return 3;
    }
    return 1;
}
