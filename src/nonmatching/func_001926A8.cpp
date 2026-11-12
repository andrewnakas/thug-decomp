/* cflags: -fno-gcse -fno-rerun-loop-opt */
/* fuzzy: 70.9 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);
extern void* D_00388A70;

struct Vert_001926A8 {
    float x;
    float y;
    float z;
    float w;
    int m10[4];
    unsigned char m_flag;
    char m21[15];
    Vert_001926A8() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Ring_001926A8 {
    char m0[0x50];
    Vert_001926A8* m_verts;
    unsigned short m_count;
    void Build(int n, float rx, float rz, float h);
};

void Ring_001926A8::Build(int n, float rx, float rz, float h)
{
    m_count = n * 2;
    if (m_verts) {
        delete[] m_verts;
    }
    m_verts = new Vert_001926A8[m_count];
    int idx = 0;
    int side = 0;
    do {
        for (int i = n - 1; i != -1; i--) {
            m_verts[idx].x = (side ? rx : rz) * func_00340F60(2.0f * i * 3.1415f / n);
            m_verts[idx].y = side ? h : -h;
            m_verts[idx].z = (side ? rx : rz) * func_00341068(2.0f * i * 3.1415f / n);
            m_verts[idx].w = 1.0f;
            m_verts[idx].m_flag = 0;
            idx++;
        }
        side ^= 1;
    } while (side);
}
