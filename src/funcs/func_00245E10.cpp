extern int D_0038FFD0[];
extern int D_0038FFD8[];

union Name_00245E10 {
    char s[128];
    int w;
};

struct Goal_00245E10 {
    char m_pad[0x20];
    void* m_params;
};

struct Comp_00245E10 {
    char m_pad[0x1C];
    void* m1C;
};

extern void* D_0038FC78;

extern "C" void* func_0022DD38(void* self);
extern "C" Comp_00245E10* func_00185578(void* self, unsigned int id);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int assert_);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" int func_0023A168(void* self, unsigned int name, int a, int b, int c);
extern "C" bool func_001E8708(void* params, unsigned int name);

bool func_00245E10(Goal_00245E10* self)
{
    void* trickset = func_00185578(func_0022DD38(D_0038FC78), 0xD262802F)->m1C;
    const char* name;
    func_001E7C80(self->m_params, 0x3A54CC4B, &name, 1);
    unsigned int type;
    func_001E8398(self->m_params, 0x3D929B66, &type, 1);
    Name_00245E10 buf;
    if (type == 0x255ED86F) {
        buf.w = D_0038FFD0[0];
        func_00331678(buf.s, name);
        if (func_0023A168(trickset, func_001F0D78(buf.s), 0, 0, 1)) {
            return true;
        }
        buf.w = D_0038FFD8[0];
        func_00331678(buf.s, name);
        if (func_0023A168(trickset, func_001F0D78(buf.s), 0, 0, 1)) {
            return true;
        }
    }
    if (func_001E8708(self->m_params, 0x8E6014F6)) {
        if (func_0023A168(trickset, func_001F0D78(name), 0, 0, 1) > 0) {
            return true;
        }
    } else if (func_0023A168(trickset, func_001F0D78(name), 0, 0, 1) > 0) {
        return true;
    }
    return false;
}
