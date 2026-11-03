struct Heap_001F0750 {
    char m_pad[0xEC];
    int m_EC;
};

struct Script_001F0750;

struct Entry_001F0750 {
    char m_0[2];
    unsigned char m_type;
    char m_3[0xC - 3];
    int (*m_fn)(void* params, Script_001F0750* script);
};

struct Script_001F0750 {
    char m_pad0[0xB8];
    int m_B8;
    char m_padBC[0xCC - 0xBC];
    unsigned int m_active : 1;
    unsigned int m_b1 : 1;
    unsigned int m_b2 : 1;
    unsigned int m_b3 : 1;
    int m_D0;
    void* m_D4;
    void* m_D8;
};

extern Heap_001F0750* D_00388A70;
extern void* D_00392068;
extern "C" Entry_001F0750* func_001E5040(int name);
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_00121960(int size);
extern "C" Script_001F0750* func_001EE428(void* mem);
extern "C" void func_001EE4D8(Script_001F0750* s, int flags);
extern "C" void func_001EE8C8(Script_001F0750* s, int name, void* params, void* obj);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* s, void* p);
extern "C" int func_002A19A8(void* p);
extern "C" void func_001F0638(int name, int a, int b, int c);

extern "C" Script_001F0750* func_001F0750(int name, void* params, void* data, void* extra, int t0, int t1, int t2,
                                          int t3, int b1, int b3)
{
    Entry_001F0750* e = func_001E5040(name);
    if (e && e->m_type == 8) {
        func_0010A950(D_00388A70, D_00388A70->m_EC);
        Script_001F0750* s = func_001EE428(func_00121960(0xF4));
        func_0010A9B0(D_00388A70);
        e->m_fn(params, s);
        if (s) {
            func_001EE4D8(s, 3);
        }
        return 0;
    }
    Script_001F0750* s = func_001EE428(func_00121960(0xF4));
    func_001EE8C8(s, name, params, 0);
    s->m_active = 1;
    s->m_b2 = 0;
    s->m_b1 = b1;
    s->m_b3 = b3;
    s->m_D0 = t1;
    s->m_B8 = t0;
    if (data) {
        s->m_D4 = data;
        s->m_D8 = func_001E6978(func_001190D0(8));
        if (extra) {
            func_001E6A50(s->m_D8, extra);
        }
    }
    void* mgr = D_00392068;
    if (t2 && func_002A19A8(mgr)) {
        func_001F0638(name, 0, t0, t3);
    }
    return s;
}
