typedef int qword __attribute__((mode(TI)));
union Vec_001B6BD0 { qword q; struct { float x, y, z, w; } v; };
struct Obj_001B6BD0 { char pad[0x30]; Vec_001B6BD0 m_30; void Set(const Vec_001B6BD0& v); };
void Obj_001B6BD0::Set(const Vec_001B6BD0& v) { m_30 = v; }
