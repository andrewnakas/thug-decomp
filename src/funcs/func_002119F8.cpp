extern "C" void func_001E8A30(void* params, int name, int* out, int required);
extern "C" int func_00229780(int id);

int Get_002119F8(void* params)
{
    int id = 0;
    func_001E8A30(params, 0, &id, 1);
    return func_00229780(id);
}
