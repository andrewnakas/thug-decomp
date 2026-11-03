typedef int qword __attribute__((mode(TI)));

struct Vec1A35B0 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
};

struct Model1A35B0;
extern "C" void* func_00114E18(void* t);
extern "C" Vec1A35B0 func_0026C0B0(Model1A35B0* m, void* bone);

struct Obj1A35B0 {
    char m_pad[0xC4];
    Model1A35B0* mC4;
    bool GetBonePos(void* t, Vec1A35B0* out);
};

bool Obj1A35B0::GetBonePos(void* t, Vec1A35B0* out)
{
    if (t && mC4) {
        *out = func_0026C0B0(mC4, func_00114E18(t));
        return true;
    }
    return false;
}
