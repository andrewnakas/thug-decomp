struct Arr_002103B0 {
    int m0;
    int m4;
    int m_type;
    int m_size;
};
struct Script_002103B0 {
    char pad[0xBC];
    void* mBC;
};
extern "C" bool func_001E8248(void* params, unsigned int name, Arr_002103B0** out, int required);
extern "C" int func_00100030(int range);
extern "C" void* func_001E9300(Arr_002103B0* a, int index);
extern "C" void func_001EE8C8(Script_002103B0* s, void* a, void* b, void* owner);

extern "C" bool func_002103B0(void* params, Script_002103B0* script)
{
    Arr_002103B0* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    if (arr && arr->m_size && arr->m_type == 13)
    {
        int i = func_00100030(arr->m_size);
        func_001EE8C8(script, func_001E9300(arr, i), 0, script->mBC);
    }
    return true;
}
