extern "C" float sqrtf(float x);

struct Vec_0027D6B8 {
    float x, y, z, w;
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Body_0027D6B8 {
    char m_pad[0x90];
    Vec_0027D6B8 m_dir;
    char m_padA0[0xB0 - 0xA0];
    Vec_0027D6B8 m_vel;
};

struct Inner_0027D6B8 {
    char m_pad[0x2C];
    int m2C;
    char m_pad30[0x50 - 0x30];
    int m50;
    char m_pad54[0x74 - 0x54];
    int m74;
};

struct Ctl_0027D6B8 {
    char m_pad[0x24];
    Inner_0027D6B8 m24;
    char m_pad9C[0x1B8 - 0x9C];
    int m1B8;
};

struct Skater_0027D6B8 {
    char m_pad[0xC];
    Body_0027D6B8* m_body;
    char m_pad10[0x364 - 0x10];
    int m364;
    char m_pad368[0x374 - 0x368];
    int m374;
    char m_pad378[0x594 - 0x378];
    Ctl_0027D6B8* m594;
    bool Check();
};

bool Skater_0027D6B8::Check()
{
    Ctl_0027D6B8* c = m594;
    Inner_0027D6B8* in = &c->m24;
    if (!m364 && !c->m1B8 && m_body->m_vel.Length() < 50.0f)
        return true;
    bool r = false;
    if (in->m2C && m374) {
        Body_0027D6B8* b = m_body;
        if (b->m_vel.Length() < 50.0f || (!in->m74 && !in->m50)
            || b->m_vel.x * b->m_dir.x + b->m_vel.y * b->m_dir.y + b->m_vel.z * b->m_dir.z < 0.0f)
            r = true;
    }
    return r;
}
