/* fuzzy: 98.0 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);
extern void* D_00388A70;

struct Vec_001926A8 {
    float x, y, z, w;
    float& operator[](int i) { return (&x)[i]; }
};

struct Vert_001926A8 {
    Vec_001926A8 pos;
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
    Vert_001926A8& Vert(int i) { return m_verts[i]; }
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
        int i = n;
        while (--i != -1) {
            float fi = i;
            Vert(idx).pos[0] = (side ? rx : rz) * func_00340F60(2.0f * fi * 3.1415f / n);
            Vert(idx).pos[1] = side ? h : -h;
            Vert(idx).pos[2] = (side ? rx : rz) * func_00341068(2.0f * fi * 3.1415f / n);
            Vert(idx).pos[3] = 1.0f;
            Vert(idx).m_flag = 0;
            idx++;
        }
        side ^= 1;
    } while (side);
}
