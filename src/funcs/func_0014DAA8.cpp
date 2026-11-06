struct Sph_0014DAA8 {
    float x, y, z, r;
    Sph_0014DAA8(float x_, float y_, float z_, float r_)
    {
        x = x_;
        y = y_;
        z = z_;
        r = r_;
    }
    Sph_0014DAA8(const Sph_0014DAA8& o);
};

extern "C" Sph_0014DAA8 func_00172078(void* p);
extern "C" Sph_0014DAA8 func_00172870(void* p);

struct Ent_0014DAA8 {
    char pad[0x18];
    void* m18;
    int m1C;
    void* m20;
    Sph_0014DAA8 GetBounds();
};

Sph_0014DAA8 Ent_0014DAA8::GetBounds()
{
    if (m20)
        return func_00172078(m20);
    if (m18)
        return func_00172870(m18);
    return Sph_0014DAA8(0.0f, 0.0f, 0.0f, 1e10f);
}
