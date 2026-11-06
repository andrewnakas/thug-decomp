struct Vec_001711F8 {
    float x, y, z, w;
};

struct Pool_001711F8 {
    char pad0[0xD8];
    int mD8;
};

struct Node_001711F8 {
    char pad0[0x10];
    float m10;
    float m14;
    float m18;
    char pad1C[0x20 - 0x1C];
    void* m20;
    int m24;
    Node_001711F8* m28;
    char pad2C[0x4C - 0x2C];
    Node_001711F8* m4C;
};

extern Pool_001711F8* D_00388A70;

extern "C" void func_00171030(Node_001711F8* n, Vec_001711F8* v);
extern "C" void func_00101630(Node_001711F8* n, int flags);
extern "C" int func_00170518(Node_001711F8* n);
extern "C" int func_00170528(Node_001711F8* n);
extern "C" int func_00161860(void* p);
extern "C" void func_0010A950(Pool_001711F8* pool, int a);
extern "C" void* func_0010A638(Pool_001711F8* pool, int size, int a, int b);
extern "C" void func_00161D50(void* p, Vec_001711F8* buf);
extern "C" void func_00103EB8(int flags, float* x, float* y, float* z);
extern "C" void func_00161E70(void* p, Vec_001711F8* buf, int a);
extern "C" void func_0010A8D8(Pool_001711F8* pool, void* p);
extern "C" void func_0010A9B0(Pool_001711F8* pool);

extern "C" void func_001711F8(Node_001711F8* n, Vec_001711F8* off, int flags, int top)
{
    if (top) {
        Vec_001711F8 neg;
        neg.x = -off->x;
        neg.y = -off->y;
        neg.z = -off->z;
        neg.w = -off->w;
        func_00171030(n, &neg);
    }
    if (flags & 1) {
        float t = n->m10;
        n->m10 = n->m18;
        n->m18 = t;
    }
    func_00101630(n, flags);
    if (func_00170518(n)) {
        int cnt = func_00161860(n->m20);
        func_0010A950(D_00388A70, D_00388A70->mD8);
        Vec_001711F8* buf = (Vec_001711F8*)func_0010A638(D_00388A70, cnt * 16, 1, 0);
        func_00161D50(n->m20, buf);
        for (int i = 0; i < cnt; i++) {
            func_00103EB8(flags, &buf[i].x, &buf[i].y, &buf[i].z);
        }
        func_00161E70(n->m20, buf, 0);
        if (buf) func_0010A8D8(D_00388A70, buf);
        func_0010A9B0(D_00388A70);
    } else {
        if (func_00170528(n)) {
            if (n->m4C) func_001711F8(n->m4C, off, flags, 0);
        }
        for (Node_001711F8* c = (Node_001711F8*)n->m20; c; c = c->m28) {
            func_001711F8(c, off, flags, 0);
        }
    }
    if (top) func_00171030(n, off);
}
