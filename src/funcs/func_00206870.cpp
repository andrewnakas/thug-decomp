struct Script_00206870;

extern "C" void* func_00121960(unsigned int size);
extern "C" Script_00206870* func_001EE428(void* mem);
extern "C" void* func_00185578(void* obj, unsigned int type);
extern "C" void func_002919B0(void* c);
extern "C" void func_001EE8C8(Script_00206870* s, unsigned int name, void* params, void* obj);
extern "C" void func_001EFDC0(Script_00206870* s);

struct Obj_00206870 {
    char pad0[0x14];
    Script_00206870* m_script;

    void RunScript(unsigned int name, void* params);
};

void Obj_00206870::RunScript(unsigned int name, void* params)
{
    if (!m_script)
        m_script = func_001EE428(func_00121960(0xF4));
    func_002919B0(func_00185578(this, 0x488AF07A));
    func_001EE8C8(m_script, name, params, this);
    func_001EFDC0(m_script);
}
