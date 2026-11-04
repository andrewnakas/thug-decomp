typedef int qword __attribute__((mode(TI)));
union Vec_00298508;
extern "C" void func_003233B8(Vec_00298508* a, Vec_00298508* b);
union Vec_00298508 {
    qword q;
    struct { float x, y, z, w; } f;
    Vec_00298508() {}
    void Normalize() { func_003233B8(this, this); }
    Vec_00298508(float x, float y, float z, float w) { f.x = x; f.y = y; f.z = z; f.w = w; }
};

struct Node_00298508 {
    char pad[0x10];
    Vec_00298508 m10;
    char pad20[0x2C - 0x20];
    Node_00298508* m2C;
    int m30;
    int m34;
    void Draw(void* a, void* b, float f);
};

extern "C" void func_00298BF8(Node_00298508* n);
extern "C" int func_002978F8(unsigned int name);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" float func_00340F60(float);
extern "C" Vec_00298508 func_002977F8(Vec_00298508* p, void* a, void* b, float f);
extern "C" void func_00297BF8(Vec_00298508* a, Vec_00298508* b, Vec_00298508* c, int d, unsigned int name, int e, int g);

void Node_00298508::Draw(void* a, void* b, float f)
{
    if (!m2C) {
        func_00298BF8(this);
        return;
    }
    if (!m34)
        m34 = func_002978F8(0x66FE99BF);
    Vec_00298508 v0;
    Vec_00298508 v1;
    Vec_00298508 v2;
    bool ok = true;
    if (m2C->m2C) {
        Vec_00298508* pos = &m10;
        v0 = Vec_00298508(m2C->m10.f.x - m2C->m2C->m10.f.x, m2C->m10.f.y - m2C->m2C->m10.f.y, m2C->m10.f.z - m2C->m2C->m10.f.z, m2C->m10.f.w - m2C->m2C->m10.f.w);
        v1 = Vec_00298508(m10.f.x - m2C->m10.f.x, m10.f.y - m2C->m10.f.y, m10.f.z - m2C->m10.f.z, m10.f.w - m2C->m10.f.w);
        v0.Normalize();
        v1.Normalize();
        float d = v0.f.x * v1.f.x + v0.f.y * v1.f.y + v0.f.z * v1.f.z;
        if (d < func_00340F60(func_001E5318(0xB1459A78, 0) * 0.01745329425f))
            ok = false;
        v0 = func_002977F8(&m2C->m2C->m10, a, b, f);
        v1 = func_002977F8(&m2C->m10, a, b, f);
        v2 = func_002977F8(pos, a, b, f);
        func_00297BF8(&v0, &v1, &v2, m34, 0x66FE99BF, ok ? m2C->m34 : 0, 1);
    } else {
        Vec_00298508 e;
        v0 = func_002977F8(&m2C->m10, a, b, f);
        v1 = func_002977F8(&m10, a, b, f);
        func_00297BF8(&e, &v0, &v1, m34, 0x66FE99BF, 0, 1);
    }
}
