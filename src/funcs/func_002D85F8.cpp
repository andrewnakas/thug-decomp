struct Game_002D85F8 {
    int m0;
    int m4;
    int m8;
    void* mC;
};

extern Game_002D85F8* D_00392068;
extern "C" int func_001E87B8(void* p, char* name);
extern "C" int func_001E7D18(void* p, char* name, char** out, int v);
extern "C" void func_001E7E58(void* p, char* name, int* out, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_002D3D30(int id);
extern "C" int func_00305F28(void* p);
extern "C" void func_002A18D8(Game_002D85F8* g, int v);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_002D8248(void* p, int v, char* a, char* b);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" char* func_00327098(int v);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int v);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, char* v);
extern "C" int func_00100030(int n);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern char D_00392DE0[];
extern char D_0037C308[];
extern char D_00392DC0[];
extern char D_0037C3C0[];
extern char D_0037C3D0[];
extern char D_0037C608[];
extern char D_0037C618[];
extern char D_0037C630[];
extern char D_0037C648[];

bool Cmd_002D85F8(void* params, void* script)
{
    char buf[1024];
    char* name;
    int a;
    int b;
    int c;
    int same = 0;
    Game_002D85F8* g = D_00392068;
    int flag = func_001E87B8(params, D_00392DE0);
    func_001E7D18(params, D_0037C308, &name, 1);
    func_001E7E58(params, D_00392DC0, &a, 1);
    func_001E7E58(params, D_0037C3C0, &b, 1);
    func_001E7E58(params, D_0037C3D0, &c, 1);
    func_003331D0(buf, D_0037C608, a, b, c, name);
    if (a == func_00305F28(func_002D3D30(g->m4))) {
        c = 0x141E;
        same = 1;
        a = b;
    }
    if (flag) {
        func_002A18D8(g, 1);
        func_002D8248(g->mC, 2, func_001E54B8(D_0037C618, 0), buf);
    } else {
        func_002A18D8(g, 0);
        func_002D8248(g->mC, 2, func_001E54B8(D_0037C630, 0), buf);
    }
    void* s = func_001E6978(func_001190D0(8));
    char* str = func_00327098(a);
    func_001E7A68(s, 0, 1, c);
    func_001E7A30(s, 0, 3, str);
    if (!same) {
        func_001E7A68(s, 0x751F4599, 13, func_00100030(0xFFFF));
    }
    func_001F0370(D_0037C648, s, 0, 0);
    if (s) func_001E6AE8(s, 3);
    return true;
}
