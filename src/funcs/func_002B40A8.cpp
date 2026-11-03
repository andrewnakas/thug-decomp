struct Heap_002B40A8 {
    char pad0[0x108];
    int m108;
};

extern Heap_002B40A8* D_00388A70;
extern char D_00379B30[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" void func_002DCDE8(int v);
extern "C" int func_0010FC30();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_002B4078();
extern "C" void func_002B3F48();
extern "C" int func_002E4600(char* name, int a, void* buf, int size, int b, int c, int d,
                             void (*cb1)(), void (*cb2)(), void* arg);

struct Obj_002B40A8 {
    char pad[0x99D4];
    char m99D4[0x400];
    int m9DD4;
    int m9DD8;
    void Init();
};

extern "C" void func_002B5608(Obj_002B40A8* o, int v);

void Obj_002B40A8::Init()
{
    char buf[256];
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_003267F8();
    func_002DCDE8(100);
    func_002B5608(this, 4);
    m9DD8 = func_0010FC30();
    func_003331D0(buf, D_00379B30);
    m9DD4 = func_002E4600(buf, 0, m99D4, 0x400, 0, 0, 0, func_002B4078, func_002B3F48, this);
    func_00326938();
    func_0010A9B0(D_00388A70);
}
