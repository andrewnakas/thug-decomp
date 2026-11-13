/* fuzzy: 73.5 */
/* blocked: game redoes var*var mult per access (cf. func_001118A0); no C++ shape found */
typedef int qword __attribute__((mode(TI)));

union Vec_00292770 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_00292770 {
    char pad[0xA0];
    Vec_00292770 hit;
    Vec_00292770 normal;
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
};

extern "C" void func_00209240(Coll_00292770* c);
extern "C" void func_00209360(Coll_00292770* c, Vec_00292770* a);
extern "C" void func_00209370(Coll_00292770* c, Vec_00292770* b);
extern "C" bool func_002093E8(Coll_00292770* c, int a, int b);

struct Elem_00292770 {
    Vec_00292770 pos;
    char pad[0x20];
};

struct Obj_00292770 {
    char pad[0x130];
    Elem_00292770 elems[1];
    void Snap(int i);
};

void Obj_00292770::Snap(int i)
{
    Vec_00292770 p = elems[i].pos;
    Vec_00292770 a = p;
    Vec_00292770 b = p;
    a.f.y += 10000.0f;
    b.f.y -= 10000.0f;
    Coll_00292770 c;
    Coll_00292770* pc = &c;
    func_00209240(pc);
    Vec_00292770* pa = &a;
    func_00209360(pc, pa);
    Vec_00292770* pb = &b;
    func_00209370(pc, pb);
    if (func_002093E8(pc, 1, 0)) {
        elems[i].pos = c.hit;
    } else {
        a.f.y += 10000.0f;
        func_00209360(pc, pa);
        func_00209370(pc, pb);
        if (func_002093E8(pc, 1, 0)) {
            elems[i].pos.q = c.hit.q;
        }
    }
    c.mC0.Release();
}
