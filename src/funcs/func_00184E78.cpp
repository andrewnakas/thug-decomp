struct Obj_00184E78 { char pad[8]; int m_flags; void SetFlag(bool on); };
void Obj_00184E78::SetFlag(bool on) { if (on) m_flags |= 1; else m_flags &= ~1; }
