struct Array_0021CD28 {
    char pad0[0xC];
    unsigned int m_size;
};

extern char D_00371688[];
extern void* D_0038FC78;

extern "C" Array_0021CD28* func_001E55F8(const char* name, int a);
extern "C" void* func_001E9378(Array_0021CD28* a, unsigned int i);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E050(void* mgr);
extern "C" void* func_002629B8(void* mgr, unsigned int id);
extern "C" bool func_00261118(void* obj, void* params);

bool func_0021CD28()
{
    Array_0021CD28* a = func_001E55F8(D_00371688, 1);
    for (unsigned int i = 0; i < a->m_size; i++) {
        void* params = func_001E9378(a, i);
        unsigned int id;
        func_001E8398(params, 0xA1DC81F9, &id, 1);
        func_00261118(func_002629B8(func_0022E050(D_0038FC78), id), params);
    }
    return true;
}
