typedef int qword_001D8D10 __attribute__((mode(TI)));

struct Vec_001D8D10 {
    union {
        struct { float x, y, z, w; };
        qword_001D8D10 q;
    };
};

struct Mesh_001D8D10 {
    char pad0[6];
    unsigned short m_numVerts;
    void SetVerts(const Vec_001D8D10* verts);
};

extern "C" void func_001D8A50(Mesh_001D8D10* self, int i, const Vec_001D8D10* v);

void Mesh_001D8D10::SetVerts(const Vec_001D8D10* verts)
{
    for (int i = 0; i < m_numVerts; i++)
        func_001D8A50(this, i, &verts[i]);
}
