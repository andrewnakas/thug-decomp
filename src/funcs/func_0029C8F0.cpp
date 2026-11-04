typedef int qword __attribute__((mode(TI)));

union Vec_0029C8F0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_0029C8F0 {
    char pad[0xA0];
    Vec_0029C8F0 hit;
    Vec_0029C8F0 normal;
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
    ~Coll_0029C8F0() { mC0.Release(); }
};

extern int D_00391F40;
extern "C" void func_0029C7B0(void* o);
extern "C" int func_0029C858(Vec_0029C8F0* a, Vec_0029C8F0* b);
extern "C" void func_00209240(Coll_0029C8F0* c);
extern "C" void func_00209360(Coll_0029C8F0* c, Vec_0029C8F0* a);
extern "C" void func_00209370(Coll_0029C8F0* c, Vec_0029C8F0* b);
extern "C" bool func_002093E8(Coll_0029C8F0* c, int a, int b);

struct Obj_0029C8F0 {
    char pad[0x94];
    int m94;
    bool Probe(Vec_0029C8F0* a, Vec_0029C8F0* b, float* outY);
};

bool Obj_0029C8F0::Probe(Vec_0029C8F0* a, Vec_0029C8F0* b, float* outY)
{
    Coll_0029C8F0 c;
    func_00209240(&c);
    func_00209360(&c, a);
    func_00209370(&c, b);
    if (!func_002093E8(&c, 1, 0))
        return false;
    if (m94) {
        D_00391F40 = 0;
        Vec_0029C8F0 p = c.hit;
        *outY = p.f.y;
        return true;
    }
    D_00391F40 = 0;
    func_0029C7B0(&c);
    if (D_00391F40)
        return false;
    Vec_0029C8F0 n = c.normal;
    if (n.f.y < 0.087f)
        return false;
    Vec_0029C8F0 p = c.hit;
    *outY = p.f.y;
    if (!func_0029C858(a, &p))
        return true;
    return false;
}
