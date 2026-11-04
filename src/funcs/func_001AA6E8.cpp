typedef int qword __attribute__((mode(TI)));

struct Vec_001AA6E8 {
    union {
        struct { float x, y, z, w; };
        float v[4];
        qword q;
    };
    Vec_001AA6E8() {}
    Vec_001AA6E8(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0.0f; }
    Vec_001AA6E8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001AA6E8 operator+(const Vec_001AA6E8& o) const { return Vec_001AA6E8(x + o.x, y + o.y, z + o.z, w + o.w); }
    Vec_001AA6E8 operator-(const Vec_001AA6E8& o) const { return Vec_001AA6E8(x - o.x, y - o.y, z - o.z, w - o.w); }
    float LengthSqr() const { return x * x + y * y + z * z; }
};

struct Obj_001AA6E8 {
    char pad0[0x50];
    Vec_001AA6E8 m_pos;
    char pad60[0x70 - 0x60];
    Vec_001AA6E8 m_matrix[4];
};

struct Cam_001AA6E8 {
    char pad0[0x20];
    Vec_001AA6E8 m_dir;
};

struct Self_001AA6E8 {
    char pad0[0xC];
    Obj_001AA6E8* m_obj;
    float GetAngle();
};

extern void* D_0038FC78;
extern "C" Obj_001AA6E8* func_0022DD38(void* g);
extern "C" Cam_001AA6E8* func_00206900(Obj_001AA6E8* o);
extern "C" void func_003233B8(Vec_001AA6E8* d, Vec_001AA6E8* s);
extern "C" float func_00101A10(Vec_001AA6E8* m, Vec_001AA6E8* dir, int i, int j);

float Self_001AA6E8::GetAngle()
{
    Obj_001AA6E8* sk = func_0022DD38(D_0038FC78);
    Vec_001AA6E8 a = func_00206900(sk)->m_dir;
    a.y = 0.0f;
    func_003233B8(&a, &a);
    Vec_001AA6E8 up(0.0f, 1.0f, 0.0f);
    a = Vec_001AA6E8(a.y * up.z - a.z * up.y, a.z * up.x - a.x * up.z, a.x * up.y - a.y * up.x, up.z);
    Obj_001AA6E8* o = m_obj;
    Vec_001AA6E8 b, c;
    b = Vec_001AA6E8(o->m_pos.x + a.x, o->m_pos.y + a.y, o->m_pos.z + a.z, o->m_pos.w + a.w);
    c = Vec_001AA6E8(o->m_pos.x - a.x, o->m_pos.y - a.y, o->m_pos.z - a.z, o->m_pos.w - a.w);
    float l1 = Vec_001AA6E8(sk->m_pos.x - b.x, sk->m_pos.y - b.y, sk->m_pos.z - b.z, sk->m_pos.w - b.w).LengthSqr();
    float l2 = Vec_001AA6E8(sk->m_pos.x - c.x, sk->m_pos.y - c.y, sk->m_pos.z - c.z, sk->m_pos.w - c.w).LengthSqr();
    if (l1 < l2) {
        a.x = -a.x;
        a.z = -a.z;
    }
    return func_00101A10(o->m_matrix, &a, 2, 1) * 57.29577637f;
}
