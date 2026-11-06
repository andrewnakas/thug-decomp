typedef int qword_001A5760 __attribute__((mode(TI)));
union Vec_001A5760 {
    qword_001A5760 q;
    struct { float x, y, z, w; } f;
};
struct Sub_001A5760 {
    char pad[0x50];
    Vec_001A5760 m50;
};
struct Obj_001A5760 {
    int m0, m4, m8;
    Sub_001A5760* mC;
    char pad[0x200 - 0x10];
    float m200;
    void Run();
};

void Obj_001A5760::Run()
{
    Sub_001A5760* s = mC;
    Vec_001A5760 v = s->m50;
    v.f.y = m200;
    s->m50 = v;
}
