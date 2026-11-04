extern char D_003718E0[];
extern char D_0038F8E0[];
extern char D_003718F0[];
extern char D_0038F8E8[];
extern char D_0038F8F0[];

struct Combo_00221DE8 {
    int m0;
    unsigned int m_trick;
    unsigned int m_combo;
    int m_cat;
};

extern void* D_0038FC78;

extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void* func_0022E368(void* self, int index);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" Combo_00221DE8* func_00264728(Combo_00221DE8* self);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_002620D8(void* self, int index, Combo_00221DE8* combo, int update);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

bool func_00221DE8(void* params)
{
    unsigned int combo;
    func_001E84E8(params, D_003718E0, &combo, 1);
    unsigned int trick = 0;
    func_001E84E8(params, D_0038F8E0, &trick, 0);
    int cat = 0;
    bool is_cat = func_001E7E58(params, D_0038F8E0, &cat, 0) != 0;
    int do_update = 1;
    int update = 1;
    func_001E7E58(params, D_003718F0, &update, 0);
    if (!update) {
        do_update = 0;
    }
    void* tricks = func_0022E368(D_0038FC78, 0);
    if (func_001E87B8(params, D_0038F8E8)) {
        int index;
        if (!func_001E7E58(params, D_0038F8F0, &index, 0)) {
            return false;
        }
        Combo_00221DE8 c;
        func_00264728(&c);
        c.m_combo = combo;
        if (is_cat) {
            c.m_trick = cat;
        } else {
            c.m_trick = trick;
        }
        if (func_001E8708(params, 0x61A1BC57)) {
            c.m_cat = 1;
        } else {
            c.m_cat = 0;
        }
        func_002620D8(tricks, index, &c, do_update);
        return true;
    }
    void* mappings = func_00262330(tricks, 0xD544AA2D);
    if (is_cat) {
        func_001E6B90(mappings, combo);
        func_001E7200(mappings, combo, cat);
    } else {
        func_001E6B90(mappings, combo);
        func_001E7360(mappings, combo, trick);
    }
    return true;
}
