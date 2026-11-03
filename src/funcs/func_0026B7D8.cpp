extern char D_003912E8[];
extern char D_003912F0[];
extern char D_003912F8[];
extern void* D_0038C608;

struct Goal_0026B7D8;

struct List_0026B7D8 {
    int m0;
    Goal_0026B7D8* m4;
};

struct Skate_0026B7D8 {
    char m_pad[0x2C];
    List_0026B7D8* m2C;
};
extern Skate_0026B7D8* D_0038FC78;

struct Skater_0026B7D8 {
    char m_pad[0x31C];
    int m31C;
};

struct Goal_0026B7D8 {
    int m0;
    void* m4;
    int m8;
    unsigned int mC;
    char m10[0x20];
    int m30;
    int m34;
    int m38;
    unsigned int m3C;
    int m40;
    int m44;
    int m48;
    float m4C;
    float m50;
    int m54;
    char m58[8];
    char m60[0x24];
    unsigned int m84;
    Goal_0026B7D8* m88;
};

extern "C" void* func_001046B0(int size);
extern "C" void func_001022D8(void* p);
extern "C" void* func_00229DF0(void* node);
extern "C" bool func_001E84E8(void* params, char* name, void* out, int required);
extern "C" int func_0026BD60(unsigned int type);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* mgr, unsigned int id);
extern "C" void func_0026BF28(Goal_0026B7D8* g, void* p);
extern "C" void func_00229FF8(void* params, void* pos);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" Skater_0026B7D8* func_00187B48(void* mgr, int index);
extern "C" void func_0026BDF0(Goal_0026B7D8* g, int type);

void CreateGoal_0026B7D8(void* node, int type)
{
    Skate_0026B7D8* sk = D_0038FC78;
    Goal_0026B7D8* g = (Goal_0026B7D8*)func_001046B0(0x90);
    func_001022D8(g->m60);
    g->m88 = sk->m2C->m4;
    sk->m2C->m4 = g;
    g->m4 = node;
    g->m30 = type;
    g->m54 = 0;
    g->m48 = 0;
    void* params = func_00229DF0(node);
    func_001E84E8(params, D_003912E8, &g->mC, 0);
    unsigned int t;
    if (func_001E84E8(params, D_003912F0, &t, 0))
        g->m48 = func_0026BD60(t);
    func_0026BF28(g, func_00132FD0(func_00131E48(), g->mC));
    func_00229FF8(params, g->m10);
    g->m44 = 0;
    func_001E7DE8(params, 0x7321A8D6, &g->m44, 0);
    func_001E7EB0(params, 0xC48391A5, &g->m4C, 0);
    g->m50 = g->m4C * g->m4C;
    func_001E8398(params, 0x2CA8A299, &g->m84, 0);
    g->m34 = 0;
    g->m38 = 0;
    g->m3C = 0;
    if (func_001E8708(params, 0x5113F19C)) {
        g->m40 = -1;
        func_001E84E8(params, D_003912F8, &g->m34, 0);
        return;
    }
    g->m40 = 0;
    g->m30 = 1;
    int i = 0;
    Skater_0026B7D8* s;
    while ((s = func_00187B48(D_0038C608, i)) && i < 32) {
        if (s->m31C)
            g->m3C |= 1 << i;
        i++;
    }
    func_0026BDF0(g, 0);
    func_0026BDF0(g, type);
}
