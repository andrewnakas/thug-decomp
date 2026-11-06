typedef int qword __attribute__((mode(TI)));

struct Vec_001423C0 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

class Obj_001423C0 {
public:
    char pad[0x80];
    Vec_001423C0 m_vecs[1];
    void SetVec(int i, const Vec_001423C0* v);
};

void Obj_001423C0::SetVec(int i, const Vec_001423C0* v)
{
    m_vecs[i] = *v;
}
