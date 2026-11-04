typedef int qword __attribute__((mode(TI)));

struct Vec1A3D00 {
    union {
        struct {
            float x, y, z, w;
        };
        qword q;
    };
};

struct Model1A3D00;
extern "C" void* func_00114E18(void* t);
extern "C" Vec1A3D00 func_0026C0B0(Model1A3D00* m, void* bone);

struct Obj1A3D00 {
    char m_pad[0x2C];
    Model1A3D00* m2C;
    bool GetBonePos(void* t, Vec1A3D00* out);
};

bool Obj1A3D00::GetBonePos(void* t, Vec1A3D00* out)
{
    if (t && m2C) {
        *out = func_0026C0B0(m2C, func_00114E18(t));
        return true;
    }
    return false;
}
