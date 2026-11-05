extern "C" unsigned int func_00105520(char* s);
extern "C" void func_001F0210(unsigned int id, int a, int b, int c, char* name);

void func_001F0370(char* name, int a, int b, int c)
{
    func_001F0210(func_00105520(name), a, b, c, name);
}
