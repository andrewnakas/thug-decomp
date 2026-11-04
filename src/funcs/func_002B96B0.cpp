typedef int qword __attribute__((mode(TI)));

union Vec_002B96B0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct V4_002B96B0 { float x, y, z, w; };
struct Pt_002B96B0 {
    char pad[0x10];
    Vec_002B96B0 m_pos;
    char pad2[0x28 - 0x20];
    Pt_002B96B0* m_next;
};

struct Group_002B96B0 {
    char pad[0x8];
    Pt_002B96B0* m_pts;
    char pad2[0x14 - 0xC];
    Group_002B96B0* m_next;
};

struct Obj_002B96B0 {
    char pad[0x68];
    Group_002B96B0* m_groups;
    bool FindNearest(Vec_002B96B0* pos, Vec_002B96B0* out, float* outDist);
};

bool Obj_002B96B0::FindNearest(Vec_002B96B0* pos, Vec_002B96B0* out, float* outDist)
{
    float best = 100000000.0f;
    bool found = false;
    for (Group_002B96B0* g = m_groups; g; g = g->m_next) {
        for (Pt_002B96B0* p = g->m_pts; p; p = p->m_next) {
            V4_002B96B0 d;
            float dx = p->m_pos.f.x - pos->f.x;
            float dy = p->m_pos.f.y - pos->f.y;
            float dz = p->m_pos.f.z - pos->f.z;
            float dw = p->m_pos.f.w - pos->f.w;
            d.x = dx;
            d.y = dy;
            d.z = dz;
            d.w = dw;
            float l = d.x * d.x + d.y * d.y + d.z * d.z;
            if (l < best) {
                *out = p->m_pos;
                best = l;
                found = true;
                *outDist = best;
            }
        }
    }
    return found;
}
