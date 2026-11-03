struct Arr_00292388 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" Arr_00292388* func_001E55B8(unsigned int id, int v);
extern "C" void func_001E8E98(Arr_00292388* arr, int n, int type);
extern "C" void func_001E8F48(Arr_00292388* arr, int n);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E5548(unsigned int id, int v);
extern "C" void func_001E6AC8(void* s, void* src);
extern "C" int func_00292090(int a, int b);
extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E9170(Arr_00292388* arr, int i, void* s);

void func_00292388()
{
    int n = 0;
    Arr_00292388* arr = func_001E55B8(0xC472ECC5, 1);
    if (!arr->mC) {
        func_001E8E98(arr, 0x50, 10);
    } else {
        n = arr->mC;
        func_001E8F48(arr, n + 0x50);
    }
    for (int i = 0; i < 10; i++) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E6AC8(s, func_001E5548(0x8F0F67D7, 1));
        func_001E7360(s, 0xA1DC81F9, func_00292090(i, 0));
        func_001E7200(s, 0xE50D6573, n);
        func_001E9170(arr, n++, s);
        s = func_001E6978(func_001190D0(8));
        func_001E6AC8(s, func_001E5548(0xC9119673, 1));
        func_001E7360(s, 0xA1DC81F9, func_00292090(i, 1));
        func_001E7200(s, 0xE50D6573, n);
        func_001E9170(arr, n++, s);
        for (int j = 0; j < 6; j++) {
            s = func_001E6978(func_001190D0(8));
            func_001E6AC8(s, func_001E5548(0x1AAF51BA, 1));
            func_001E7360(s, 0xA1DC81F9, func_00292090(i, j + 2));
            func_001E7200(s, 0xE50D6573, n);
            func_001E9170(arr, n++, s);
        }
    }
}
