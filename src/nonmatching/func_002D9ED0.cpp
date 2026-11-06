/* fuzzy: 92.6 */
struct Pool_002D9ED0 {
    char pad[0x108];
    int m108;
};

struct Skater_002D9ED0 {
    char pad[0x18];
    int m18;
};

struct Pl_002D9ED0 {
    char pad[0x18];
    Skater_002D9ED0* m18;
    char pad1C[0x24 - 0x1C];
    int m24;
};

struct It_002D9ED0 {
    int m0;
    void* cur;
    void* vt;
};

struct Funcs_002D9ED0 {
    void (*f0)(void* a, char* name, int b, int c, int d);
    void* pad[5];
    void (*f6)(void* a, char* name, int b, int c, int d);
};

struct Obj_002D9ED0 {
    char pad[0xC];
    void* mC;
    unsigned int m10;
};

extern void* D_00392068;
extern Pool_002D9ED0* D_00388A70;
extern char D_00371C78[];
extern char D_00392E90[];
extern char D_00392EB8[];
extern char D_0037C9A8[];
extern Funcs_002D9ED0 D_00355DE0;
extern int D_00355DC0[];
extern int D_00390EF8;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" Pl_002D9ED0* func_002A53F8(void* g, It_002D9ED0* it, int a);
extern "C" Pl_002D9ED0* func_002A5490(void* g, It_002D9ED0* it, int a);
extern "C" int func_00185578(Skater_002D9ED0* s, unsigned int checksum);
extern "C" int func_002B1108(void* g, int id);
extern "C" int func_002A8580(void* g);
extern "C" void func_002F2030(void* a, int b, int c);
extern "C" void func_002DA080(Obj_002D9ED0* o);
extern "C" unsigned int func_0010FC30();

extern "C" void func_002D9ED0(Obj_002D9ED0* self, int flag)
{
    void* g = D_00392068;
    It_002D9ED0 it;
    it.vt = D_00371C78;
    it.cur = 0;
    if (!self->mC) return;
    func_0010A950(D_00388A70, D_00388A70->m108);
    for (Pl_002D9ED0* p = func_002A53F8(g, &it, 0); p; p = func_002A5490(g, &it, 0)) {
        func_00185578(p->m18, 0xD262802F);
        int id = p->m18->m18;
        D_00355DE0.f6(self->mC, D_00392E90, D_00355DC0[0], func_002B1108(g, id), id);
        D_00355DE0.f6(self->mC, D_00392EB8, D_00355DC0[0], p->m24, id);
    }
    bool b = func_002A8580(g) != 0;
    int f = (D_00390EF8 != 0) | b;
    D_00355DE0.f0(self->mC, D_0037C9A8, D_00355DC0[0], f, 0);
    func_002F2030(self->mC, 0, flag);
    if (flag) func_002DA080(self);
    self->m10 = func_0010FC30();
    func_0010A9B0(D_00388A70);
    it.vt = D_00371C78;
}
