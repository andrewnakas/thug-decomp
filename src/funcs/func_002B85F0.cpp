typedef int qword __attribute__((mode(TI)));

union Vec_002B85F0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Obj_002B85F0 {
    char pad0[0x430];
    Vec_002B85F0 m430[4];
    void SetRow(const Vec_002B85F0& v, int i);
};

void Obj_002B85F0::SetRow(const Vec_002B85F0& v, int i) {
    m430[i] = v;
}
