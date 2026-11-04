typedef int qword_00174FB8 __attribute__((mode(TI)));

struct V_00174FB8 {
    union {
        struct {
            float x, y, z, w;
        } v;
        qword_00174FB8 q;
    };
    V_00174FB8() {}
    V_00174FB8(float x, float y, float z, float w)
    {
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
    }
    V_00174FB8 operator-(const V_00174FB8& b) const { return V_00174FB8(v.x - b.v.x, v.y - b.v.y, v.z - b.v.z, v.w - b.v.w); }
    V_00174FB8 operator+(const V_00174FB8& b) const { return V_00174FB8(v.x + b.v.x, v.y + b.v.y, v.z + b.v.z, v.w + b.v.w); }
    V_00174FB8 operator*(float f) const { return V_00174FB8(v.x * f, v.y * f, v.z * f, v.w * f); }
};

struct Mat_00174FB8 {
    int pad0;
    unsigned int m4;
    char pad8[0x30];
};

struct Mesh_00174FB8 {
    int m0;
    int m4;
    Mat_00174FB8* m8;
    int mC;
    char m10[0x10];
    char m20[0x10];
    char m30[0x14];
    int m44;
    int m48;
    int pad4C;
};

struct Sector_00174FB8 {
    Sector_00174FB8* m_next;
    int pad4;
    unsigned int m8;
    char padC[0x24];
    Mesh_00174FB8* m30;
    unsigned int m34;
};

struct Geom_00174FB8 {
    V_00174FB8 m_sphere;
    char pad10[0x18];
    int m28;
    Mat_00174FB8* m2C;
    int m30;
    int pad34;
    Mesh_00174FB8* m38;
};

extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern Sector_00174FB8* D_003942F4;
extern unsigned int D_00394318;

extern "C" float sqrtf(float);
extern "C" void func_00161020();
extern "C" int func_00161070();
extern "C" void func_00177948(Mesh_00174FB8* m, int a);
extern "C" unsigned char* func_00175650(unsigned char* p, Mesh_00174FB8* m, Mat_00174FB8* mat, Sector_00174FB8* s, int a);

static inline unsigned char* Read(unsigned char* src, int n, void* dst)
{
    unsigned char* d = (unsigned char*)dst;
    unsigned char* s = src;
    int c = n;
    while (c > 0) {
        *d++ = *s++;
        c--;
    }
    return s;
}

extern "C" unsigned char* func_00174FB8(unsigned char* p, Geom_00174FB8* geom, int unused2, int unused3, int base, int arg)
{
    V_00174FB8 s;
    V_00174FB8 big;
    V_00174FB8 small;
    unsigned int id;
    int count;
    int tmp;
    int skip;
    int n;
    unsigned int matSum;
    p = Read(p, 4, &id);
    p = Read(p, 4, &count);
    id += base;
    Sector_00174FB8* sec = D_003942F4;
    while (sec && sec->m8 != id)
        sec = sec->m_next;
    sec->m30 = geom->m38 + geom->m30;
    Mesh_00174FB8* mesh = sec->m30;
    sec->m34 = count;
    int i;
    for (i = 0; i < count; i++) {
        func_00161020();
        unsigned int* tag = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)tag;
        tag[0] = 0x60000000;
        tag[1] = 0;
        D_00394274 = (unsigned char*)(tag + 2);
        p = Read(p, 4, &mesh->m0);
        if (D_00394318 >= 2) {
            p = Read(p, 4, &tmp);
            p = Read(p, 4, &tmp);
            p = Read(p, 4, &skip);
            p = Read(p, 4, &n);
            int j;
            for (j = 0; j < n; j++)
                p = Read(p, 4, &skip);
            p = Read(p, 16, &s);
            if (geom->m_sphere.v.w < 0.0f)
                geom->m_sphere = s;
            if (geom->m_sphere.v.x != s.v.x || geom->m_sphere.v.y != s.v.y || geom->m_sphere.v.z != s.v.z
                || geom->m_sphere.v.w != s.v.w) {
                if (s.v.w < geom->m_sphere.v.w) {
                    big = geom->m_sphere;
                    small = s;
                } else {
                    big = s;
                    small = geom->m_sphere;
                }
                float rd = big.v.w - small.v.w;
                V_00174FB8 d;
                d = small - big;
                float t = 0.0f;
                float len2 = d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z;
                if (rd * rd - len2 < 0.0f)
                    t = (small.v.w - big.v.w + sqrtf(len2)) * 0.5f;
                geom->m_sphere = big + d * t;
                geom->m_sphere.v.w = big.v.w + t;
            }
        }
        p = Read(p, 4, &matSum);
        Mat_00174FB8* mat = geom->m2C;
        int k;
        for (k = 0; k < geom->m28; k++) {
            if (mat->m4 == matSum)
                break;
            mat++;
        }
        mesh->m8 = mat;
        p = Read(p, 4, &mesh->m4);
        func_00177948(mesh, 1);
        p = Read(p, 12, mesh->m10);
        p = Read(p, 12, mesh->m20);
        p = Read(p, 16, mesh->m30);
        if (D_00394318 >= 5)
            p = Read(p, 4, &mesh->m44);
        if (D_00394318 >= 6)
            p = Read(p, 4, &mesh->m48);
        p = func_00175650(p, mesh, mat, sec, arg);
        int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
        while ((unsigned int)D_00394274 & 0xF) {
            *(unsigned int*)D_00394274 = 0;
            D_00394274 += 4;
        }
        if (kind != 3 && kind != 0 && kind != 4)
            *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
        mesh->mC = func_00161070();
        mesh++;
    }
    geom->m30 += count;
    return p;
}
