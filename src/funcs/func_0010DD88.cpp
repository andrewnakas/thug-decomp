extern "C" int func_00336228(const char*, const char*);
extern char* D_00396568[100];

char* func_0010DD88(const char* name)
{
    if (!name) {
        for (int i = 0; i < 100; i++)
            if (D_00396568[i])
                return D_00396568[i];
        return 0;
    }
    int found = 0;
    for (int i = 0; i < 100; i++) {
        char* p = D_00396568[i];
        if (p) {
            if (found)
                return p;
            found = 0;
            if (func_00336228(p, name) == 0)
                found = 1;
        }
    }
    return 0;
}
