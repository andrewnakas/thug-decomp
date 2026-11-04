struct Net_001F9E08;
extern Net_001F9E08* D_0038EB78;
extern "C" void func_001FA6A0(Net_001F9E08*, int);
extern "C" int func_001FA5D0(Net_001F9E08*);
extern "C" int func_00327BE0(int, int, void*, int);

void func_001F9E08(int ev)
{
    Net_001F9E08* n = D_0038EB78;
    int z;
    switch (ev) {
    case 3:
    case 5:
        func_001FA6A0(n, 0);
        if (func_001FA5D0(n)) {
            z = 0;
            func_00327BE0(0, 6, &z, 4);
        }
        break;
    case 6:
        func_001FA6A0(n, 1);
        break;
    case 8:
        func_001FA6A0(n, 2);
        break;
    }
}
