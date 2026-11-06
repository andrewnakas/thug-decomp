extern "C" void* func_00185578(void* self, unsigned int id);
extern "C" void func_0019D008(void* self);
struct Obj_0019CCF0 { char pad[0xC]; void* m_C; char pad2[0xB0 - 0x10]; void* m_B0; void Go(); };
void Obj_0019CCF0::Go() { m_B0 = func_00185578(m_C, 0x81C7122D); func_0019D008(this); }
