typedef int qword __attribute__((mode(TI)));

struct Vec_00190120 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00190120() {}
    Vec_00190120(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_00190120 {
    Vec_00190120 r[3];
};

static inline Vec_00190120 Rotate_00190120(const Vec_00190120& v, const Mat_00190120& m)
{
    Vec_00190120 r;
    r.x = v.x * m.r[0].x + v.y * m.r[1].x + v.z * m.r[2].x;
    r.y = v.x * m.r[0].y + v.y * m.r[1].y + v.z * m.r[2].y;
    r.z = v.x * m.r[0].z + v.y * m.r[1].z + v.z * m.r[2].z;
    r.w = v.w;
    return r;
}

struct Bone_00190120 {
    Vec_00190120 v;
    char pad10[0x30 - 0x10];
};

extern Bone_00190120 D_003E4540[];

struct Obj_00190120 {
    char pad0[0x50];
    Bone_00190120* m50;
    unsigned short m54;
    char pad56[0x120 - 0x56];
    Mat_00190120 m120;
    void Fn();
};

void Obj_00190120::Fn()
{
    int i = m54;
    while (i-- != 0) {
        Vec_00190120 r = Rotate_00190120(m50[i].v, m120);
        D_003E4540[i].v = r;
    }
}
