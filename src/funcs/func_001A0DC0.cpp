extern "C" void* func_001A0718(void* p);
extern "C" int func_00119870(void* p);

int func_001A0DC0(void* p)
{
    if (!func_001A0718(p)) {
        return 0;
    }
    return func_00119870(func_001A0718(p));
}
