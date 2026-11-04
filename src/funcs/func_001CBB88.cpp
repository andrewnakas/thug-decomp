typedef unsigned int u128 __attribute__((mode(TI)));

union Vec_001CBB88 {
    struct {
        float x, y, z, w;
    } f;
    u128 q;
};

struct Hit_001CBB88 {
    Vec_001CBB88 m_pos;
    Vec_001CBB88 m_dir;
    float m_speed;
};

struct Ref_001CBB88 {
    void* m_target;
};

struct Lock_001CBB88 {
    char m_pad[0x1C];
    Ref_001CBB88* m1C;
    unsigned int m20;
};

struct Mgr_001CBB88 {
    char m_pad[0x28];
    void* m28;
};

struct Obj_001CBB88 {
    char m_pad[0x30];
    Vec_001CBB88 m30;
    Vec_001CBB88 m40;
    int m50;
    char m_pad54[0x60 - 0x54];
    Vec_001CBB88 m60;
    char m_pad70[0x90 - 0x70];
    unsigned int m90;
    char m_pad94[0xA1C - 0x94];
    char mA1C[8];
    void* mA24;
    char m_padA28[0xA3C - 0xA28];
    Lock_001CBB88* mA3C;
    char m_padA40[0xBF0 - 0xA40];
    float mBF0;
    bool TryGrind(void* a, void* b);
};

extern Mgr_001CBB88* D_0038FC78;
extern void* D_00388A70;

extern "C" bool func_00269810(void* rails, void* a, void* b, Obj_001CBB88* skater, Hit_001CBB88* hit, void* out);
extern "C" void func_00183CB8(void* target, Ref_001CBB88* ref);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void func_001BF130(Obj_001CBB88* self, int state);

bool Obj_001CBB88::TryGrind(void* a, void* b)
{
    Hit_001CBB88 hit;
    if (!func_00269810(D_0038FC78->m28, a, b, this, &hit, mA1C))
        return false;
    Lock_001CBB88* lock = mA3C;
    mA24 = D_0038FC78->m28;
    Ref_001CBB88* ref = lock->m1C;
    if (ref) {
        if (ref->m_target) {
            func_00183CB8(ref->m_target, ref);
            ref->m_target = 0;
        }
        func_0010A8D8(D_00388A70, ref);
        lock->m1C = 0;
        lock->m20 = func_0010FC30();
    }
    m30.q = hit.m_pos.q;
    m60.q = hit.m_dir.q;
    mBF0 = hit.m_speed;
    m50 = 0;
    Vec_001CBB88* v = &m40;
    v->f.x = 0.0f;
    v->f.y = 0.0f;
    v->f.z = 0.0f;
    v->f.w = 1.0f;
    func_001BF130(this, 3);
    m90 = 0xC84243DA;
    return true;
}
