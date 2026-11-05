extern "C" void func_001160A0(void* a, bool b, void* c, int d);

void Dispatch_00116070(void*, int kind, void* a2, void* a3, int t0)
{
    if (kind == 3)
        func_001160A0(a3, t0 != 0, a2, 1);
}
