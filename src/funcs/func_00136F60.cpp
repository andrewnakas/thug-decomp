typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_00136F60 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00136F60() {}
    Vec_00136F60(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vec_00136F60 operator+(const Vec_00136F60& a, const Vec_00136F60& b)
{
    return Vec_00136F60(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00136F60 operator-(const Vec_00136F60& a, const Vec_00136F60& b)
{
    return Vec_00136F60(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_00136F60 operator*(const Vec_00136F60& a, float s)
{
    return Vec_00136F60(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct BBox_00136F60 {
    Vec_00136F60 m_min;
    Vec_00136F60 m_max;
};

struct HashTable_00134B50 {
    void Reset();
    void* Next(int* key);
};

struct Scene_00136F60 {
    char pad0[0xD0];
    HashTable_00134B50* m_D0;
};

struct Mesh_00136F60 {
    int m0;
    int m4;
    unsigned int m8;
};

struct Query_00136F60 {
    Vec_00136F60 m_pos;
    float m10;
    float m_radius;
    char pad18[8];
    void* m_list;
};

extern "C" void func_00136F10(Query_00136F60* q);
extern "C" Scene_00136F60* func_00131E48();
extern "C" void* func_00134F18(Mesh_00136F60* m);
extern "C" BBox_00136F60* func_00135120(Mesh_00136F60* m);
extern "C" void func_00134C20(void* list, Mesh_00136F60** item, Mesh_00136F60* m);

extern "C" void func_00136F60(Query_00136F60* q)
{
    func_00136F10(q);
    Scene_00136F60* scene = func_00131E48();
    if (!scene) {
        return;
    }
    HashTable_00134B50* t = scene->m_D0;
    if (!t) {
        return;
    }
    t->Reset();
    for (Mesh_00136F60* m = (Mesh_00136F60*)t->Next(0); m; m = (Mesh_00136F60*)t->Next(0)) {
        if (m->m8 == 0xED82767B || m->m8 == 0xEC6542D3) {
            continue;
        }
        if (!func_00134F18(m)) {
            continue;
        }
        BBox_00136F60 b = *func_00135120(m);
        Vec_00136F60 center = (b.m_max + b.m_min) * 0.5f;
        float r = (b.m_max - center).Length() + q->m_radius;
        Vec_00136F60 d = center - q->m_pos;
        if (d.Length() < r) {
            Mesh_00136F60* item = m;
            func_00134C20(q->m_list, &item, m);
        }
    }
}
