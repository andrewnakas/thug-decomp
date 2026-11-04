typedef int qword __attribute__((mode(TI)));

union Vec_002BA960 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Obj_002BA960 {
    char pad0[0x10];
    Vec_002BA960 m10;
    Vec_002BA960 Get() const;
};

Vec_002BA960 Obj_002BA960::Get() const {
    return m10;
}
