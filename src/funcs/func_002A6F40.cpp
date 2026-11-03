extern char D_00371C78[];
extern char D_00377D78[];
extern void* D_0038FC78;

struct Iter_002A6F40 {
    int m0;
    int m4;
    void* m8;
    Iter_002A6F40() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A6F40() { m8 = D_00371C78; }
};

struct Obj_002A6F40;
extern "C" int func_002A1A38(Obj_002A6F40* o);
extern "C" int func_002A76F0(Obj_002A6F40* o);
extern "C" int func_002A1CE8(Obj_002A6F40* o);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F590(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" void func_0024FA70(void* p, int v);
extern "C" void func_0024F418(void* p, int v);
extern "C" void func_002A7598(Obj_002A6F40* o);
extern "C" void* func_002A5820(Obj_002A6F40* o);
extern "C" void func_002B2BC0(void* p, int v);
extern "C" void* func_002A53F8(Obj_002A6F40* self, Iter_002A6F40* it, int a);
extern "C" void* func_002A5490(Obj_002A6F40* self, Iter_002A6F40* it, int a);
extern "C" void func_002B2310(void* p);
extern "C" void func_002A8020(Obj_002A6F40* o);
extern "C" unsigned int func_0010FC30();

struct Obj_002A6F40 {
    char pad[0x24];
    int m24;
    int m28;
    char pad2C[4];
    int m30;
    char pad34[0x188 - 0x34];
    unsigned int m188;
    void Start();
};

void Obj_002A6F40::Start()
{
    void* g = D_0038FC78;
    Iter_002A6F40 it;
    int mode;
    if (func_002A1A38(this)) {
        m28 = func_002A76F0(this);
        mode = func_002A1CE8(this);
    } else {
        mode = func_0024F590(func_0022E358(g));
    }
    m24 = func_001F0D78(D_00377D78);
    func_0024FA70(func_0022E358(g), m24);
    func_0024F418(func_0022E358(g), mode);
    m30 = 0;
    func_002A7598(this);
    void* e = func_002A5820(this);
    if (e) func_002B2BC0(e, 0);
    void* p = func_002A53F8(this, &it, 1);
    if (p) do {
        func_002B2310(p);
        p = func_002A5490(this, &it, 1);
    } while (p);
    func_002A8020(this);
    m188 = func_0010FC30();
}
