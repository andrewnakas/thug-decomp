extern char D_00375CD8[];
extern char D_00375CE8[];
extern char D_00375CF8[];
extern char D_00375D08[];
extern char D_00375D18[];
extern char D_00375D28[];
extern char D_00375D38[];
extern char D_00390F00[];

struct Vec_00263DC0 {
    float x, y, z, w;
    Vec_00263DC0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Skate_00263DC0 {
    char m_pad[0x3B0];
    int m3B0;
};
extern Skate_00263DC0* D_0038FC78;

struct Gap_00263DC0 {
    int m0;
};

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E90A8(void* arr, unsigned int index, int value);
extern "C" void func_001E9170(void* arr, unsigned int index, void* value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7200(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* params, unsigned int name, int value);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" void func_001E7720(void* params, unsigned int name, void* arr);
extern "C" void func_001E7788(void* params, char* name, void* arr);
extern "C" void func_001E7360(void* params, unsigned int name, int value);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" int func_001E5400(char* s, int a);
extern "C" void* func_0022E358(Skate_00263DC0* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_0026D528(Gap_00263DC0* g);
extern "C" int func_0026DCB0(Gap_00263DC0* g, int i);
extern "C" int func_0026DCD8(Gap_00263DC0* g, int i);
extern "C" int func_0026DD00(Gap_00263DC0* g, int i);
extern "C" void func_0026DD20(Gap_00263DC0* g, int i, Vec_00263DC0* a, Vec_00263DC0* b);

struct Career_00263DC0 {
    int m0;
    int m4[21][8];
    int m2A4[21][8];
    int m544[16];
    int m584[16];
    char m5C4[0x58];
    int m61C[21];
    void WriteToStructure(void* out);
};

extern "C" Gap_00263DC0* func_002637B0(Career_00263DC0* self, unsigned int level);

void Career_00263DC0::WriteToStructure(void* out)
{
    void* goals = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(goals, 0xA8, 1);
    for (unsigned int i = 0; i < 21; i++)
        for (unsigned int j = 0; j < 8; j++)
            func_001E90A8(goals, i * 8 + j, m4[i][j]);

    void* levels = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(levels, 0xA8, 1);
    for (unsigned int i = 0; i < 21; i++)
        for (unsigned int j = 0; j < 8; j++)
            func_001E90A8(levels, i * 8 + j, m2A4[i][j]);

    void* globals = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(globals, 0x10, 1);
    for (unsigned int i = 0; i < 16; i++)
        func_001E90A8(globals, i, m584[i]);

    void* gaps = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(gaps, 0x15, 0xA);
    for (unsigned int i = 0; i < 21; i++) {
        Gap_00263DC0* g = func_002637B0(this, i);
        void* lvl = func_001E6978(func_001190D0(8));
        func_001E7200(lvl, 0x651533EC, i);
        if (g->m0 == 0) {
            func_001E7200(lvl, 0x73F8CA00, 0);
        } else {
            func_001E7200(lvl, 0x73F8CA00, 1);
            int n = func_0026D528(g);
            void* list = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(list, n, 0xA);
            for (int k = 0; k < n; k++) {
                void* e = func_001E6978(func_001190D0(8));
                func_001E70C0(e, 0x699FCFC0, func_0026DCB0(g, k));
                func_001E7200(e, 0x25EB70DB, func_0026DCD8(g, k));
                func_001E7200(e, 0x92AB03E8, func_0026DD00(g, k));
                Vec_00263DC0 pos;
                Vec_00263DC0 dir;
                if (func_0026DCD8(g, k))
                    func_0026DD20(g, k, &pos, &dir);
                func_001E7410(e, 0xA4605544, pos.x, pos.y, pos.z);
                func_001E7410(e, 0x9E12C9F8, dir.x, dir.y, dir.z);
                func_001E9170(list, k, e);
            }
            func_001E7720(lvl, 0xD76C173E, list);
        }
        func_001E9170(gaps, i, lvl);
    }

    void* visited = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(visited, 0x15, 1);
    for (unsigned int i = 0; i < 21; i++)
        func_001E90A8(visited, i, m61C[i]);

    void* s = func_001E6978(func_001190D0(8));
    func_001E7A68(s, func_001F0D78(D_00375CD8), 0xC, goals);
    func_001E7A68(s, func_001F0D78(D_00375CE8), 0xC, levels);
    func_001E7A68(s, func_001F0D78(D_00375CF8), 0xC, globals);
    func_001E7A68(s, func_001F0D78(D_00375D08), 0xC, gaps);
    func_001E7788(s, D_00375D18, visited);
    Skate_00263DC0* sk = D_0038FC78;
    func_001E7360(s, 0xE3335D2F, sk->m3B0);
    func_001E7360(s, 0x2CC06F5E, func_0024F938(func_0022E358(sk)));
    func_001E7268(s, D_00375D28, func_001E5400(D_00375D38, 0));
    func_001E7A68(out, func_001F0D78(D_00390F00), 0xB, s);
}
