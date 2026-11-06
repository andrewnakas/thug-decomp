void Pack_0017EF28(unsigned long* out, unsigned short a, unsigned short b, unsigned short c, unsigned long d)
{
    *out = (unsigned long)a | ((unsigned long)c << 16) | ((unsigned long)b << 32) | (d << 48);
}
