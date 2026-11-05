/* sym: __muldi3 = 0x0033D1D8 */
extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern int D_0039401C;
extern int D_00394000;
extern int D_00394018;
extern short* D_0039402C;
extern int D_0038BF80;
extern int D_0038BF68;
extern signed char* D_0038BF6C;
struct W_00177020 {
    float w[3];
};
extern W_00177020* D_0038BF70;
extern int D_0038BF7C;
extern long D_00393FB8;
extern long D_00393FC0;
extern long D_00393FC8;
extern long D_00393FD0;
extern long D_00393FD8;
extern long D_00393FE0;
extern long D_00393FE8;
extern long D_00393FF0;
extern long D_00393FF8;
extern char D_00361010[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));
extern "C" void func_00177A20(int a, short* p);

typedef int qword __attribute__((mode(TI)));

struct Vec_00177020 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_00177020() {}
    Vec_00177020(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void operator*=(const Vec_00177020& b)
    {
        x *= b.x;
        y *= b.y;
        z *= b.z;
        w *= b.w;
    }
    void operator+=(const Vec_00177020& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
    }
};

static inline Vec_00177020 operator-(const Vec_00177020& a, const Vec_00177020& b)
{
    return Vec_00177020(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_00177020 operator+(const Vec_00177020& a, const Vec_00177020& b)
{
    return Vec_00177020(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00177020 operator*(const Vec_00177020& a, float s)
{
    return Vec_00177020(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" Vec_00177020 func_00176F88(int i);
extern "C" Vec_00177020 func_00176F18(int i);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void PutS(int v)
{
    *D_0039402C++ = v;
}

extern "C" void func_00177020(void* v, int skinned, int* count)
{
    if (!D_0039401C) {
        short adc = -0x8000;
        Put(0x05000001);
        unsigned char* p = D_00394274;
        D_00394288 = p;
        D_00394284 = 0x10;
        D_0039428C = 4;
        Put((((unsigned short)D_00394000 + (unsigned short)D_00394280) & 0x3FF) | 0x6D008000);
        D_0039402C = (short*)D_00394274;
        if (D_0038BF80) {
            PutS((unsigned short)D_00393FD0);
            PutS((unsigned short)D_00393FD8);
            PutS((unsigned short)D_00393FE0);
            PutS(adc);
            PutS((unsigned short)D_00393FE8);
            PutS((unsigned short)D_00393FF0);
            PutS((unsigned short)D_00393FF8);
            PutS(adc);
        }
        D_00394274 = (unsigned char*)(D_0039402C + D_00394018 * 4);
        unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
        D_00394290 = ((D_00394274 - D_00394288) - 4) * 8 / (D_0039428C * D_00394284);
        while (D_00394274 < end) {
            *D_00394274++ = 0;
        }
        if (D_00394290 == 0) {
            D_00394274 -= 4;
        } else if (D_00394290 < 0x100) {
            D_00394288[2] = D_00394290;
        } else if (D_00394290 == 0x100) {
            D_00394288[2] = 0;
        } else {
            func_00103F28(D_00361010);
            func_00334148(1);
        }
        Put(0x05000000);
    }
    if (skinned) {
        short* s = (short*)v;
        if (D_0038BF68) {
            Vec_00177020 p;
            p.x = s[0];
            p.y = s[1];
            p.z = s[2];
            p.w = 1.0f;
            Vec_00177020 b0 = func_00176F88(D_0038BF6C[D_0038BF7C * 3 + 0]);
            Vec_00177020 b1 = func_00176F88(D_0038BF6C[D_0038BF7C * 3 + 1]);
            Vec_00177020 b2 = func_00176F88(D_0038BF6C[D_0038BF7C * 3 + 2]);
            Vec_00177020 d0 = p - b0;
            Vec_00177020 d1 = p - b1;
            Vec_00177020 d2 = p - b2;
            d0 *= func_00176F18(D_0038BF6C[D_0038BF7C * 3 + 0]);
            d1 *= func_00176F18(D_0038BF6C[D_0038BF7C * 3 + 1]);
            d2 *= func_00176F18(D_0038BF6C[D_0038BF7C * 3 + 2]);
            d0 += b0;
            d1 += b1;
            d2 += b2;
            Vec_00177020 r = d0 * D_0038BF70[D_0038BF7C].w[0] + d1 * D_0038BF70[D_0038BF7C].w[1] +
                             d2 * D_0038BF70[D_0038BF7C].w[2];
            int x = (int)r.x;
            int y = (int)r.y;
            int z = (int)r.z;
            PutS(x);
            PutS(y);
            PutS(z);
        } else {
            PutS((unsigned short)s[0]);
            PutS((unsigned short)s[1]);
            PutS((unsigned short)s[2]);
        }
    } else {
        float* f = (float*)v;
        PutS((int)(f[0] * 16.0f));
        PutS((int)(f[1] * 16.0f));
        PutS((int)(f[2] * 16.0f));
    }
    if (skinned) {
        func_00177A20(*count, D_0039402C);
    }
    (*count)++;
    if (skinned) {
        *D_0039402C++ = ((unsigned short*)v)[3] ? -0x8000 : 0;
    } else {
        *D_0039402C++ = ((int*)v)[3] ? -0x8000 : 0;
    }
    D_00393FB8 = D_00393FD0;
    D_00393FC0 = D_00393FD8;
    D_00393FC8 = D_00393FE0;
    D_00393FD0 = D_00393FE8;
    D_00393FD8 = D_00393FF0;
    D_00393FE0 = D_00393FF8;
    short* q = (short*)D_0039402C;
    D_00393FE8 = q[-4];
    D_00393FF0 = q[-3];
    D_00393FF8 = q[-2];
    long ax = D_00393FB8;
    long ay = D_00393FC0;
    long az = D_00393FC8;
    long bx = D_00393FD0;
    long by = D_00393FD8;
    long bz = D_00393FE0;
    long cx = D_00393FE8;
    long cy = D_00393FF0;
    long cz = D_00393FF8;
    long nx = by * cz + cy * az + ay * bz - cy * bz - ay * cz - by * az;
    long ny = bz * cx + cz * ax + az * bx - cz * bx - az * cx - bz * ax;
    long nz = bx * cy + cx * ay + ax * by - cx * by - ax * cy - bx * ay;
    if (nx * nx + ny * ny + nz * nz == 0) {
        q[-1] = -0x8000;
    }
    D_00394000++;
}
