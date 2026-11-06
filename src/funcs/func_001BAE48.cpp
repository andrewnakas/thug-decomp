typedef int qword __attribute__((mode(TI)));
union Vec_001BAE48 { qword q; struct { float x, y, z, w; } v; };
struct Src_001BAE48 { char pad[0x50]; Vec_001BAE48 m_50; };
struct Obj_001BAE48 { char pad[0xC]; Src_001BAE48* m_C; char pad2[0x10]; Vec_001BAE48 m_20; void Fetch(); };
void Obj_001BAE48::Fetch() { m_20 = m_C->m_50; }
