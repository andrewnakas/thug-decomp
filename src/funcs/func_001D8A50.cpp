struct Vec_001D8A50 {
    float x, y, z, w;
};

struct Mesh_001D8A50 {
    char m_pad[0xB];
    unsigned char m_packed;
    char m_padC[0x10 - 0xC];
    Vec_001D8A50 m_origin;
    char m_pad20[0x30 - 0x20];
    void* m_verts;
    void SetVert(int i, const Vec_001D8A50* v);
};

void Mesh_001D8A50::SetVert(int i, const Vec_001D8A50* v)
{
    if (m_packed) {
        Vec_001D8A50 d;
        d.x = v->x - m_origin.x;
        d.y = v->y - m_origin.y;
        d.z = v->z - m_origin.z;
        d.w = v->w - m_origin.w;
        ((short*)m_verts)[i * 3 + 0] = (short)(int)(d.x * 16.0f);
        ((short*)m_verts)[i * 3 + 1] = (short)(int)(d.y * 16.0f);
        ((short*)m_verts)[i * 3 + 2] = (short)(int)(d.z * 16.0f);
    } else {
        ((float*)m_verts)[i * 3 + 0] = v->x;
        ((float*)m_verts)[i * 3 + 1] = v->y;
        ((float*)m_verts)[i * 3 + 2] = v->z;
    }
}
