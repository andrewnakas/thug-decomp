struct Heap_002D3698 {
    char pad0[0x108];
    int m108;
};

struct Thread_002D3698 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)();
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

struct Sub_002D3698 {
    char pad[0x158];
    void* m158;
    char pad2[4];
    void* m160;
};

struct Mgr_002D3698 {
    void* m0;
    Sub_002D3698* m4;
};

extern Heap_002D3698* D_00388A70;
extern Mgr_002D3698* D_00392068;
extern char* D_0038C308;
extern int D_0037BD30[];
extern char D_0037B9E8[];
extern char D_00392BB8[];

extern "C" void* func_003315B8(void* p, int v, int n);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002D3B98(Sub_002D3698* s);
extern "C" int func_003057A8(void* a, char* b, char* c, char* d, char* e, int f, int g, int h, int* i, int* j);
extern "C" void func_002D0B00();
extern "C" int func_002A84B8(void* m);
extern "C" void func_00106038(Thread_002D3698* t);
extern "C" void func_002A84C0(void* m, int v);
extern "C" void* func_002A84D0(void* m);
extern "C" int func_0031BAC0(void* p, Sub_002D3698* o);
extern "C" void func_00105260(void* p, void* q);

bool Cmd_002D3698(void* params, void* script)
{
    int a[3];
    __builtin_memcpy(a, D_0037BD30, 12);
    int b[3];
    Mgr_002D3698* m = D_00392068;
    char* q = D_0038C308;
    func_003315B8(b, 0, 12);
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_002D3B98(m->m4);
    void* x = m->m4->m158;
    func_003057A8(x, D_0037B9E8, D_00392BB8, D_0037B9E8, D_00392BB8, 5, 0xF, 1, a, b);
    Thread_002D3698 t;
    t.m24 = 10;
    t.m18 = func_002D0B00;
    t.m1C = func_002A84B8(m);
    t.m20 = 0x8000;
    t.m10 = 0x152;
    func_00106038(&t);
    func_002A84C0(m, t.m14);
    func_0031BAC0(func_002A84D0(m), m->m4);
    func_00105260(q + 8, m->m4->m160);
    func_0010A9B0(D_00388A70);
    return true;
}
