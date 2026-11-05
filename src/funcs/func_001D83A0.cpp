typedef int qword __attribute__((mode(TI)));

struct Vec_001D83A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001D83A0() {}
    Vec_001D83A0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Pt_001D83A0 {
    float x, y, z;
};

extern "C" void func_001D7A60(void* p, const Vec_001D83A0* d);

struct Obj_001D83A0 {
    char m_pad0[6];
    unsigned short m6;
    char m_pad8[3];
    unsigned char mB;
    char m_padC[4];
    Vec_001D83A0 m10;
    Vec_001D83A0 m20;
    Pt_001D83A0* m30;
    void* m34;
    void Move(const Vec_001D83A0& d);
};

void Obj_001D83A0::Move(const Vec_001D83A0& d)
{
    if (m34) {
        func_001D7A60(m34, &d);
    }
    if (!mB) {
        for (int i = 0; i < m6; i++) {
            m30[i].x += d.x;
            m30[i].y += d.y;
            m30[i].z += d.z;
        }
    }
    Vec_001D83A0 a;
    Vec_001D83A0 b;
    a = Vec_001D83A0(m10.x + d.x, m10.y + d.y, m10.z + d.z, m10.w + d.w);
    b = Vec_001D83A0(m20.x + d.x, m20.y + d.y, m20.z + d.z, m20.w + d.w);
    m10 = a;
    m20 = b;
}
