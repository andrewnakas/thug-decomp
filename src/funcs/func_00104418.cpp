extern "C" void func_00104418(char* s)
{
    while (*s) {
        char c = *s;
        if ((unsigned int)(c - 'A') < 26) c += 32;
        *s = c;
        s++;
    }
}
