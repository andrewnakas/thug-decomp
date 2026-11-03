static inline int ToLower_00104610(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c + 32);
    return c;
}

int func_00104610(const char* a, const char* b)
{
    int ca, cb;
    for (;;) {
        char ra = *a++;
        char rb = *b++;
        ca = ToLower_00104610(ra);
        cb = ToLower_00104610(rb);
        if (ca < cb)
            return -1;
        if (ca > cb)
            return 1;
        if (!ca && !cb)
            return 0;
        if (!ca)
            return -1;
        if (!cb)
            return 1;
    }
}
