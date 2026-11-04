extern char D_00376320[];
extern char D_00376330[];
extern char D_00376340[];
extern char D_00376350[];
extern char D_003913E0[];

typedef int qword_0026D6C8 __attribute__((mode(TI)));

struct Vec_0026D6C8 {
    union {
        qword_0026D6C8 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Gap_0026D6C8 {
    int m0;
    int m4;
    int m8;
    Gap_0026D6C8* mC;
    char m10[0x10];
    Vec_0026D6C8 m20;
    Vec_0026D6C8 m30;
    char m40[8];
    int m48;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" void func_001F0370(char* name, void* params, int a, int b);
extern "C" int func_0026CB68(Gap_0026D6C8* g);
extern "C" char* func_0026CBB0(Gap_0026D6C8* g);

static inline Gap_0026D6C8* Valid_0026D6C8(Gap_0026D6C8* n)
{
    Gap_0026D6C8* g = 0;
    if (n->m4 != -1)
        g = n;
    return g;
}

struct Level_0026D6C8 {
    char m_pad[0x10];
    Gap_0026D6C8* m10;
    bool AddGapMenuItems(void* params);
};

bool Level_0026D6C8::AddGapMenuItems(void* params)
{
    int i = 0;
    unsigned int id = 0x0F7E902C;
    func_001E8398(params, 0xA7D7C610, &id, 0);
    Gap_0026D6C8* g = Valid_0026D6C8(m10);
    while (g) {
        void* s = func_001E6978(func_001190D0(8));
        Gap_0026D6C8* next = Valid_0026D6C8(g->mC);
        if (i == 0)
            func_001E7360(s, 0, 0x171665D5);
        else if (!next)
            func_001E7360(s, 0, 0x76CF1EBD);
        func_001E7268(s, D_00376320, g->m48);
        func_001E7138(s, D_00376330, func_0026CBB0(g));
        func_001E7268(s, D_003913E0, func_0026CB68(g));
        func_001E7268(s, D_00376340, i);
        Vec_0026D6C8 v;
        v = g->m20;
        func_001E7410(s, 0x26A4E85A, v.f.x, v.f.y, v.f.z);
        v = g->m30;
        func_001E7410(s, 0x1CD674E6, v.f.x, v.f.y, v.f.z);
        func_001E7360(s, 0xA7D7C610, id);
        func_001F0370(D_00376350, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
        g = next;
        i++;
    }
    return i != 0;
}
