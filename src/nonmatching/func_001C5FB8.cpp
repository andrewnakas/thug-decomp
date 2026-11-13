/* fuzzy: 93.8 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001C5FB8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C5FB8() {}
    Vec_001C5FB8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Phys_001C5FB8 {
    char pad0[0x90];
    Vec_001C5FB8 m_normal;
};

struct Board_001C5FB8 {
    char pad0[0x24C];
    float m24C;
    float m250;
    char pad254[0x26C - 0x254];
    float m_angle;
    float m270;
};

struct Rider_001C5FB8 {
    char pad0[0x200];
    int m200;
    Board_001C5FB8* GetBoard() { return (Board_001C5FB8*)((char*)this + 0x24); }
};

extern "C" void func_003233B8(Vec_001C5FB8* dst, Vec_001C5FB8* src);
extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int a);
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" float func_0026F7C8(Board_001C5FB8* b, float x, float y, float a);

static inline float fabsf_001C5FB8(float f) { return __builtin_fabsf(f); }

static inline float Dot_001C5FB8(const Vec_001C5FB8& a, const Vec_001C5FB8& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Self_001C5FB8 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x60 - 0x20];
    Vec_001C5FB8 m_vel;
    char pad70[0xA0 - 0x70];
    Vec_001C5FB8 m_dir;
    float mB0;
    int mB4;
    int mB8;
    char padBC[0x95C - 0xBC];
    int m95C;
    char pad960[0xA14 - 0x960];
    Phys_001C5FB8* mA14;
    char padA18[0xA28 - 0xA18];
    Rider_001C5FB8* mA28;

    void UpdateDir();
};

void Self_001C5FB8::UpdateDir()
{
    Rider_001C5FB8* rider = mA28;
    Board_001C5FB8* board = rider->GetBoard();
    Vec_001C5FB8 d(-mA14->m_normal.x, 0.0f, -mA14->m_normal.z, -mA14->m_normal.w);
    func_003233B8(&d, &d);
    float ang = board->m_angle;
    float aang = fabsf_001C5FB8(ang);
    float thr;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x4676A268, &thr, 1);
    if (aang < thr * 0.017453294f)
        ang = 0.0f;
    float s = func_00341068(ang);
    float c = func_00340F60(ang);
    m_dir.x = c * d.x - s * d.z;
    m_dir.z = s * d.x + c * d.z;
    if (board->m24C == 0.0f && board->m250 == 0.0f) {
        mB8 = 0;
        if (board->m270 == 0.0f) {
            mB0 = 0.0f;
            mB4 = 0;
        } else {
            float v;
            if (m1C == 0 && rider->m200 == 0) {
                float p;
                func_001E7EB0(func_001E5548(0x6775E538, 0), 0xC1528F7F, &p, 1);
                v = p;
            } else {
                v = 1.0f;
            }
            mB4 = 1;
            mB0 = v;
        }
    } else {
        mB8 = 1;
        float f = func_0026F7C8(board, board->m24C, board->m250, board->m_angle) * 1.1764705f;
        mB0 = f;
        if (f >= 1.0f) {
            mB0 = 1.0f;
            mB4 = 1;
        } else {
            mB4 = 0;
        }
    }
    if (m1C == 0 && m95C) {
        float f = mB0 * (m_dir.x * m_vel.x + m_dir.y * m_vel.y + m_dir.z * m_vel.z);
        if (f < 0.0f)
            f = 0.0f;
        mB0 = f;
        m_dir.q = m_vel.q;
    }
}
