extern "C" int func_00229EB0(void* o);
extern "C" int func_00229F48(void* o, int i);

extern "C" bool func_00229F78(void* o, int id)
{
    int i = 0;
    int n = func_00229EB0(o);
    for (; i < n; i++) {
        if (func_00229F48(o, i) == id)
            return true;
    }
    return false;
}
