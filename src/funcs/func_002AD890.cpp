extern char D_00379000[];
extern "C" void func_001F0370(void* name, int a, int b, int c);

bool Cmd_002AD890(void* params, void* script)
{
    func_001F0370(D_00379000, 0, 0, 0);
    return true;
}
