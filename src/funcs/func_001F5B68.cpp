void Pack_001F5B68(unsigned long* p, unsigned int a, unsigned int b, unsigned int c)
{
    *p = ((unsigned long)a << 32) | ((unsigned long)b << 28) | (unsigned long)c;
}
