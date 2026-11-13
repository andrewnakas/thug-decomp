/* fuzzy: 80.7 */
typedef int qword_001D87F8 __attribute__((mode(TI)));

struct Heap_001D87F8 {
    char m_pad[0xD8];
    int m_D8;
};

extern Heap_001D87F8* D_00388A70;
extern "C" void func_0010A950(Heap_001D87F8* heap, int ctx);
extern "C" void func_0010A9B0(Heap_001D87F8* heap);
extern "C" void* func_0010A638(Heap_001D87F8* heap, int size, int a, int b);
extern "C" void func_0010A8D8(Heap_001D87F8* heap, void* p);

struct Vec_001D87F8 {
    union {
        struct {
            float x, y, z, w;
        } f;
        qword_001D87F8 q;
    } u;
    Vec_001D87F8() {}
    Vec_001D87F8(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Box_001D87F8 {
    Vec_001D87F8 min;
    Vec_001D87F8 max;
};

struct RawVert_001D87F8 {
    float x, y, z;
};

struct Mesh_001D87F8 {
    int m0;
    short m4;
    unsigned short m_numVerts;
    char m8[3];
    unsigned char m_packed;
    char mC[4];
    Box_001D87F8 m_box;
    RawVert_001D87F8* m_verts;
    void* m34;
};

extern "C" void func_001D83A0(Mesh_001D87F8* self, const Vec_001D87F8* offset);
extern "C" void func_001D7D00(void* sub, const Vec_001D87F8* pivot, const Vec_001D87F8* scale, int flag);
extern "C" void func_001D8C20(Mesh_001D87F8* self, Vec_001D87F8* out);
extern "C" void func_001D8D10(Mesh_001D87F8* self, Vec_001D87F8* in);

static inline Vec_001D87F8 operator-(const Vec_001D87F8& v)
{
    return Vec_001D87F8(-v.u.f.x, -v.u.f.y, -v.u.f.z, -v.u.f.w);
}

static inline void Translate_001D87F8(Mesh_001D87F8* self, const Vec_001D87F8& v)
{
    func_001D83A0(self, &v);
}

extern "C" void func_001D87F8(Mesh_001D87F8* self, const Vec_001D87F8* pivot, const Vec_001D87F8* scale)
{
    Translate_001D87F8(self, -*pivot);
    if (self->m34)
        func_001D7D00(self->m34, pivot, scale, 0);
    Vec_001D87F8* tmp = 0;
    if (self->m_packed) {
        func_0010A950(D_00388A70, D_00388A70->m_D8);
        tmp = new Vec_001D87F8[self->m_numVerts];
        func_0010A9B0(D_00388A70);
        func_001D8C20(self, tmp);
    }
    for (int i = 0; i < self->m_numVerts; i++) {
        if (tmp) {
            tmp[i].u.f.x *= scale->u.f.x;
            tmp[i].u.f.y *= scale->u.f.y;
            tmp[i].u.f.z *= scale->u.f.z;
        } else {
            self->m_verts[i].x *= scale->u.f.x;
            self->m_verts[i].y *= scale->u.f.y;
            self->m_verts[i].z *= scale->u.f.z;
        }
    }
    Box_001D87F8 box = self->m_box;
    box.min.u.f.x *= scale->u.f.x;
    box.min.u.f.y *= scale->u.f.y;
    box.min.u.f.z *= scale->u.f.z;
    box.max.u.f.x *= scale->u.f.x;
    box.max.u.f.y *= scale->u.f.y;
    box.max.u.f.z *= scale->u.f.z;
    self->m_box = box;
    if (tmp) {
        func_001D8D10(self, tmp);
        delete[] tmp;
    }
    Translate_001D87F8(self, *pivot);
}
