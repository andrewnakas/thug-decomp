struct Array_0021CC08 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" Array_0021CC08* func_001E55F8(const char* name, int a);
extern "C" void* func_001E9378(Array_0021CC08* arr, unsigned int i);
extern "C" void* func_0022E050(void* game);
extern "C" void* func_002629B8(void* list, unsigned int name);
extern "C" void func_002612A0(void* profile, void* skater);
extern "C" void func_00261118(void* profile, void* skater);

extern void* D_0038FC78;
extern char D_00371688[];

bool Cmd_0021CC08(void* params, void* script)
{
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    Array_0021CC08* skaters = func_001E55F8(D_00371688, 1);
    for (unsigned int i = 0; i < skaters->m_size; i++) {
        void* skater = func_001E9378(skaters, i);
        unsigned int sname;
        func_001E8398(skater, 0xA1DC81F9, &sname, 1);
        if (name == sname) {
            void* profile = func_002629B8(func_0022E050(D_0038FC78), sname);
            unsigned int dummy;
            if (func_001E8398(params, 0x55F82F0B, &dummy, 0)) {
                func_002612A0(profile, skater);
            } else {
                func_00261118(profile, skater);
            }
        }
    }
    return true;
}
