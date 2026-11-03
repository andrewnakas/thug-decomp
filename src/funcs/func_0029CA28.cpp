typedef int qword __attribute__((mode(TI)));

union Vec_0029CA28 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_0029CA28 {
    char pad[0xC0];
    struct Ref {
        void* p;
        ~Ref() {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
        void Release() {}
    } mC0;
    char pad2[0xE0 - 0xC4];
    ~Coll_0029CA28() { mC0.Release(); }
};

struct Obj_0029CA28;
extern "C" float func_001E5318(unsigned int name, int a);
extern "C" bool func_0029C8F0(Obj_0029CA28* o, Vec_0029CA28* a, Vec_0029CA28* b, float* y);
extern "C" int func_0029C858(Vec_0029CA28* a, Vec_0029CA28* b);
extern "C" void func_00209240(Coll_0029CA28* c);
extern "C" void func_00209350(Coll_0029CA28* c, int a, int b);
extern "C" void func_00209360(Coll_0029CA28* c, Vec_0029CA28* a);
extern "C" void func_00209370(Coll_0029CA28* c, Vec_0029CA28* b);
extern "C" bool func_002093E8(Coll_0029CA28* c, int a, int b);

struct Obj_0029CA28 {
    char pad[0x40];
    Vec_0029CA28 pos;
    char pad2[0x94 - 0x50];
    int m94;
    int m98;
    bool Snap(Vec_0029CA28* target, float up);
};

bool Obj_0029CA28::Snap(Vec_0029CA28* target, float up)
{
    Vec_0029CA28 top = pos;
    Vec_0029CA28 bot = pos;
    top.f.y += up;
    bot.f.y += func_001E5318(0xF230D521, 0);
    Vec_0029CA28 a = top;
    Vec_0029CA28 b = bot;
    float y;
    bool ok = func_0029C8F0(this, &a, &b, &y) != 0;
    if (!ok)
        return false;
    b = pos;
    a = *target;
    b.f.y = y + 72.0f;
    a.f.y = y + 72.0f;
    if (!m94) {
        if (func_0029C858(&a, &b))
            ok = false;
    }
    if (!m98) {
        Coll_0029CA28 c;
        func_00209240(&c);
        func_00209350(&c, 0x10, 0);
        func_00209360(&c, &a);
        func_00209370(&c, &b);
        if (func_002093E8(&c, 1, 0))
            ok = false;
    }
    if (ok) {
        pos.f.y = y;
        return true;
    }
    return false;
}
