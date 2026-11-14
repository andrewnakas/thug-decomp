/* fuzzy: 93.6 */
/* blocked (lane2 b3): game has a dead `lb $v0,0x58(info)` (info->m58) before both returns (0x1D3B60/0x1D3BC8), which also gives info the $s3 allocation; no non-volatile C++ read survives flow, and nothing shows a handler touching m58. */
typedef int qword __attribute__((mode(TI)));

union Vec_001D3890 {
    qword q;
    struct {
        float x, y, z, w;
    } v;
};

struct Box_001D3890 {
    Vec_001D3890 mn;
    Vec_001D3890 mx;
};

struct Seg_001D3890 {
    Vec_001D3890 a;
    Vec_001D3890 b;
};

struct Info_001D3890 {
    char pad0[0x30];
    float m30;
    char pad34[0x4C - 0x34];
    int m4C;
    int m50;
    int m54;
    signed char m58;
};

class Obj_001D3890 {
public:
    int m0;
    unsigned short m4;
    short m6;
    int m8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int GetId();
    virtual void v11();
    virtual void v12();
    virtual int Overlaps(Box_001D3890* box);
    virtual int Collide(Seg_001D3890* seg, Vec_001D3890* dir, Info_001D3890* info, Box_001D3890* box);
};

struct Node_001D3890 {
    int m0;
    Obj_001D3890* m4;
    int m8;
    Node_001D3890* mC;
    Node_001D3890* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Entry_001D3890 {
    Obj_001D3890* obj;
    Box_001D3890* box;
};

struct Grid_001D3890 {
    Box_001D3890 box;
    Entry_001D3890 m20[500];
    int mFC0;
    int mFC4;
    int mFC8;
};

extern int D_0038DE40;
extern "C" void func_00102328(Box_001D3890* box, Vec_001D3890* p);
extern "C" void func_00102358(Box_001D3890* box, Vec_001D3890* p);
extern "C" void* func_001324B8(Seg_001D3890* seg);
extern "C" Obj_001D3890** func_00208E80(void* sector, Seg_001D3890* seg);

static inline bool Inside_001D3890(const Box_001D3890& o, const Box_001D3890& b)
{
    bool r = false;
    if (b.mn.v.x >= o.mn.v.x && b.mx.v.x <= o.mx.v.x && b.mn.v.y >= o.mn.v.y && b.mx.v.y <= o.mx.v.y &&
        b.mn.v.z >= o.mn.v.z && b.mx.v.z <= o.mx.v.z)
        r = true;
    return r;
}

static inline bool Overlap_001D3890(const Box_001D3890& a, const Box_001D3890& b)
{
    if (a.mn.v.x > b.mx.v.x || b.mn.v.x > a.mx.v.x || a.mn.v.z > b.mx.v.z || b.mn.v.z > a.mx.v.z ||
        a.mn.v.y > b.mx.v.y || b.mn.v.y > a.mx.v.y)
        return false;
    return true;
}

extern "C" bool func_001D3890(Seg_001D3890* seg, Info_001D3890* info, int arg, Grid_001D3890* grid)
{
    info->m4C = arg;
    Box_001D3890 box;
    func_00102328(&box, &seg->a);
    bool inside = grid != 0;
    func_00102358(&box, &seg->b);
    if (inside) inside = Inside_001D3890(grid->box, box);
    Obj_001D3890** list = 0;
    if (!inside) {
        void* sector = func_001324B8(seg);
        if (!sector) return false;
        list = func_00208E80(sector, seg);
    }
    if (D_0038DE40)
        info->m30 = -0.01f;
    else
        info->m30 = 1.01f;
    bool hit = false;
    Vec_001D3890 t;
    t = box.mx;
    t.v.x += 0.5f;
    t.v.y += 0.5f;
    t.v.z += 0.5f;
    func_00102358(&box, &t);
    t = box.mn;
    t.v.x -= 0.5f;
    t.v.y -= 0.5f;
    t.v.z -= 0.5f;
    func_00102358(&box, &t);
    Vec_001D3890 d;
    d.v.x = seg->b.v.x - seg->a.v.x;
    d.v.y = seg->b.v.y - seg->a.v.y;
    d.v.z = seg->b.v.z - seg->a.v.z;
    d.v.w = seg->b.v.w - seg->a.v.w;
    if (inside) {
        Entry_001D3890* e = grid->m20;
        int n = grid->mFC4;
        for (int i = 0; i < n; i++, e++) {
            if (Overlap_001D3890(box, *e->box)) {
                if (e->obj->Collide(seg, &d, info, &box))
                    hit = true;
            }
        }
        return hit;
    }
    for (Obj_001D3890* o = *list; o; o = *++list) {
        if (o->Overlaps(&box)) {
            if (o->Collide(seg, &d, info, &box))
                hit = true;
        }
    }
    return hit;
}
