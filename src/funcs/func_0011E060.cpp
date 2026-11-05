typedef int qword __attribute__((mode(TI)));

struct Vec_0011E060 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0011E060() {}
    Vec_0011E060(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Ent_0011E060 {
    int m0;
    int m4;
    int m8;
    unsigned int m_flags;
    int m10;
    int m14;
    int m18;
    int m1C;
    Vec_0011E060 m_color;
};

struct Obj_0011E060 {
    char pad[0x14];
    int m_count;
    Ent_0011E060* m_ents;
    void ResetColors();
};

void Obj_0011E060::ResetColors()
{
    for (int i = 0; i < m_count; i++) {
        Ent_0011E060* e = &m_ents[i];
        e->m_flags &= 0xCFFFFFFF;
        e->m_color = Vec_0011E060(1.0f, 1.0f, 1.0f, 1.0f);
    }
}
