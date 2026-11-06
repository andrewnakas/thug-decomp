extern "C" void func_001E6AC8(void* a, void* b);
struct Obj_001841F0 { char pad[0x24]; void* m_24; void Go(void* a); };
void Obj_001841F0::Go(void* a) { if (m_24) func_001E6AC8(a, m_24); }
