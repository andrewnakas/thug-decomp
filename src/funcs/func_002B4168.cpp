struct Heap_002B4168 {
    char pad0[0x108];
    int m108;
};

extern Heap_002B4168* D_00388A70;
extern char D_00379B58[];
extern char D_00379B68[];
extern char D_003799D0[];
extern char D_00392480[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" int func_00326938();
extern "C" int func_0010FC30();
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int v);
extern "C" int func_001E7D18(void* p, char* name, char** out, int req);
extern "C" void func_002B4080();
extern "C" int func_002F4538(int a, int size, char* name, int b, int c, void (*cb)());

struct Obj_002B4168 {
    char pad[0x9DD4];
    int m9DD4;
    int m9DD8;
    void Start();
};

extern "C" void* func_002A6070(Obj_002B4168* o);
extern "C" void func_002B5608(Obj_002B4168* o, int v);

void Obj_002B4168::Start()
{
    char* name = D_00379B58;
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_003267F8();
    void* a = func_002A6070(this);
    func_001E7D18(func_00202EF8(a, func_001F0D78(D_00379B68)), D_003799D0, &name, 0);
    m9DD8 = func_0010FC30();
    m9DD4 = func_002F4538(0, 0x27B0, D_00392480, 0, 0, func_002B4080);
    func_002B5608(this, 9);
    func_00326938();
    func_0010A9B0(D_00388A70);
}
