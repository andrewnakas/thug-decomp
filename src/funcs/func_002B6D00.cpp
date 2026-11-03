typedef int qword __attribute__((mode(TI)));

union Vec_002B6D00 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Obj_002B6D00 {
    int m0;
    int m4;
    int m8;
    virtual Vec_002B6D00 GetPos();
};

struct Holder_002B6D00 {
    char pad[0x14];
    Obj_002B6D00* m14;
};

struct Node_002B6D00 {
    int m0;
    int m4;
};

extern "C" Obj_002B6D00* func_002B6CF0(Node_002B6D00* n);
extern "C" Holder_002B6D00* func_002B6CF8(Node_002B6D00* n);

Vec_002B6D00 GetPos_002B6D00(Node_002B6D00* n, int flags)
{
    Obj_002B6D00* o;
    if (n->m4 & 1)
        o = func_002B6CF0(n);
    else
        o = func_002B6CF8(n)->m14;
    Vec_002B6D00 r;
    if (flags & 1) {
        r.f.x = o->GetPos().f.z;
        r.f.z = o->GetPos().f.x;
    } else {
        r.f.x = o->GetPos().f.x;
        r.f.z = o->GetPos().f.z;
    }
    r.f.y = o->GetPos().f.y;
    return r;
}
