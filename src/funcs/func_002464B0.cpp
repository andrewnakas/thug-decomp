extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int req);
extern "C" int func_00336228(const char* a, const char* b);

struct Obj_002464B0 {
    char pad[0x20];
    void* m20;
    bool Fn(const char* s);
};

bool Obj_002464B0::Fn(const char* s)
{
    char* v;
    if (func_001E7C80(m20, 0x955C6305, &v, 0) && func_00336228(v, s) == 0)
        return true;
    return false;
}
