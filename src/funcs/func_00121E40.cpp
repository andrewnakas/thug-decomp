struct Arr_00121E40 {
    char pad[0xC];
    int mC;
};

extern "C" Arr_00121E40* func_001E55B8(void* name, int a);
extern "C" void* func_001E9378(Arr_00121E40* arr, int i);
extern "C" bool func_001E8708(void* s, unsigned int id);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" int func_001E8398(void* s, unsigned int id, int* out, int req);

void* func_00121E40(void* name, int index, int id)
{
    Arr_00121E40* arr = func_001E55B8(name, 1);
    int n = arr->mC;
    if (!id) {
        for (int i = 0; i < n; i++) {
            void* s = func_001E9378(arr, i);
            int v = -1;
            if (func_001E7DE8(s, 0x4B833E64, &v, 1) && v == index)
                return s;
        }
    } else {
        for (;;) {
            for (int i = 0; i < n; i++) {
                void* s = func_001E9378(arr, i);
                int ok = !func_001E8708(s, 0xF6F8E158);
                func_001E7DE8(s, 0xF1E3CD22, &ok, 1);
                int v = 0;
                func_001E8398(s, 0x0D7260FD, &v, 0);
                bool any = v == 0;
                if (ok && (v == id || any)) {
                    if (index <= 0)
                        return s;
                    index--;
                }
            }
        }
    }
    return 0;
}
