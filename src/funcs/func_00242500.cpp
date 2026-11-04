struct Combo_00242500 {
    int m0;
    unsigned int m_trick;
    unsigned int m_key;
    int m_flag;
};

struct Script_00242500 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" bool func_001E8398(void* self, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_0022E368(void* self, int index);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" bool func_001E8708(void* self, unsigned int name);
extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void* func_001E5548(unsigned int name, int assert_);
extern "C" bool func_001E8180(void* self, unsigned int name, void** out, int assert_);
extern "C" bool func_001E7D70(void* self, unsigned int name, const char** out, int assert_);
extern "C" bool func_001E7C80(void* self, unsigned int name, const char** out, int assert_);
extern "C" void func_001E70C0(void* self, unsigned int name, const char* value);
extern "C" void func_001E7360(void* self, unsigned int name, unsigned int value);
extern "C" bool func_001E8248(void* self, unsigned int name, void** out, int assert_);
extern "C" unsigned int func_001E9300(void* self, int index);
extern "C" void* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(void* self, int index);
extern "C" int func_00261F80(void* self);
extern "C" void func_00261FB0(Combo_00242500* out, void* self, int index);

bool func_00242500(void* params, Script_00242500* script)
{
    Combo_00242500 c;
    unsigned int key;
    int value;
    unsigned int trick;
    void* desc;
    const char* name;
    unsigned int cat;
    void* cats;
    void* desc2;
    const char* name2;
    void* desc3;
    const char* name3;

    func_001E8398(params, 0xACFDB27A, &key, 1);
    void* mgr = func_0022E368(D_0038FC78, 0);
    void* slots = func_00262330(mgr, 0xD544AA2D);
    if (!func_001E8708(params, 0xB394C01C)) {
        if (func_001E7DE8(slots, key, &value, 0)) {
            func_001E7200(script->m_params, 0xA75B8581, value);
            return true;
        }
        if (!func_001E8398(slots, key, &trick, 0))
            return false;
        if (trick == 0xF60C9090)
            return false;
        func_001E8180(func_001E5548(trick, 1), 0x7031F10C, &desc, 1);
        func_001E7D70(desc, 0xA1DC81F9, &name, 1);
        func_001E70C0(script->m_params, 0x3A54CC4B, name);
        func_001E7360(script->m_params, 0x4443A4DA, trick);
        cat = 0;
        if (!func_001E8398(desc, 0x6E855102, &cat, 0)) {
            if (func_001E8248(desc, 0x6E855102, &cats, 0))
                cat = func_001E9300(cats, 0);
        }
        if (cat) {
            func_001E8180(func_001E9378(func_001E55B8(cat, 1), 0), 0x7031F10C, &desc2, 1);
            func_001E7C80(desc2, 0xA1DC81F9, &name2, 1);
            func_001E70C0(script->m_params, 0x3DAAF58B, name2);
            func_001E7360(script->m_params, 0xD0BCFC62, cat);
        }
        return true;
    }
    if (func_001E8708(params, 0xB394C01C)) {
        int n = func_00261F80(mgr);
        for (int i = 0; i < n; i++) {
            func_00261FB0(&c, mgr, i);
            if (c.m_key == key) {
                if (c.m_trick == 0xF60C9090)
                    return false;
                void* t = func_001E5548(c.m_trick, 0);
                if (t) {
                    func_001E8180(t, 0x7031F10C, &desc3, 1);
                    func_001E7D70(desc3, 0xA1DC81F9, &name3, 1);
                    func_001E70C0(script->m_params, 0x3A54CC4B, name3);
                }
                if (c.m_flag)
                    func_001E7200(script->m_params, 0x4443A4DA, c.m_trick);
                else
                    func_001E7360(script->m_params, 0x4443A4DA, c.m_trick);
                func_001E7200(script->m_params, 0xDB92EFFA, i);
                return true;
            }
        }
    }
    return false;
}
