typedef int qword __attribute__((mode(TI)));
union Vec_001BF0A8 { qword q; struct { float x, y, z, w; } v; };
struct Dst_001BF0A8 { char pad[0x250]; Vec_001BF0A8 m_250; };
struct Obj_001BF0A8 { char pad[0xA30]; Dst_001BF0A8* m_A30; void Go(); };
void Obj_001BF0A8::Go() { Vec_001BF0A8 v; v.v.x = 0.0f; v.v.y = 0.0f; v.v.z = 0.0f; v.v.w = 1.0f; m_A30->m_250 = v; }
