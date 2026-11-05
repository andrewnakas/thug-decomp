extern char D_0038F730[];
struct Script_00219F70 {
    char pad[0x18];
    void* m18;
};
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001326F8(void* s);
extern "C" void func_001E7860(void* s, void* name, void* v);

bool func_00219F70(void* params, Script_00219F70* script)
{
    void* s = func_001E6978(func_001190D0(8));
    func_001326F8(s);
    func_001E7860(script->m18, D_0038F730, s);
    return true;
}
