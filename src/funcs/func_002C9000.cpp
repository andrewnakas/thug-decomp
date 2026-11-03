struct Opt_002C9000 {
    int m0;
    int m4;
};

struct Item_002C9000 {
    int m0;
    Opt_002C9000 opts[40];
    int pad144;
    int m148;
    int m14C;
    signed char m150;
    signed char m151;
};

struct Board_002C9000;

extern "C" Item_002C9000* func_002C0370(Board_002C9000* b, int idx, void* p);
extern "C" void func_002C8CC8(void* self, int v);
extern "C" void func_002C9C18(void* self, int v);

struct Sub_002C9000 {
    int m0;
    Board_002C9000* m4;
};

struct Obj_002C9000 {
    char pad0[0x4];
    Sub_002C9000 m4;
    char padC[0x74 - 0xC];
    int m74;
    char m78[4];
    void Scroll(int delta);
};

void Obj_002C9000::Scroll(int delta)
{
    Item_002C9000* it = func_002C0370(m4.m4, m74, m78);
    int v = it->m14C;
    v += delta;
    if (v < 0) v = it->m148 - 1;
    else if (v >= it->m148) v = 0;
    it->m14C = v;
    if (it->m151) func_002C8CC8(this, v);
    else func_002C9C18(this, it->opts[v].m4);
}
