struct Heap_002612A0 {
    char m_pad[0x3EC];
    int m3EC;
};
extern Heap_002612A0* D_00388A70;

extern char D_00375B40[];
extern char D_00375B50[];
extern char D_00375B60[];
extern char D_00375B70[];
extern char D_00375B80[];
extern char D_00390DF8[];
extern char D_00390E00[];
extern char D_00375B90[];
extern char D_00375BA0[];
extern char D_00375BB0[];
extern char D_00390E08[];
extern char D_00390E10[];
extern char D_00390E18[];
extern char D_00375BC0[];
extern char D_00375BD0[];
extern char D_00375BE0[];

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void func_00120120(void* p);
extern "C" void func_0011FA48(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" void func_0011FB18(void* p, int v, int a);
extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" void func_001E73C8(void* params, char* name, unsigned int value);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void func_001E7860(void* params, char* name, void* value);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" void func_001200E8(void* p);
extern "C" void func_001E6B30(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);

struct Profile_002612A0 {
    int m0;
    char m4[0x58];
    char m5C[4];
    bool Load(void* params);
};

extern "C" int func_002623B8(Profile_002612A0* self);

bool Profile_002612A0::Load(void* params)
{
    void* info = m4;
    void* store = m5C;
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    func_00120120(info);
    func_0011FA48(info);
    func_001E7A68(store, 0xD544AA2D, 0xB, func_001E6978(func_001190D0(8)));
    func_001E7A68(store, 0xDDBEE809, 0xB, func_001E6978(func_001190D0(8)));
    func_0010A9B0(D_00388A70);
    if (params) {
        int a;
        char* str;
        int i;
        unsigned int c;
        void* s;
        unsigned int x;
        void* y;
        func_001E8A30(params, 0x1D6F290C, &a, 1);
        func_0011FB18(info, a, 1);
        func_001E7C80(params, 0x2AB66CB8, &str, 1);
        func_001E7138(store, D_00375B40, str);
        func_001E7C80(params, 0x562E3ECD, &str, 1);
        func_001E7138(store, D_00375B50, str);
        func_001E7C80(params, 0x2820E997, &str, 1);
        func_001E7138(store, D_00375B60, str);
        func_001E7C80(params, 0x6C375B95, &str, 1);
        func_001E7138(store, D_00375B70, str);
        func_001E7DE8(params, 0x6F14C39C, &i, 1);
        func_001E7268(store, D_00375B80, i);
        func_001E7DE8(params, 0xD82F8AC8, &i, 1);
        func_001E7268(store, D_00390DF8, i);
        func_001E7DE8(params, 0x3F813177, &i, 1);
        func_001E7268(store, D_00390E00, i);
        func_001E7DE8(params, 0x09F350E5, &i, 1);
        func_001E7268(store, D_00375B90, i);
        func_001E7DE8(params, 0x4564BAB1, &i, 1);
        func_001E7268(store, D_00375BA0, i);
        func_001E7DE8(params, 0x27EB9B9D, &i, 0);
        func_001E7268(store, D_00375BB0, i);
        func_001E7DE8(params, 0x5ECFEF4D, &i, 1);
        func_001E7268(store, D_00390E08, i);
        func_001E8398(params, 0xA1DC81F9, &c, 1);
        func_001E73C8(store, D_00390E10, c);
        func_001E8398(params, 0x7D02BCC3, &c, 1);
        func_001E73C8(store, D_00390E18, c);
        func_001E8398(params, 0xC15DBF86, &c, 1);
        func_001E73C8(store, D_00375BC0, c);
        func_001E8398(params, 0xDFD4043E, &c, 1);
        func_001E73C8(store, D_00375BD0, c);
        func_001E8180(params, 0xDDBEE809, &s, 1);
        func_001E7860(store, D_00375BE0, s);
        if (!func_002623B8(this)) {
            func_0010A950(D_00388A70, D_00388A70->m3EC);
            func_001200E8(info);
            func_0010A9B0(D_00388A70);
        }
        func_001E8398(params, 0xE365363E, &x, 1);
        void* src = func_001E5548(x, 1);
        func_001E8180(store, 0xD544AA2D, &y, 1);
        func_001E6B30(y);
        func_001E6AC8(y, src);
    }
    return true;
}
