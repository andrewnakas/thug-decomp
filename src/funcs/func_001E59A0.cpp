struct Rec_001E59A0 {
    char m0;
    char m1;
    char m2;
};
extern "C" unsigned int func_00105520(const char* s);
extern "C" void func_001E60C8(unsigned int key, const char* str);
extern "C" Rec_001E59A0* func_001E5188(unsigned int key);

extern "C" void func_001E59A0(const char** names, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        unsigned int key = func_00105520(names[i]);
        func_001E60C8(key, names[i]);
        func_001E5188(key)->m2 = 9;
    }
}
