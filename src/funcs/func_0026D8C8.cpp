extern char D_00376320[];
extern char D_00376330[];
extern char D_00376340[];
extern char D_003913E0[];

typedef int qword_0026D8C8 __attribute__((mode(TI)));

struct Vec_0026D8C8 {
    union {
        qword_0026D8C8 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Gap_0026D8C8 {
    int m0;
    int m4;
    int m8;
    Gap_0026D8C8* mC;
    char m10[0x10];
    Vec_0026D8C8 m20;
    Vec_0026D8C8 m30;
    char m40[8];
    int m48;
};

struct Out_0026D8C8 {
    char m_pad[0x18];
    void* m18;
};

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E9170(void* arr, int index, void* value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" void func_001E7720(void* params, unsigned int name, void* arr);
extern "C" int func_0026CB68(Gap_0026D8C8* g);
extern "C" char* func_0026CBB0(Gap_0026D8C8* g);

static inline Gap_0026D8C8* Valid_0026D8C8(Gap_0026D8C8* n)
{
    Gap_0026D8C8* g = 0;
    if (n->m4 != -1)
        g = n;
    return g;
}

struct Level_0026D8C8 {
    char m_pad[0x10];
    Gap_0026D8C8* m10;
    bool WriteGaps(void* unused, Out_0026D8C8* out);
};

bool Level_0026D8C8::WriteGaps(void* unused, Out_0026D8C8* out)
{
    int count = 0;
    void* p = out->m18;
    Gap_0026D8C8* g;
    for (g = Valid_0026D8C8(m10); g; g = Valid_0026D8C8(g->mC))
        count++;
    func_001E7200(p, 0x7F5B3D4D, count);
    if (count == 0) {
        func_001E7200(out->m18, 0x6A8A0061, 0);
        return false;
    }
    int i = 0;
    int got = 0;
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, count, 0xA);
    for (g = Valid_0026D8C8(m10); g; g = Valid_0026D8C8(g->mC)) {
        if (func_0026CB68(g))
            got++;
        void* s = func_001E6978(func_001190D0(8));
        func_001E7268(s, D_00376320, g->m48);
        func_001E7138(s, D_00376330, func_0026CBB0(g));
        func_001E7268(s, D_003913E0, func_0026CB68(g));
        func_001E7268(s, D_00376340, i);
        Vec_0026D8C8 v;
        v = g->m20;
        func_001E7410(s, 0x26A4E85A, v.f.x, v.f.y, v.f.z);
        v = g->m30;
        func_001E7410(s, 0x1CD674E6, v.f.x, v.f.y, v.f.z);
        func_001E9170(arr, i++, s);
    }
    func_001E7720(out->m18, 0x737449DE, arr);
    func_001E7200(out->m18, 0x6A8A0061, got);
    return true;
}
