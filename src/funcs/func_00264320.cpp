extern char D_00390F00[];
extern char D_00375CD8[];
extern char D_00375CE8[];
extern char D_00375CF8[];
extern char D_00375D08[];
extern char D_00375D18[];
extern char D_00390F08[];
extern char D_00390F10[];

typedef int qword_00264320 __attribute__((mode(TI)));

struct Vec_00264320 {
    union {
        qword_00264320 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_00264320() {}
    Vec_00264320(const Vec_00264320& o) { q = o.q; }
};

struct Array_00264320 {
    char m_pad[0xC];
    int mC;
};

struct Gap_00264320 {
    int m0;
};

extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" bool func_001E82B8(void* params, char* name, Array_00264320** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_00264320** out, int required);
extern "C" int func_001E9270(Array_00264320* arr, unsigned int index);
extern "C" void* func_001E9378(Array_00264320* arr, unsigned int index);
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_00264320* out, int required);
extern "C" void func_0026CD98(Gap_00264320* g);
extern "C" void func_0026CE20(Gap_00264320* g, char* name, int a, int b);
extern "C" void func_0026D208(Gap_00264320* g, char* name, Vec_00264320 pos, Vec_00264320 dir);

struct Career_00264320 {
    int m0;
    int m4[21][8];
    int m2A4[21][8];
    int m544[16];
    int m584[16];
    char m5C4[0x58];
    bool m61C[21];
    void ReadFromStructure(void* in);
};

extern "C" Gap_00264320* func_002637B0(Career_00264320* self, unsigned int level);

void Career_00264320::ReadFromStructure(void* in)
{
    void* data = 0;
    func_001E81F0(in, D_00390F00, &data, 0);
    Array_00264320* goals = 0;
    func_001E82B8(data, D_00375CD8, &goals, 0);
    Array_00264320* levels = 0;
    func_001E82B8(data, D_00375CE8, &levels, 0);
    for (unsigned int i = 0; i < 21; i++) {
        for (unsigned int j = 0; j < 8; j++)
            m4[i][j] = func_001E9270(goals, i * 8 + j);
        for (unsigned int j = 0; j < 8; j++)
            m2A4[i][j] = func_001E9270(levels, i * 8 + j);
    }

    Array_00264320* globals = 0;
    func_001E82B8(data, D_00375CF8, &globals, 0);
    for (unsigned int i = 0; i < 16; i++)
        m584[i] = func_001E9270(globals, i);

    Array_00264320* gaps = 0;
    func_001E82B8(data, D_00375D08, &gaps, 0);
    if (gaps) {
        for (unsigned int i = 0; i < 21; i++) {
            Gap_00264320* g = func_002637B0(this, i);
            func_0026CD98(g);
            void* lvl = func_001E9378(gaps, i);
            int index = 0;
            int unlocked = 0;
            func_001E88F8(lvl, D_00390F08, &index, 1);
            func_001E88F8(lvl, D_00390F10, &unlocked, 1);
            if (unlocked) {
                Array_00264320* list = 0;
                func_001E8248(lvl, 0xD76C173E, &list, 0);
                int n = list->mC;
                for (int k = 0; k < n; k++) {
                    void* e = func_001E9378(list, k);
                    char* name = 0;
                    int got = 0;
                    int score = 0;
                    func_001E7C80(e, 0x699FCFC0, &name, 0);
                    func_001E7DE8(e, 0x25EB70DB, &got, 0);
                    func_001E7DE8(e, 0x92AB03E8, &score, 0);
                    func_0026CE20(g, name, got, score);
                    if (got) {
                        Vec_00264320 pos;
                        Vec_00264320 dir;
                        func_001E7FA8(e, 0xA4605544, &pos, 0);
                        func_001E7FA8(e, 0x9E12C9F8, &dir, 0);
                        func_0026D208(g, name, pos, dir);
                    }
                }
            }
        }
    }

    Array_00264320* visited = 0;
    func_001E82B8(data, D_00375D18, &visited, 0);
    if (visited) {
        for (int i = 0; i < 21; i++)
            m61C[i] = func_001E9270(visited, i) != 0;
    }
}
