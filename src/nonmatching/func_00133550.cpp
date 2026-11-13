/* fuzzy: 87.8 */
/* sym: __13Inst_00133550 = 0x001D5608 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;
extern char D_0035D4F8[];
extern char D_00389CD8[];
extern char D_00389CE0[];

struct Vec_00133550 {
    float x, y, z, w;
};

struct Mesh_00133550 {
    char pad0[8];
    unsigned short m8;
    int GetCount() { return m8; }
    char padA[6];
    Vec_00133550 m10;
    Vec_00133550 m20;
    char pad30[0x10];
};

struct Base_00133550 {
    int m0;
    int m4;
    int m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Bind(Mesh_00133550* m);
};

struct Inst_00133550 : Base_00133550 {
    int m10;
    Inst_00133550();
    ~Inst_00133550();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Header_00133550 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" char* func_0010DAB0(const char* name);
extern "C" void func_001D76B0(Mesh_00133550* m, void* a, char* b, char* c, char* d, char* e, char* f);
extern "C" void func_001D7EE8(Mesh_00133550* m);
extern "C" void func_00102358(void* box, Vec_00133550* v);

extern "C" int func_00133550(void* p0, char* name, char* buf, int* outCount, Inst_00133550** outInst,
                             Mesh_00133550** outMesh, void* box, int flag)
{
    func_003331D0(buf, D_0035D4F8, name, name, flag ? D_00389CD8 : D_00389CE0, func_00132580());
    int any = 0;
    char* data = func_0010DAB0(buf);
    if (data) {
        Header_00133550* h = (Header_00133550*)data;
        *outCount = h->m4;
        char* base = (char*)(h + 1);
        *outMesh = (Mesh_00133550*)base;
        char* p1 = base + (*outCount << 6);
        p1 = (char*)((unsigned int)(p1 + 15) & 0xFFFFFFF0);
        char* p2 = p1 + (h->m14 * 12 + h->m18 * 6);
        char* p3 = p2 + h->m8;
        p3 = (char*)((unsigned int)(p3 + 3) & 0xFFFFFFFC);
        char* p4 = p3 + (h->mC * 10 + h->m10 * 8);
        if (h->mC & 1)
            p4 += 2;
        char* p5 = p4 + 4;
        char* p6 = p5 + *(int*)p4;
        *outInst = new Inst_00133550[h->m4];
        for (int i = 0; i < h->m4; i++) {
            func_001D76B0(&(*outMesh)[i], p0, p1, p2, p3, p5, p6);
            func_001D7EE8(&(*outMesh)[i]);
            (*outInst)[i].Bind(&(*outMesh)[i]);
            if ((*outMesh)[i].GetCount() > 0) {
                func_00102358(box, &(*outMesh)[i].m10);
                any = 1;
                func_00102358(box, &(*outMesh)[i].m20);
            }
        }
        if (!any) {
            Vec_00133550 v;
            v.x = -100.0f;
            v.y = -100.0f;
            v.z = -100.0f;
            v.w = 1.0f;
            func_00102358(box, &v);
            v.x = 100.0f;
            v.y = 100.0f;
            v.z = 100.0f;
            v.w = 1.0f;
            func_00102358(box, &v);
        }
        return 1;
    }
    return 0;
}
