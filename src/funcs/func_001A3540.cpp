typedef int qword __attribute__((mode(TI)));

struct Vec1A3540 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
};

struct Model1A3540;
extern "C" void* func_00114E18(void* t);
extern "C" Vec1A3540 func_0026C650(Model1A3540* m, void* bone);

struct Obj1A3540 {
    char m_pad[0xA0];
    Vec1A3540 mA0;
    Vec1A3540 mB0;
    Model1A3540* mC0;
    Vec1A3540 GetDir(void* t);
};

Vec1A3540 Obj1A3540::GetDir(void* t)
{
    if (mC0 && t) {
        return func_0026C650(mC0, func_00114E18(t));
    }
    return mB0;
}
