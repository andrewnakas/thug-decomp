typedef int qword __attribute__((mode(TI)));
union Vec_00297BF8 {
    qword q;
    struct { float x, y, z, w; } f;
    Vec_00297BF8() {}
    Vec_00297BF8(float x, float y, float z, float w) { f.x = x; f.y = y; f.z = z; f.w = w; }
    Vec_00297BF8 operator-(const Vec_00297BF8& o) const { return Vec_00297BF8(f.x - o.f.x, f.y - o.f.y, f.z - o.f.z, f.w - o.f.w); }
    Vec_00297BF8 operator+(const Vec_00297BF8& o) const { return Vec_00297BF8(f.x + o.f.x, f.y + o.f.y, f.z + o.f.z, f.w + o.f.w); }
    Vec_00297BF8 operator*(float k) const { return Vec_00297BF8(f.x * k, f.y * k, f.z * k, f.w * k); }
};

struct Idx_00297BF8 {
    int v[11];
};
extern Idx_00297BF8 D_00377518;
extern Idx_00297BF8 D_00377548;

struct Geo_00297BF8 {
    char pad[6];
    unsigned short m6;
};

extern "C" void* func_001317D0(unsigned int name);
extern "C" void* func_00134F18(void* p);
extern "C" int func_0013C7E0(void* p);
extern "C" Vec_00297BF8* func_0010BDE0(int size);
extern "C" void func_0013C808(void* p, Vec_00297BF8* v);
extern "C" void func_00297990(Vec_00297BF8* pos, Vec_00297BF8* dir, Vec_00297BF8* verts, int* idx, int n);
extern "C" void func_0013C930(void* p, Vec_00297BF8* v);
extern "C" void func_0010BEB8(void* p);
extern "C" Geo_00297BF8* func_0013C710(void* p);
extern "C" void func_001D8B48(Geo_00297BF8* g, Vec_00297BF8* v);
extern "C" void func_00101EA8(Vec_00297BF8* v);
extern "C" void func_00135380(int mesh, Vec_00297BF8* v);

extern "C" void func_00297BF8(Vec_00297BF8* p0, Vec_00297BF8* p1, Vec_00297BF8* p2, int mesh, unsigned int name, int prev, int weld)
{
    Idx_00297BF8 a = D_00377518;
    Idx_00297BF8 b = D_00377548;
    void* src = func_00134F18(func_001317D0(name));
    int n = func_0013C7E0(src);
    Vec_00297BF8* verts = func_0010BDE0(n << 4);
    func_0013C808(src, verts);
    Vec_00297BF8 dir;
    if (prev) {
        dir = ((*p1 - *p0) + (*p2 - *p1)) * 0.5f;
        func_00297990(p1, &dir, verts, a.v, 11);
        void* pm = func_00134F18((void*)prev);
        Vec_00297BF8* pv = func_0010BDE0(func_0013C7E0(pm) << 4);
        func_0013C808(pm, pv);
        for (int k = 0; k < 11; k++)
            pv[b.v[k]] = verts[a.v[k]];
        func_0013C930(pm, pv);
        func_0010BEB8(pv);
    } else {
        dir = *p2 - *p1;
        func_00297990(p1, &dir, verts, a.v, 11);
    }
    dir = *p2 - *p1;
    func_00297990(p2, &dir, verts, b.v, 11);
    func_0013C930(func_00134F18((void*)mesh), verts);
    if (weld) {
        Vec_00297BF8* orig = func_0010BDE0(n << 4);
        func_0013C808(src, orig);
        Geo_00297BF8* g = func_0013C710(src);
        int m = g->m6;
        Vec_00297BF8* out = func_0010BDE0(m << 4);
        func_001D8B48(g, out);
        for (int i = 0; i < m; i++) {
            Vec_00297BF8 v = out[i];
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (orig[j].f.x == v.f.x && orig[j].f.y == v.f.y && orig[j].f.z == v.f.z) {
                    out[i] = verts[j];
                    found = 1;
                    break;
                }
            }
            if (found)
                continue;
            int found2 = 0;
            for (int j = 0; j < n; j++) {
                if (orig[j].f.x == v.f.x && orig[j].f.z == v.f.z) {
                    float dy = v.f.y - orig[j].f.y;
                    out[i] = verts[j];
                    found2 = 1;
                    out[i].f.y += dy;
                    break;
                }
            }
            if (!found2)
                func_00101EA8(&v);
        }
        func_00135380(mesh, out);
        func_0010BEB8(out);
        func_0010BEB8(orig);
    }
    func_0010BEB8(verts);
}
