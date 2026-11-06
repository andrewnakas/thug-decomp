/* fuzzy: 92.9 */
typedef int qword __attribute__((mode(TI)));

extern "C" float fabsf(float);
extern "C" void* func_003315B8(void* dst, int c, unsigned int n);
extern "C" int func_001D2438(float* t, float ox, float oy, float ux, float uy, float px, float py,
                             float dx, float dy);

struct Vec_001D2530 {
    union {
        struct { float x, y, z, w; };
        float v[4];
        qword q;
    };
    Vec_001D2530() {}
    Vec_001D2530(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001D2530& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
    Vec_001D2530& operator+=(const Vec_001D2530& o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
};

static inline Vec_001D2530 operator-(const Vec_001D2530& a, const Vec_001D2530& b)
{
    return Vec_001D2530(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001D2530 operator+(const Vec_001D2530& a, const Vec_001D2530& b)
{
    return Vec_001D2530(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001D2530 operator*(const Vec_001D2530& a, float s)
{
    return Vec_001D2530(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline void Isect_001D2530(Vec_001D2530& r, const Vec_001D2530& a, const Vec_001D2530& b, float da,
                                  float db)
{
    float diff = da - db;
    if (fabsf(diff) > 0.00001f) {
        r = a + (b - a) * da * (1.0f / diff);
    } else {
        r = a;
    }
}

static inline void ClassP_001D2530(float ref, float sa, float sc, bool& ia, bool& ib)
{
    if (ref > 0.0f) {
        ia = sa >= 0.0f;
        ib = sc >= 0.0f;
    } else {
        ia = sa <= 0.0f;
        ib = sc <= 0.0f;
    }
}

static inline void ClassN_001D2530(float ref, float sa, float sc, bool& ia, bool& ib)
{
    if (ref < 0.0f) {
        ia = sa >= 0.0f;
        ib = sc >= 0.0f;
    } else {
        ia = sa <= 0.0f;
        ib = sc <= 0.0f;
    }
}

struct Box_001D2530 {
    Vec_001D2530 o;
    Vec_001D2530 u;
    Vec_001D2530 v;
};

bool func_001D2530(Box_001D2530* box, const Vec_001D2530& p0, const Vec_001D2530& p1,
                   const Vec_001D2530& p2, Vec_001D2530* out, int* outIdx)
{
    Vec_001D2530 n;
    Vec_001D2530 pt0;
    Vec_001D2530 pt1;
    n.x = box->u.y * box->v.z - box->u.z * box->v.y;
    n.y = box->u.z * box->v.x - box->u.x * box->v.z;
    n.z = box->u.x * box->v.y - box->u.y * box->v.x;
    n.w = 0.0f;
    float d = -(n.x * box->o.x + n.y * box->o.y + n.z * box->o.z);
    float d0 = n.x * p0.x + n.y * p0.y + n.z * p0.z + d;
    float d1 = n.x * p1.x + n.y * p1.y + n.z * p1.z + d;
    float d2 = n.x * p2.x + n.y * p2.y + n.z * p2.z + d;
    if (d0 > 0.0f && d1 > 0.0f && d2 > 0.0f) {
        return false;
    }
    if (d0 < 0.0f && d1 < 0.0f && d2 < 0.0f) {
        return false;
    }
    if (fabsf(d0) < 0.00001f) {
        d0 = 0.0f;
    }
    if (fabsf(d1) < 0.00001f) {
        d1 = 0.0f;
    }
    if (fabsf(d2) < 0.00001f) {
        d2 = 0.0f;
    }
    int i0;
    int i1;
    if ((d0 <= 0.0f && d1 >= 0.0f) || (d0 >= 0.0f && d1 <= 0.0f)) {
        i0 = 1;
        Isect_001D2530(pt0, p0, p1, d0, d1);
        if ((d1 <= 0.0f && d2 >= 0.0f) || (d1 >= 0.0f && d2 <= 0.0f)) {
            i1 = 2;
            Isect_001D2530(pt1, p1, p2, d1, d2);
        } else {
            i1 = 3;
            Isect_001D2530(pt1, p2, p0, d2, d0);
        }
    } else {
        i0 = 2;
        Isect_001D2530(pt0, p1, p2, d1, d2);
        i1 = 3;
        Isect_001D2530(pt1, p0, p2, d0, d2);
    }

    float ox, oy, ux, uy, vx, vy, ax, ay, cx, cy;
    if (fabsf(n.x) < fabsf(n.z) && fabsf(n.y) < fabsf(n.z)) {
        ox = box->o.x;
        oy = box->o.y;
        ux = box->u.x;
        uy = box->u.y;
        vx = box->v.x;
        vy = box->v.y;
        ax = pt0.x;
        ay = pt0.y;
        cx = pt1.x;
        cy = pt1.y;
    } else if (fabsf(n.x) < fabsf(n.y) && fabsf(n.z) < fabsf(n.y)) {
        ox = box->o.x;
        oy = box->o.z;
        ux = box->u.x;
        uy = box->u.z;
        vx = box->v.x;
        vy = box->v.z;
        ax = pt0.x;
        ay = pt0.z;
        cx = pt1.x;
        cy = pt1.z;
    } else {
        ox = box->o.y;
        oy = box->o.z;
        ux = box->u.y;
        uy = box->u.z;
        vx = box->v.y;
        vy = box->v.z;
        ax = pt0.y;
        ay = pt0.z;
        cx = pt1.y;
        cy = pt1.z;
    }

    bool inA[4];
    bool inB[4];
    func_003315B8(inA, 0, sizeof(inA));
    func_003315B8(inB, 0, sizeof(inB));

    float nu = -ux;
    float refU = uy * vx + nu * vy;
    float k = oy * ux - ox * uy;
    ClassP_001D2530(refU, uy * ax + nu * ay + k, uy * cx + nu * cy + k, inA[0], inB[0]);
    if (!inA[0] && !inB[0]) {
        return false;
    }
    ClassN_001D2530(refU, uy * ax + nu * ay + ((oy + vy) * ux - (ox + vx) * uy), uy * cx + nu * cy + ((oy + vy) * ux - (ox + vx) * uy), inA[1], inB[1]);
    if (!inA[1] && !inB[1]) {
        return false;
    }

    float nv = -vx;
    float refV = vy * ux + nv * uy;
    k = oy * vx - ox * vy;
    ClassP_001D2530(refV, vy * ax + nv * ay + k, vy * cx + nv * cy + k, inA[2], inB[2]);
    if (!inA[2] && !inB[2]) {
        return false;
    }
    ClassN_001D2530(refV, vy * ax + nv * ay + ((oy + uy) * vx - (ox + ux) * vy), vy * cx + nv * cy + ((oy + uy) * vx - (ox + ux) * vy), inA[3], inB[3]);
    if (!inA[3] && !inB[3]) {
        return false;
    }

    int cnt;
    if (inA[0] && inA[1] && inA[2] && inA[3]) {
        out[0] = pt0;
        outIdx[0] = i0;
        if (inB[0] && inB[1] && inB[2] && inB[3]) {
            out[1] = pt1;
            outIdx[1] = i1;
            return true;
        }
        cnt = 1;
    } else if (inB[0] && inB[1] && inB[2] && inB[3]) {
        cnt = 1;
        out[0] = pt1;
        outIdx[0] = i1;
    } else {
        cnt = 0;
    }

    float t;
    if (func_001D2438(&t, ox, oy, ux, uy, ax, ay, cx - ax, cy - ay)) {
        out[cnt] = box->u;
        out[cnt] *= t;
        out[cnt] += box->o;
        outIdx[cnt] = 0;
        if (cnt == 1) {
            return true;
        }
        cnt = 1;
    }
    if (func_001D2438(&t, ox + vx, oy + vy, ux, uy, ax, ay, cx - ax, cy - ay)) {
        out[cnt] = box->u;
        out[cnt] *= t;
        out[cnt] += box->o;
        out[cnt].x += box->v.x;
        out[cnt].y += box->v.y;
        out[cnt].z += box->v.z;
        out[cnt].w += box->v.w;
        outIdx[cnt] = 0;
        if (cnt == 1) {
            return true;
        }
        cnt = 1;
    }
    if (func_001D2438(&t, ox, oy, vx, vy, ax, ay, cx - ax, cy - ay)) {
        out[cnt] = box->v;
        out[cnt] *= t;
        out[cnt] += box->o;
        outIdx[cnt] = 0;
        if (cnt == 1) {
            return true;
        }
        cnt = 1;
    }
    if (func_001D2438(&t, ox + ux, oy + uy, vx, vy, ax, ay, cx - ax, cy - ay)) {
        if (cnt == 1) {
            Vec_001D2530& r = out[cnt];
            r = box->v;
            r *= t;
            r += box->o;
            r.x += box->u.x;
            r.y += box->u.y;
            r.z += box->u.z;
            r.w += box->u.w;
            outIdx[cnt] = 0;
            return true;
        }
    }
    return false;
}
