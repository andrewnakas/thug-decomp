extern "C" unsigned char* func_001EB070(unsigned char* p);

extern "C" unsigned char* func_001ECD40(unsigned char* p)
{
    while (*p != '$')
        p = func_001EB070(p);
    p = func_001EB070(p);
    if (*p == 2)
        p = func_001EB070(p);
    return p;
}
