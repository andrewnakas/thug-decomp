typedef int qword_001B80D8 __attribute__((mode(TI)));
union Vec_001B80D8 {
    qword_001B80D8 q;
    struct { float x, y, z, w; } f;
};
struct Sub_001B80D8 {
    char pad[0x50];
    Vec_001B80D8 m50;
};
struct Obj_001B80D8 {
    int m0, m4, m8;
    Sub_001B80D8* mC;
    void Set(const Vec_001B80D8& v);
};

void Obj_001B80D8::Set(const Vec_001B80D8& v)
{
    mC->m50 = v;
}
