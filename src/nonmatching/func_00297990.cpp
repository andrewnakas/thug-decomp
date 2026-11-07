/* fuzzy: 96.4 */
/* nonmatch func_00297990: best earlier draft (thug-claude-lane3/work/nm67/wt2/func_00297990.nm.cpp), 5 of 154 words differ. */
/* near miss (5 words): v0/v1 swap in org = verts[idx[0]] qword copy (address/data regs). Tried decl permutations, *(verts+idx[0]), .q copy, temp index. r3 wt2 also: org/up decl order and org init placement (size change or 8 words), verts[*idx], unsigned/short idx, byte-offset form: no change. */
typedef int qword __attribute__((mode(TI)));
union Vec_00297990 {
    qword q;
    struct { float x, y, z, w; } f;
    void Set(float ax, float ay, float az, float aw) { f.x = ax; f.y = ay; f.z = az; f.w = aw; }
};
struct Mat_00297990 {
    Vec_00297990 r[4];
};

extern "C" void func_003233B8(Vec_00297990* a, Vec_00297990* b);
extern "C" void func_00323298(Vec_00297990* out, Mat_00297990* m, Vec_00297990* v);
extern "C" float fabsf(float);

extern "C" void func_00297990(Vec_00297990* pos, Vec_00297990* dir, Vec_00297990* verts, int* idx, int n)
{
    Vec_00297990 org;
    Vec_00297990 up;
    Vec_00297990 fwd;
    Vec_00297990 side;
    org = verts[idx[0]];
    up.Set(0.0f, 1.0f, 0.0f, 1.0f);
    fwd = *dir;
    func_003233B8(&fwd, &fwd);
    if (fabsf(fwd.f.y) > 0.9999899864f) {
        side.Set(0.0f, 0.0f, 1.0f, 1.0f);
    } else {
        Vec_00297990 c;
        float x = up.f.y * fwd.f.z - up.f.z * fwd.f.y;
        float y = up.f.z * fwd.f.x - up.f.x * fwd.f.z;
        float z = up.f.x * fwd.f.y - up.f.y * fwd.f.x;
        c.f.w = 0.0f;
        c.f.x = x;
        c.f.z = z;
        c.f.y = y;
        side = c;
        func_003233B8(&side, &side);
    }
    Vec_00297990 top;
    {
        float x = fwd.f.y * side.f.z - fwd.f.z * side.f.y;
        float y = fwd.f.z * side.f.x - fwd.f.x * side.f.z;
        float z = fwd.f.x * side.f.y - fwd.f.y * side.f.x;
        top.f.w = 0.0f;
        top.f.x = x;
        top.f.z = z;
        top.f.y = y;
    }
    func_003233B8(&top, &top);
    Mat_00297990 m;
    m.r[0] = fwd;
    m.r[1] = top;
    m.r[2] = side;
    m.r[3].f.w = 1.0f;
    for (int i = 0; i < n; i++) {
        Vec_00297990* v = &verts[idx[i]];
        Vec_00297990 d;
        Vec_00297990 r;
        Vec_00297990 t;
        d.f.x = v->f.x - org.f.x;
        d.f.y = v->f.y - org.f.y;
        d.f.z = v->f.z - org.f.z;
        d.f.w = v->f.w - org.f.w;
        func_00323298(&t, &m, &d);
        d = t;
        r.f.x = d.f.x + pos->f.x;
        r.f.y = d.f.y + pos->f.y;
        r.f.z = d.f.z + pos->f.z;
        r.f.w = d.f.w + pos->f.w;
        *v = r;
    }
}
