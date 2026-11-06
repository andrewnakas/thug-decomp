extern "C" int func_00170518(void* o);
extern "C" void* func_00170680(void* o);
extern "C" void* func_00170718(void* o);

void func_00150DE0(void* n, void** out, int* count)
{
    if (func_00170518(n)) {
        int i = *count;
        out[i] = n;
        *count = i + 1;
        return;
    }
    for (void* c = func_00170680(n); c; c = func_00170718(c))
        func_00150DE0(c, out, count);
}
