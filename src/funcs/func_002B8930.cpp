struct Vec_002B8930 {
    float x, y, z, w;
};

struct Rgba_002B8930 {
    unsigned char r, g, b, a;
};

struct Lamp_002B8930 {
    float x, y, z, w;
};


struct Obj_002B8930 {
    char pad0[0x410];
    int m410;
    float m414[3];
    float m420[3];
    char pad42C[4];
    Lamp_002B8930 m430[1];
    void Light(Vec_002B8930* p, Rgba_002B8930* c);
};

void Obj_002B8930::Light(Vec_002B8930* p, Rgba_002B8930* c)
{
    float f[3];
    f[0] = c->r * m414[0];
    f[1] = c->g * m414[1];
    f[2] = c->b * m414[2];
    float sum = 0.0f;
    Lamp_002B8930* l = m430;
    for (int i = 0; i < m410; i++, l++) {
        float dx = p->x - l->x;
        float dz = p->z - l->z;
        sum += 1.0f / (dx * dx + 160000.0f + dz * dz);
    }
    sum *= 255.0f;
    f[0] += sum * m420[0];
    if (f[0] > 255.0f) c->r = 255; else c->r = (int)f[0];
    f[1] += sum * m420[1];
    if (f[1] > 255.0f) c->g = 255; else c->g = (int)f[1];
    f[2] += sum * m420[2];
    if (f[2] > 255.0f) c->b = 255; else c->b = (int)f[2];
}
