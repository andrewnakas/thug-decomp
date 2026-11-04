struct Heap_002D0B00 {
    char pad0[0x104];
    void* m104;
    void* m108;
};

struct Mgr_002D0B00 {
    char pad0[0xC];
    void* mC;
};

extern Heap_002D0B00* D_00388A70;
extern Mgr_002D0B00* D_00392068;
extern char D_0037B7F8[];
extern char D_0037B808[];
extern char D_00392B60[];
extern "C" void func_0010A950(void* h, void* ctx);
extern "C" void func_0010A9B0(void* h);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" int func_002A6070(Mgr_002D0B00* m);
extern "C" int func_001F0D78(char* s);
extern "C" int func_00202F78(int a, int b, int c);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_002D8158(void* p);
extern "C" unsigned int func_0010FC30();
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_002D2148();
extern "C" void func_002D2258();
extern "C" void func_00305400(void* a, char* name, int id, void (*f1)(), void (*f2)(), void* self, int z);

struct Obj_002D0B00 {
    char pad0[0x148];
    int m148;
    char pad14C[0x158 - 0x14C];
    void* m158;
    void Start();
};

void Obj_002D0B00::Start()
{
    Mgr_002D0B00* mgr = D_00392068;
    Heap_002D0B00* h = D_00388A70;
    func_0010A950(h, h->m108);
    func_003267F8();
    int a = func_002A6070(mgr);
    int b = func_001F0D78(D_0037B7F8);
    int x = func_00202F78(a, b, func_001F0D78(D_0037B808));
    char buf[0x80];
    if (func_002D7EB8(mgr->mC))
        func_003331D0(buf, D_00392B60, func_002D8158(mgr->mC), x);
    else
        func_003331D0(buf, D_00392B60, func_0010FC30(), x);
    m148 = 1;
    func_00305400(m158, buf, func_002D8158(mgr->mC), func_002D2148, func_002D2258, this, 0);
    func_00326938();
    func_0010A9B0(D_00388A70);
}
