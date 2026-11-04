extern "C" char* func_00336418(const char*, int);

int func_0010FD88(const char* mode)
{
    char* r = func_00336418(mode, 'r');
    char* w = func_00336418(mode, 'w');
    char* a = func_00336418(mode, 'a');
    char* plus = func_00336418(mode, '+');
    char* n = func_00336418(mode, 'n');
    char* d = func_00336418(mode, 'd');
    int flags;
    if (plus)
        flags = 3;
    else if (r)
        flags = 1;
    else if (w)
        flags = 2;
    else if (a)
        flags = 2;
    else
        return 0;
    if (w)
        flags |= 0x600;
    if (a)
        flags |= 0x200;
    if (n)
        flags |= 0x8000;
    return flags;
}
