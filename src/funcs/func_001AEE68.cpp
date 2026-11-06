struct Obj_001AEE68 { char pad[0x12C4]; int m_12C4; int m_12C8[10]; char pad2[4]; int m_12F4; void Clear(); };
void Obj_001AEE68::Clear() { m_12F4 = 0; m_12C4 = 0; for (int i = 9; i >= 0; i--) m_12C8[i] = 0; }
