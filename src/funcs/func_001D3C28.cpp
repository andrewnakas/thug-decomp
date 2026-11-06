typedef int qword __attribute__((mode(TI)));

union Vec_001D3C28 {
    qword q;
    struct {
        float x, y, z, w;
    } v;
};

struct Box_001D3C28 {
    Vec_001D3C28 mn;
    Vec_001D3C28 mx;
};

struct Seg_001D3C28 {
    Vec_001D3C28 a;
    Vec_001D3C28 b;
};

struct Info_001D3C28 {
    char pad0[0x30];
    float m30;
    char pad34[0x4C - 0x34];
    int m4C;
    int m50;
    int m54;
    signed char m58;
};

class Obj_001D3C28 {
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
    virtual int Overlaps(Box_001D3C28* box);
    virtual int Collide(Seg_001D3C28* seg, Vec_001D3C28* dir, Info_001D3C28* info, Box_001D3C28* box);
};

struct Node_001D3C28 {
    int m0;
    Obj_001D3C28* m4;
    int m8;
    Node_001D3C28* mC;
    Node_001D3C28* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Entry_001D3C28 {
    Obj_001D3C28* obj;
    Box_001D3C28* box;
};

struct Grid_001D3C28 {
    Box_001D3C28 box;
    Entry_001D3C28 m20[500];
    int mFC0;
    int mFC4;
    int mFC8;
};

extern int D_0038DE40;
extern Node_001D3C28* D_003E82EC[];
extern "C" void func_00102328(Box_001D3C28* box, Vec_001D3C28* p);
extern "C" void func_00102358(Box_001D3C28* box, Vec_001D3C28* p);

static inline bool Inside_001D3C28(const Box_001D3C28& o, const Box_001D3C28& b)
{
    bool r = false;
    if (b.mn.v.x >= o.mn.v.x && b.mx.v.x <= o.mx.v.x && b.mn.v.y >= o.mn.v.y && b.mx.v.y <= o.mx.v.y &&
        b.mn.v.z >= o.mn.v.z && b.mx.v.z <= o.mx.v.z)
        r = true;
    return r;
}

static inline bool Overlap_001D3C28(const Box_001D3C28& a, const Box_001D3C28& b)
{
    if (a.mn.v.x > b.mx.v.x || b.mn.v.x > a.mx.v.x || a.mn.v.z > b.mx.v.z || b.mn.v.z > a.mx.v.z ||
        a.mn.v.y > b.mx.v.y || b.mn.v.y > a.mx.v.y)
        return false;
    return true;
}

extern "C" int func_001D3C28(Seg_001D3C28* seg, Info_001D3C28* info, int arg, Grid_001D3C28* grid)
{
    info->m4C = arg;
    int hit = 0;
    if (!info->m58) {
        if (D_0038DE40)
            info->m30 = -0.01f;
        else
            info->m30 = 1.01f;
    }
    Box_001D3C28 box;
    func_00102328(&box, &seg->a);
    bool inside = grid != 0;
    func_00102358(&box, &seg->b);
    if (inside) inside = Inside_001D3C28(grid->box, box);
    Vec_001D3C28 t;
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
    Vec_001D3C28 d;
    d.v.x = seg->b.v.x - seg->a.v.x;
    d.v.y = seg->b.v.y - seg->a.v.y;
    d.v.z = seg->b.v.z - seg->a.v.z;
    d.v.w = seg->b.v.w - seg->a.v.w;
    if (inside) {
        Entry_001D3C28* e = &grid->m20[grid->mFC4];
        int n = grid->mFC8;
        for (int i = 0; i < n; i++, e++) {
            if (e->box && Overlap_001D3C28(box, *e->box)) {
                info->m54 = e->obj->GetId();
                if (e->obj->Collide(seg, &d, info, &box))
                    hit = e->obj->GetId();
                info->m54 = 0;
            }
        }
        return hit;
    }
    for (Node_001D3C28* n = D_003E82EC[0]->Valid(); n; n = n->mC->Valid()) {
        Obj_001D3C28* o = n->m4;
        if (o && !(o->m4 & 6) && o->Overlaps(&box)) {
            info->m54 = o->GetId();
            if (o->Collide(seg, &d, info, &box))
                hit = o->GetId();
            info->m54 = 0;
        }
    }
    return hit;
}
