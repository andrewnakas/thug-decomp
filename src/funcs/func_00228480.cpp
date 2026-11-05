struct Script_00228480 {
    char pad0[0x18];
    void* m18;
};
extern char D_00372370[];
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_00228480(void* params, Script_00228480* s)
{
    func_001E7268(s->m18, D_00372370, 0x4B);
    return true;
}
