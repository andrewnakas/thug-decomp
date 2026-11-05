struct Obj_00239358 {
    short m0;
    short m_2;
};

struct Sk_00239358 {
    char pad[0x18];
    unsigned short m_18;
};

struct Pl_00239358 {
    char pad[0x1C];
    int m_1C;
};

extern void* D_0038FC78;
extern void* D_00392068;
extern "C" Sk_00239358* func_0022DF08(void* self, int id);
extern "C" Pl_00239358* func_002A52F0(void* a, int id);

int Get_00239358(Obj_00239358* o)
{
    void* net = D_00392068;
    Sk_00239358* s = func_0022DF08(D_0038FC78, o->m_2);
    if (!s) {
        return 0;
    }
    Pl_00239358* p = func_002A52F0(net, s->m_18);
    if (!p) {
        return 0;
    }
    return p->m_1C;
}
