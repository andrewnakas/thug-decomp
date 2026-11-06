/* fuzzy: 97.4 */
typedef int qword_0020FD98 __attribute__((mode(TI)));

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;
extern "C" float sqrtf(float);

struct Vec_0020FD98 {
    union {
        struct { float x, y, z, w; };
        qword_0020FD98 q;
    };
    Vec_0020FD98() {}
    Vec_0020FD98(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

static inline Vec_0020FD98 operator+(const Vec_0020FD98& a, const Vec_0020FD98& b)
{
    return Vec_0020FD98(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
static inline Vec_0020FD98 operator-(const Vec_0020FD98& a, const Vec_0020FD98& b)
{
    return Vec_0020FD98(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
static inline Vec_0020FD98 operator*(const Vec_0020FD98& a, float k)
{
    return Vec_0020FD98(a.x * k, a.y * k, a.z * k, a.w * k);
}

static inline float Length_0020FD98(const Vec_0020FD98& d)
{
    return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
}

struct Box_0020FD98 {
    Vec_0020FD98 mn;
    Vec_0020FD98 mx;
};

struct Mat_0020FD98;
extern "C" Mat_0020FD98* func_00100890(Mat_0020FD98* out, float a);
extern "C" Mat_0020FD98* func_00100928(Mat_0020FD98* out, float a);
extern "C" Mat_0020FD98* func_001009C0(Mat_0020FD98* out, float a);
extern "C" void func_00323318(Mat_0020FD98* d, Mat_0020FD98* a, Mat_0020FD98* b);

struct Mat_0020FD98 {
    float r[4][4];
    void RotX(float a)
    {
        Mat_0020FD98 t;
        func_00323318(this, func_00100890(&t, a), this);
    }
    void RotY(float a)
    {
        Mat_0020FD98 t;
        func_00323318(this, func_00100928(&t, a), this);
    }
    void RotZ(float a)
    {
        Mat_0020FD98 t;
        func_00323318(this, func_001009C0(&t, a), this);
    }
    void Ident()
    {
        r[0][0] = 1.0f; r[0][1] = 0.0f; r[0][2] = 0.0f; r[0][3] = 0.0f;
        r[1][0] = 0.0f; r[1][1] = 1.0f; r[1][2] = 0.0f; r[1][3] = 0.0f;
        r[2][0] = 0.0f; r[2][1] = 0.0f; r[2][2] = 1.0f; r[2][3] = 0.0f;
        r[3][0] = 0.0f; r[3][1] = 0.0f; r[3][2] = 0.0f; r[3][3] = 1.0f;
    }
};

struct Cam_0020FD98 {
    char pad0[0x50];
    Vec_0020FD98 m50;
    char pad60[0x70 - 0x60];
    Mat_0020FD98 m70;
};

struct Model_0020FD98 {
    char pad0[0xD0];
    void* mD0;
    void Frame(int id, float scale, float rx, float ry, float rz);
};

extern void* D_0038C608;
extern "C" void func_001022D8(Box_0020FD98* box);
extern "C" void func_00102358(Box_0020FD98* box, Vec_0020FD98* p);
extern "C" void func_00132A80(void* list);
extern "C" void* func_00132A90(void* list, int a);
extern "C" int func_00134F08(void* item);
extern "C" int func_001350B8(void* item);
extern "C" void* func_00134F18(void* item);
extern "C" int func_0013C7E0(void* geom);
extern "C" void func_0013C808(void* geom, Vec_0020FD98* v);
extern "C" Cam_0020FD98* func_00187B48(void* mgr, unsigned int id);
void Model_0020FD98::Frame(int id, float scale, float rx, float ry, float rz)
{
    Box_0020FD98 box;
    func_001022D8(&box);
    void* list = mD0;
    if (list) {
        func_00132A80(list);
        for (void* item = func_00132A90(list, 0); item; item = func_00132A90(list, 0)) {
            if (id && id != func_00134F08(item)) continue;
            if (!func_001350B8(item)) continue;
            void* geom = func_00134F18(item);
            if (!geom) continue;
            int n = func_0013C7E0(geom);
            if (!n) continue;
            Vec_0020FD98* verts = new Vec_0020FD98[n];
            func_0013C808(geom, verts);
            Vec_0020FD98* v = verts;
            for (int i = 0; i < n; i++) {
                func_00102358(&box, v);
                v++;
            }
            delete[] verts;
        }
    }
    Cam_0020FD98* cam = func_00187B48(D_0038C608, 0xEB17151B);
    if (!cam) return;
    Box_0020FD98 b = box;
    Vec_0020FD98 c((b.mn.x + b.mx.x) * 0.5f, (b.mn.y + b.mx.y) * 0.5f, (b.mn.z + b.mx.z) * 0.5f, (b.mn.w + b.mx.w) * 0.5f);
    float len = Length_0020FD98(b.mx - b.mn);
    if (len < 1000.0f) len = 1000.0f;
    Mat_0020FD98* m = &cam->m70;
    m->Ident();
    len *= scale;
    m->RotX(rx * 0.01745329425f);
    m->RotY(ry * 0.01745329425f);
    m->RotZ(rz * 0.01745329425f);
    float k = scale * len;
    cam->m50 = c + Vec_0020FD98(cam->m70.r[2][0] * k, cam->m70.r[2][1] * k, cam->m70.r[2][2] * k, cam->m70.r[2][3] * k);
}
