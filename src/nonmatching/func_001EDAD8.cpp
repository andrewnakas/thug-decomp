/* fuzzy: 56.9 */
// nm: 16-24 words: loop structure right, register assignment of p/counters differs (lane 2 draft, decl orders tried)
extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" bool func_001EB440(unsigned char* p);

unsigned char* func_001EDAD8(unsigned char* p)
{
    int brackets = 0;
    int parens = 0;
    int braces = 0;
top:
    {
        unsigned char t = *p;
        if (t == 5) parens++;
        if (t == 3) brackets++;
        if (t == 0xE) braces++;
        if (t == 4) brackets--;
        if (t == 6) parens--;
        if (t == 0xF) braces--;
        if (brackets || parens || braces || !func_001EB440(p)) {
            p = func_001EB070(p);
            goto top;
        }
    }
    return func_001EB070(p);
}
