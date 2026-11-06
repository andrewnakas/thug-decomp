struct Vec_001728C0 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

class Obj_001728C0 {
public:
    char pad[0x50];
    Vec_001728C0 m_50;
    int m_flags;
    void Set(float x, float y, float z, float w);
};

void Obj_001728C0::Set(float x, float y, float z, float w)
{
    m_50.Set(x, y, z, w);
    m_flags |= 4;
}
