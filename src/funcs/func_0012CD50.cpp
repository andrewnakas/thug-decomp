struct Sub_0012CD50 {
    char pad[0x80];
};

struct Obj_0012CD50 {
    char pad[0x80];
    Sub_0012CD50 m80;
    char pad100[0x88];
    float m188;
    float m18C;
};

struct Handle_0012CD50 {
    Obj_0012CD50* m_obj;
};

extern "C" void func_001239D0(Obj_0012CD50* o, float* x, float* y);
extern "C" void func_00123A00(Obj_0012CD50* o, float* x, float* y);
extern "C" float func_0012C128(Sub_0012CD50* s);
extern "C" float func_0012C130(Sub_0012CD50* s);

struct C_0012CD50 {
    char pad[0x1BC];
    Obj_0012CD50* m1BC;
    void GetRect(Handle_0012CD50& h, float* x, float* y, float* w, float* hh);
};

void C_0012CD50::GetRect(Handle_0012CD50& h, float* x, float* y, float* w, float* hh)
{
    func_001239D0(h.m_obj, x, y);
    *x *= func_0012C128(&m1BC->m80);
    *y *= func_0012C130(&m1BC->m80);
    float sw = h.m_obj->m188;
    float aw = func_0012C128(&h.m_obj->m80);
    *w = sw * aw * func_0012C128(&m1BC->m80);
    float sh = h.m_obj->m18C;
    float ah = func_0012C130(&h.m_obj->m80);
    *hh = sh * ah * func_0012C130(&m1BC->m80);
    float a[2];
    func_00123A00(h.m_obj, &a[0], &a[1]);
    *x -= (a[0] + 1.0f) * *w * 0.5f;
    *y -= (a[1] + 1.0f) * *hh * 0.5f;
}
