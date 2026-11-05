extern "C" int func_00331BB8(const char* s);

char* Skip_0010D4E0(char* s)
{
    return s + ((func_00331BB8(s) + 16) & ~15);
}
