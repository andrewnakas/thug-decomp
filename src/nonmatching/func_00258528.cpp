/* fuzzy: 87.5 */
struct Arr_00258528 {
    int m0;
    int m4;
    int m8;
    int mC;
    int GetSize() { return mC; }
};

extern char D_003755A0[];
extern "C" Arr_00258528* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(Arr_00258528* a, int i);
extern "C" int func_002584A0(void* p);
extern "C" int func_001E82B8(void* params, const char* name, Arr_00258528** out, int required);
extern "C" int func_001E9300(Arr_00258528* a, int i);

int Fn_00258528(int type, int* out, int start)
{
    int n = 0;
    Arr_00258528* arr = func_001E55B8(0xC472ECC5, 0);
    if (!arr) return 0;
    int i = -1;
    if (start >= 0) i = start;
    for (i++; i < arr->mC; i++) {
        void* item = func_001E9378(arr, i);
        if (func_002584A0(item)) {
            if (!type) {
                out[n++] = i;
            } else {
                Arr_00258528* sub;
                if (func_001E82B8(item, D_003755A0, &sub, 0)) {
                    for (int j = 0; j < sub->GetSize(); j++) {
                        if (func_001E9300(sub, j) == type) out[n++] = i;
                    }
                }
            }
        }
    }
    return n;
}
