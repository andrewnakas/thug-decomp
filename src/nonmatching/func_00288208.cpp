/* fuzzy: 92.1 */
typedef int qword __attribute__((mode(TI)));

union Vec_00288208 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_00288208 {
    Vec_00288208 start;
    Vec_00288208 end;
    char pad[0xA0 - 0x20];
    Vec_00288208 hit;
    Vec_00288208 normal;
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
    ~Coll_00288208() { mC0.Release(); }
};

extern "C" void func_00209240(Coll_00288208* c);
extern "C" bool func_002093E8(Coll_00288208* c, int a, int b);
extern "C" float func_002032A0(unsigned int, int);

struct Body_00288208 {
    char pad[0x50];
    Vec_00288208 m50;
};
struct Sub_00288208 {
    char pad[0xA0];
    int mA0;
};

struct Obj_00288208 {
    char pad0[0xC];
    Body_00288208* mC;
    char pad10[0x5B0 - 0x10];
    Sub_00288208* m5B0;
    bool Probe(Vec_00288208* pos);
};

bool Obj_00288208::Probe(Vec_00288208* pos)
{
    if (m5B0->mA0) return false;
    Coll_00288208 c;
    func_00209240(&c);
    float h = func_002032A0(0x786B3272, 0);
    Body_00288208* b = mC;
    c.start = b->m50;
    float sy = c.start.f.y + h;
    c.start.f.y = sy;
    c.end = b->m50;
    float py = pos->f.y;
    if (py < b->m50.f.y) c.end.f.y = py;
    if (sy < py + h) c.start.f.y = py + h;
    float ny;
    if (func_002093E8(&c, 1, 0) && 0.5f < (ny = c.normal.f.y)) {
        Vec_00288208 n;
        n.f.x = c.hit.f.x + c.normal.f.x;
        n.f.y = c.hit.f.y + ny;
        n.f.z = c.hit.f.z + c.normal.f.z;
        n.f.w = c.hit.f.w + c.normal.f.w;
        c.start = *pos;
        c.end = n;
        c.start.f.y += h;
        c.end.f.y += h;
        if (!func_002093E8(&c, 1, 0)) {
            mC->m50 = n;
            mC->m50.f.y += 0.1f;
            return true;
        }
    }
    return false;
}
