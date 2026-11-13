/* force: {"kind": "ga", "before": [124, 168]} */
static inline char ToLower_00104328(char c)
{
    return (c >= 'A' && c <= 'Z') ? (char)(c + ('a' - 'A')) : c;
}

/* Case-insensitive strstr: first occurrence of sub in s, or 0.
 * The lower-casing in c0 and in the compare loop is written out as ?: expressions (a tolower macro in the
 * original): fold pushes the `!=` into the arms of the right-hand ?:, which is the game's two compare-branches
 * (bnel a2,v0 / beql a2,a3), and the left-hand one is if-converted (movz) with a char range test (andi 0xFF). */
extern "C" const char* func_00104328(const char* s, const char* sub)
{
    char first = *sub++;
    if (!first)
        return 0;
    char c0 = (first >= 'A' && first <= 'Z') ? first + ('a' - 'A') : first;
    for (;;) {
        char c;
        while ((c = ToLower_00104328(*s++)) != c0) {
            if (!c)
                return 0;
        }
        const char* p = s;
        const char* q = sub;
        for (;;) {
            char k = *q++;
            if (!k)
                return s - 1;
            char b = *p++;
            if (((k >= 'A' && k <= 'Z') ? k + ('a' - 'A') : k) != ((b >= 'A' && b <= 'Z') ? b + ('a' - 'A') : b))
                break;
        }
    }
}
