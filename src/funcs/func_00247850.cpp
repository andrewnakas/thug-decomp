extern char D_003739A8[];

struct Array_00247850 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Trick_00247850 {
    int m0;
    unsigned int m_script;
    unsigned int m_name;
    int mC;
};

struct CatTrick_00247850 {
    void* m_params;
};

struct Skater_00247850 {
    char m_pad[0x248];
    CatTrick_00247850* m_catTricks[1];
};

extern void* D_0038FC78;

extern "C" void* func_001E5548(unsigned int name, int assert_);
extern "C" void* func_0022E368(void* self, int index);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" unsigned int func_001E9300(Array_00247850* self, int index);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" int func_00261F80(void* self);
extern "C" Trick_00247850 func_00261FB0(void* self, int index);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int assert_);
extern "C" Skater_00247850* func_0022DD38(void* self);
extern "C" Array_00247850* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(Array_00247850* self, int index);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int assert_);
extern "C" bool func_001E7D70(void* params, unsigned int name, const char** out, int assert_);
extern "C" const char* func_001E4DE0(const char* s);
extern "C" void func_001E9058(Array_00247850* self, int index, const char* value);

bool func_00247850(Array_00247850* list, Array_00247850* names, Array_00247850* keys, int type)
{
    void* trick_names = func_001E5548(0x8856C817, 1);
    void* mgr = D_0038FC78;
    void* profile = func_0022E368(mgr, 0);
    void* mappings = func_00262330(profile, 0xD544AA2D);
    int n = list->m_size;
    for (int i = 0; i < n; i++) {
        int found = 0;
        unsigned int trick = func_001E9300(list, i);
        unsigned int script = 0;
        int is_cat = 0;
        int cat_index = 0;
        if (func_001E7DE8(mappings, trick, &cat_index, 0)) {
            func_00103F28(D_003739A8, cat_index);
            is_cat = 1;
            found = 1;
        } else if (func_001E8398(mappings, trick, &script, 0)) {
            found = 1;
        } else {
            int num = func_00261F80(profile);
            for (int j = 0; j < num; j++) {
                Trick_00247850 t = func_00261FB0(profile, j);
                if (t.m_name == trick) {
                    found = 1;
                    script = t.m_script;
                    break;
                }
            }
        }
        if (!found) {
            return false;
        }
        const char* name;
        func_001E7C80(trick_names, trick, &name, 1);
        const char* key;
        if (is_cat) {
            Skater_00247850* skater = func_0022DD38(mgr);
            if (skater) {
                func_001E7C80(skater->m_catTricks[cat_index]->m_params, 0xA1DC81F9, &key, 1);
            }
        } else if (type >= 0) {
            func_001E7C80(func_001E9378(func_001E55B8(0xFFD7913F, 1), type), 0xA1DC81F9, &key, 1);
        } else {
            void* params;
            func_001E8180(func_001E5548(script, 1), 0x7031F10C, &params, 1);
            func_001E7D70(params, 0xA1DC81F9, &key, 1);
        }
        func_001E9058(names, i, func_001E4DE0(name));
        func_001E9058(keys, i, func_001E4DE0(key));
    }
    return true;
}
