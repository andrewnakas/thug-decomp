struct Mgr_002D39B0 {
    int m0;
    void* m4;
    int m8;
    void* mC;
};

extern Mgr_002D39B0* D_00392068;
extern "C" int func_002D30E0(void* p);
extern "C" int func_002D7EB8(void* p);
extern "C" unsigned int func_002D8158(void* p);
extern "C" int func_002D3070(void* p);
extern "C" int func_002D3080(void* p);

bool Check_002D39B0()
{
    Mgr_002D39B0* m = D_00392068;
    if (func_002D30E0(m->m4)) {
        if (!func_002D7EB8(m->mC))
            return false;
        unsigned int id = func_002D8158(m->mC);
        if (id == 0x1A7665B || id == 0x1A76689 || id == 0x1A766AB || id == 0x1A76701 || id == 0x1A766CC ||
            id == 0x1A7672E || id == 0x1A7675B || id == 0x1A76773 || id == 0x1A76794 || id == 0x1A767B1)
            return true;
        return false;
    }
    return func_002D3070(m->m4) < func_002D3080(m->m4);
}
