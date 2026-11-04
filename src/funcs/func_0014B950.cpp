typedef int qword_0014B950 __attribute__((mode(TI)));

union Vec_0014B950 {
    qword_0014B950 q;
    struct {
        float x, y, z, w;
    } f;
    struct {
        int x, y, z, w;
    } i;
};

struct Mat_0014B950 {
    Vec_0014B950 row[4];
};

extern Mat_0014B950 D_003E1100;
extern Mat_0014B950 D_003E1180;
extern int D_0038882C;
extern float D_0038C0FC;
extern float D_0038C100;
extern float D_0038A0F0;
extern float D_0038A0F4;
extern float D_0038A0F8;
extern "C" void func_0014B888(void* cam);
extern "C" Vec_0014B950 func_00323298(Mat_0014B950* m, Vec_0014B950* v);

static inline bool IsPal_0014B950()
{
    return D_0038882C == 1;
}

extern "C" float func_0014B950(void* cam, Vec_0014B950* p, float* sx, float* sy, unsigned int* sz)
{
    func_0014B888(cam);
    Vec_0014B950 v;
    Vec_0014B950 t = func_00323298(&D_003E1100, p);
    v = t;
    if (v.f.x > v.f.w || v.f.x < -v.f.w || v.f.y > v.f.w || v.f.y < -v.f.w || v.f.z > v.f.w
        || v.f.z < -v.f.w)
        return -1.0f;
    float depth = -v.f.z;
    t = func_00323298(&D_003E1180, p);
    v = t;
    float iw = 1.0f / v.f.w;
    v.f.x *= iw;
    v.f.y *= iw;
    v.f.z *= iw;
    v.f.w *= iw;
    *sx = ((float)(v.i.x & 0xFFFF) - (IsPal_0014B950() ? 27648.0f : 28672.0f)) * 0.0625f;
    *sy = ((float)(v.i.y & 0xFFFF) - (IsPal_0014B950() ? 29184.0f : 28672.0f)) * 0.0625f;
    *sz = v.i.z & 0xFFFFFF;
    *sx /= D_0038C0FC;
    float h = D_0038C100;
    *sy /= h;
    float d = D_0038A0F0 / depth;
    float lo = d < D_0038A0F4 ? d : D_0038A0F4;
    return lo > D_0038A0F8 ? lo : D_0038A0F8;
}
