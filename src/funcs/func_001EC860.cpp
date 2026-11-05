unsigned char* Put16_001EC860(unsigned char* p, unsigned short v)
{
    *p++ = v;
    *p++ = v >> 8;
    return p;
}
