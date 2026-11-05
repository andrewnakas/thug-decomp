extern "C" void func_001E14F0(char* a, void* b, void* c, char* d);

void Call_001E1AF8(void* b, void* unused, char* a, void* c)
{
    func_001E14F0(a, b, c, a + 8);
}
