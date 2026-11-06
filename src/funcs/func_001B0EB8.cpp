extern "C" void func_00266698(void* p);
extern "C" void func_001B0EF0(void* self, int v);
struct Sub_001B0EB8 { char pad[0x204]; int m_204; };
struct Obj_001B0EB8 { char pad[0x2C]; Sub_001B0EB8* m_2C; char pad2[0x1400 - 0x30]; int m_1400; char m_1404[4]; void Set(int on); };
void Obj_001B0EB8::Set(int on) { m_1400 = on; if (!on) func_00266698(m_1404); else func_001B0EF0(this, m_2C->m_204); }
