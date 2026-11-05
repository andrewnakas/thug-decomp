struct Obj_00222F88 {
    char pad[0x30];
    int m_slots[2];
};

extern Obj_00222F88* D_00390828;
extern char D_00371B00[];
extern char D_00371B58[];
extern char D_00371B68[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_00254C98(Obj_00222F88* obj);

bool Cmd_00222F88(void* params, void* script)
{
    int value;
    int slot;
    func_001E7E58(params, D_00371B00, &value, 1);
    func_001E7E58(params, D_00371B58, &slot, 1);
    func_00103F28(D_00371B68, slot, value);
    Obj_00222F88* obj = D_00390828;
    int old = obj->m_slots[slot];
    for (int i = 0; i < 2; i++) {
        if (obj->m_slots[i] == value) {
            obj->m_slots[i] = old;
        }
    }
    obj->m_slots[slot] = value;
    func_00254C98(obj);
    return true;
}
