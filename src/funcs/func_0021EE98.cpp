struct Info_0021EE98 {
    char m[0x38];
};

struct Script_0021EE98 {
    char m_pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_0022E3C8(void* self, int index);
extern "C" void* func_001200E0(void* self);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int assert_);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" Info_0021EE98 func_00123440(void* self);
extern "C" int func_00122688(Info_0021EE98 info, void* params);
extern "C" void func_001E93D0(void* self, int value);
extern "C" void func_001E77D0(void* self, unsigned int name, void* value);
extern "C" void func_001E6AE8(void* self, int flags);

bool func_0021EE98(void* params, Script_0021EE98* script)
{
    int created = 0;
    int index;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    void* app = func_001200E0((char*)func_0022E3C8(D_0038FC78, index) + 4);
    void* p = 0;
    if (!func_001E8180(script->m_params, 0x12E87395, &p, 0)) {
        created = 1;
        p = func_001E6978(func_001190D0(8));
    }
    Info_0021EE98 info;
    info = func_00123440(app);
    if (!func_00122688(info, p)) {
        func_001E93D0(params, 0);
    }
    if (created) {
        func_001E77D0(script->m_params, 0x12E87395, p);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
    return true;
}
