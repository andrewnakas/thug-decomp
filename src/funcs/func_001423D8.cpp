typedef int qword __attribute__((mode(TI)));

struct Vec_001423D8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

class Obj_001423D8 {
public:
    char pad[0xB0];
    Vec_001423D8 m_vecs[1];
    void Set(int i, const Vec_001423D8* v);
};

void Obj_001423D8::Set(int i, const Vec_001423D8* v)
{
    m_vecs[i] = *v;
}
