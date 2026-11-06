typedef int qword __attribute__((mode(TI)));
union Vec_002987C8;
extern "C" void func_003233B8(Vec_002987C8* a, Vec_002987C8* b);
union Vec_002987C8 {
    qword q;
    struct { float x, y, z, w; } f;
    Vec_002987C8() {}
    Vec_002987C8(float x, float y, float z, float w) { f.x = x; f.y = y; f.z = z; f.w = w; }
    Vec_002987C8 operator+(const Vec_002987C8& o) const { return Vec_002987C8(f.x + o.f.x, f.y + o.f.y, f.z + o.f.z, f.w + o.f.w); }
    Vec_002987C8 operator*(float k) const { return Vec_002987C8(f.x * k, f.y * k, f.z * k, f.w * k); }
    void Normalize() { func_003233B8(this, this); }
};

struct Idx_002987C8 {
    int v[9];
};
extern Idx_002987C8 D_00377578;

struct Node_002987C8 {
    char pad[0x10];
    Vec_002987C8 m10;
    int m20;
    char pad24[4];
    float m28;
    Node_002987C8* m2C;
    Node_002987C8* m30;
    int m34;
    int m38;
    void Build(void* a, void* b, float f);
};

extern "C" void func_00298C60(Node_002987C8* n);
extern "C" void* func_001317D0(unsigned int name);
extern "C" void* func_00134F18(void* p);
extern "C" int func_0013C7E0(void* p);
extern "C" Vec_002987C8* func_0010BDE0(int size);
extern "C" void func_0013C808(void* p, Vec_002987C8* v);
extern "C" Vec_002987C8 func_002977F8(Vec_002987C8* p, void* a, void* b, float f);
extern "C" int func_002978F8(unsigned int name);
extern "C" void func_0013C930(void* p, Vec_002987C8* v);
extern "C" void func_0010BEB8(void* p);
extern "C" float sqrtf(float);

void Node_002987C8::Build(void* a, void* b, float f)
{
    if (!m20) {
        func_00298C60(this);
        return;
    }
    if (m28 < 2.625f) {
        func_00298C60(this);
        return;
    }
    float hi = -1000000.0f;
    void* mesh = func_00134F18(func_001317D0(0x2756C52D));
    int n = func_0013C7E0(mesh);
    Vec_002987C8* verts = func_0010BDE0(n << 4);
    func_0013C808(mesh, verts);
    float lo = 1000000.0f;
    for (int i = 0; i < n; i++) {
        float y = verts[i].f.y;
        if (y < lo)
            lo = y;
        if (hi < y)
            hi = y;
    }
    float h = 2.625f;
    if (m2C && m30) {
        Vec_002987C8 d0(m30->m10.f.x - m10.f.x, m30->m10.f.y - m10.f.y, m30->m10.f.z - m10.f.z, m30->m10.f.w - m10.f.w);
        Vec_002987C8 d1(m10.f.x - m2C->m10.f.x, m10.f.y - m2C->m10.f.y, m10.f.z - m2C->m10.f.z, m10.f.w - m2C->m10.f.w);
        Vec_002987C8 m = (d0 + d1) * 0.5f;
        m.Normalize();
        h = sqrtf(1.0f - m.f.y * m.f.y) * h;
    }
    Vec_002987C8 p = func_002977F8(&m10, a, b, f);
    float top = hi + h;
    for (int i = 0; i < n; i++) {
        verts[i].f.x += p.f.x;
        verts[i].f.y += p.f.y;
        verts[i].f.z += p.f.z;
        verts[i].f.w += p.f.w;
        verts[i].f.y -= top;
    }
    Idx_002987C8 idx = D_00377578;
    top = m28 - top - hi;
    for (int k = 0; k < 9; k++)
        verts[idx.v[k]].f.y -= top;
    if (m2C) {
        Vec_002987C8 dir;
        float x = m10.f.x - m2C->m10.f.x;
        float z = m10.f.z - m2C->m10.f.z;
        float w = m10.f.w - m2C->m10.f.w;
        dir.f.y = 0.0f;
        dir.f.x = x;
        dir.f.z = z;
        dir.f.w = w;
        dir.Normalize();
        float sn = dir.f.z;
        float c = dir.f.x;
        float nsn = -sn;
        for (int i = 0; i < n; i++) {
            float dx = verts[i].f.x - p.f.x;
            float dz = verts[i].f.z - p.f.z;
            verts[i].f.x = c * dx + nsn * dz + p.f.x;
            verts[i].f.z = sn * dx + c * dz + p.f.z;
        }
    }
    if (!m38)
        m38 = func_002978F8(0x2756C52D);
    func_0013C930(func_00134F18((void*)m38), verts);
    func_0010BEB8(verts);
}
