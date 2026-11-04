typedef int qword __attribute__((mode(TI)));

union Vec_00298CC8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_00298CC8 {
    char pad[0xA0];
    Vec_00298CC8 hit;
    Vec_00298CC8 normal;
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

extern "C" void func_00209240(Coll_00298CC8* c);
extern "C" void func_00209360(Coll_00298CC8* c, Vec_00298CC8* a);
extern "C" void func_00209370(Coll_00298CC8* c, Vec_00298CC8* b);
extern "C" bool func_002093E8(Coll_00298CC8* c, int a, int b);

struct Obj_00298CC8 {
    char pad[0x10];
    Vec_00298CC8 pos;
    float Probe();
};

float Obj_00298CC8::Probe()
{
    Vec_00298CC8 off;
    off.f.x = 0.0f;
    off.f.y = 10000.0f;
    off.f.z = 0.0f;
    off.f.w = 0.0f;
    Coll_00298CC8 c;
    Coll_00298CC8* pc = &c;
    func_00209240(pc);
    Vec_00298CC8 v;
    Vec_00298CC8* pv = &v;
    v.f.x = pos.f.x + off.f.x;
    v.f.y = pos.f.y + off.f.y;
    v.f.z = pos.f.z + off.f.z;
    v.f.w = pos.f.w + off.f.w;
    func_00209360(pc, pv);
    v.f.x = pos.f.x - off.f.x;
    v.f.y = pos.f.y - off.f.y;
    v.f.z = pos.f.z - off.f.z;
    v.f.w = pos.f.w - off.f.w;
    func_00209370(pc, pv);
    if (func_002093E8(pc, 1, 0)) {
        float y = c.hit.f.y;
        pc->mC0.Release();
        return y;
    }
    pc->mC0.Release();
    return 0.0f;
}
