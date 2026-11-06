struct Array_001853F0 {
    char pad0[0xC];
    int m_count;
};

extern "C" int func_001E9378(Array_001853F0* a, int i);
extern "C" void func_00185300(void* obj, int item, int arg);

extern "C" void func_001853F0(void* obj, Array_001853F0* arr, int arg)
{
    int n = arr->m_count;
    for (int i = 0; i < n; i++) {
        func_00185300(obj, func_001E9378(arr, i), arg);
    }
}
