struct Obj_00128818;
extern void* D_00393EF4;
extern "C" void* func_00139468(void* mgr, int id);
extern "C" void func_0013B920(void* p, void* tex);
extern "C" int func_00138920(void* tex);
extern "C" int func_00138948(void* tex);
extern "C" void func_00123C40(Obj_00128818* self, float w, float h, int flag);

struct Obj_00128818 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0x1A0 - 0x10];
    int m_tex;
    void* m1A4;
    void SetTexture(int id);
};

void Obj_00128818::SetTexture(int id)
{
    m_tex = id;
    void* t = func_00139468(D_00393EF4, id);
    func_0013B920(m1A4, t);
    func_00123C40(this, (float)func_00138920(t), (float)func_00138948(t), 0);
    m_flags |= 0x1000;
}
