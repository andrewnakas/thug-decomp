struct Ent_001E60C8 {
    unsigned int key;
    char* str;
};

extern int D_00388818;
extern Ent_001E60C8* D_0038E580;
extern char* D_0038E588;
extern "C" int func_00336228(const char* a, const char* b);

extern "C" void func_001E60C8(unsigned int key, char* str)
{
    if (!D_00388818) return;
    Ent_001E60C8* e = &D_0038E580[(key & 0xFFFF) * 10];
    while (e->str) {
        if (e->key == key) {
            func_00336228(e->str, str);
            return;
        }
        e++;
    }
    e->key = key;
    e->str = D_0038E588;
    while (*str) *D_0038E588++ = *str++;
    *D_0038E588++ = 0;
}
