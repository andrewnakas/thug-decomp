struct Obj_001ABE98 { char pad[0x9A0]; int m_9A0[3]; void Set(int* src); };
void Obj_001ABE98::Set(int* src) { for (int i = 0; i < 3; i++) m_9A0[i] = src[i]; }
