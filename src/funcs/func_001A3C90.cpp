typedef int qword __attribute__((mode(TI)));

struct Vec1A3C90 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
};

struct Model1A3C90;
extern "C" void* func_00114E18(void* t);
extern "C" Vec1A3C90 func_0026C650(Model1A3C90* m, void* bone);

struct Xform1A3C90 {
    char m_pad[0x50];
    Vec1A3C90 m50;
};

struct Obj1A3C90 {
    char m_pad[0xC];
    Xform1A3C90* mC;
    char m_pad10[0x28 - 0x10];
    Model1A3C90* m28;
    Vec1A3C90 GetPos(void* t);
};

Vec1A3C90 Obj1A3C90::GetPos(void* t)
{
    if (m28 && t) {
        return func_0026C650(m28, func_00114E18(t));
    }
    return mC->m50;
}
