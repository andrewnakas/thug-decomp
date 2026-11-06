extern "C" void func_001B99A0(void* self, int a, float f);
struct Obj_001B9978 { char pad[0x2C]; int m_2C; void Go(); };
void Obj_001B9978::Go() { func_001B99A0(this, m_2C, 1.0f); }
