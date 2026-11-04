struct Array_00266370 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern char D_00375F60[];
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" bool func_001E82B8(void* params, char* name, Array_00266370** out, int required);
extern "C" unsigned int func_001E9300(Array_00266370* a, int i);
extern "C" void func_001E6B30(void* s);

struct Obj_00266370 {
    char pad0[0x38];
    void* m38;
    void Load();
};

extern "C" void func_00265E50(Obj_00266370* self, unsigned int name, int idx);

void Obj_00266370::Load()
{
    char buf[0x20];
    Array_00266370* arr;
    for (int i = 0; i < 8; i++) {
        func_003331D0(buf, D_00375F60, i);
        if (func_001E82B8(m38, buf, &arr, 0)) {
            int j = 0;
            if (arr->mC > 0) {
                do {
                    func_00265E50(this, func_001E9300(arr, j++), i);
                } while (j < arr->mC);
            }
        }
    }
    func_001E6B30(m38);
}
