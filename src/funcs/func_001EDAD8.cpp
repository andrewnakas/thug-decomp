extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" bool func_001EB440(unsigned char* p);

unsigned char* func_001EDAD8(unsigned char* p)
{
    int brackets = 0;
    int parens = 0;
    int braces = 0;
    while (1) {
        unsigned char t = *p;
        if (t == 3) brackets++;
        if (t == 5) parens++;
        if (t == 0xE) braces++;
        if (t == 4) brackets--;
        if (t == 6) parens--;
        if (t == 0xF) braces--;
        if (brackets || parens || braces || !func_001EB440(p))
            p = func_001EB070(p);
        else
            break;
    }
    return func_001EB070(p);
}
