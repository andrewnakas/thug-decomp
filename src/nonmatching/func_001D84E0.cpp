/* fuzzy: 97.0 */
/* blocked: last block: game stores z,x,y,w in source order and copies m_box.mn from v on the stack. m_box.mn = v fixes the copy but swaps pv/v (s7/fp); dropping pv rebuilds the frame (190 words). */
typedef int qword __attribute__((mode(TI)));

struct Heap_001D84E0 {
    char pad0[0xD8];
    int mD8;
};

extern Heap_001D84E0* D_00388A70;
extern "C" void func_0010A950(Heap_001D84E0* heap, int ctx);
extern "C" void func_0010A9B0(Heap_001D84E0* heap);
extern "C" void* func_0010A638(Heap_001D84E0* heap, int size, int a, int b);

struct Vec_001D84E0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001D84E0() {}
    Vec_001D84E0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Box_001D84E0 {
    Vec_001D84E0 mn;
    Vec_001D84E0 mx;
};

struct Packed_001D84E0 {
    unsigned short x, y, z;
};

extern "C" void func_0010A8D8(Heap_001D84E0* heap, void* p);
extern "C" Vec_001D84E0* func_00101630(Vec_001D84E0* v, void* mat);
extern "C" void func_00102358(Box_001D84E0* b, const Vec_001D84E0* p);
extern "C" void func_001D7B18(void* sub, Vec_001D84E0* pos, void* mat, int flags);

struct Mesh_001D84E0 {
    char pad0[0x6];
    unsigned short m_count;
    char pad8[0x3];
    unsigned char m_packed;
    char padC[0x4];
    Box_001D84E0 m_box;
    void* m_verts;
    void* m_sub;
    void Transform(Vec_001D84E0* pos, void* mat);
};

extern "C" void func_001D83A0(Mesh_001D84E0* m, Vec_001D84E0* offset);
extern "C" void func_001D8C20(Mesh_001D84E0* m, Vec_001D84E0* verts);
extern "C" void func_001D8D10(Mesh_001D84E0* m, Vec_001D84E0* verts);

void Mesh_001D84E0::Transform(Vec_001D84E0* pos, void* mat)
{
    Vec_001D84E0 a;
    Vec_001D84E0 b;
    Vec_001D84E0 v;
    v.x = -pos->x;
    v.y = -pos->y;
    v.z = -pos->z;
    v.w = -pos->w;
    func_001D83A0(this, &v);
    if (m_sub) {
        func_001D7B18(m_sub, pos, mat, 0);
    }
    Box_001D84E0* box = &m_box;
    Vec_001D84E0* tmp = 0;
    if (m_packed) {
        func_0010A950(D_00388A70, D_00388A70->mD8);
        tmp = new Vec_001D84E0[m_count];
        func_0010A9B0(D_00388A70);
        func_001D8C20(this, tmp);
    }
    Vec_001D84E0* pv = &v;
    for (int i = 0; i < m_count; i++) {
        if (tmp) {
            func_00101630(&tmp[i], mat);
        } else {
            if (m_packed) {
                v = m_box.mn;
                v.x += ((Packed_001D84E0*)m_verts)[i].x * 0.0625f;
                v.y += ((Packed_001D84E0*)m_verts)[i].y * 0.0625f;
                v.z += ((Packed_001D84E0*)m_verts)[i].z * 0.0625f;
                v.w = 0.0f;
            } else {
                v.x = ((float*)m_verts)[i * 3 + 0];
                v.y = ((float*)m_verts)[i * 3 + 1];
                v.z = ((float*)m_verts)[i * 3 + 2];
                v.w = 0.0f;
            }
            func_00101630(pv, mat);
            ((float*)m_verts)[i * 3 + 0] = v.x;
            ((float*)m_verts)[i * 3 + 1] = v.y;
            ((float*)m_verts)[i * 3 + 2] = v.z;
        }
    }
    a = m_box.mn;
    b = m_box.mx;
    func_00101630(&a, mat);
    func_00101630(&b, mat);
    pv->y = v.x = pv->z = 10000000.0f;
    pv->w = 1.0f;
    m_box.mn = *pv;
    v.x = pv->z = pv->y = -10000000.0f;
    m_box.mx = v;
    func_00102358(box, &a);
    func_00102358(box, &b);
    if (tmp) {
        func_001D8D10(this, tmp);
        func_0010A8D8(D_00388A70, tmp);
    }
    func_001D83A0(this, pos);
}
