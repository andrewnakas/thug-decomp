typedef int qword __attribute__((mode(TI)));

struct Vec_0014B5D8 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

struct Blk_0014B5D8 {
    unsigned int m_mask;
    int pad[3];
    Vec_0014B5D8 m_vecs[1];
};

class Obj_0014B5D8 {
public:
    char pad[0x1C];
    Blk_0014B5D8* m_blk;
    int SetVec(int i, const Vec_0014B5D8* v);
};

int Obj_0014B5D8::SetVec(int i, const Vec_0014B5D8* v)
{
    Blk_0014B5D8* b = m_blk;
    b->m_mask |= 2 << i;
    b->m_vecs[i] = *v;
    return 1;
}
