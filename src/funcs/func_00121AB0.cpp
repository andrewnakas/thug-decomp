struct Arr_00121AB0 {
    char pad[0xC];
    unsigned int mC;
};

extern "C" Arr_00121AB0* func_001E55B8(void* name, int a);
extern "C" void* func_001E9378(Arr_00121AB0* arr, int i);
extern "C" int func_00121A80(void* s);

void* func_00121AB0(void* name, int key)
{
    void* found = 0;
    Arr_00121AB0* arr = func_001E55B8(name, 1);
    if (!key)
        return 0;
    for (unsigned int i = 0; i < arr->mC; i++) {
        void* s = func_001E9378(arr, i);
        if (func_00121A80(s) == key) {
            found = s;
            break;
        }
    }
    return found;
}
