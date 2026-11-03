struct Pool_002D3288 {
    char pad[0x104];
    int m104;
};

struct Obj_002D3288 {
    char pad[0x15C];
    int m15C;
    int m160;
    int m164;
    int m168;
};

struct Glob_002D3288 {
    int m0;
    Obj_002D3288* m4;
};

extern Glob_002D3288* D_00392068;
extern char* D_0038C308;
extern Pool_002D3288* D_00388A70;
extern char D_004532C8[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_001E8870(void* params, int name, char** out, int a);
extern "C" int func_001E7DE8(void* params, int name, int* out, int a);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int a);
extern "C" void* func_002A2AE8(void* g, int a, int b, int c, int d);
extern "C" void* func_002D3D30(void* o);
extern "C" int func_00326E30(char* s);
extern "C" void func_00306100(void* x, int addr, unsigned short port, int v);
extern "C" void* func_002012B0(void* s);
extern "C" int func_00303E38(void* a, int b, int c, void* d, void* e, int f);
extern "C" void func_00105260(char* p, int v);
extern "C" void func_002012B8(void* s, void* f);
extern "C" void func_00303958();
extern "C" void func_002D3228();
extern "C" void func_002D30E8();
extern "C" void func_002D2730();

bool func_002D3288(void* params, void* script)
{
    char* str = 0;
    int port = 0;
    Glob_002D3288* g = D_00392068;
    char* q = D_0038C308;
    func_0010A950(D_00388A70, D_00388A70->m104);
    Obj_002D3288* o = g->m4;
    func_001E8870(params, 0, &str, 0);
    func_001E7DE8(params, 0, &port, 0);
    func_001E8398(params, 0x751F4599, &o->m15C, 0);
    void* s = func_002A2AE8(g, 0, 0, 1, 0);
    void* x = func_002D3D30(o);
    func_00306100(x, func_00326E30(str), port, o->m15C);
    if (func_00303E38(func_002012B0(s), o->m15C, 1, (void*)func_002D3228, (void*)func_002D30E8, o->m15C)) {
        func_00303958();
        func_0010A9B0(D_00388A70);
        return false;
    }
    func_00105260(q + 8, o->m164);
    func_002012B8(s, (void*)func_002D2730);
    func_00105260(q + 8, o->m168);
    D_004532C8[0] = 0;
    func_0010A9B0(D_00388A70);
    return true;
}
