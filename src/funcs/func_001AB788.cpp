struct Obj_001AB788 { char pad[0x127C]; int m_127C; int m_1280[10]; char pad2[4]; int m_12AC; void Clear(); };
void Obj_001AB788::Clear() { m_12AC = 0; m_127C = 0; for (int i = 9; i >= 0; i--) m_1280[i] = 0; }
