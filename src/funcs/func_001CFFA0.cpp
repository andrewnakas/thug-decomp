struct Ext_001CFFA0 {
    char* ext;
    int val;
};

extern Ext_001CFFA0 D_0034ED88[];
extern "C" int func_00331BB8(const char* s);
extern "C" int func_00336228(const char* a, const char* b);

extern "C" int func_001CFFA0(void* self, char* name)
{
    char* p = name + func_00331BB8(name);
    while (p > name && *p != '.') p--;
    if (*p != '.') return 0;
    p++;
    for (Ext_001CFFA0* e = D_0034ED88; e->ext; e++) {
        if (!func_00336228(e->ext, p)) return e->val;
    }
    return 0;
}
