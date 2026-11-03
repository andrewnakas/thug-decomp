struct Heap_002D1888 {
    char pad0[0x104];
    void* m104;
};

struct Count_002D1888 {
    int m0;
    int m4;
    void Inc() { m4++; }
};

struct Info_002D1888 {
    char pad0[0x150];
    Count_002D1888 m150;
    char pad158[0xC];
    int m164;
};

struct Mgr_002D1888 {
    int m0;
    Info_002D1888* m4;
};

struct Snd_002D1888 {
    char pad0[8];
    char m8[4];
};

extern Heap_002D1888* D_00388A70;
extern Mgr_002D1888* D_00392068;
extern Snd_002D1888* D_0038C308;
extern "C" void func_0010A950(void* h, void* ctx);
extern "C" void func_0010A9B0(void* h);
extern "C" void* func_002A39D8(Mgr_002D1888* m);
extern "C" void* func_002012B0(void* p);
extern "C" void func_002D3228();
extern "C" void func_002D30E8();
extern "C" int func_00303E38(void* p, int a, int b, void (*f1)(), void (*f2)(), int c);
extern "C" void func_00303F20(int a);
extern "C" void func_00304190();
extern "C" void func_00105260(void* p, int v);

struct Obj_002D1888 {
    void Run(int a);
};

void Obj_002D1888::Run(int a)
{
    Mgr_002D1888* mgr = D_00392068;
    Snd_002D1888* snd = D_0038C308;
    if (mgr->m4->m150.m4)
        return;
    void* p = func_002A39D8(mgr);
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (func_00303E38(func_002012B0(p), a, 0, func_002D3228, func_002D30E8, a)) {
        func_00303F20(a);
        func_00304190();
        func_0010A9B0(D_00388A70);
        return;
    }
    if (!mgr->m4->m150.m4)
        func_00105260(snd->m8, mgr->m4->m164);
    mgr->m4->m150.Inc();
    func_0010A9B0(D_00388A70);
}
