/* sym: SetOn__12Obj_0017F5F8b = 0x0017F648 */
extern char D_00361258[];

struct Obj_0017F5F8 {
    char pad0[0x18];
    void* m18;
    void Fn(void* a);
    void SetOn(bool on);
};

extern "C" void func_0017EFC0(Obj_0017F5F8* self, void* a);

void Obj_0017F5F8::Fn(void* a)
{
    m18 = D_00361258;
    SetOn(true);
    func_0017EFC0(this, a);
}
