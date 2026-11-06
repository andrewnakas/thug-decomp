/* fuzzy: 31.7 */
static inline char ToLower_00104328(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

/* Case-insensitive strstr: first occurrence of sub in s, or 0. */
extern "C" const char* func_00104328(const char* s, const char* sub)
{
    char first = *sub++;
    if (!first)
        return 0;
    char c0 = ToLower_00104328(first);
    for (;;) {
        char c = ToLower_00104328(*s++);
        if (c == c0) {
            const char* p = s;
            const char* q = sub;
            for (;;) {
                char k = *q++;
                if (!k)
                    return s - 1;
                if (ToLower_00104328(k) != ToLower_00104328(*p++))
                    break;
            }
        } else if (!c) {
            return 0;
        }
    }
}
