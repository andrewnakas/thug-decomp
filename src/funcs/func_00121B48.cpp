struct Arr_00121B48 {
    char pad[0xC];
    int mC;
};

extern "C" Arr_00121B48* func_001E55B8(void* name, int a);
extern "C" void* func_001E9378(Arr_00121B48* arr, int i);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" int func_001E8398(void* s, unsigned int id, int* out, int req);

void func_00121B48(void* name, int id, void** out, int* count)
{
    int i = 0;
    Arr_00121B48* arr = func_001E55B8(name, 1);
    *count = 0;
    int n = arr->mC;
    for (; i < n; i++) {
        void* s = func_001E9378(arr, i);
        int flag = 0;
        func_001E7DE8(s, 0x355F9467, &flag, 1);
        if (flag) {
            int v = 0;
            func_001E8398(s, 0x0D7260FD, &v, 0);
            if (v == id) {
                *out++ = s;
                (*count)++;
            }
        }
    }
}
