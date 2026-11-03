extern char D_00371920[];
extern char D_00371950[];
extern char D_00371968[];
extern char D_00371980[];

struct Trick_00222170 {
    int m0;
    unsigned int m4;
    unsigned int m8;
    int mC;
};

struct Script_00222170 {
    char m_pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_0022E368(void* self, int index);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" unsigned int func_00221FA0(void* params, unsigned int name, int depth);
extern "C" int func_00261F80(void* self);
extern "C" Trick_00222170 func_00261FB0(void* self, int index);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" unsigned int func_002220B8(void* self, int index);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00222170(void* params, Script_00222170* script)
{
    unsigned int trick = 0;
    int cat;
    if (!func_001E8398(params, 0x270F56E1, &trick, 0)) {
        func_001E7DE8(params, 0xA75B8581, &cat, 1);
    }
    unsigned int combo = 0;
    int special = 0;
    void* profile = func_0022E368(D_0038FC78, 0);
    int index = 0;
    if (trick) {
        if (!func_001E8708(params, 0xB394C01C)) {
            void* mappings = func_00262330(profile, 0xD544AA2D);
            unsigned int key = func_00221FA0(mappings, trick, 0);
            unsigned int value = 0;
            if (func_001E8398(mappings, key, &value, 0) && value == trick) {
                combo = key;
            }
        } else if (func_001E8708(params, 0xB394C01C)) {
            int n = func_00261F80(profile);
            for (int i = 0; i < n; i++) {
                Trick_00222170 t = func_00261FB0(profile, i);
                if (t.m4 == trick) {
                    index = i;
                    func_00103F28(D_00371920);
                    special = 1;
                    combo = t.m8;
                    break;
                }
            }
        }
    } else {
        combo = func_002220B8(func_00262330(profile, 0xD544AA2D), cat);
    }
    if (combo) {
        func_001E73C8(script->m_params, D_00371950, combo);
        if (special) {
            func_00103F28(D_00371968, index);
            func_001E7268(script->m_params, D_00371980, index);
        }
        return true;
    }
    return false;
}
