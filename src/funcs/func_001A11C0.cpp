extern "C" void func_001E6B90(void* p, unsigned int crc);
struct Sub_001A11C0 { char pad[0x24]; void* m_24; };
struct Obj_001A11C0 { char pad[0xC]; Sub_001A11C0* m_C; void Go(); };
void Obj_001A11C0::Go() { void* p = m_C->m_24; if (p) func_001E6B90(p, 0x5DB4115F); }
