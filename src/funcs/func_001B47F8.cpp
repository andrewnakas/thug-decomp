typedef int qword __attribute__((mode(TI)));
union Vec_001B47F8 { qword q; struct { float x, y, z, w; } v; };
struct Mat_001B47F8 { Vec_001B47F8 r[4];
  Mat_001B47F8& operator=(const Mat_001B47F8& o) { r[0] = o.r[0]; r[1] = o.r[1]; r[2] = o.r[2]; r[3] = o.r[3]; return *this; } };
struct Dst_001B47F8 { char pad[0xC0]; Mat_001B47F8 m_C0; };
struct Obj_001B47F8 { char pad[0xC]; Dst_001B47F8* m_C; char pad2[0x130 - 0x10]; Mat_001B47F8 m_130; void Go(); };
void Obj_001B47F8::Go() { Mat_001B47F8* d = &m_C->m_C0; d->r[0] = m_130.r[0]; d->r[1] = m_130.r[1]; d->r[2] = m_130.r[2]; d->r[3] = m_130.r[3]; }
