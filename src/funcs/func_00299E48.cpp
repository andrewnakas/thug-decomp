typedef int qword __attribute__((mode(TI)));

union Vec_00299E48 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_00299E48 {
    char pad0[0x10];
    Vec_00299E48 m10;
    char pad20[0x2C - 0x20];
    Node_00299E48* m2C;
};

extern "C" Vec_00299E48 func_002977F8(Vec_00299E48* p, Vec_00299E48* a, Vec_00299E48* b, float f);

struct Obj_00299E48 {
    int m0;
    int m4;
    int m8;
    Node_00299E48* mC;
    void Transform(Vec_00299E48* a, Vec_00299E48* b, float f);
};

void Obj_00299E48::Transform(Vec_00299E48* a, Vec_00299E48* b, float f)
{
    for (Node_00299E48* n = mC; n; n = n->m2C)
        n->m10 = func_002977F8(&n->m10, a, b, f);
}
