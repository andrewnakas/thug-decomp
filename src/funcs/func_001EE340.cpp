extern "C" void func_001EDBA8(void* a, void* b, void* c, int d);
extern "C" void func_001EDA20();
extern "C" void func_001EE1F0();

void Call_001EE340(void* a, void* b, void* c)
{
    func_001EDBA8(a, b, c, 0);
    func_001EDA20();
    func_001EE1F0();
}
