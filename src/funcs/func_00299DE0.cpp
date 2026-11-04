typedef int qword __attribute__((mode(TI)));

union Vec_00299DE0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_00299DE0 {
    char pad0[0x10];
    Vec_00299DE0 m10;
    int m20;
    int m24;
    float m28;
    Node_00299DE0* m2C;
};

struct Obj_00299DE0;
extern "C" void func_002995D0(Obj_00299DE0* o);
extern "C" Node_00299DE0* func_00299830(Obj_00299DE0* o);

struct Obj_00299DE0 {
    int m0;
    int m4;
    int m8;
    Node_00299DE0* mC;
    void CopyFrom(Obj_00299DE0* src);
};

void Obj_00299DE0::CopyFrom(Obj_00299DE0* src)
{
    func_002995D0(this);
    for (Node_00299DE0* n = src->mC; n; n = n->m2C) {
        Node_00299DE0* d = func_00299830(this);
        d->m10 = n->m10;
        d->m20 = n->m20;
        d->m28 = n->m28;
    }
}
