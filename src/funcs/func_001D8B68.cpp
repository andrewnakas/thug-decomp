typedef int qword_001D8B68 __attribute__((mode(TI)));

struct Vec_001D8B68 {
    union {
        struct { float x, y, z, w; };
        qword_001D8B68 q;
    };
    Vec_001D8B68() {}
    Vec_001D8B68(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Box_001D8B68 {
    Vec_001D8B68 m_min;
    Vec_001D8B68 m_max;
};

extern "C" void func_00102358(Box_001D8B68* box, const Vec_001D8B68* p);

struct Mesh_001D8B68 {
    char pad0[6];
    unsigned short m_numVerts;
    char pad8[8];
    Box_001D8B68 m_box;
};

extern "C" void func_001D8D10(Mesh_001D8B68* self, const Vec_001D8B68* verts);

void func_001D8B68(Mesh_001D8B68* self, const Vec_001D8B68* verts)
{
    self->m_box.m_min = Vec_001D8B68(10000000.0f, 10000000.0f, 10000000.0f, 1.0f);
    self->m_box.m_max = Vec_001D8B68(-10000000.0f, -10000000.0f, -10000000.0f, 1.0f);
    for (int i = 0; i < self->m_numVerts; i++)
        func_00102358(&self->m_box, &verts[i]);
    func_001D8D10(self, verts);
}
