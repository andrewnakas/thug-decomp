typedef int qword_001B2EA0 __attribute__((mode(TI)));
union Vec_001B2EA0 {
    qword_001B2EA0 q;
    struct { float x, y, z, w; } f;
};
struct Sub_001B2EA0 {
    char pad[0x50];
    Vec_001B2EA0 m50;
};
struct Obj_001B2EA0 {
    int m0, m4, m8;
    Sub_001B2EA0* mC;
    char pad[0x170 - 0x10];
    Vec_001B2EA0 m170[5];
    void Push();
};

void Obj_001B2EA0::Push()
{
    int i;
    Vec_001B2EA0* p = &m170[1];
    for (i = 0; i < 4; i++) {
        p[-1] = p[0];
        p++;
    }
    m170[4] = mC->m50;
}
