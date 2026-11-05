extern "C" unsigned int func_00105520(char* s);
extern "C" int func_001E8090(void* params, unsigned int id, void* a, void* b, int c);

int func_001E8118(void* params, char* name, void* a, void* b, int c)
{
    return func_001E8090(params, func_00105520(name), a, b, c);
}
