extern "C" int func_00105520(const char* name);
extern "C" void func_001E7410(void* s, int name, float x, float y, float z);

extern "C" void func_001E74C0(void* s, const char* name, float x, float y, float z)
{
    func_001E7410(s, func_00105520(name), x, y, z);
}
