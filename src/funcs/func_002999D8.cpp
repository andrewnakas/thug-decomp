typedef int qword __attribute__((mode(TI)));

union Vec_002999D8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_002999D8 {
    char pad0[0x10];
    Vec_002999D8 m10;
    int m20;
    int m24;
    float m28;
    Node_002999D8* m2C;
};

struct Obj_002999D8;
extern "C" Node_002999D8* func_00299830(Obj_002999D8* o);

struct Obj_002999D8 {
    int m0;
    void Clone(Node_002999D8* src);
};

void Obj_002999D8::Clone(Node_002999D8* src)
{
    Node_002999D8* d = func_00299830(this);
    d->m10 = src->m10;
    d->m20 = src->m20;
    d->m28 = src->m28;
}
