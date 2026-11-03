struct Combo_00246F50 {
    int m0;
    unsigned int m_trick;
    int m_combo;
};

struct Item_00246F50 {
    int m0;
    int m4;
    int m8;
};

struct Goal_00246F50 {
    char pad[0x20];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_003738B8[];
extern char D_003738C8[];
extern char D_003738D8[];
extern char D_003738E8[];
extern char D_0038FFE8[];
extern char D_0038FFF0[];

extern "C" bool func_001E8708(void* self, unsigned int name);
extern "C" bool func_001E84E8(void* self, const char* name, unsigned int* out, int assert_);
extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(void* self, unsigned int index);
extern "C" bool func_001E7C80(void* self, unsigned int name, const char** out, int assert_);
extern "C" void func_001E70C0(void* self, unsigned int name, const char* value);
extern "C" void* func_001E5548(unsigned int name, int assert_);
extern "C" bool func_001E81F0(void* self, const char* name, void** out, int assert_);
extern "C" bool func_001E7D90(void* self, const char* name, const char** out, int assert_);
extern "C" void func_001E7138(void* self, const char* name, const char* value);
extern "C" void* func_0022E050(void* self);
extern "C" void* func_00262990(void* self);
extern "C" int func_00261F80(void* self);
extern "C" void func_00261FB0(Combo_00246F50* out, void* self, int index);
extern "C" void func_001E6D18(void* self, int v);
extern "C" Item_00246F50* func_001E6E90(void* self, int index);
extern "C" void func_00261F10(void* self, int v);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_001E6978(void* self);
extern "C" void func_001E7360(void* self, unsigned int name, int value);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void func_001F0210(unsigned int name, void* params, void* a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" Combo_00246F50* func_00264728(Combo_00246F50* self);
extern "C" void func_002620D8(void* self, int index, Combo_00246F50* combo, int v);
extern "C" void func_001E6C28(void* self, const char* name);
extern "C" void* func_00122CF8(unsigned int size);
extern "C" void* func_001E8DD0(void* self);
extern "C" void func_001E8E98(void* self, int size, int type);
extern "C" void func_001E90F8(void* self, int index, int value);
extern "C" void func_001E7788(void* self, const char* name, void* value);
extern "C" void func_00247D00(Goal_00246F50* self);

bool func_00246F50(Goal_00246F50* self)
{
    Combo_00246F50 e;
    unsigned int type;
    int index;
    unsigned int trick;
    const char* text;
    void* desc;
    const char* str;

    bool cat = func_001E8708(self->m_params, 0x8E6014F6);
    func_001E84E8(self->m_params, D_003738B8, &type, 1);
    if (cat) {
        func_001E7DE8(self->m_params, 0x0B502200, &index, 1);
        trick = index;
    } else {
        func_001E84E8(self->m_params, D_003738C8, &trick, 1);
    }
    if (cat) {
        func_001E7C80(func_001E9378(func_001E55B8(0xFFD7913F, 1), trick), 0xA1DC81F9, &text, 1);
        func_001E70C0(self->m_params, 0x3A54CC4B, text);
    } else {
        func_001E81F0(func_001E5548(trick, 1), D_0038FFE8, &desc, 1);
        func_001E7D90(desc, D_0038FFF0, &str, 1);
        func_001E7138(self->m_params, D_003738D8, str);
    }
    void* combos = 0;
    switch (type) {
    case 0x61A1BC57:
    case 0x439F4704:
        combos = func_001E5548(0x4764231D, 1);
        break;
    case 0xA549B57B:
        combos = func_001E5548(0xA1B2D162, 1);
        break;
    case 0x255ED86F:
        combos = func_001E5548(0xF481D0CD, 1);
        break;
    case 0xEF24413B:
        combos = func_001E5548(0xD72D5CF7, 1);
        break;
    }
    int combo = 0;
    bool found = false;
    int i = 0;
    void* mgr = func_00262990(func_0022E050(D_0038FC78));
    int n = func_00261F80(mgr);
    for (; i < n; i++) {
        func_00261FB0(&e, mgr, i);
        if (!cat && e.m_trick == trick) {
            combo = e.m_combo;
            found = true;
            break;
        }
        func_001E6D18(combos, e.m_combo);
    }
    if (!found) {
        int v = func_001E6E90(combos, 0)->m8;
        func_00261F10(mgr, 1);
        combo = v;
        if (cat) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0xA92A2280, combo);
            func_001E7200(s, 0x7F8C98FE, trick);
            func_001E7200(s, 0x7F264BE9, n);
            func_001F0210(0x466576C8, s, 0, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
        } else {
            func_00264728(&e);
            e.m_trick = trick;
            e.m_combo = combo;
            func_002620D8(mgr, n, &e, 1);
        }
        func_001E7200(self->m_params, 0xBC678826, 1);
    }
    func_001E6C28(self->m_params, D_003738E8);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 1, 13);
    func_001E90F8(arr, 0, combo);
    func_001E7788(self->m_params, D_003738E8, arr);
    func_00247D00(self);
    return !found;
}
