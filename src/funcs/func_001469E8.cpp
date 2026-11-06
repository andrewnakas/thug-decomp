typedef int qword __attribute__((mode(TI)));

struct Vec_001469E8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" void func_00146B18(void* self);

class Obj_001469E8 {
public:
    char pad[0x70];
    Vec_001469E8 m_70;
    void Set(const Vec_001469E8* v);
};

void Obj_001469E8::Set(const Vec_001469E8* v)
{
    m_70 = *v;
    func_00146B18(this);
}
