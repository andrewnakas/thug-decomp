struct Arr_00121C48 {
    char pad[0xC];
    int mC;
};

extern "C" Arr_00121C48* func_001E55B8(void* name, int a);
extern "C" void* func_001E9378(Arr_00121C48* arr, int i);
extern "C" bool func_001E8708(void* s, unsigned int id);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" int func_001E8398(void* s, unsigned int id, int* out, int req);
extern "C" int func_001E88D8(void* s, unsigned int id, int* out, int req);
extern "C" int func_00100030(int n);
extern "C" void func_001E7200(void* s, unsigned int id, int v);

void* func_00121C48(void* name, int id)
{
    void* items[32];
    int used[32];
    int i;
    int count = 0;
    Arr_00121C48* arr = func_001E55B8(name, 1);
    int n = arr->mC;
    for (i = 0; i < n; i++) {
        void* s = func_001E9378(arr, i);
        int ok = !func_001E8708(s, 0xF6F8E158);
        func_001E7DE8(s, 0xF1E3CD22, &ok, 1);
        if (id) {
            int v = 0;
            if (func_001E8398(s, 0x0D7260FD, &v, 0) && v != id)
                ok = 0;
        }
        if (ok) {
            int u;
            items[count] = s;
            func_001E88D8(s, 0x92BDDFD9, &u, 1);
            used[count] = u != 0;
            count++;
        }
    }
    int fresh = 0;
    for (int j = 0; j < count; j++)
        if (!used[j])
            fresh++;
    if (!fresh)
        for (int j = 0; j < count; j++)
            used[j] = 0;
    int k = 0;
    for (int j = 0; j < count; j++) {
        if (!used[j]) {
            items[k] = items[j];
            used[k] = used[j];
            k++;
        }
    }
    void* s = items[func_00100030(k)];
    func_001E7200(s, 0x92BDDFD9, 1);
    return s;
}
