struct Obj_001A3D70 { char pad[0x1C]; int m_1C[3]; int Find(); };
int Obj_001A3D70::Find() { for (int i = 0; i < 3; i++) if (!m_1C[i]) return i + 1; return 0; }
