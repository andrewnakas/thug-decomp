extern "C" int func_00127DE0(void* o);
extern "C" void func_00127BE8(void* o, char* buf, int size);
extern "C" void func_00127BC0(void* o, char* s);

bool func_00127F00(void* o)
{
    int len = func_00127DE0(o);
    if (!len)
        return false;
    char buf[0x200];
    func_00127BE8(o, buf, 0x200);
    if (len > 1 && buf[len - 1] == '\\' && buf[len - 2] == '\\')
        buf[len - 2] = 0;
    buf[len - 1] = 0;
    func_00127BC0(o, buf);
    return true;
}
