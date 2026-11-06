/* fuzzy: 82.6 */
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E87B8(void* params, const char* name);
extern char D_0038F718[];

bool func_00219A98(void* params)
{
    int v = 10000;
    func_001E7DE8(params, 0, &v, 0);
    func_001E87B8(params, D_0038F718);
    return true;
}
