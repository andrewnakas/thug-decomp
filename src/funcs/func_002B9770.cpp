struct Vec_002B9770 {
    float x, y, z;
};

struct Node_002B9770 {
    char pad[0x10];
    Vec_002B9770 m10;
    char pad1C[4];
    int m20;
    int m24;
    Node_002B9770* m28;
};

struct Seg_002B9770 {
    char m0;
    unsigned char m1;
    char pad2[6];
    Node_002B9770* m8;
    char padC[0x14 - 0xC];
    Seg_002B9770* m14;
};

struct List_002B9770 {
    int m0;
    Seg_002B9770* m4;
};

extern char D_00392650[];
extern char D_00392658[];
extern char D_00392660[];
extern char D_0037A148[];
extern char D_0037A118[];
extern char D_00392670[];
extern char D_0037A158[];
extern char D_0037A138[];
extern char D_00392668[];
extern "C" int func_001F0D78(const char* s);
extern "C" int func_002B65F0(List_002B9770* l);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E7AF8(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int v);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E7B38(void* s, unsigned int name, void* arr);
extern "C" void func_001E8DE8(void* p, int v);

static inline void AddVec_002B9770(void* s, unsigned int name, const Vec_002B9770& v)
{
    func_001E7AF8(s, name, v.x, v.y, v.z);
}

struct Obj_002B9770 {
    char pad0[0x64];
    List_002B9770 m64;
    void Export(void* arr, int* idx);
};

void Obj_002B9770::Export(void* arr, int* idx)
{
    int c0 = func_001F0D78(D_00392650);
    List_002B9770* l = &m64;
    int c1 = func_001F0D78(D_00392658);
    int c2 = func_001F0D78(D_00392660);
    int c3 = func_001F0D78(D_0037A148);
    int c4 = func_001F0D78(D_0037A118);
    int c5 = func_001F0D78(D_00392670);
    int c6 = func_001F0D78(D_0037A158);
    int c7 = func_001F0D78(D_0037A138);
    int c8 = func_001F0D78(D_00392668);
    int n = func_002B65F0(l);
    if (!n) return;
    int id = 0x1E8481;
    Seg_002B9770* seg = l->m4;
    int start = *idx;
    int end = start + n;
    Node_002B9770* node = seg->m8;
    while (*idx < end) {
        void* s = func_001E9378(arr, *idx);
        AddVec_002B9770(s, 0x7F261953, node->m10);
        func_001E7AF8(s, c0, 0.0f, 0.0f, 0.0f);
        func_001E7A68(s, c1, 13, id++);
        func_001E7A68(s, c2, 13, c3);
        func_001E7A68(s, 0, 13, c4);
        func_001E7A68(s, c6, 13, node->m20);
        if (node->m24) {
            func_001E7A68(s, 0, 13, c7);
            func_001E7A68(s, c8, 13, ~node->m24);
        }
        if (node->m28 || seg->m1) {
            int next = *idx + 1;
            if (!node->m28 && seg->m1) next = start;
            void* a = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(a, 1, 1);
            func_001E90A8(a, 0, next);
            func_001E7B38(s, c5, a);
            if (a) func_001E8DE8(a, 3);
        }
        node = node->m28;
        if (!node) {
            seg = seg->m14;
            if (seg) {
                node = seg->m8;
                start = *idx + 1;
            }
        }
        (*idx)++;
    }
}
