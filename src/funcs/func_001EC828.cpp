unsigned char* func_001EC828(unsigned char* p, float f)
{
    unsigned int v = *(unsigned int*)&f;
    *p = v;
    p++;
    *p = v >> 8;
    p++;
    *p = v >> 16;
    p++;
    *p = v >> 24;
    return p + 1;
}
