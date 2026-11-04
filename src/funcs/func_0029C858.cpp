typedef int qword __attribute__((mode(TI)));

union Vec_0029C858 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_0029C858 {
    Vec_0029C858 start;
    Vec_0029C858 end;
    void (*cb)(void*);
    char pad[0xC0 - 0x24];
    struct Ref {
        void* p;
        void Release() {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char pad2[0xE0 - 0xC4];
    ~Coll_0029C858() { mC0.Release(); }
};

extern int D_00391F40;
extern "C" void func_0029C7B0(void* o);
extern "C" void* func_00209240(Coll_0029C858* c);
extern "C" void func_00209350(Coll_0029C858* c, int a, int b);
extern "C" void func_002093E8(Coll_0029C858* c, int a, int b);

extern "C" int func_0029C858(Vec_0029C858* a, Vec_0029C858* b)
{
    D_00391F40 = 0;
    Coll_0029C858 c;
    func_00209240(&c);
    c.start = *a;
    c.end = *b;
    func_00209350(&c, 0, 0x50);
    c.cb = func_0029C7B0;
    func_002093E8(&c, 1, 0);
    return D_00391F40;
}
