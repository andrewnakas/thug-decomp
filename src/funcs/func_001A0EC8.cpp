extern "C" void* func_001A0718(void* a);
extern "C" float func_00119768(void* a);

extern "C" float func_001A0EC8(void* a)
{
    if (!func_001A0718(a)) {
        return 0.0f;
    }
    return func_00119768(func_001A0718(a));
}
