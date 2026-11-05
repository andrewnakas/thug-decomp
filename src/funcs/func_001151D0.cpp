struct Vec_001151D0 {
    float x, y, z, w;
};

struct Pair_001151D0 {
    Vec_001151D0 a;
    Vec_001151D0 b;
};

extern "C" void func_00114E08(void* obj, Pair_001151D0* p);
extern "C" void func_00132018(void* a, void* b);

struct Obj_001151D0 {
    char pad[0xC];
    void* mC;
    void* m10;
    char pad14[0x20 - 0x14];
    Vec_001151D0 m_ext;
    float m_scale;
    void Place(const Vec_001151D0* pos);
};

void Obj_001151D0::Place(const Vec_001151D0* pos)
{
    Pair_001151D0 p;
    float s = m_scale;
    float x = m_ext.x * s;
    float y = m_ext.y * s;
    float z = m_ext.z * s;
    float w = m_ext.w * s;
    p.a.x = pos->x - x;
    p.a.y = pos->y - y;
    p.a.z = pos->z - z;
    p.a.w = pos->w - w;
    p.b.x = x;
    p.b.y = y;
    p.b.z = z;
    p.b.w = w;
    func_00114E08(mC, &p);
    func_00132018(m10, mC);
}
