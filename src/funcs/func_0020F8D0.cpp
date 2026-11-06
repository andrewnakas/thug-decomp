struct Color_0020F8D0 {
    unsigned char r, g, b, a;
    Color_0020F8D0() {}
    Color_0020F8D0(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
};

struct Node_0020F8D0 {
    char pad[0x14];
    Node_0020F8D0* m_next;
};

extern char D_0038F3E8[];
extern char D_0038F3F0[];
extern char D_003702F0[];
extern void* D_0039274C;
extern void* D_0038C608;

extern "C" int func_001E88F8(void* params, const char* name, unsigned int* out, int req);
extern "C" int func_001E7E58(void* params, const char* name, unsigned int* out, int req);
extern "C" int func_001E84E8(void* params, const char* name, unsigned int* out, int req);
extern "C" void* func_00131E48();
extern "C" void* func_00131E88();
extern "C" void* func_002BDD30(void* p);
extern "C" void* func_00131DD8(void* p);
extern "C" void func_0020F278(void* obj, Color_0020F8D0 c, unsigned int mode);
extern "C" void func_00134808(void* obj, Color_0020F8D0 c);
extern "C" Node_0020F8D0* func_00187278(void* mgr, unsigned int name);
extern "C" void func_0018DFF0(Node_0020F8D0* n, Color_0020F8D0 c);

bool Cmd_0020F8D0(void* params)
{
    unsigned int rgb;
    func_001E88F8(params, D_0038F3E8, &rgb, 1);
    unsigned int rgb2 = rgb;
    func_001E7E58(params, D_0038F3F0, &rgb2, 0);
    unsigned int mode = 0;
    func_001E84E8(params, D_003702F0, &mode, 0);
    void* obj = func_00131E48();
    Color_0020F8D0 c1;
    c1.r = rgb;
    c1.g = rgb >> 8;
    c1.b = rgb >> 16;
    c1.a = 0x80;
    Color_0020F8D0 c2;
    c2.r = rgb2;
    c2.g = rgb2 >> 8;
    c2.b = rgb2 >> 16;
    c2.a = 0x80;
    if (obj) {
        if (rgb != 0x808080 && (mode == 0xE3714DC1 || mode == 0)) {
            Color_0020F8D0 g(0x80, 0x80, 0x80, 0x80);
            func_0020F278(obj, g, mode);
        }
        if (!(mode == 0xE3714DC1 || mode == 0) || rgb == 0x808080)
            func_0020F278(obj, c1, mode);
        if (mode == 0xE3714DC1 || mode == 0)
            func_00134808(obj, c1);
    }
    obj = func_00131DD8(func_002BDD30(D_0039274C));
    if (obj) {
        if (!(mode == 0xE3714DC1 || mode == 0) || rgb == 0x808080)
            func_0020F278(obj, c1, mode);
        if (mode == 0xE3714DC1 || mode == 0)
            func_00134808(obj, c1);
    }
    obj = func_00131E88();
    if (obj)
        func_0020F278(obj, c2, mode);
    if (mode == 0xE3714DC1 || mode == 0) {
        for (Node_0020F8D0* n = func_00187278(D_0038C608, 0x286A8D26); n; n = n->m_next)
            func_0018DFF0(n, c1);
    }
    return true;
}
