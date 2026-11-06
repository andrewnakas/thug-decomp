typedef int qword_001D8C20 __attribute__((mode(TI)));

struct Vec_001D8C20 {
    union {
        qword_001D8C20 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Packed_001D8C20 {
    unsigned short x, y, z;
};

struct Raw_001D8C20 {
    float x, y, z;
};

struct Mesh_001D8C20 {
    char pad0[6];
    unsigned short m_numVerts;
    char pad8[3];
    unsigned char m_packed;
    char padC[4];
    Vec_001D8C20 m_base;
    char pad20[0x10];
    void* m_verts;

    Vec_001D8C20 GetVert(int i)
    {
        if (m_packed) {
            Packed_001D8C20* p = (Packed_001D8C20*)m_verts;
            Vec_001D8C20 v = m_base;
            v.f.x += (float)p[i].x * 0.0625f;
            v.f.y += (float)p[i].y * 0.0625f;
            v.f.z += (float)p[i].z * 0.0625f;
            v.f.w = 0.0f;
            return v;
        }
        Raw_001D8C20* p = (Raw_001D8C20*)m_verts;
        Vec_001D8C20 v;
        v.f.x = p[i].x;
        v.f.y = p[i].y;
        v.f.z = p[i].z;
        v.f.w = 0.0f;
        return v;
    }
    void GetVerts(Vec_001D8C20* out);
};

void Mesh_001D8C20::GetVerts(Vec_001D8C20* out)
{
    for (int i = 0; i < m_numVerts; i++)
        out[i] = GetVert(i);
}
