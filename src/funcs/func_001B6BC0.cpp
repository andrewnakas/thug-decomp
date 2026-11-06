typedef int qword_001B6BC0 __attribute__((mode(TI)));
union Vec_001B6BC0 {
    qword_001B6BC0 q;
    struct { float x, y, z, w; } f;
};
struct Obj_001B6BC0 {
    char pad[0x20];
    Vec_001B6BC0 m20;
    void Set(const Vec_001B6BC0& v);
};

void Obj_001B6BC0::Set(const Vec_001B6BC0& v)
{
    m20 = v;
}
