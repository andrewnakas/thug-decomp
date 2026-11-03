extern char D_003721D8[];
extern char D_003721E8[];
extern char D_003721F8[];
extern char D_0038FA20[];
extern int D_00388814;

struct Script_00226DB0 {
    char pad[0x18];
    void* m_params;
};

struct Array_00226DB0 {
    char pad[0xC];
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

extern "C" void func_001E6C28(void* params, char* name);
extern "C" bool func_001E8248(void* params, unsigned int key, Array_00226DB0** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" void* func_001E9378(Array_00226DB0* a, unsigned int i);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" bool func_001E87B8(void* params, char* name);
extern "C" bool func_00226B78(void* a, void* b);
extern "C" void func_001E7860(void* params, char* name, void* value);

bool func_00226DB0(void* params, Script_00226DB0* script)
{
    func_001E6C28(script->m_params, D_003721D8);
    Array_00226DB0* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    void* best;
    if (arr) {
        unsigned int type = 0;
        func_001E8398(params, 0, &type, 0);
        best = 0;
        for (unsigned int i = 0; i < arr->GetSize(); i++) {
            void* e = func_001E9378(arr, i);
            unsigned int ft = 0;
            func_001E84E8(e, D_003721E8, &ft, 0);
            if (type == 0 || type == ft) {
                if ((!func_001E87B8(e, D_003721F8) && !func_001E87B8(e, D_0038FA20)) || D_00388814 == 4 ||
                    D_00388814 == 5) {
                    if (best) {
                        if (func_00226B78(e, best))
                            best = e;
                    } else {
                        best = e;
                    }
                }
            }
        }
        if (best)
            goto found;
    }
    return false;
found:
    func_001E7860(script->m_params, D_003721D8, best);
    return true;
}
