extern "C" float sqrtf(float);

struct Vec_001713E8 {
    float x, y, z, w;
};

struct Heap_001713E8 {
    char pad[0xD8];
    void* mD8;
};

struct Node_001713E8 {
    char pad[0xC];
    float m_radius;
    float m_scale[3];
    char pad1c[4];
    void* m20;
    char pad24[4];
    Node_001713E8* m_next;
    char pad2c[0x20];
    Node_001713E8* m4C;
};

extern Heap_001713E8* D_00388A70;

extern "C" void func_00171030(Node_001713E8* n, Vec_001713E8* off);
extern "C" int func_00170518(Node_001713E8* n);
extern "C" int func_00170528(Node_001713E8* n);
extern "C" int func_00161860(void* mesh);
extern "C" void func_00161D50(void* mesh, int* buf);
extern "C" void func_00161E70(void* mesh, int* buf, int a);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0010A9B0(void* heap);

extern "C" void func_001713E8(Node_001713E8* n, Vec_001713E8* off, float* scale, int top)
{
    if (top) {
        Vec_001713E8 neg;
        neg.x = -off->x;
        neg.y = -off->y;
        neg.z = -off->z;
        neg.w = -off->w;
        func_00171030(n, &neg);
    }
    n->m_scale[0] *= scale[0];
    n->m_scale[1] *= scale[1];
    n->m_scale[2] *= scale[2];
    float a = sqrtf(n->m_scale[0] * n->m_scale[0] + n->m_scale[1] * n->m_scale[1] + n->m_scale[2] * n->m_scale[2]);
    float b = sqrtf(scale[0] * scale[0] + scale[1] * scale[1] + (scale[2] + scale[2]));
    float r = n->m_radius * b;
    n->m_radius = a < r ? a : r;
    if (func_00170518(n)) {
        int ix = (int)(scale[0] * 16.0f);
        int iy = (int)(scale[1] * 16.0f);
        int iz = (int)(scale[2] * 16.0f);
        int count = func_00161860(n->m20);
        func_0010A950(D_00388A70, D_00388A70->mD8);
        int* buf = (int*)func_0010A638(D_00388A70, count << 4, 1, 0);
        func_00161D50(n->m20, buf);
        for (int i = 0; i < count; i++) {
            buf[i * 4 + 0] = buf[i * 4 + 0] * ix / 16;
            buf[i * 4 + 1] = buf[i * 4 + 1] * iy / 16;
            buf[i * 4 + 2] = buf[i * 4 + 2] * iz / 16;
        }
        func_00161E70(n->m20, buf, 0);
        if (buf)
            func_0010A8D8(D_00388A70, buf);
        func_0010A9B0(D_00388A70);
    } else {
        if (func_00170528(n) && n->m4C)
            func_001713E8(n->m4C, off, scale, 0);
        for (Node_001713E8* c = (Node_001713E8*)n->m20; c; c = c->m_next)
            func_001713E8(c, off, scale, 0);
    }
    if (top)
        func_00171030(n, off);
}
