extern "C" float sqrtf(float);

struct Vec_0027CA10 {
    float x, y, z, w;
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Body_0027CA10 {
    char pad[0xB0];
    Vec_0027CA10 m_vel;
};

struct Skater_0027CA10 {
    char pad0[0xC];
    Body_0027CA10* m_body;
    char pad10[0x94 - 0x10];
    float m_dt;
    char pad98[0x378 - 0x98];
    float m378;
    char pad37C[0x384 - 0x37C];
    float m384;
    char pad388[0x3B4 - 0x388];
    float m3B4;
    float m3B8;
    float m3BC;
};

extern "C" float func_00203D40(Body_0027CA10*, unsigned int);
extern "C" float func_002032A0(unsigned int, int);
extern "C" void func_0027CBE0(Skater_0027CA10*, float);

void func_0027CA10(Skater_0027CA10* self)
{
    float savedY = self->m_body->m_vel.y;
    self->m_body->m_vel.y = 0.0f;
    float speed = self->m_body->m_vel.Length();
    float max = func_00203D40(self->m_body, 0xCC5F87AA);
    float limit = func_00203D40(self->m_body, 0x2EACDDB3);
    if (self->m3B4 != 0.0f) {
        if (self->m3B4 != -1.0f) {
            self->m3B4 = self->m3B4 - self->m_dt;
            if (self->m3B4 < 0.0f)
                self->m3B4 = 0.0f;
        }
        max = self->m3BC;
        limit = self->m3B8;
    }
    if (max < speed) {
        Vec_0027CA10& vel = self->m_body->m_vel;
        float len = vel.Length();
        speed = max;
        if (len > 0.0f) {
            float s = speed / len;
            vel.x = vel.x * s;
            vel.y = vel.y * s;
            vel.z = vel.z * s;
        }
    }
    if (limit < speed)
        func_0027CBE0(self, func_002032A0(0x850EB87A, 0));
    self->m_body->m_vel.y = savedY;
    if (self->m384 != 0.0f) {
        self->m384 = self->m384 - self->m_dt;
        if (self->m384 <= 0.0f) {
            self->m384 = 0.0f;
            self->m378 = func_002032A0(0x78F80EC4, 0);
        }
    }
}
