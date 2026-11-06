struct Heap_00171030 {
    char pad[0xD8];
    int m_D8;
};

struct Vec_00171030 {
    float x, y, z;
};

struct IVtx_00171030 {
    int x, y, z, w;
};

extern Heap_00171030* D_00388A70;
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" int func_00161860(void* mesh);
extern "C" int func_00161C98(void* mesh);
extern "C" void func_00161D50(void* mesh, IVtx_00171030* out);
extern "C" void func_00161E70(void* mesh, IVtx_00171030* in, int a);

class Node_00171030 {
public:
    Vec_00171030 m_pos;
    char pad0C[0x20 - 0xC];
    void* m_20;
    int m_24;
    Node_00171030* m_28;
    char pad2C[0x4C - 0x2C];
    Node_00171030* m_4C;
    void Move(const Vec_00171030* d);
};

extern "C" int func_00170518(Node_00171030* n);
extern "C" int func_00170528(Node_00171030* n);

void Node_00171030::Move(const Vec_00171030* d)
{
    m_pos.x += d->x;
    m_pos.y += d->y;
    m_pos.z += d->z;
    if (func_00170518(this)) {
        if (func_00161C98(m_20) != 0x20) return;
        int dx = (int)(d->x * 16.0f);
        int dy = (int)(d->y * 16.0f);
        int dz = (int)(d->z * 16.0f);
        int n = func_00161860(m_20);
        func_0010A950(D_00388A70, D_00388A70->m_D8);
        IVtx_00171030* buf = (IVtx_00171030*)func_0010A638(D_00388A70, n * 16, 1, 0);
        func_00161D50(m_20, buf);
        int i;
        for (i = 0; i < n; i++) {
            buf[i].x += dx;
            buf[i].y += dy;
            buf[i].z += dz;
        }
        func_00161E70(m_20, buf, 0);
        if (buf) func_0010A8D8(D_00388A70, buf);
        func_0010A9B0(D_00388A70);
    } else {
        if (func_00170528(this) && m_4C) m_4C->Move(d);
        Node_00171030* c;
        for (c = (Node_00171030*)m_20; c; c = c->m_28) c->Move(d);
    }
}
