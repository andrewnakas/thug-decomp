extern char D_0038F428[];

struct Obj_00217C28;

struct Model_00217C28 {
    char pad[0xBC];
    Obj_00217C28* m_owner;
};

struct Obj_00217C28 {
    char pad[0x14];
    Model_00217C28* m_model;
};

struct Script_00217C28 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E8A50(void* params, char* name, unsigned int* out, int assert_);
extern "C" bool func_001E8A30(void* params, int name, int* out, int assert_);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" Obj_00217C28* func_00184D70(unsigned int id);
extern "C" void func_00183C98(Obj_00217C28* o, Obj_00217C28** ref);
extern "C" void func_00184C88(Obj_00217C28* o, int a, int b);

bool func_00217C28(void* params, Script_00217C28* script)
{
    unsigned int id;
    int a;
    func_001E8A50(params, D_0038F428, &id, 1);
    func_001E8A30(params, 0, &a, 1);
    int b = 0;
    func_001E8180(params, 0x7031F10C, &b, 0);
    func_001E6B90(script->m_params, 0xA2B033FD);
    Obj_00217C28* o = func_00184D70(id);
    if (o) {
        Model_00217C28* m = o->m_model;
        if (m) {
            Obj_00217C28** ref = &m->m_owner;
            if (!*ref) {
                *ref = o;
                func_00183C98(o, ref);
            }
        }
        func_00184C88(o, a, b);
        return true;
    }
    return false;
}
