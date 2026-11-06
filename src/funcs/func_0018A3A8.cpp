struct Array_0018A3A8 {
    char pad0[0xC];
    unsigned int m_count;
    unsigned int GetSize() { return m_count; }
};

extern void* D_00389A30;
extern void* D_0038C7B0;
extern "C" void* func_0012E438(void* mgr, void* params, unsigned int key);
extern "C" void* func_001895B0(void* mgr, void* obj);
extern "C" int func_001E8708(void* params, unsigned int key);
extern "C" int func_001E8248(void* params, unsigned int key, Array_0018A3A8** out, int required);
extern "C" int func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" int func_001E9300(Array_0018A3A8* a, unsigned int i);
extern "C" void func_001F0E98(void* set, int id);
extern "C" void func_001F0E08(void* set, int id);

extern "C" bool func_0018A3A8(void* params, void* script)
{
    void* set = func_001895B0(D_0038C7B0, func_0012E438(D_00389A30, params, 0x40C698AF));
    int remove = func_001E8708(params, 0xC89F3564);
    Array_0018A3A8* arr;
    if (func_001E8248(params, 0x22E168C1, &arr, 0)) {
        for (unsigned int i = 0; i < arr->GetSize(); i++) {
            if (remove) {
                func_001F0E98(set, func_001E9300(arr, i));
            } else {
                func_001F0E08(set, func_001E9300(arr, i));
            }
        }
    } else {
        int id = 0;
        func_001E8398(params, 0x6166F3AD, &id, 0);
        if (remove) {
            func_001F0E98(set, id);
        } else {
            func_001F0E08(set, id);
        }
    }
    return true;
}
