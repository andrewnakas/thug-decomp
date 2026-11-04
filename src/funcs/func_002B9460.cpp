typedef int qword __attribute__((mode(TI)));

union Vec_002B9460 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Info_002B9460 {
    char pad0[0x24];
    int m24;
};

struct Piece_002B9460 {
    int m0;
    int m4;
    char pad8[0x14 - 0x8];
    Info_002B9460* m14;
    char pad18[0x20 - 0x18];
    Vec_002B9460 m20;
};

struct Node_002B9460 {
    int m0;
    int m4;
    Node_002B9460* m8;
};

extern char D_00392650[];
extern char D_00392658[];
extern char D_00392660[];
extern char D_0037A108[];
extern char D_0037A118[];
extern char D_0037A128[];
extern char D_0037A138[];
extern char D_00392668[];

extern "C" int func_001F0D78(char* s);
extern "C" Piece_002B9460* func_002B6CF8(Node_002B9460* n);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E7AF8(void* s, int name, float x, float y, float z);
extern "C" void func_001E7A68(void* s, int name, int type, int v);
extern "C" int func_002B6EE0(Piece_002B9460* p);
extern "C" void* func_002CC830();
extern "C" int func_002CC4C8(void* p, Piece_002B9460* q);

struct Obj_002B9460 {
    int m0;
    Node_002B9460* m4;
    void Export(void* arr, int* idx);
};

void Obj_002B9460::Export(void* arr, int* idx)
{
    int c0 = func_001F0D78(D_00392650);
    int c1 = func_001F0D78(D_00392658);
    int c2 = func_001F0D78(D_00392660);
    int c3 = func_001F0D78(D_0037A108);
    int c4 = func_001F0D78(D_0037A118);
    int c5 = func_001F0D78(D_0037A128);
    int c6 = func_001F0D78(D_0037A138);
    int c7 = func_001F0D78(D_00392668);
    for (Node_002B9460* n = m4; n; n = n->m8) {
        Piece_002B9460* p = func_002B6CF8(n);
        if (p->m4 & 0x20) continue;
        if (p->m4 & 0x80) continue;
        void* s = func_001E9378(arr, *idx);
        Vec_002B9460 v;
        v.q = p->m20.q;
        float x = v.f.x;
        float y = v.f.y;
        float z = v.f.z;
        func_001E7AF8(s, 0x7F261953, x, y, z);
        func_001E7AF8(s, c0, 0.0f, 0.0f, 0.0f);
        func_001E7A68(s, c1, 0xD, p->m0);
        func_001E7A68(s, c2, 0xD, c3);
        func_001E7A68(s, 0, 0xD, c4);
        func_001E7A68(s, 0, 0xD, c6);
        func_001E7A68(s, c7, 0xD, ~func_002B6EE0(p));
        if (p->m4 & 0x40) {
            func_001E7A68(s, c5, 0xD, func_002CC4C8(func_002CC830(), p));
        } else if (p->m14->m24) {
            func_001E7A68(s, c5, 0xD, p->m14->m24);
        }
        (*idx)++;
    }
}
