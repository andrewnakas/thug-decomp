extern "C" void* func_001E4FC8();
extern "C" void func_001ED8D0(void* p);

void Call_001ED9A0()
{
    void* p = func_001E4FC8();
    if (p) func_001ED8D0(p);
}
