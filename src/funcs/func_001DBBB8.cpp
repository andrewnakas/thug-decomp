struct Array_001DBBB8 {
    char m_pad[0xC];
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

extern "C" unsigned int func_001DB7A8(void* name);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_001DBBB8** out, int required);
extern "C" void* func_001E9378(Array_001DBBB8* arr, unsigned int i);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void* func_001DBA90(void* entry);

extern "C" void* func_001DBBB8(void* params, void* name, float t)
{
    unsigned int key = func_001DB7A8(name);
    void* found;
    if (func_001E8180(params, key, &found, 0))
        return found;
    Array_001DBBB8* arr;
    func_001E8248(params, key, &arr, 1);
    for (unsigned int i = 0; i < arr->GetSize(); i++) {
        void* e = func_001E9378(arr, i);
        float limit;
        if (!func_001E7EB0(e, 0x9EE9A09A, &limit, 0))
            return func_001DBA90(e);
        if (t <= limit)
            return func_001DBA90(e);
    }
    return 0;
}
