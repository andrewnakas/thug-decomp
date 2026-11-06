extern "C" void func_00104460(char* s)
{
    while (*s) {
        char c = *s;
        if ((unsigned int)(c - 'a') < 26) c -= 32;
        *s = c;
        s++;
    }
}
