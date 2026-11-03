typedef int qword __attribute__((mode(TI)));

struct Vec1A34D0 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
};

struct Model1A34D0;
extern "C" void* func_00114E18(void* t);
extern "C" Vec1A34D0 func_0026C650(Model1A34D0* m, void* bone);

struct Obj1A34D0 {
    char m_pad[0xA0];
    Vec1A34D0 mA0;
    Vec1A34D0 mB0;
    Model1A34D0* mC0;
    Vec1A34D0 GetPos(void* t);
};

Vec1A34D0 Obj1A34D0::GetPos(void* t)
{
    if (mC0 && t) {
        return func_0026C650(mC0, func_00114E18(t));
    }
    return mA0;
}
