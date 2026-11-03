typedef int qword __attribute__((mode(TI)));

struct Vec_00192A68 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00192A68() {}
    Vec_00192A68(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00192A68(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
};



struct Pt_00192A68 {
    Vec_00192A68 pos;
    char pad10[0x20];
};

extern int D_0038C9AC;
extern Pt_00192A68 D_003E4540[];

extern "C" void func_001235E8(Vec_00192A68 a, Vec_00192A68 b, unsigned int c0, unsigned int c1, int n);
extern "C" void func_001235F8(Vec_00192A68 p, unsigned int c, int n, float r);
extern "C" void func_00123600(Vec_00192A68 p, int segs, unsigned int c, int n, float r);

struct Obj_00192A68 {
    char pad0[0x30];
    float m30;
    float m34;
    char pad38[0x54 - 0x38];
    unsigned short m_numPts;
    char pad56[0xD4 - 0x56];
    int m_state;
    char padD8[0xE0 - 0xD8];
    Vec_00192A68 m_pos;
    char padF0[0x164 - 0xF0];
    float m164;
    void Draw();
    Vec_00192A68 Moved(const Vec_00192A68& a) const
    {
        return Vec_00192A68(a.x + m_pos.x, a.y + m_pos.y, a.z + m_pos.z, a.w + m_pos.w);
    }
    Vec_00192A68 Add(const Vec_00192A68& b) const
    {
        return Vec_00192A68(m_pos.x + b.x, m_pos.y + b.y, m_pos.z + b.z, m_pos.w + b.w);
    }
};

void Obj_00192A68::Draw()
{
    unsigned int color = 0;
    bool circles = false;
    switch (m_state) {
    case 0:
        color = 0xFFC80000;
        circles = true;
        break;
    case 1:
        color = 0xFF00C800;
        if (m164 > 0.0f) {
        } else {
            circles = true;
            color = 0xFF0000C8;
        }
        break;
    }
    if (circles && D_0038C9AC) {
        func_00123600(Add(Vec_00192A68(0.0f, m34, 0.0f)), 8, 0xFF00C8C8, 1, m30);
        func_00123600(Add(Vec_00192A68(0.0f, -m34, 0.0f)), 8, 0xFF00C8C8, 1, m30);
    }
    if (D_0038C9AC) {
        func_001235F8(m_pos, 0xFFC800C8, 1, 36.0f);
    }
    int i = m_numPts;
    while (i-- != 0) {
        for (int k = 0; k < i; k++) {
            func_001235E8(Moved(D_003E4540[i].pos), Moved(D_003E4540[k].pos), color, color, 1);
        }
    }
}
