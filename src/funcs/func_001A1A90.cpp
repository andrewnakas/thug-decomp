extern "C" void* func_001A0718(void* a);
extern "C" float func_00119890(void* a);

extern "C" float func_001A1A90(void* a)
{
    if (!func_001A0718(a)) {
        return 0.0f;
    }
    return func_00119890(func_001A0718(a));
}
