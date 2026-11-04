struct Slot_002BA5D8 {
    int m0;
    char pad[0x2C];
};

struct Obj_002BA5D8 {
    char pad[0xCC];
    Slot_002BA5D8 mCC[18];
    int Count(int n);
};

extern "C" void func_002BA688(Obj_002BA5D8* o, int n, int* a, int* b);

int Obj_002BA5D8::Count(int n)
{
    int lo = 0;
    int hi = 0;
    func_002BA688(this, n, &lo, &hi);
    int c = 0;
    for (int i = lo; i <= hi; i++) {
        if (mCC[i].m0)
            c++;
    }
    return c;
}
