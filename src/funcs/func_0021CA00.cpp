struct Array_0021CA00 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" Array_0021CA00* func_001E55F8(const char* name, int a);
extern "C" void* func_001E9378(Array_0021CA00* arr, unsigned int i);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* s, unsigned int name, int value);
extern "C" bool func_001E7E58(void* s, const char* name, int* out, int required);
extern "C" void func_001E7268(void* s, const char* name, int value);
extern "C" void* func_0022E050(void* game);
extern "C" unsigned int func_00262828(void* list);
extern "C" char* func_00262860(void* list, unsigned int i);
extern "C" void func_001E6AC8(void* s, void* other);
extern "C" void func_001E6AE8(void* p, int flags);

extern void* D_0038FC78;
extern char D_00371688[];
extern char D_003716A0[];
extern char D_003716B0[];

bool Cmd_0021CA00(void* params, void* script)
{
    Array_0021CA00* skaters = func_001E55F8(D_00371688, 1);
    for (unsigned int i = 0; i < skaters->m_size; i++) {
        void* stats = func_001E6978(func_001190D0(8));
        void* skater = func_001E9378(skaters, i);
        unsigned int name;
        func_001E8398(skater, 0xA1DC81F9, &name, 1);
        Array_0021CA00* names = func_001E55F8(D_003716A0, 0);
        for (unsigned int j = 0; j < names->m_size; j++) {
            unsigned int stat;
            int value;
            func_001E8398(func_001E9378(names, j), 0xA1DC81F9, &stat, 1);
            func_001E7DE8(skater, stat, &value, 1);
            func_001E7200(stats, stat, value);
        }
        int points;
        func_001E7E58(skater, D_003716B0, &points, 1);
        func_001E7268(stats, D_003716B0, points);
        void* list = func_0022E050(D_0038FC78);
        unsigned int count = func_00262828(list);
        for (unsigned int k = 0; k < count; k++) {
            void* profile = func_00262860(list, k) + 0x5C;
            unsigned int pname;
            func_001E8398(profile, 0xA1DC81F9, &pname, 1);
            if (pname == name) {
                func_001E6AC8(profile, stats);
                break;
            }
        }
        if (stats) {
            func_001E6AE8(stats, 3);
        }
    }
    return true;
}
