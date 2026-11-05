extern char D_0038F340[];
extern char D_00354CA8[];
extern "C" int func_001E7C80(void* params, unsigned int id, char** out, int req);
extern "C" char* func_00331A9C(char* d, char* s);

bool func_0020CE78(void* params, void* script)
{
    char* s = D_0038F340;
    func_001E7C80(params, 0, &s, 0);
    func_00331A9C(D_00354CA8, s);
    return false;
}
