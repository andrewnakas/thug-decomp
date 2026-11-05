extern char D_00354CA8[];
struct Script_0020CE48 {
    char pad[0x18];
    void* m_params;
};
extern "C" void func_001E70C0(void* s, unsigned int id, void* v);

bool func_0020CE48(void* params, Script_0020CE48* script)
{
    func_001E70C0(script->m_params, 0xCC23BDDB, D_00354CA8);
    return false;
}
