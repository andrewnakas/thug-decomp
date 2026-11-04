extern "C" int func_00336228(const char*, const char*);
extern "C" void func_0010BEB8(char*);
extern char* D_00396568[100];

bool func_0010D970(const char* name)
{
    bool found = false;
    for (int i = 0; i < 100; i++) {
        if (D_00396568[i] && func_00336228(D_00396568[i], name) == 0) {
            func_0010BEB8(D_00396568[i]);
            found = true;
            D_00396568[i] = 0;
        }
    }
    return found;
}
