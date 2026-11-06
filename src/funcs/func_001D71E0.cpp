typedef int qword_001D71E0 __attribute__((mode(TI)));

struct Vec_001D71E0 {
    union {
        struct { float x, y, z, w; };
        qword_001D71E0 q;
    };
};

struct Mat_001D71E0 {
    Vec_001D71E0 row[4];
};

struct Obj_001D71E0 {
    char pad0[8];
    void* m8;
    char padC[4];
    Vec_001D71E0 m_pos;
    Vec_001D71E0 m_rot[3];
    void Draw(int a, int b);
};

extern "C" void func_001DA7C8(void* p, Mat_001D71E0* m, int a, int b, int c);

void Obj_001D71E0::Draw(int a, int b)
{
    Mat_001D71E0 m;
    m.row[0] = m_rot[0];
    m.row[1] = m_rot[1];
    m.row[2] = m_rot[2];
    m.row[3] = m_pos;
    func_001DA7C8(m8, &m, a, b, 1);
}
