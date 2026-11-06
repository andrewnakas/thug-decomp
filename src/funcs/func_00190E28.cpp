typedef int qword __attribute__((mode(TI)));
union Vec_00190E28 { qword q; struct { float x, y, z, w; } v; };
struct Src_00190E28 { char pad[0x50]; Vec_00190E28 m_50; };
struct Obj_00190E28 { char pad[0xC]; Src_00190E28* m_C; char pad2[0xC0 - 0x10]; Vec_00190E28 m_C0; char pad3[4]; int m_D4; void Go(); };
void Obj_00190E28::Go() { if (m_D4 != 1) { m_C0 = m_C->m_50; m_D4 = 1; } }
