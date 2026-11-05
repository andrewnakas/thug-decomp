extern char D_00375D80[];
extern "C" unsigned int func_001F0D78(const char* s);

struct Obj_00264738 {
    int m0;
    unsigned int m4;
    bool Is();
};

bool Obj_00264738::Is()
{
    return m4 == func_001F0D78(D_00375D80);
}
