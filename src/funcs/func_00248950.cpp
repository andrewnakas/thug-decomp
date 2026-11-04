extern char D_00390078[];

extern void* D_0038FC78;

extern "C" void* func_00249FE0(void* self);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int assert_);
extern "C" void* func_0022E368(void* self, int index);
extern "C" const char* func_002624F0(void* profile);
extern "C" bool func_002623B8(void* profile);
extern "C" char* func_003364D8(const char* s, const char* find);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" unsigned int func_001F0D78(const char* name);

static inline void GetBaseName_00248950(char* dst, const char** src)
{
    if (!func_003364D8(*src, D_00390078)) {
        func_00331A9C(dst, *src);
    } else {
        char* p = dst;
        while (**src != ' ') {
            *p++ = **src;
            (*src)++;
        }
        *p = 0;
    }
}

const char* func_00248950(void* self)
{
    void* params = func_00249FE0(self);
    const char* text;
    if (!func_001E8870(params, 0x944B2900, &text, 0)) {
        return 0;
    }
    int use_alt = 0;
    void* profile = func_0022E368(D_0038FC78, 0);
    const char* name = func_002624F0(profile);
    const char* alt;
    if (func_002623B8(profile)) {
        char buf[128];
        GetBaseName_00248950(buf, &name);
        if (func_002623B8(profile) && func_001F0D78(buf) == func_001F0D78(text)) {
            if (!func_001E8870(params, 0x878CCC12, &alt, 0)) {
                return 0;
            }
            use_alt = 1;
        }
    }
    if (use_alt) {
        return alt;
    }
    return text;
}
