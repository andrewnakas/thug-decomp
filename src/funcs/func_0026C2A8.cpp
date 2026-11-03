extern char D_00391368[];
extern char D_00391370[];
extern void* D_00391360;

struct Gap_0026C2A8 {
    int m0;
    void* m4;
    int m8;
    unsigned int mC;
    char m10[0x20];
    int m30;
    int m34;
    float m38;
    float m3C;
    int m40;
    char m44[0xC];
    char m50[0x24];
    unsigned int m74;
};

extern "C" void* func_001046B0(int size);
extern "C" void func_001022D8(void* p);
extern "C" void* func_00229DF0(void* node);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void func_0026C9F0(void* list, unsigned int* key, Gap_0026C2A8* gap);
extern "C" int func_0026C480(unsigned int type);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* mgr, unsigned int id);
extern "C" void func_0026C4E8(Gap_0026C2A8* gap, void* p);
extern "C" void func_00229FF8(void* params, void* pos);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

void CreateGap_0026C2A8(void* node, int type)
{
    Gap_0026C2A8* g = (Gap_0026C2A8*)func_001046B0(0x80);
    func_001022D8(g->m50);
    g->m30 = type;
    g->m4 = node;
    g->m40 = 0;
    g->m34 = 2;
    void* params = func_00229DF0(node);
    func_001E84E8(params, D_00391368, &g->mC, 0);
    func_0026C9F0(D_00391360, &g->mC, g);
    unsigned int t;
    if (func_001E84E8(params, D_00391370, &t, 0))
        g->m34 = func_0026C480(t);
    func_0026C4E8(g, func_00132FD0(func_00131E48(), g->mC));
    func_00229FF8(params, g->m10);
    func_001E7EB0(params, 0xC48391A5, &g->m38, 0);
    g->m3C = g->m38 * g->m38;
    func_001E8398(params, 0x2CA8A299, &g->m74, 0);
}
