struct Opt_002C9090 {
    int m0;
    int m4;
};

struct Item_002C9090 {
    int m0;
    Opt_002C9090 opts[40];
    int pad144;
    int m148;
    int m14C;
    signed char m150;
    signed char m151;
};

struct Board_002C9090 {
    char pad0[0x6A5C];
    int m6A5C;
};

extern "C" Item_002C9090* func_002C0370(Board_002C9090* b, int idx, void* p);
extern "C" void func_002C8CC8(void* self, int v);
extern "C" void func_002C9C18(void* self, int v);
extern "C" void func_002C7488(void* self);
extern "C" void func_002C9DA8(void* self, int v);

struct Sub_002C9090 {
    int m0;
    Board_002C9090* m4;
    Board_002C9090* Get() { return m4; }
};

struct Obj_002C9090 {
    char pad0[0x4];
    Sub_002C9090 m4;
    char padC[0x74 - 0xC];
    int m74;
    char m78[4];
    void Select(int delta);
};

void Obj_002C9090::Select(int delta)
{
    for (int n = m4.Get()->m6A5C; n > 0; n--) {
        m74 += delta;
        if (m74 < 0) m74 = m4.Get()->m6A5C - 1;
        if (m74 >= m4.Get()->m6A5C) m74 = 0;
        Item_002C9090* it = func_002C0370(m4.Get(), m74, m78);
        if (it->m150) break;
    }
    Item_002C9090* it = func_002C0370(m4.Get(), m74, m78);
    if (it->m151) {
        func_002C8CC8(this, it->m14C);
        func_002C7488(this);
        func_002C9DA8(this, 5);
    } else {
        func_002C9C18(this, it->opts[it->m14C].m4);
    }
}
