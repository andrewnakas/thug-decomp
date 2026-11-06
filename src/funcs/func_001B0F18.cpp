extern "C" void func_00266698(void* p);
extern "C" void func_001B0EB8(void* self, int on);
struct Obj_001B0F18 { char pad[0x13F4]; int m_13F4; int m_13F8; int m_13FC; int m_1400; char m_1404[4]; void Reset(); };
void Obj_001B0F18::Reset() { m_13FC = 0; m_13F8 = 0; m_13F4 = 0; func_001B0EB8(this, 0); func_00266698(m_1404); }
