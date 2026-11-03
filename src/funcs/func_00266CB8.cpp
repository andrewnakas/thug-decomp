extern "C" float sqrtf(float);

struct Vec_00266CB8 {
    float x, y, z, w;
    Vec_00266CB8() {}
    Vec_00266CB8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vec_00266CB8 operator-(const Vec_00266CB8& a, const Vec_00266CB8& b)
{
    return Vec_00266CB8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Cam_00266CB8 {
    char m_pad0[0x1C];
    float m_heading;
    float m_tilt;
    float m_targetTilt;
    float m_pitch;
    float m_targetPitch;
    float m_radius;
    float m_speed;
    float m_minPitch;
    float m_maxPitch;
    float m_pitchRate;
    float m_pitchScale;
};

struct Body_00266CB8 {
    char m_pad0[0x10];
    Vec_00266CB8 m_pos;
    char m_pad20[0xD0 - 0x20];
    Vec_00266CB8 m_oldPos;
    char m_padE0[0x100 - 0xE0];
    float m_vel;
};

struct Skater_00266CB8 {
    char m_pad0[0x34];
    float m_speed;
};

extern "C" void* func_00185578(void* self, unsigned int name);
extern "C" Body_00266CB8* func_001A67A8(void* comp);
extern "C" float func_0010FAB8();
extern "C" float func_001001B8(float target, float cur, float rate);
extern "C" float func_003413F0(float x);
extern "C" int func_001E5628(unsigned int key, int a);
extern "C" float func_001E5318(unsigned int key, int a);

static inline Cam_00266CB8* Cam(void* self) { return (Cam_00266CB8*)func_00185578(self, 0xC695136D); }
static inline Skater_00266CB8* Sk(void* self) { return (Skater_00266CB8*)func_00185578(self, 0x0A015E17); }
static inline float Frames() { return func_0010FAB8() * 60.0f; }

void func_00266CB8(void* self)
{
    Cam(self)->m_heading += Frames() * (Sk(self)->m_speed * 90.0f) * 0.0006684492109f;
    while (Cam(self)->m_heading > 360.0f) {
        Cam(self)->m_heading -= 360.0f;
    }
    while (Cam(self)->m_heading < 0.0f) {
        Cam(self)->m_heading += 360.0f;
    }
    if (func_001A67A8(Sk(self))) {
        if (func_001A67A8(Sk(self))->m_vel != 0.0f) {
            Body_00266CB8* a = func_001A67A8(Sk(self));
            Body_00266CB8* b = func_001A67A8(Sk(self));
            Vec_00266CB8 d(a->m_pos.x - b->m_oldPos.x, a->m_pos.y - b->m_oldPos.y, a->m_pos.z - b->m_oldPos.z, a->m_pos.w - b->m_oldPos.w);
            float len = d.Length();
            float ang = func_003413F0(Cam(self)->m_radius / len);
            Cam(self)->m_targetTilt = -ang * 57.29577637f;
            if (func_001A67A8(Sk(self))->m_vel < 0.0f) {
                Cam(self)->m_targetTilt = -Cam(self)->m_targetTilt;
            }
        } else {
            Cam(self)->m_targetTilt = 0.0f;
        }
        Cam(self)->m_tilt = func_001001B8(Cam(self)->m_targetTilt, Cam(self)->m_tilt, Frames());
    } else {
        Cam(self)->m_tilt = 0.0f;
    }
    float delta = Sk(self)->m_speed - Cam(self)->m_speed;
    Cam(self)->m_speed = Sk(self)->m_speed;
    if (func_001E5628(0x4CF13D8F, 0)) {
        Cam(self)->m_minPitch = func_001E5318(0x877DB8DA, 1);
        Cam(self)->m_maxPitch = func_001E5318(0xFB3464DF, 1);
        Cam(self)->m_pitchRate = func_001E5318(0xFD8BC8D6, 1);
        Cam(self)->m_pitchScale = func_001E5318(0xB2C7447B, 1);
    }
    Cam(self)->m_targetPitch = -delta / Cam(self)->m_pitchScale;
    if (Cam(self)->m_targetPitch > Cam(self)->m_maxPitch) {
        Cam(self)->m_targetPitch = Cam(self)->m_maxPitch;
    }
    if (Cam(self)->m_targetPitch < Cam(self)->m_minPitch) {
        Cam(self)->m_targetPitch = Cam(self)->m_minPitch;
    }
    Cam(self)->m_pitch = func_001001B8(Cam(self)->m_targetPitch, Cam(self)->m_pitch, Cam(self)->m_pitchRate * Frames());
}
