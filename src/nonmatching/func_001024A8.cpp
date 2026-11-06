/* fuzzy: 64.2 */
typedef int qword_001024A8 __attribute__((mode(TI)));

union Vec_001024A8 {
    qword_001024A8 q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = 1.0f;
    }
};

struct Box_001024A8 {
    Vec_001024A8 min;
    Vec_001024A8 max;
};

struct Mat_001024A8;

extern "C" Vec_001024A8 func_00323298(Mat_001024A8* m, Vec_001024A8* v);
extern "C" void func_001235E8(Vec_001024A8* a, Vec_001024A8* b, unsigned int c0, unsigned int c1, int p);

extern "C" void func_001024A8(Box_001024A8* box, Mat_001024A8* m, unsigned int color, int p)
{
    Vec_001024A8 c[8];
    Vec_001024A8 t;
    c[0].Set(box->min.f.x, box->min.f.y, box->min.f.z);
    c[1].Set(box->min.f.x, box->min.f.y, box->max.f.z);
    c[2].Set(box->min.f.x, box->max.f.y, box->max.f.z);
    c[3].Set(box->min.f.x, box->max.f.y, box->min.f.z);
    c[4].Set(box->max.f.x, box->min.f.y, box->min.f.z);
    c[5].Set(box->max.f.x, box->min.f.y, box->max.f.z);
    c[6].Set(box->max.f.x, box->max.f.y, box->max.f.z);
    c[7].Set(box->max.f.x, box->max.f.y, box->min.f.z);
    c[0] = t = func_00323298(m, &c[0]);
    c[1] = t = func_00323298(m, &c[1]);
    c[2] = t = func_00323298(m, &c[2]);
    c[3] = t = func_00323298(m, &c[3]);
    c[4] = t = func_00323298(m, &c[4]);
    c[5] = t = func_00323298(m, &c[5]);
    c[6] = t = func_00323298(m, &c[6]);
    c[7] = t = func_00323298(m, &c[7]);
    func_001235E8(&c[0], &c[1], 0xFF000080, 0xFF000080, p);
    func_001235E8(&c[1], &c[2], 0xFF000080, 0xFF000080, p);
    func_001235E8(&c[2], &c[3], 0xFF000080, 0xFF000080, p);
    func_001235E8(&c[3], &c[0], 0xFF000080, 0xFF000080, p);
    func_001235E8(&c[4], &c[5], 0xFF80, 0xFF80, p);
    func_001235E8(&c[5], &c[6], 0xFF80, 0xFF80, p);
    func_001235E8(&c[6], &c[7], 0xFF80, 0xFF80, p);
    func_001235E8(&c[7], &c[4], 0xFF80, 0xFF80, p);
    func_001235E8(&c[0], &c[4], color, color, p);
    func_001235E8(&c[1], &c[5], color, color, p);
    func_001235E8(&c[2], &c[6], color, color, p);
    func_001235E8(&c[3], &c[7], color, color, p);
}
