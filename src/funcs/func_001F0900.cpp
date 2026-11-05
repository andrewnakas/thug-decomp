struct E_001F0900 {
    char m0, m1;
    unsigned char m2;
};

extern "C" E_001F0900* func_001E5040(int a);

extern "C" int func_001F0900(int a)
{
    E_001F0900* p = func_001E5040(a);
    if (p && p->m2 == 7) return 1;
    return 0;
}
