struct Arr_002B9350 {
    char pad[0xC];
    unsigned int mC;
};

struct Info_002B9350 {
    char pad[0x24];
    int m24;
};

extern "C" void* func_001E9378(Arr_002B9350* a, int i);
extern "C" int func_001E8398(void* s, unsigned int name, int* out, int v);
extern "C" void* func_002B7740(void* self, int id, int v);
extern "C" Info_002B9350* func_002B6CF0(void* p);

extern "C" void func_002B9350(void* self, Arr_002B9350* a)
{
    for (unsigned int i = 0; i < a->mC; i++) {
        void* e = func_001E9378(a, i);
        int type = 0;
        func_001E8398(e, 0x12B4E660, &type, 0);
        if (type == (int)0xBF4D3536) {
            int x = 0;
            func_001E8398(e, 0xA1DC81F9, &x, 0);
            int y = 0;
            func_001E8398(e, 0x2CA8A299, &y, 0);
            if (x && y)
                func_002B6CF0(func_002B7740(self, x, 1))->m24 = y;
        }
    }
}
