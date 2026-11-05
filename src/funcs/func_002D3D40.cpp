extern "C" char* func_003317AC(const char* s, int c);

struct Obj_002D3D40 {
    char* Suffix(char* s);
};

char* Obj_002D3D40::Suffix(char* s)
{
    char* p = func_003317AC(s, '_');
    if (p)
        return p + 1;
    return s;
}
