extern "C" void func_00107E10(void* p);
extern "C" void func_00107D80(void* p);
struct Obj_001BAD68 { char pad[0x1C]; int m_1C; char pad2[0x38 - 0x20]; void* m_38; void Set(void* p); };
void Obj_001BAD68::Set(void* p) { m_38 = p; if (m_1C) func_00107E10(p); else func_00107D80(p); }
