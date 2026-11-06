struct Sub_001A67B0 { char pad[0x74]; int m_74; };
struct Obj_001A67B0 { char pad[0x1C]; int m_1C; char pad2[0x21C - 0x20]; Sub_001A67B0* m_21C; int Get(); };
int Obj_001A67B0::Get() { if (!(m_1C & 0x10)) return -1; Sub_001A67B0* p = m_21C; if (!p) return -1; return p->m_74; }
