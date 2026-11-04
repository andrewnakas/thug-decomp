typedef int qword __attribute__((mode(TI)));

struct Vec_00134548 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct BBox_00134548 {
    Vec_00134548 m_min;
    Vec_00134548 m_max;
    bool Intersects(const BBox_00134548& o) const
    {
        if (o.m_max.x < m_min.x || o.m_min.x > m_max.x || m_min.z > o.m_max.z || o.m_min.z > m_max.z ||
            m_min.y > o.m_max.y || o.m_min.y > m_max.y)
            return false;
        return true;
    }
};

struct Mesh_00134548;

struct HashTable_00134B50 {
    void Reset();
    void* Next(int* key);
};

extern "C" BBox_00134548* func_00135120(Mesh_00134548* m);
extern "C" void func_00135048(Mesh_00134548* m, int a);

struct Scene_00134548 {
    char pad0[0xD0];
    HashTable_00134B50* m_D0;
    void SetActiveInBox(const BBox_00134548& box, int active);
};

void Scene_00134548::SetActiveInBox(const BBox_00134548& box, int active)
{
    BBox_00134548 b = box;
    m_D0->Reset();
    Mesh_00134548* m;
    while ((m = (Mesh_00134548*)m_D0->Next(0)) != 0) {
        if (b.Intersects(*func_00135120(m))) {
            func_00135048(m, active);
        }
    }
}
